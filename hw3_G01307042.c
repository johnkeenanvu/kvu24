#include <stdio.h>
#include <string.h>
#include <time.h>

int getInteger(); //takes user input from 1 to 1,000,000
//char *getDateAndTime();//returns date and time when called
void decimalToBinary(int decValue, char binString[]);
void decimalToHex(int decValue, char hexString[]);
void decimalToOct(int decValue, char octString[]);
char *getDateAndTime();

int main(){//************************** main
int num = 0;
char str[50], bin[50], hex[50], oct[50];
char fname[50];
FILE *filePtr;
char f,b;
time_t ti;



printf("Enter your name: "); //Name getting
fgets(str,sizeof(str),stdin);
printf("%s", str); //delete me


while(num!=-1){

num=-2;
while(num==-2){
    num= getInteger();
}
if (num==-1){
    break;
}
printf("\n");

printf("Decimal: %d\n", num);

printf("Binary: ");
decimalToBinary(num, bin); 

printf("Hexadecimal: ");
decimalToHex(num,hex);

printf("Octal: ");
decimalToOct(num, oct);
printf("\n");

while(f!='y'|| f!='n'){
    printf("\nSave to a file? (y/n): ");
    f=fgetc(stdin);
    b=fgetc(stdin);//newline grabber (pls email me for a better fix)
    if (f=='y'){
        ti = getDateAndTime();
        printf("Enter file name: ");
        fgets(fname ,sizeof(fname),stdin);
        filePtr = fopen(fname, "w");

        fprintf(filePtr,"%s\n", str);
        fprintf(filePtr,"Today's date: %s\n", ti);
        fprintf(filePtr,"Decimal: %d\n", num);
        fprintf(filePtr,"Binary: %s\n", bin);
        fprintf(filePtr,"Hexadecimal: %s\n", hex);
        fprintf(filePtr,"Octal: %s\n", oct);
        fclose(filePtr);
        printf("File saved.\n\n");
        break;
    }
    else if(f=='n'){
        break;
    }   
    else{
        printf("Error: illegal value\n");
        f=NULL;
    }
}
}



return 0;
}



int getInteger(){
char in[30];


printf("Enter an Integer [1 - 1000000] or type x to exit: ");
fgets(in, 30, stdin);
if (strchr(in,'x')!= NULL){  //exit condition
    printf("\nGoodbye!\n");
    return -1;
}
if (atoi(in) > 1000000 || atoi(in) <= 0){ 
    printf("Error: %d is out of range\n", atoi(in));
    return -2; //negative 1 was already used
}

return atoi(in); //if value is correct code defaults to here and returns input
} 

char *getDateAndTime(){ //like lecture
    time_t t;
    time(&t);
    return ctime(&t);
}

void decimalToBinary(int decValue, char binString[50]){
int q=decValue, i=1,j,x=0;
char h[50];

while (q != 0){
    h[i++]=q%2; //math
    q=q/2;
}

for (j = i-1; j>0; j--){ //array reverse
    printf("%d",h[j]);
    sprintf(&binString[x], "%d", h[j]);
    x++;
}
binString[x]=NULL;
printf("\n");
}

void decimalToHex(int decValue, char hexString[50]){

int q=decValue, i=1,j,x=0;
char h[50];

while (q !=0){
    if (q%16>=10){
        switch(q%16){ //if value is above 9 it is turn into a letter using switch case
            case 10:
            h[i++]='A';
            q=q/16; break;
            case 11:
            h[i++]='B';
            q=q/16; break;
            case 12:
            h[i++]='C';
            q=q/16; break;
            case 13:
            h[i++]='D';
            q=q/16; break;
            case 14:
            h[i++]='E';
            q=q/16; break;
            case 15:
            h[i++]='F';
            q=q/16; break;
        }
    }

    h[i++]=q%16 + 0x30; //statement for nums 9 or below, 0x30 to be readable
    q=q/16;
    
}

for (j = i-1; j>0; j--){ //array reverse 
    printf("%c",h[j]);
    sprintf(&hexString[x], "%c", h[j]);
    x++;
}

hexString[x]=NULL;
printf("\n");
}

void decimalToOct(int decValue, char octString[50]){
int q=decValue, i=1,j,x=0;
char h[50];

while (q != 0){
    h[i++]=q%8; //math but octal!
    q=q/8;
}

for (j = i-1; j>0; j--){ //array reversal
    printf("%d",h[j]);
    sprintf(&octString[x], "%d", h[j]);
    x++;
}
octString[x]=NULL;
printf("\n");
}