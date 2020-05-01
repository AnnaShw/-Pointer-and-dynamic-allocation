#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void CreateNewString(char* str);
int* BuildArray(int* size);
void PrintArray(int* group,int size);
int* MergeTwoArrays(int* arr1,int size1,int* arr2,int size2);
/*in main function we call a functions and get string from user,
also we get memory for string with help of malloc function.*/
int main(){
    int* ar1,*ar2,*ar3;
    int size1=0,size2=0;
    char* str;
    printf("Enter a string:\n");
    str=(char*)malloc(sizeof(*str)*sizeof(char*));
    scanf("%s",str);
    /*every time that we see this if statement we cheking possibility 
    if there enough memory.*/
    if(str==NULL){
		printf("Error-unable to allocate required memory.\n");
		exit(1);
	}
    CreateNewString(str);
    free(str);
    ar1=BuildArray(&size1);
    PrintArray(ar1,size1);
    ar2=BuildArray(&size2);
    PrintArray(ar2,size2);
    ar3=MergeTwoArrays(ar1,size1,ar2,size2);
    PrintArray(ar3,sizeof(ar3)-2);
    free(ar3);
    free(ar2);
    free(ar1);
    return 0;
}

//this function will create new string from the given
void CreateNewString(char* str){
   char* st=(char*)malloc(1);
   st[0]='\0';
   int count=1;
   int i=0,newsize=0;
   do{
        if(str[i]==str[i+1])
            count++;
       
        else{
            st=(char*)realloc(st,(newsize+2)*sizeof(char));
            if(!st){
                printf("Error.");
                exit(1);
            }
            st[newsize]=str[i];
            st[newsize+1]=count+'0';
            count=1;
            newsize+=2;
        }
        i++;

   }while(str[i]!='\0');
   st[newsize]='\0';
   puts(st);
   free(st); 
}
//this function will get memory for the array,build him and return him
int* BuildArray(int* size){
    int* arr;
    printf("Enter size of array:\n");
    scanf("%d",size);
    arr=(int*)calloc(*size,sizeof(int));
    for(int i=0;i<(*size);i++){
        printf("Enter number for %d position:\n",i);
        scanf("%d",&(arr[i]));
    }
    return arr;
}
//this function will only print array
void PrintArray(int* group,int size){
    printf("(");
    for(int i=0;i<size;i++){
    printf("%d",group[i]);
    if(i!=size-1)
    printf(",");
    }
    printf(")\n"); 
}
/*This function will make one array from 
two given from user without doubles*/
int* MergeTwoArrays(int* arr1,int size1,int* arr2,int size2){
int* arr=(int*)malloc((size1+size2)*sizeof(int));
int index=0;
for(int i=0,j=0;i<size1 || j<size2;){
    if(arr1[i]<arr2[j]){
        arr[index]=arr1[i];
        i++;
        index++;
    }
    else if(arr1[i]>arr2[j]){
        arr[index]=arr2[j];
        j++;
        index++;
    }
    else{
        arr[index]=arr2[j];
        i++;
        j++;
        index++;
    }
}
return arr;
}