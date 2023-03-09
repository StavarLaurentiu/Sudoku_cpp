#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

// the dimension of the board
#define N 9

// the numbers of available boards
#define MAX 9

void menu();
void game();
void getInput(int board[N][N], int answer[N][N]);
void gameLost(int answer[N][N]);
void gameWon();
bool isWon(int board[N][N]);
void highlightGreen(int board[N][N], int i, int j);
void highlight(int board[N][N], int i, int j);
void hide(int board[N][N], int n);
void generateBoard(int board[N][N]);
bool sudokuSolver(int board[][N], int row, int col);
bool isEligible(int board[][N], int row, int col, int num);
void printBox(int board[N][N], int i, int j);
void printBoard(int board[][N], int row, int col);
