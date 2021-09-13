//including the neccessary header files
#include<cstdio>
#include<iostream>
#include"Board.cpp"

using namespace std;

void Players(){
    char player[2][20]; //to store name of the players
    int move,m,n; 
    //move:count the no of moves played till present
    //m: row number
    //n: column number

    //name of first player
    printf("\n  Enter the name of  first player: ");
	scanf("%s",player[0]);
    
    //name of second player
	printf("\n  Enter the name of second player: ");
    scanf("%s",player[1]);

    //initialize the board
    Board *board=new Board();
    int size=board->getSize();
    move=1; //initializing the move to 0
    while(move<=size*size){  //total no of moves=size*size ie 3*3=9 moves
        
        //if move%2==1 player1 turn else player 2 turn    
        printf("\n  %s ,its your turn :\n ",player[move%2]);
            
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
                        printf("%s is winner.",player[move%2]);
                        return ;//the winner is found return to main finction
                    }
                    break;

                }

            }
             
        }
        //increasing the move count
        move++;
    }

    //will be executed iff no players wins
    printf("  \nThis match is draw.\n");
	printf("  \nYou both have well played.\n");

}
