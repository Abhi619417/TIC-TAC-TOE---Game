//including the necessary header files
#include<iostream>
#include<cstdio>

using namespace std;

//defining the class board to display board 
//set user input check winner 
class Board{

    private:
        const  int size=3; //size of board=3
        char **board; //defining the board;

    public:
        Board(){

            board=new char*[size];
            for(int i=0;i<size;i++) {
                board[i]=new char[size];
            }
            
            //setting the characters to null
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    board[i][j]='\0';
                }
            }
        
        }
        //function to get the size of board
        int getSize(){ return size;}

        //function to display the board
        void show(){
            printf("\n");
        
	        for (int i=0;i<size;i++){
    	        printf(" | ");
		        for(int j=0;j<size;j++){
			
                    //if the place is empty 
			        if(board[i][j]=='\0') printf("  ");

			        //else  if(j==2) printf("%c ",a[i][j]);
                    else printf("%c ",board[i][j]);
		        }

		        printf("|");
		        printf("\n");
	        }

            printf("\n");
        }

        //m: row number ,n: column number , player=player1(0) or player2(1)
        bool input(int m,int n,int player){
           
            //if the place is already filled return false 
            if(board[m-1][n-1]!='\0') return false;

            //player==0 put O in board[m-1][n-1] for player1	
            if(player==0) board[m-1][n-1]='O';

            //player==1 put X in board[m-1][n-1] for player2
	        else if(player==1) board[m-1][n-1]='X';
    
            return true;    
        }


        //to check winner
        /*
        since we are checking  winner after every input 
        so if the win return true its mean the player who has played the    
        last   move will won
        else it will return false

        */
        int win(){
            int i,j; // to iterate for loop

            //to count the no of 'O' and 'X'

            //to check along rows and columns  
            int row1,row2,col1,col2;
            
            //to check along primary diagonal(major diagonal,main diagonal)
            //(0,0),(1,1),(2,2)
            int pd1=0,pd2=0; 

            //to check along secondary diagonal(minor diagonal)
            int sd1=0,sd2=0,k=size-1; //k=for column count (0,2),(1,1),(2,0)

            for(i=0;i<size;i++){
        
                //initializing the value 

                //to check the rows are same or not
                row1=0;   //for player1
                row2=0;   //for player2

                //to check the columne are same or not
                col1=0;    //for player1
                col2=0;    //for player2

                for(j=0;j<size;j++){
                    //to check for rows
                    if(board[i][j]=='O') row1+=1; //player 1
                    if(board[i][j]=='X') row2+=1; //player 2

                    // to check for columns
                    if(board[j][i]=='O') col1+=1;  //player 1
                    if(board[j][i]=='X') col2+=1;  //player 2
            
                    //to check along primary diagonally 
                    if(i==j){
                        if(board[i][j]=='O') pd1+=1; //player 1
                        if(board[i][j]=='X') pd2+=1; //player 2
                    }
             
                }

                //to check along secondary diagonal 
		        if(board[i][k]=='O') sd1+=1; //player 1
                if(board[i][k]=='X') sd2+=1; // player 2
		
                //decresing the column count to check along seconaday diagonal 
                k=k-1;
		
                //to check if any player is winning or not for columns and rows
		        if(row1==size|| col1==size) return  true;  //player 1
		        if(row2==size|| col2==size) return  true;   //player 2
		
            }

            //to check if any player is wining or not diagonally
	        if(pd1==size||sd1==size) return true;   //player 1
	        if(pd2==size||sd2==size) return true;    //player 2

            //no player is winning
	        return false;
        }
    
    friend class Computer; //to access the board from Computer class
    
};