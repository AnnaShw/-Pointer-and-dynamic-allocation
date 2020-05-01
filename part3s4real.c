#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZENAME 80
char** GetAllNames(int* countNames);
void FreeAllNames(char** names,int countNames);
void PrintAllNames(char** names,int countNames);
void UpdateAllNames(char** names,int countNames);
void SortAllNames(char** names,int countNames);
char SecondName(char* names);
//in main function we only calling a functions
int main(){
    int countNames;
    char** names;
    printf("How many names do you want?\n");
    scanf("%d",&countNames);
    names=GetAllNames(&countNames);
    UpdateAllNames(names,countNames);
    SortAllNames(names,countNames);
    PrintAllNames(names,countNames);
    FreeAllNames(names,countNames);
    return 0;
}
//This funtion wil creationg stings with alocation of  memory 
char** GetAllNames(int* countNames){
    char** names=NULL;
    char help[SIZENAME];
    names=(char**)calloc(*countNames,sizeof(char*));
    int len;
    for(int i=0;i<(*countNames);i++){
        printf("Okey,enter  %d names:\n",i+1); 
        if(i==0)
            getchar();
        gets(help);
        len=strlen(help);
        if((len>0)&&(help[len-1]=='\n')){
            help[len-1]='\n';
        }
        names[i]=(char*)malloc(len+1);
        strcpy(names[i],help);
    }
    return names;
}
//This function will print names on the screen
void PrintAllNames(char** names,int countNames){
    printf("List of names:\n");
    for(int i=0;i<countNames;i++){
        printf("%s\n",(names[i]));
    }
}
//this function will free allocating memory
void FreeAllNames(char** names,int countNames){
    int j=0;
    while(j<countNames){
        free(names[j]);
        j++;
        }
    }
//this funtion will remove space if there more than 1 betwen words
   void UpdateAllNames(char** names,int countNames){
        int j=0;
    for(int i=0;i<countNames;i++){
        while((names)[i][j]!='\0'){
            if(names[i][j]==' '){
                names[i][j]='_';
            }
            j++;
        }
        j=0;
    }
   }
//This function will sort names in alphabetical order
    void SortAllNames(char** names,int countNames){
        int k;
        char* temp;
        for(int i=0;i<countNames;i++){
            for(int w=i;w<countNames;w++){
                if(strcmp(names[i],names[w])>0){
                    temp=names[i];
                    names[i]=names[w];
                    names[w]=temp; 
                    w=i;
                  }
                }
               
                }
            }
        
    
    char SecondName(char* names){
        int i;
        for( i=0;names[i]=="";i++);
        return names[i+1];
           
    }