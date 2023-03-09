#include "header.h"

// easy = 1 / medium = 2 / hard = 3
int difficulty = 2;
int lives = 3;

// prints Sudoku Board
void printBoard(int board[][N], int row, int col) {
    cleardevice();
    setbkcolor(DARKGRAY);
    cleardevice();

    // prints 81 rectangles, numbers and colors them
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // index for boxes
            int x1 = 75;
            int y1 = 75 * (i + 1);
            int x2 = 150;
            int y2 = 75 * (i + 2);

            // set color for box depending on row
            if (i < 3) setfillstyle(SOLID_FILL, BLUE);
            else if (i < 6) setfillstyle(SOLID_FILL, CYAN);
            else if (i < 9) setfillstyle(SOLID_FILL, BROWN);

            rectangle(x1 + j * 75, y1, x2 + j * 75, y2);
            floodfill(x1 + j * 75 + 1, y1 + 1, WHITE);
            if(board[i][j] != 0) {
                char arr[2];
                sprintf(arr, "%d", board[i][j]);
                settextstyle(6, 0, 4);
                if (i < 3) setbkcolor(BLUE);
                else if (i < 6) setbkcolor(CYAN);
                else if (i < 9) setbkcolor(BROWN);
                setcolor(LIGHTGREEN);
                outtextxy(x1 + j * 75 + 25, y1 + 25, arr);
                setcolor(WHITE);
            }
        }
    }

}

// prints a certain box
void printBox(int board[N][N], int i, int j) {
    // index for boxes
    int x1 = 75;
    int y1 = 75 * (i + 1);
    int x2 = 150;
    int y2 = 75 * (i + 2);

    // set color for box depending on row
    if (i < 3) setfillstyle(SOLID_FILL, BLUE);
    else if (i < 6) setfillstyle(SOLID_FILL, CYAN);
    else if (i < 9) setfillstyle(SOLID_FILL, BROWN);

    rectangle(x1 + j * 75, y1, x2 + j * 75, y2);
    floodfill(x1 + j * 75 + 1, y1 + 1, WHITE);

    char arr[2];
    if (board[i][j] != 0) {
        sprintf(arr, "%d", board[i][j]);
    }
    else {
        sprintf(arr, "    ", board[i][j]);
    }


    settextstyle(6, 0, 4);
    if (i < 3) setbkcolor(BLUE);
    else if (i < 6) setbkcolor(CYAN);
    else if (i < 9) setbkcolor(BROWN);

    setcolor(LIGHTGREEN);

    outtextxy(x1 + j * 75 + 25, y1 + 25, arr);
    setcolor(WHITE);

}

