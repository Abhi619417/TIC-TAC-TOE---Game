#include<iostream>
#include<cstdio>
#include<ctime>
//#include"Board.cpp"  //defined already in main->players
using namespace std;

class Computer{
    private:
        //to store the magic number
        int magic_number[3][3]={8,3,4,1,5,9,6,7,2};
        //to store the size of board 
        int size;
        //to store the player no ie 1 or 0 
        int id;
        //to define the board
        Board *board;
        // used in func find and nextMove to store the row and column value for  corresponding magic number 
        int row=0,column=0;
        //for level 2 (hard) to place first move func:nextMove(); 
        bool flag=true;;

    public:
        
         
        //constructor to store the board and id ie 0 or 1 
        Computer(Board *board,int id){
            this->board=board;
            size=board->getSize();
            this->id=id;
            flag=true;
        }
    private:
        bool easy(){
            int i,j,count=0;
            
            //generating a random number s between 0 & 2 to 
            //loopin only for 10 times using random number to fill the next cell
            while(++count<10){
                srand(time(0));
                i=rand()%3;
                j=rand()%3;
                if(board->input(i+1,j+1,id)) return true;
            }
            //if random number can not place valid input
            // will fill the first empty place 
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    if(board->board[i][j]=='\0'){
                        board->input(i+1,j+1,id);
                        return true;
                    }
                }  
            }

            return false;
        }
        //to find the position of row and column value for given magic number
        bool find(int sum){
            int i,j;
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    if(magic_number[i][j]==sum){
                        this->row=i+1;  // starting index=1
                        this->column=j+1;
                     
                        return true;
                    }
                }
            }
            return false;
        }

        //to fill the next cell
        bool nextMove(int level){
            //for looping
            int i,j;
            //to store the sum of magic number && count the no of occurenecs of O & X 
            //----count to store occurences
            //row_,col_ ,pd_,sd_ to store sum of magic number
            // in row wise
            int row1[3],row2[3],row1count[3],row2count[3];
            //in columne wise
            int col1[3],col2[3],col1count[3],col2count[3];

            //initializing the value
            //in principal diagonal wise i.e. major diagonal wise 
            int pd1=0,pd2=0,pd1count=0,pd2count=0;
            //in secondary diagonal wise i.e minor diagonal
            int sd1=0,sd2=0,sd1count=0,sd2count=0,k=size-1;//k: to store column no(i,k)-(0,2),(1,1),(2,0)

            for(i=0;i<size;i++){
                //initializing the value for rows and columns 
                row1[i]=row2[i]=row1count[i]=row2count[i]=0;
                col1[i]=col2[i]=col1count[i]=col2count[i]=0;

                for(j=0;j<size;j++){

                    //checking along columns
                    if(board->board[i][j]=='O'){   //computer
                        col1count[i]+=1;
                        col1[i]+=magic_number[i][j];
                    }
                    if(board->board[i][j]=='X'){   //user
                        col2count[i]+=1;
                        col2[i]+=magic_number[i][j];
                    }
                    //checking along rows
                    if(board->board[j][i]=='O'){ //computer
                        row1count[i]+=1;
                        row1[i]+=magic_number[j][i];
                    }
                    if(board->board[j][i]=='X'){ //user
                        row2count[i]+=1;
                        row2[i]+=magic_number[j][i];
                    }

                    //checking along principal diagonal
                    if(i==j){
                        if(board->board[i][j]=='O'){ //computer
                            pd1count+=1;
                            pd1+=magic_number[i][j];
                        }
                        if(board->board[i][j]=='X'){ //user
                            pd2count+=1;
                            pd2+=magic_number[i][j];
                        }
                    }

                } //end of j loop

                //along secondary diagonal
                if(board->board[i][k]=='O'){ //computer
                    sd1count+=1;
                    sd1+=magic_number[i][k];
                }
                
                if(board->board[i][k]=='X'){ //user
                    sd2count+=1;
                    sd2+=magic_number[i][k];
                }
                //decrementing column value
                k=k-1;

            }
            
            //computer

            //checking if computer can win or not
            //if computer can win trace the position and fill it;
            for(int i=0;i<size;i++){
                //row wise 
                if(row1count[i]==2 && find(15-row1[i])) { //find call will change row and column value
                    if(board->input(this->row,this->column,id)) return true;
                }
                //column wise
                if(col1count[i]==2 && find(15-col1[i])){
                    if(board->input(this->row,this->column,id)) return true;
                }
            }
            //princpal diagonal wise
            if(pd1count==2 && find(15-pd1)){
                if(board->input(this->row,this->column,id)) return true;
            }
            //seconadary diagonal wise
            if(sd1count==2 && find(15-sd1)){
                if(board->input(this->row,this->column,id)) return true;
            }

            //user

            //cheking if user can win in next move or not
            // if he can win our move will try to stop user
            for(i=0;i<size;i++){
                //row wise
                if(row2count[i]==2 && find(15-row2[i])){
                    if(board->input(this->row,this->column,id)) return true;
                }
                //column size
                if(col2count[i]==2 && find(15-col2[i])){
                    if(board->input(this->row,this->column,id)) return true;
                }
            }
            //along principal diagonal
            if(pd2count==2 && find(15-pd2)){
                if(board->input(this->row,this->column,id)) return true;
            }
            //along secondary diagonal
            if(sd2count==2 && find(15-sd2)){
                if(board->input(this->row,this->column,id)) return true;
            }

            //first move of computer for level 2
            if(level==2 && flag){
                flag=false;
                if(easy()) return true;
                
            }
            //first move for level 3
            if(board->input(size/2+1,size/2+1,id)) return true; //middle position;

            //if level is hard and user tries to trap            
            //to counter it           
            if(level==3 && (pd2count==2 || sd2count==2) ){
                if(board->board[size/2][size/2]=='X'){
                    //if user tries to trap with middle and any corner element
                    if (board->input(1,size,id)) return true; 
                    if(board->input(size,1,id)) return true; 
                }
                //by putting values at opposite diagonal
 
                if(board->input(size-1,1,id)) return true;
                if(board->input(size-1,size,id)) return true;
            }

            //if the level is medium user trying to trap 
            //computer will be traped
            if (board->input(1,1,id)) return true; //first move  if middle position is filled by user
            if(board->input(size,size,id)) return true; 
            if(board->input(1,size,id)) return true;
            if(board->input(size,size,id)) return true;
            
            if(board->input(size-1,1,id)) return true;
            if(board->input(size-1,size,id)) return true;

            //in some cases 15-sum will be  already filled
            //with all the previous inputs
            //eg user input (1 1),(3 3),(2 3),(1,2)
            if(board->input(size,1,id)) return true;   
            if(board->input(size,size-1,id)) return true; 

            //will not be executed
            return false;

        }

    public:
        void play(int level){
            if(level==1){
                easy();
            }
            else {
                nextMove(level);
            }
        }

};
