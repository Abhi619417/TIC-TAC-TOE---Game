#include<iostream>
#include<cstdio>
//#include"Board.cpp" \\defined already in main->players
#include"Computer.cpp"

using namespace std;

void playWithComputer(){
    
    //choice= easy: 1,medium:2,Hard:3
    //move =to count no of move played
    //m= row number n=column number
    int choice,move,m,n;

    //taking input while choice is not valid input 
    while(1){ 

        //displaying the menu
        printf("\n  EASY      [1]\n\n  MEDIUM    [2]\n\n  HARD      [3]\n\n");
	    printf("  ENTER YOUR CHOICE: ");
    	scanf("%d",&choice);
        
        //if choice is invalid
        if(choice<1 || choice>3){
            printf("Invalid Input !\n");
        }
        //if choice is valid
        else break;
    }

    //initializing the board
    Board *board= new Board();
    
    //initializing the computer
    Computer *computer=new Computer(board,0); // 0 as computer is playing when move%2==0
    //initializing the move to 1
    move=1;

    //while each 3*3 cell is not filled in board ie move<=9
    while(move<=9){
        if(move%2==1){
            printf("\nIts Your Turn:\n ");
            
           //while players not giving correct input
            while(1){

                //input row and column value starting index: 1
		        printf("\tEnter the row number and column number : ");
		        scanf("%d%d",&m,&n);
		        if((m>3 || m<1)||(n>3||n<1)){ 
		            printf(" Please Enter the correct position !\n");
		        }
                else{
                    
                    // calling input to place the value && 0 for player1 
                    if(!board->input(m,n,move%2)){ //if the input place is all-ready filled it will be false
                        printf("Position is already filled. please enter other position !\n"); 
                    }
                    //if the input position is correct came out from the loop
                    else{

                        //display the board
                        board->show();
                        //check if the move is winning move or not 
                        if(board->win()==1){
                            printf("Congrats You won.");
                            return ;//the winner is found return to main finction
                        }
                        break;

                    }

                } 
            }
        }
        else{
            printf("\nComputer's Turn: \n");
            computer->play(choice);
            board->show();
            if(board->win()){
                printf("\nComputer won.\nBetter Luck Next Time\n");
                return;
            }
        }
        //incrementing the move count 
        move++;
    }

    //if the match is draw
    printf("  \nThis match is draw.\n");
	printf("  \nYou played nicely.\n");


}