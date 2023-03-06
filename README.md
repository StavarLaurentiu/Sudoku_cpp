This is a Sudoku generator and solver made in C++ using graphics.h library.

When the game is open the menu screen will pop up.

![6f816a3d-ac87-476f-8709-52200f6c3904](https://user-images.githubusercontent.com/118437095/223203168-60cca82a-382f-4d9a-98b7-18e529f2f289.jpg)

If the PLAY GAME button is pressed, the board will be generated, printed and the game will start.

![9058d017-eed8-4c05-b358-6ed285d0852a](https://user-images.githubusercontent.com/118437095/223205362-f92061e7-c2bb-4048-9e50-ebabc9d14abd.jpg)

After that, the user can move using "wasd" keys, select a number, change it by simply presing another number, return to menu, reset the board or quit the game. A lives counter will be shown in the right bottom corner. There are four scenarious after the user submits a number. 

   1. The number is correct - the game will continue.
   
![50d47add-3b40-442e-81ab-45ec40dfa61f](https://user-images.githubusercontent.com/118437095/223247555-200e210d-e0b2-4cab-ab84-c58998d556c4.jpg)

![5ab0c810-192e-4047-8cad-1b49bc93d3ef](https://user-images.githubusercontent.com/118437095/223247965-eff940b5-2609-47b9-8b4a-78f89c561aa3.jpg)

  
   2. The number is wrong and lives > 1 - the lives counter will decrease 
   
![6ee468be-b991-4426-987d-7ab8da679be8](https://user-images.githubusercontent.com/118437095/223252027-9ba8dd82-2760-442c-b644-5cfbf17147e1.jpg)
   
   3. The number is wrong and lives = 1 - the game is lost
   
![382a94c9-ae34-429d-852c-afa86ad0cfd2](https://user-images.githubusercontent.com/118437095/223253017-d8dfae39-d943-4b1f-b1d8-dbd47bdc1eb4.jpg)
  
![4d8d3331-f0b7-476a-bedc-2c2e35167e36](https://user-images.githubusercontent.com/118437095/223253071-6193b570-47a3-4656-845e-36f10643b850.jpg)
   
   4. The last number is submitted corectly - the game is won
   