// decide if a number fits a certain box
bool isEligible(int board[][N], int row, int col, int num) {
    // if we found num in twice in the same row or collum
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // if we found the same number twice in a 3 x 3 box
    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[boxRow + i][boxCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// solves the Sudoku (if it is posible)
bool sudokuSolver(int board[][N], int row, int col) {
    // base case
    if (row == N) {
        return true;
    }
    // overflow case
    if (col == N) return sudokuSolver(board, row + 1, 0);
    // already filled case
    if (board[row][col] != 0) return sudokuSolver(board, row, col + 1);
    // normal case
    for (int num = 1; num < 10; num++) {
        if (isEligible(board, row, col, num) == true) {
            board[row][col] = num;
            bool partAns = sudokuSolver(board, row, col + 1);
            if (partAns == true) return true;
            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

// generates a random board
void generateBoard(int board[N][N]) {
    do {
        for(int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = 0;

        srand(time(NULL));
        int num1 = (rand() % 9) + 1;
        int num2 = num1;
        while(num2 == num1) {
            srand(time(NULL));
            num2 = (rand() % 9) + 1;
        }

        // complete 5 numbers on the board based on 2 random numbers
        // also verify if the board is solvable
        board[0][2] = num1;
        board[0][7] = num2;
        board[1][4] = ((num1 * 2000) % 9) + 1;
        board[5][5 + num1 % 2] = ((num1 * 4000) % 9) + 1;
        board[8][6 + num2 % 2] = ((num2 * 4000) % 9) + 1;
    } while (sudokuSolver(board, 0, 0) == 0);

}

// hides a number of elements of the board based on the dificulty
void hide(int board[N][N], int n) {
    while (n > 0) {
        int index1[N], index2[N];
        for (int i = 0; i < N; i++) {
            index1[i] = i;
            index2[i] = i;
        }

        // get a random set of i & j
        random_shuffle(begin(index1), end(index1));
        random_shuffle(begin(index2), end(index2));

        int i = index1[0];
        int j = index2[0];

        if (board[i][j] != 0) {
            board[i][j] = 0;
            n--;
        }
    }
}

// highlights selected boxs
void highlight(int board[N][N], int i, int j) {
    // index for boxes
            int x1 = 75;
            int y1 = 75 * (i + 1);
            int x2 = 150;
            int y2 = 75 * (i + 2);

            setfillstyle(SOLID_FILL, BLACK);
            rectangle(x1 + j * 75, y1, x2 + j * 75, y2);
            floodfill(x1 + j * 75 + 1, y1 + 1, WHITE);

            if(board[i][j] != 0) {
                char arr[2];
                sprintf(arr, "%d", board[i][j]);
                settextstyle(6, 0, 4);
                setbkcolor(BLACK);
                setcolor(WHITE);
                outtextxy(x1 + j * 75 + 25, y1 + 25, arr);
            }
}

// highlights selected boxs with green color
void highlightGreen(int board[N][N], int i, int j) {
    // index for boxes
            int x1 = 75;
            int y1 = 75 * (i + 1);
            int x2 = 150;
            int y2 = 75 * (i + 2);

            setfillstyle(SOLID_FILL, BLACK);
            rectangle(x1 + j * 75, y1, x2 + j * 75, y2);
            floodfill(x1 + j * 75 + 1, y1 + 1, WHITE);

            if(board[i][j] != 0) {
                char arr[2];
                sprintf(arr, "%d", board[i][j]);
                settextstyle(6, 0, 4);
                setbkcolor(BLACK);
                setcolor(LIGHTGREEN);
                outtextxy(x1 + j * 75 + 25, y1 + 25, arr);
                setcolor(WHITE);
            }
}

// checks if the game has been won
bool isWon(int board[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 0) return false;

    return true;
}

// generates the screen after user lost/won; flag: lost = 1 / won = 2
void gameLostWon(int board[N][N], int flag) {
    cleardevice();
    printBoard(board, N, N);

    // INFO ABOUT CONTROLS
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(800, 200, 1300, 425);
    floodfill(801, 201, WHITE);

    if(flag == 1) {
        setbkcolor(BLUE);
        settextstyle(6, 0, 3);
        outtextxy(816, 225, "UNFORTUNETELY, YOU LOST");

        setbkcolor(BLUE);
        settextstyle(6, 0, 2);
        outtextxy(875, 265, "Here you can see a posible");
        outtextxy(900, 290, "solution for this Sudoku.");
    } else if (flag == 2) {
        setbkcolor(BLUE);
        settextstyle(6, 0, 3);
        outtextxy(870, 225, "CONGRATS, YOU WON");

        setbkcolor(BLUE);
        settextstyle(6, 0, 2);
        outtextxy(875, 265, "Here you can see the solution");
        outtextxy(900, 290, "you found for this Sudoku.");
    }

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 325, "q - quit");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 350, "n - new game");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 375, "m - menu");

    // buttons

    setfillstyle(SOLID_FILL, BLUE);
    rectangle(875, 625, 1025, 675);
    floodfill(876, 626, WHITE);
    outtextxy(904, 642, "MENU");

    setfillstyle(SOLID_FILL, BLUE);
    rectangle(1075, 625, 1225, 675);
    floodfill(1076, 626, WHITE);
    outtextxy(1114, 642, "QUIT");

    setfillstyle(SOLID_FILL, BLUE);
    rectangle(925, 525, 1160, 575);
    floodfill(926, 526, WHITE);
    outtextxy(960, 542, "NEW GAME");

    POINT mouse;

    while (1) {


        // button cursor detection
        while (1) {
            GetCursorPos(&mouse);
            if (GetAsyncKeyState(VK_LBUTTON)) {
                if ((mouse.x < 1025 && mouse.x > 875) && (mouse.y < 675 && mouse.y > 625)) {
                        menu();
                } else if ((mouse.x < 1225 && mouse.x > 1075) && (mouse.y < 675 && mouse.y > 625)) {
                        exit(0);
                } else if ((mouse.x < 1160 && mouse.x > 925) && (mouse.y < 575 && mouse.y > 525)) {
                        game();
                }
            }
        }

        int c = getch();

        // if user wants to enter the menu the game
        if(c == 'm' || c == 'M') menu();

        // if user wants to quit the game
        if(c == 'q' || c == 'Q') exit(0);

        // if user wants to generate a new game
        if(c == 'n' || c == 'N') game();

    }

}

// waits for users input
void getInput(int board[N][N], int answer[N][N]) {
    // setup
    cleardevice();
    printBoard(board, N, N);
    int livesCount = 0;

    // make a copy of the initial board
    int copyBoard[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            copyBoard[i][j] = board[i][j];

    // INFO ABOUT CONTROLS
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(800, 100, 1300, 325);
    floodfill(801, 101, WHITE);

    setbkcolor(BLUE);
    settextstyle(6, 0, 4);
    outtextxy(925, 125, "CONTROLS");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 175, "r - reset");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 200, "ENTER - submit box");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 225, "q - quit");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 250, "w a s d - movement");

    setbkcolor(BLUE);
    settextstyle(6, 0, 2);
    outtextxy(925, 275, "m - menu");

    // buttons

    setfillstyle(SOLID_FILL, BLUE);
    rectangle(875, 425, 1025, 475);
    floodfill(876, 426, WHITE);
    outtextxy(904, 442, "RESET");

    setfillstyle(SOLID_FILL, BLUE);
    rectangle(1075, 425, 1225, 475);
    floodfill(1076, 426, WHITE);
    outtextxy(1104, 442, "MENU");

    setfillstyle(SOLID_FILL, BLUE);
    rectangle(975, 525, 1125, 575);
    floodfill(976, 526, WHITE);
    outtextxy(1010, 542, "QUIT");

    POINT mouse;

    // index of selected box
    int i = 0, j = 0;
    while (1) {

        // button cursor detection
        GetCursorPos(&mouse);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if ((mouse.x < 1025 && mouse.x > 875) && (mouse.y < 475 && mouse.y > 425)) {
                    getInput(copyBoard, answer);
            }
            if ((mouse.x < 1225 && mouse.x > 1075) && (mouse.y < 475 && mouse.y > 425)) {
                    menu();
            }
            if ((mouse.x < 1125 && mouse.x > 975) && (mouse.y < 575 && mouse.y > 525)) {
                    exit(0);
            }
        }

        // if the game was won
        if (isWon(board)) gameLostWon(board, 2);

        // if the game was lost
        if (livesCount == lives) gameLostWon(answer, 1);

        // prints remaining lives
        int d = lives - livesCount;
        char arr[21];
        settextstyle(6, 0, 4);
        sprintf(arr, "Lives: %d", d);
        setbkcolor(RED);
        outtextxy(975, 700, arr);
        setbkcolor(BLACK);

        // highlight selected box
        highlightGreen(board, i, j);
        int c = getch();

        // if user resets the board
        if(c == 'r' || c == 'R') getInput(copyBoard, answer);

        // if user wants to quit the game
        if(c == 'q' || c == 'Q') exit(0);

        // if user wants to enter the menu the game
        if(c == 'm' || c == 'M') menu();

        // if the user selects a number
        if(c >= '1' && c <= '9' && board[i][j] == 0) {
                board[i][j] = c - 48;
                highlight(board, i, j);

                // until user submits his choice
                while (c != '\r') {
                    c = getch();
                    if(c >= '1' && c <= '9') board[i][j] = c - 48;
                    highlight(board, i, j);
                }

                int k = board[i][j];
                board[i][j] = 0;

                if (!isEligible(board, i, j, k)) {
                    livesCount++;
                    board[i][j] = 0;
                    printBox(board, i, j);
                } else {
                    board[i][j] = k;
                }

        }

        // switch selected box
        if((c == 'w' || c == 'W') && i > 0) {
                printBox(board, i, j);
                i--;
        }
        if((c == 's' || c == 'S') && i < 8) {
                printBox(board, i, j);
                i++;
        }
        if((c == 'a' || c == 'A')&& j > 0) {
                printBox(board, i, j);
                j--;
        }
        if((c == 'd' || c == 'D') && j < 8) {
                printBox(board, i, j);
                j++;
        }

        printBox(board, i, j);
    }


}

