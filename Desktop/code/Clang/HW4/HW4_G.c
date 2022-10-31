#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct user{ //entry structure has a name and an ip 
    char name[50];
    char ip[70];
}entry;

void Generate_Alias_List();             //prints alias list to a textfile "222_Alias_List.txt"

int Read_Data_File(entry trys[]);       //reads in names and Ips from "CS222_Inet.txt" and puts them into a list of entrys called "trys"

char *getDateAndTime();                 // gets date in time like lecture

void Bubble_sort(entry trys[], int c,char order);           // sorts trys by alphabetical order ascending or descending. Takes in array of entrys to sort, length of that array, and 'a' or 'd' to sort ascending or descending



void main(){
    Generate_Alias_List();      //bulk of the work is in generate alias list
    printf("Done!\n");
}


void Generate_Alias_List(){
    
    char name[50];
    char aod;

    printf("Please enter your name: ");     //takes name for file later
    fgets(name, sizeof(name), stdin);
    
    entry trys[100];
    int len = Read_Data_File(trys);

    while (1==1){           //loops until 'a' or 'd' is entered
        printf("Ascending or Descending order? (Please enter a or d)\n");
        aod=fgetc(stdin);

        if (aod=='a' || aod=='d'){
            break;}

        printf("Error: Illegal value.\n");
        fgetc(stdin);   //catches extra char
    }

    Bubble_sort(trys,len,aod);      //sorts trys 
    
    
    FILE *fi= fopen("222_Alias_List.txt","w");      //opens "222_Alias_List.txt" to put name date and sorted list

    fprintf(fi, "%s%s", name, getDateAndTime());
    fprintf(fi, "CS 222 Network Alias Listing\n");

    for (int z=0; z<len; z++){
        fprintf(fi,"%s %s\n",trys[z].name,trys[z].ip);
    }
    fclose(fi);


}


int Read_Data_File(entry trys[]){

    FILE *f = fopen("CS222_Inet.txt","r");      //opens file to read
    
    char line[100];

    int b = 0;
    int c=0;

    while (b!=-1){      //iterates through "CS222_Inet.txt" line by seperating ips and names

        char *nm;
        fgets(line,100,f);

        if (strcmp(line,"0.0.0.0 NONE\n")==0){      //stops reading after "terminator string" 
            break;}    
        for (int i=0; i<strlen(line); i++){     //loops through a line and looks for a space to separate name from ip
            if(line[i]==' '){
                line[i]='\0';       //turns space into terminator char allowing the line to be turned into two strings
                
                nm=&line[i+1];       //name line begins right after the terminator char

                strcpy(trys[c].ip,line);        //assigning name and ip to entry struct at c
                strcpy(trys[c].name,nm);

                trys[c].name[strcspn(trys[c].name, "\n")]='\0';     //gets rid of that pesky newline >:D
                c++;        //iterates through trys to fill the array
            }
        }
    }
    fclose(f);
    return(c); //returns length of array trys
}

char *getDateAndTime(){     //like lecture
    time_t t;
    time(&t);
    return ctime(&t);
}

void Bubble_sort(entry trys[], int c, char order){
    entry swap;
    for (int i = 0; i<c; i++){      //loops through trys doing a bubble sort alphabetically ascending or descending
        for(int x = 0; x<(c-i-1); x++){

            if (order=='a'){    //ascending

                if(strcmp(trys[x].name,trys[x+1].name)>0){
                    swap = trys[x];
                    trys[x] = trys[x+1];
                    trys[x+1] = swap;}
            }

            else if (order=='d'){   //descending

                if(strcmp(trys[x].name,trys[x+1].name)<0){
                    swap = trys[x];
                    trys[x] = trys[x+1];
                    trys[x+1] = swap;}
            }
        }
    }
}
