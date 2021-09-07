// program for playing tiktak game with computer or between two players
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"tic_tac_toe.c"

#define  z 3

			

int main(){
	char **a,c[20],d[20],ch;
	int	  b[3][3]= { 8,3,4,1,5,9,6,7,2};
	int  i,j=0,m,n,k,l;
	a=(char**)calloc(z,sizeof(char*));
	for(i=0;i<z;i++) 
		*(a+i)=(char*)calloc(z,sizeof(char));
	
/* 	b=(int**)malloc(z*sizeof(int*));
    for(i=0;i<z;i++)
    *(b+i)=(int*)malloc(z*sizeof(int));
	*/
  
	abhi:
	printf("\n  PLAY WITH COMPUTER  [1]\n\n  PLAY WITH FRIENDS   [2]\n\n  ENTER YOUR CHOICE: ");
	scanf("%d",&k);
	
	if(k==2){
		printf("\n  Enter the name of  first player: ");
		scanf("%s",c);
		printf("\n  Enter the name of second player: ");
		scanf("%s",d);
	}
	else if(k==1){
		de:
		printf("\n  EASY      [1]\n\n  MEDIUM    [2]\n\n  HARD      [3]\n\n");
		printf("  ENTER YOUR CHOICE: ");
		scanf("%d",&l);
		if(l>3 || l<1) goto de;
	}
	else {
		printf("\n INVALID INPUT !\n\n");
		goto abhi;
	}
	while(j<9){
		if(j%2==0){
			user1:
			if(k==1) printf("\n  YOUR TURN :\n");
			else
			printf("\n %s ,its your turn :\n ",c);
			printf("  Enter the row number column number : ");
			scanf("%d%d",&m,&n);
			if(m>3||m<1||n>3||n<0){ 
		
				printf(" please Enter the correct position !\n");
				goto user1;
				}
			if(input(a,m,n,0)==-1) goto user1;
			
			show(a);
			if(k==1 && win(a)==1){
				printf("\n  Congratulation You won .\n");
				break;
			}

			else if(win(a)==1) {
				printf("%s won.\n",c);
				break;
				}
				
				

		
			}
		else{
			if(k==1){
				printf("  Its, computer turn. \n");
				computer(a,b,j,l);
				sleep(1);
				show(a);				
				if(win(a)==-1){
				printf("\n Computer wins.\n\n BETTER LUCK NEXT TIME .\n",d);
				 break;
				}
				
			}
			else{
			user2:
		      
                        printf("\n  %s ,its your turn :\n ",d);
                        printf("  Enter the row number column number : ");
                        scanf("%d%d",&m,&n);
                        if(m>3||m<1||n>3||n<1){
						printf("  Please enter the correct position:\n");
							goto user2;
						}
				
						if(input(a,m,n,1)==-1) goto user2;
			
		
						show(a);				
						if(win(a)==-1){
						printf("\n  %s won.\n",d);
						 break;
						}
			
				}
			
			
		}
		j++;
	}
	if(j==9)
	{
	  printf("  This match is draw.\n");
	  printf("  \nwell played.\n");
	}
	sleep(3);
	free(a);
	printf("\n\n");
	printf("\n  ENTER ANY KEY TO EXIT: ");
	scanf("%ch",&ch);
	return 0;
}

// abhishek singh.