void game() {
    // generate a random board
    int board[N][N];
    generateBoard(board);

    // copy the answer
    int answer[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            answer[i][j] = board[i][j];

    // depending on the difficulty hide board elements
    switch(difficulty) {
        case 1: hide(board, 40); break;
        case 2: hide(board, 57); break;
        case 3: hide(board, 58); break;
    }

    getInput(board, answer);
}

void controls() {
    cleardevice();
    readimagefile("background.jpg", 0, 0, 1366, 868);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(500, 150, 1000, 675);
    floodfill(501, 301, WHITE);

    setbkcolor(LIGHTGRAY);
    settextstyle(6, 0, 4);
    setcolor(1);

    outtextxy(645, 225, "CONTROLS");
    settextstyle(6, 0, 3);

    settextstyle(6, 0, 3);
    outtextxy(600, 325, "r - reset");

    settextstyle(6, 0, 3);
    outtextxy(600, 375, "ENTER - submit box");

    settextstyle(6, 0, 3);
    outtextxy(600, 425, "q - quit");

    settextstyle(6, 0, 3);
    outtextxy(600, 475, "w a s d - movement");

    settextstyle(6, 0, 3);
    outtextxy(600, 525, "m - menu");

    settextstyle(6, 0, 2);
    outtextxy(550, 625, "PRESS ANY KEY TO RETURN");

    getch();
    graphdefaults();
    menu();
}

void credits() {
    cleardevice();
    readimagefile("background.jpg", 0, 0, 1366, 868);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(400, 250, 1100, 575);
    floodfill(501, 301, WHITE);

    setbkcolor(LIGHTGRAY);
    settextstyle(6, 0, 4);
    setcolor(1);

    outtextxy(645, 275, "CREDITS");
    settextstyle(6, 0, 3);

    settextstyle(6, 0, 2);
    outtextxy(450, 375, "THANK YOU FOR PLAYING MY GAME !!!");

    settextstyle(6, 0, 2);
    outtextxy(450, 425, "If you have any sugestions or you want to contact");

    settextstyle(6, 0, 2);
    outtextxy(470, 450, "me, you can find me on Linkedin: Stavar Laurentiu");

    settextstyle(6, 0, 2);
    outtextxy(550, 525, "PRESS ANY KEY TO RETURN");

    getch();
    graphdefaults();
    menu();
}

void settings() {
    // setup
    cleardevice();
    readimagefile("background.jpg", 0, 0, 1366, 868);

    // creates settings box
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(400, 150, 1100, 675);
    floodfill(501, 301, WHITE);

    setbkcolor(LIGHTGRAY);
    setcolor(1);

    settextstyle(6, 0, 4);
    outtextxy(645, 200, "SETTINGS");

    settextstyle(6, 0, 3);
    outtextxy(450, 350, "DIFICULTY:");
    outtextxy(450, 450, "LIVES:");

    // print difficulty boxes
    for (int i = 0; i < 3; i++) {
        if (difficulty == i + 1) {
            setfillstyle(SOLID_FILL, BLUE);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTBLUE);
        }
        rectangle(700 + i * 120, 330, 770 + i * 120 , 390);
        floodfill(701 + i * 120, 331, BLUE);

        char arr[2];
        sprintf(arr, "%d", i + 1);

        if (difficulty == i + 1) {
            setbkcolor(BLUE);
            setcolor(WHITE);
        }
        else {
            setbkcolor(LIGHTBLUE);
        }
        settextstyle(6, 0, 2);
        outtextxy(728 + i * 120, 352, arr);
        setcolor(1);
    }

    // print lives boxes
    for (int i = 0; i < 4; i++) {
         if (lives == i + 1) {
            setfillstyle(SOLID_FILL, BLUE);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTBLUE);
        }
        rectangle(610 + i * 120, 430, 680 + i * 120 , 490);
        floodfill(611 + i * 120, 431, BLUE);

        char arr[2];
        sprintf(arr, "%d", i + 1);

        if (lives == i + 1) {
            setbkcolor(BLUE);
            setcolor(WHITE);
        }
        else {
            setbkcolor(LIGHTBLUE);
        }

        settextstyle(6, 0, 2);
        outtextxy(638 + i * 120, 452, arr);
        setcolor(1);
    }

    // return to menu button
    rectangle(700, 550, 830 , 600);
    floodfill(701, 551, BLUE);
    settextstyle(6, 0, 2);
    outtextxy(722, 568, "MENU");

    POINT mouse;

    // button cursor detection
    while(1) {
        GetCursorPos(&mouse);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if ((mouse.x < 770 && mouse.x > 700) && (mouse.y < 390 && mouse.y > 330)) {
                    difficulty = 1;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 890 && mouse.x > 820) && (mouse.y < 390 && mouse.y > 330)) {
                    difficulty = 2;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 1010 && mouse.x > 940) && (mouse.y < 390 && mouse.y > 330)) {
                    difficulty = 3;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 680 && mouse.x > 610) && (mouse.y < 490 && mouse.y > 430)) {
                    lives = 1;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 800 && mouse.x > 730) && (mouse.y < 490 && mouse.y > 430)) {
                    lives = 2;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 920 && mouse.x > 850) && (mouse.y < 490 && mouse.y > 430)) {
                    lives = 3;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 1040 && mouse.x > 970) && (mouse.y < 490 && mouse.y > 430)) {
                    lives = 4;
                    graphdefaults();
                    settings();
            } else if ((mouse.x < 830 && mouse.x > 700) && (mouse.y < 600 && mouse.y > 550)) {
                    graphdefaults();
                    menu();
            }
        }
    }

}

