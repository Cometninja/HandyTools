#include <stdio.h>
#include <stdlib.h>

const char FilePath[] = "testfile.hex";
const char WriteFile[] = "newhex.hex";


char cBuff[44];

int main(){
    char c;
    FILE *rfp;  //read file pointer
    FILE *wfp;  //write file pointer
    int i = 0,j;
    int first = 0; 
    rfp = fopen(FilePath, "r");
    wfp = fopen(WriteFile, "w");
    
    if(rfp == NULL){
        printf("read file no worky\n\r");
    }
    else if (wfp == NULL){
        printf("write file no worky\n\r");
    }
    else{
        while((c = fgetc(rfp))!= EOF){
            cBuff[i++] = c;
            if(c == '\n'){
                if(!first){
                    i = 0;
                    first = !first;
                    continue;
                }
                if(i  == 21) break;       
                for(j = 9; j < (i-4); ++j){
                    fputc(cBuff[j],wfp);
                }
                printf("%d",i);
                i = 0;
            }
        }
    }
    printf("hello World\n\r");   
}


