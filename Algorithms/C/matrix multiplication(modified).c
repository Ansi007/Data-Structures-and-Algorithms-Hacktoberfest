#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initialize(int *p, int rows,int columns);
void printmatrix(int *r,int rows,int columns);
void multiply(int *firstmat,int *secondmat,int rows1,int columns1,int rows2,int columns2);

int main(){
	
	srand(time(0));
	
	int *matrix1,*matrix2,r1,c1,r2,c2;
	
	do{
		
		printf("Number of columns of matrix 1 must be equal to number of rows of matrix 2\n\n");
	
	    printf("Enter the number of rows and columns of matrix 1 ");
		scanf("%d%d",&r1,&c1);
		
		printf("Enter the number of rows and columns of matrix 2 ");
		scanf("%d%d",&r2,&c2);
		
		if(c1!=r2)
		printf("Invalid Input (^__^)\n\n");
		
	}while(c1!=r2);
	
	matrix1=(int*) malloc(r1*c1*sizeof(int*));
	matrix2=(int*) malloc(r2*c2*sizeof(int*));	
	
	
	initialize(matrix1,r1,c1);
	printmatrix(matrix1,r1,c1);
	
	printf("\n\n");
	
	initialize(matrix2,r2,c2);
	printmatrix(matrix2,r2,c2);
	
	printf("\n\n");
	
	multiply(matrix1,matrix2,r1,c1,r2,c2);
	free(matrix1);
	free(matrix2);
	
	return 0;
}

void initialize(int *p, int rows,int columns){
	
	for(int i=0;i<rows;i++){
		
		for(int j=0;j<columns;j++){
			
			p[i*columns+j]=rand()%9+1;
		}
	}
}

void printmatrix(int *r,int rows,int columns){
	
	for(int i=0;i<rows;i++){
		
		for(int j=0;j<columns;j++){
			
			printf("%d\t",r[i*columns+j]);
		}
		printf("\n");
	}
}

void multiply(int *firstmat,int *secondmat,int rows1,int columns1,int rows2,int columns2){
	
	int sum=0;
	
	for(int i=0;i<rows1;i++){
		
		for(int j=0;j<columns2;j++){
			
			for(int k=0;k<columns1;k++){
				
				sum=sum+(firstmat[i*columns1+k]*secondmat[k*columns2+j]);
				
			}
			
			printf("%d\t",sum);
			sum=0;
		}
		printf("\n");
	}
}

