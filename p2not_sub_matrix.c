#include<stdio.h>
#include<stdlib.h>

void BuildMatrix(int*** matrix,int row,int column);
void FreeMatrix(int*** matrix,int row);
void PrintMatrix(int** matrix,int row,int column);
int** SubMatrix(int** matrix,int sizeMatrix,int* pSizeSubMatrix);

int main(){
    int row,column,subsize;
    int** matrix=NULL,**matrix1=NULL;
    printf("Enter row and column for your matrix:\n");
    scanf("%d",&row);
    column=row;
    BuildMatrix(&matrix,row,column);
    PrintMatrix(matrix,row,column);

    printf("Enter size of submatrix:\n");
    scanf("%d",&subsize);

    matrix1=SubMatrix(matrix,row,&subsize);
    PrintMatrix(matrix1,subsize,subsize);

    
    FreeMatrix(&matrix1,subsize);
    FreeMatrix(&matrix,row);
    return 0;
}
//function to create a matrix
void BuildMatrix(int*** matrix,int row,int column){
    *matrix=(int**)malloc(sizeof(int*)*row);//alocation memory to the marix
    if(matrix==NULL){
        printf("Not enough memory.\n");
        exit(1);
    }//if there is not enough memory in the heap exit
    for(int i=0;i<row;i++){
        (*matrix)[i]=(int*)malloc(sizeof(int*)*column);//alocation memory
        if(matrix==NULL){//if there is not enough memory in the heap exit
            printf("Not enough memory.\n");
            FreeMatrix(matrix,i);
            exit(1);
        }
    //Gettig values for matrix from user
    for(int j=0;j<column;j++){
        printf("Enter a number for [%d][%d] position:\n",i,j);
        scanf("%d",&((*matrix)[i][j]));
        }
    }
    printf("\n");
}

void PrintMatrix(int** matrix,int row,int column){
    for(int n=0;n<row;n++){
        for(int m=0;m<column;m++){
            printf("%d ",(matrix[n][m]));
        }
        printf("\n");
    }
}

void FreeMatrix(int*** matrix,int row){
    for(int g=0;g<row;g++){
        free((*matrix)[g]);
        (*matrix)[g] = NULL;
    }
    free(*matrix);
}

int** SubMatrix(int** matrix,int sizeMatrix,int* pSizeSubMatrix){
    int sum1=0,sumMax=0,subrow=0,subcol=0,**subMatrix=NULL;
    for(int i=0;i<sizeMatrix;i++){
      for(int i=0;i<sizeMatrix;i++){
        for(int j=0;j<sizeMatrix;j++){
            for(int q=i;q<i+(*pSizeSubMatrix)&&q<sizeMatrix;q++){
                for(int w=j;w<j+(*pSizeSubMatrix)&&w<sizeMatrix;w++){
                    sum1+=matrix[q][w];
                }
            }
            if(sum1>sumMax){
                sumMax=sum1;
                subrow=i;
                subcol=j;
                sum1=0;
    
            }
        }
    }
    subMatrix=(int**)malloc(sizeof(int*)*(*pSizeSubMatrix));
    for(int g=0;g<(*pSizeSubMatrix);g++){
        subMatrix[g]=(int*)malloc(sizeof(int)*(*pSizeSubMatrix));
        if(subMatrix==NULL){
            printf("Not enough memory.\n");
            exit(1);
        }
    }               
    for(int i=0;i<(*pSizeSubMatrix);i++){
        for(int j=0;j<(*pSizeSubMatrix);j++){
            subMatrix[i][j]=matrix[subrow+i-1][subcol+j-1];
        }
    }
    return subMatrix;         
}
}