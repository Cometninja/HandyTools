#include <stdio.h>
#include <stdint.h>

#define BUFF_SIZE 100


int main(){
    char hexnumbs[] = "0123456789abcdefABCDEF";
    uint8_t temp;
    uint8_t buff[BUFF_SIZE];
    
    FILE *fp = fopen("newhex.hex", "r");
    if(fp == NULL){
        return -1;
    }    
    printf("hello World\n\r");
    
    uint8_t *buffPtr = (uint8_t *)&buff;
    uint8_t *dp = (uint8_t *)&hexnumbs;
    uint8_t tempBuff;
    int highNibble = 1;
    int i;
    char c;
    while((c = fgetc(fp)) != EOF){
        
        if(c <= '9'){ //numb
            temp = (c - 48);
        }
        else if (c <= 'Z'){ //uppercase
            temp = (c - 55);
        }
        else{
            temp = (c - 87);//lowercase
        }
        i = highNibble ? 4 : 0;
        if(highNibble){
            *buffPtr |= temp << 4;
        }
        else {
            *buffPtr |= temp;
            buffPtr++;
        }       
        highNibble = !highNibble;
        printf("%x",temp<<i); 
        
    }
    printf("\n\r");
    for(i = 0; i < BUFF_SIZE; ++i){
        printf("%x ",buff[i]);
    }
}