void menu() {
    cleardevice();
    readimagefile("background.jpg", 0, 0, 1366, 868);

    settextstyle(11, 0, 2);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    line(210, 0, 210, 868);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(290, 0, 390, 868);
    floodfill(211, 0, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(1000, 0, 1100, 868);
    //floodfill(0, 0, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    line(1180, 0, 1180, 868);
    floodfill(1101, 0, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    ellipse(700, 425, 0, 360, 160, 320);
    floodfill(401, 101, WHITE);

    setfillstyle(SOLID_FILL, BLUE);
    setbkcolor(BLUE);

    rectangle(600, 200, 800, 250);
    floodfill(601, 201, WHITE);
    outtextxy(660, 215, "PLAY GAME");

    rectangle(600, 300, 800, 350);
    floodfill(601, 301, WHITE);
    outtextxy(664, 315, "SETTINGS");

    rectangle(600, 400, 800, 450);
    floodfill(601, 401, WHITE);
    outtextxy(660, 415, "CONTROLS");

    rectangle(600, 500, 800, 550);
    floodfill(601, 501, WHITE);
    outtextxy(670, 515, "CREDITS");

    rectangle(600, 600, 800, 650);
    floodfill(601, 601, WHITE);
    outtextxy(685, 615, "QUIT");

    POINT mouse;

    // button cursor detection
    while(1) {
        GetCursorPos(&mouse);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if ((mouse.x < 825 && mouse.x > 575) && (mouse.y < 275 && mouse.y > 175)) {
                    game();
            } else if ((mouse.x < 825 && mouse.x > 575) && (mouse.y < 350 && mouse.y > 300)) {
                    settings();
            } else if ((mouse.x < 825 && mouse.x > 575) && (mouse.y < 450 && mouse.y > 400)) {
                    controls();
            } else if ((mouse.x < 825 && mouse.x > 575) && (mouse.y < 550 && mouse.y > 500)) {
                    credits();
            } else if ((mouse.x < 825 && mouse.x > 575) && (mouse.y < 650 && mouse.y > 600)) {
                    exit(0);
            }
        }
    }
}

int main() {
    initwindow(1366, 868, "Sudoku");

    menu();

    closegraph();
    return 0;
}
