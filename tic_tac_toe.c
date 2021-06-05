#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define z  3
// function to take input
int  input(char **a,int m,int n,int r)
{
		if(a[m-1][n-1]=='X'||a[m-1][n-1]=='O') return -1;
		if(r==0) a[m-1][n-1]='X';
	else if( r==1) a[m-1][n-1]='O';
}
// function to show table
void show(char **a){
        printf("\n");
        
		for (int i=0;i<z;i++){
			printf(" | ");
			for(int j=0;j<z;j++){
				
				if(a[i][j]==0) printf("  ");
				else  if(j==2) printf("%c ",a[i][j]);
                else printf("%c ",a[i][j]);
				}
			printf("|");
			printf("\n");
		}
        
        printf("\n");
	}

// function to declare winner
int win(char **a){
	
    int i,j,k=z-1,l,s1,s2,d1,d2,*p,e1=0,e2=0,f1=0,f2=0;
    for(i=0;i<z;i++){
        s1=0;
        s2=0;
        d1=0;
        d2=0;
        for(j=0;j<z;j++){
            if(a[i][j]=='O') s1+=1;
            if(a[i][j]=='X') s2+=1;
            if(a[j][i]=='O') d1+=1;
            if(a[j][i]=='X') d2+=1;
            if(i==j){
                    if(a[i][j]=='O') e1+=1;
                    if(a[i][j]=='X') e2+=1;
            }
             

        }
		if(a[i][k]=='O') f1+=1;
         if(a[i][k]=='X') f2+=1;
		k=k-1;
		
		if(s1==z|| d1==z) return -1;
		if(s2==z|| d2==z) return  1;
		
    }
	if(f1==z||e1==z) return -1;
	if(f2==z||e2==z) return 1;
	else return 0;

}

//function to find  the position 
int find(int b[z][z],int *s){
    int i,j;
    for(i=0;i<z;i++)
            for(j=0;j<z;j++) if(b[i][j]==*s) {
                *s=j;
                return i;
            } 
    return -1;

}


//functions for computer//for medium and hard
int  check(char **a,int b[z][z],int r){
    int i,j,k=z-1,l,s1,s2,d1,d2,e1=0,e2=0,f1=0,f2=0,s3=0,s4=0,d3=0,d4=0,e3=0,e4=0,f3=0,f4=0;
    int *p,n;
    p=&n;
    for(i=0;i<z;i++){
        s1=0;
        s2=0;
        d1=0;
        d2=0;
        s3=0;
        s4=0;
        d3=0;
        d4=0;
        for(j=0;j<z;j++){
            if(a[i][j]=='O'){
                s1+=b[i][j]; 
                s3++;           
            }
            if(a[i][j]=='X'){
                s2+=b[i][j];
                s4++;           
                
            }
            if(a[j][i]=='O'){
                d1+=b[j][i];
                d3++; 
            }
            if(a[j][i]=='X'){
                d2+=b[j][i]; 
                d4++;       
            }
            if(i==j){
                    if(a[i][j]=='O'){
                        e1+=b[i][j]; 
                        e3++;
                    }
                    if(a[i][j]=='X'){
                        e2+=b[i][j];  
                        e4++;
                    } 
            }
             

        }
        if(a[i][k]=='O'){
            f1+=b[i][k];
            f3++;
        }
        if(a[i][k]=='X'){
            f2+=b[i][k];
            f4++;
        }
        k=k-1;
        

        if(s3==2){
           *p=15-s1;
            s1=find(b,p);
            if( *p<=2 && *p>=-1 && input(a,s1+1,*p+1,1)!=-1) return 0;
        }

        if(d3==2){
            *p=15-d1;
            d1=find(b,p);
            if(*p<=2 && *p>=-1 && input(a,d1+1,*p+1,1)!=-1) return 0;
        }

        if(s4==2){
            *p=15-s2;
            s2=find(b,p);
            if(*p<=2 && *p>=-1 && input(a,s2+1,*p+1,1)!=-1) return 0;
        }

        if(d4==2){
            *p=15-d2;
            d2=find(b,p);
            if(*p<=2 && *p>=-1 && input(a,d2+1,*p+1,1)!=-1) return 0;
        }
        
    }
    if(e3==2){
        *p=15-e1;
        e1=find(b,p);
        if(*p<=2 && *p>=-1 && input(a,e1+1,*p+1,1)!=-1) return 0;
    }

    if(f3==2){
        *p=15-f1;
        f1=find(b,p);
        if(*p<=2 && *p>=-1 && input(a,f1+1,*p+1,1)!=-1) return 0;
    }

    if(e4==2){
        *p=15-e2;
        e2=find(b,p);
        if(*p<=2 && *p>=-1 && input(a,e2+1,*p+1,1)!=-1) return 0;
    }

    if(f4==2){
        *p=15-f2;
        f2=find(b,p);
        if(*p<=2 && *p>=-1 && input(a,f2+1,*p+1,1)!=-1) return 0;
    }
    // if in the row ,column, diagonal there is only one member in each
    
    if(r==2) if(input(a,1,1,1)!=-1) return 0;
    if(r==2) if(input(a,z,z,1)!=-1) return 0;
    if(input(a,z-1,1,1)!=-1) return 0;
    if(input(a,z,z,1)!=-1) return 0;
    if(input(a,z,1,1)!=-1) return 0;
    if(input(a,1,z,1)!=-1) return 0;
    if(input(a,1,z-1,1)!=-1) return 0;
    if(input(a,z,z-1,1)!=-1) return 0;
    
    
}
//for easy 
 int check1(char **a,int b[z][z],int k){
    int i,j,s;
    
    srand(time(0));
    s=rand()%9;
    if(s==0) s=9;
    
    for(i=0;i<z;i++)
            for(j=0;j<z;j++) if(b[i][j]==s) {
                s=input(a,i+1,j+1,1);
                if(s!=-1) return 0;
            } 
            
    

    if(s==-1 && k<=10) return check1(a,b,k+1);

    check(a,b,2);
}

void computer(char **a,int b[z][z],int k,int l){
    int i,j,s1=0,s2=0;
    
    if(l==1) check1(a,b,0);
    else if(k==1){
            if(a[1][1]==0) input(a,2,2,1);
            else input(a,1,1,1);
            
        
    }    
   
    else  check(a,b,l);
}
//abhishek singh
