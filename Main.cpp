//including neccessary header files
#include<cstdio>
#include<iostream>
//changing the order of user defined header files will cause error 
//to redclaration of function or class
#include"Players.cpp" 
#include"PlayWithComputer.cpp"

using namespace std;

int main(){
    //choice :computer:1 ,person:2
    int choice; 

    //loop untill the user gives a valid choice 
    while(1){

        printf("\n  PLAY WITH COMPUTER  [1]\n\n  PLAY WITH FRIENDS   [2]\n\n  ENTER YOUR CHOICE: ");
	    scanf("%d",&choice);

        //if the input is valid come out of loop
        if(choice>0 && choice<3) break;
        else printf("Invalid Input !"); //else display invalid input to user and continue
    }
   
    //if choice==1 i.e. play with computer
    if(choice==1) playWithComputer();
    
    //if choice =2 i.e. play with another person
    else Players();

    //waiting for user input to exit the program.
    printf("\n  ENTER ANY KEY TO EXIT: ");
	scanf("%ch",&choice);


    return 0;
}
