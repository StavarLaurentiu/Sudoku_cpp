This is a Sudoku generator and solver made in C++ using graphics.h library.

My algorithm for generating a sudoku board starts from 3 random key numbers. Using this numbers and some arithmetic ecuations I provide 6 seed numbers which are spread across the board.
From there I used a backtracking algorithm to solve the sudoku.
After that, I hide some numbers (depending on the difficulty) using another own algorithm: I make a vector which consists of numbers in 0-8 range and I suffle this vector. Then I take the first number in the vector and shuffle it again, I take another number from the vector. This two numbers are i and j, I hide board[i][j]. I do this until I hide enough different numbers.

This way I reduced the time complexity of generating a sudoku table by randomizing only 3 numbers (which was the thing that took the most time).

When the game is open the menu screen will pop up.

![6f816a3d-ac87-476f-8709-52200f6c3904](https://user-images.githubusercontent.com/118437095/223203168-60cca82a-382f-4d9a-98b7-18e529f2f289.jpg)

If the PLAY GAME button is pressed, the board will be generated, printed and the game will start.

![9058d017-eed8-4c05-b358-6ed285d0852a](https://user-images.githubusercontent.com/118437095/223205362-f92061e7-c2bb-4048-9e50-ebabc9d14abd.jpg)

After that, the user can move using "wasd" keys, select a number, change it by simply presing another number, return to menu, reset the board or quit the game. A lives counter will be shown in the right bottom corner. There are four scenarious after the user submits a number. 

   1. The number is correct - the game will continue.
   
![50d47add-3b40-442e-81ab-45ec40dfa61f](https://user-images.githubusercontent.com/118437095/223247555-200e210d-e0b2-4cab-ab84-c58998d556c4.jpg)

![5ab0c810-192e-4047-8cad-1b49bc93d3ef](https://user-images.githubusercontent.com/118437095/223247965-eff940b5-2609-47b9-8b4a-78f89c561aa3.jpg)

  
   2. The number is wrong and lives > 1 - the lives counter will decrease.
   
![6ee468be-b991-4426-987d-7ab8da679be8](https://user-images.githubusercontent.com/118437095/223252027-9ba8dd82-2760-442c-b644-5cfbf17147e1.jpg)
   
   3. The number is wrong and lives = 1 - the game is lost
                                        - a possible solution for the board will be printed
   
![382a94c9-ae34-429d-852c-afa86ad0cfd2](https://user-images.githubusercontent.com/118437095/223253017-d8dfae39-d943-4b1f-b1d8-dbd47bdc1eb4.jpg)
  
![4d8d3331-f0b7-476a-bedc-2c2e35167e36](https://user-images.githubusercontent.com/118437095/223253071-6193b570-47a3-4656-845e-36f10643b850.jpg)
   
   4. The last number is submitted corectly - the game is won
                                            - the answer found will be printed
   
![95578391-51c4-462c-affa-8dc5d065a60c](https://user-images.githubusercontent.com/118437095/223255115-209406e3-64c8-488c-bbf6-1da8a88b660c.jpg)

If the user choose to start a new game, another board will be generated.
   
![b9f00e58-873e-423c-9ed2-b8888758414f](https://user-images.githubusercontent.com/118437095/223255179-a2190458-eaa7-47d6-bd14-b1bcf267e7c5.jpg)

There is also a settings tab where you can change the difficulty(1-3) and the number of lives(1-4) by simply clicking a button.
   
![8200f7f4-93ba-478f-a75a-48b1cc3a8a6b](https://user-images.githubusercontent.com/118437095/223257759-88923b0d-2e5b-49dc-b375-0b5aee6d4837.jpg)

![65a8ddd9-4971-40f1-afb5-b0e26c914a46](https://user-images.githubusercontent.com/118437095/223257771-3b326e80-550b-4394-b8ad-e64384d97eb9.jpg)

The last two tabs are Controls and Credits.

![6e78d355-da8d-49d1-bbdc-f96ba7fb577d](https://user-images.githubusercontent.com/118437095/223262358-8120025b-ef1c-4fe6-871c-0c659d7f7228.jpg)

![595add27-0d6c-404a-8d66-b6f950a4f6ff](https://user-images.githubusercontent.com/118437095/223262460-f875b487-fb43-4da5-887d-1135bb67b291.jpg)
