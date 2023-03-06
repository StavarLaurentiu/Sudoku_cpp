This is a Sudoku generator and solver made in C++ using graphics.h library.

When the game is open the menu screen will pop up.

![6f816a3d-ac87-476f-8709-52200f6c3904](https://user-images.githubusercontent.com/118437095/223203168-60cca82a-382f-4d9a-98b7-18e529f2f289.jpg)

If the PLAY GAME button is pressed, the board will be generated, printed and the game will start.

![9058d017-eed8-4c05-b358-6ed285d0852a](https://user-images.githubusercontent.com/118437095/223205362-f92061e7-c2bb-4048-9e50-ebabc9d14abd.jpg)

After that, the user can move using "wasd" keys, select a number, change it by simply presing another number, return to menu, reset the board or quit the game. A lives counter will be shown in the right bottom corner. There are two scenarious after the user submits a number. 

   1. The number is correct - the game will continue.
 
 ![382a94c9-ae34-429d-852c-afa86ad0cfd2](https://user-images.githubusercontent.com/118437095/223246133-a82fb050-b9d7-4e4c-a458-7bcc7a36d9c6.jpg)
  
   2. The number is wrong - the lives counter will decrease and if there are any more lives the game will continue,                                else the game stops.
