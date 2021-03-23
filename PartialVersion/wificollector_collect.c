#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "insert_list.h"
#define INFO_SIZE 5


/*******************************************************************************

  FileName: wificollector_collect.c

  Synopsis: This will look for the archive info_cell the user wants to collect,
            read it and store it inside an array of "WIFIS"

*******************************************************************************/

/*typedef struct{
  int cell;
  char address[18];
  char essid[10];
  char mode[10];
  int channel;
  char encryptionKey[4];
  char quality[6];
  double frequency;
  int signalLevel;
}WIFI;*/

/*We define the structure of the wifi with all atributes it have*/

int counter=0;
//extern WIFI *info_cell;
extern LIST myCellList;

void wificollector_collect(){
  char info[40]="../Docs/cells/info_cell_";
  char txt[6]=".txt";
  char cellNum[3];
  POINT *aux;

  printf("What cell do you want to collect? (1 - 21):\n");
  scanf("%s", cellNum);



  while ( (atoi(cellNum) < 1) || (atoi(cellNum)>21) ) {
    printf("Please enter a number between 1-21: \t");
    scanf("%s", cellNum);
  }

  strcat(info,cellNum);
  strcat(info, txt); /*We create the relative path to the archive we want to read*/

  /*Now we are going to start reading the file*/
  FILE *fp;
  fp = fopen(info,"r");
  char buffer [100];//This will be our buffer

  WIFI voidWifi={};//We create a void wifi so we do not have memory problems

  while (fgets(buffer, 100, fp)!=NULL) {

    WIFI wifiAux=voidWifi;
    wifiAux.cell=counter+1;
    int j = 0;
    char auxChan[20]="";
    char auxFreq[20]="";
    char auxSig[20]=""; //This 3 auxiliary arrays we will use it to help us converting char [] to numbers

    printf("\n");
    printf("\n");
    printf("The WIFI number %d has the following atributes\n", counter+1);
    printf("\n");
    printf("\n");

    fgets(buffer, 100, fp); //ADDRES
    //we add char by char
    for (int i = 9; i<strlen(buffer)-1; i++){
      wifiAux.address[j]=buffer[i];
      j++;
    }

    printf("YOUR WIFI ADDRESS: %s\n", wifiAux.address);
    printf("\n");

    fgets(buffer, 100 , fp); //ESSID
    j = 0;
    //we add char by char
    for (int i = 7; i<strlen(buffer)-2; i++){
      wifiAux.essid[j]=buffer[i];
      j++;
    }

    printf("\n");
    printf("YOUR WIFI ESSID: %s\n", wifiAux.essid);
    printf("\n");

    fgets(buffer, 100 , fp); //MODE
    j = 0;
    //we add char by char
    for (int i = 5; i<strlen(buffer)-1; i++){
      wifiAux.mode[j]=buffer[i];
      j++;
    }

    printf("\n");
    printf("YOUR WIFI MODE: %s\n", wifiAux.mode);
    printf("\n");

    fgets(buffer, 100, fp); //CHANNEL
    j = 0;
    for (int i=8;i<strlen(buffer)-1;i++){
      auxChan[j]=buffer[i];
      j++;
    }
    wifiAux.channel = atoi(auxChan);

    printf("\n");
    printf("YOUR WIFI CHANNEL: %d\n", wifiAux.channel);
    printf("\n");

    fgets(buffer, 100, fp); //ENCRYPTIONKEY
    j = 0;
    //we add char by char
    for (int i = 15; i < strlen(buffer)-1; i++) {
      wifiAux.encryptionKey[j]=buffer[i];
      j++;
    }

    printf("\n");
    printf("YOUR WIFI ENCRYPTION KEY: %s\n", wifiAux.encryptionKey);
    printf("\n");

    fgets(buffer, 100, fp); //QUALITY
    j = 0;
    //we add char by char
    for (int i = 8; i < strlen(buffer)-1; i++) {
      wifiAux.quality[j]=buffer[i];
      j++;
    }

    printf("\n");
    printf("YOUR WIFI QUALITY: %s\n", wifiAux.quality);
    printf("\n");

    fgets(buffer, 100, fp);//FREQUENCY
    j = 0;
    strtok(buffer, "G");
    for (int i = 10; i < strlen(buffer)-1; i++) {
      auxFreq[j]=buffer[i];
      j++;
    }
    char* pEnd;
    wifiAux.frequency=strtod(auxFreq,&pEnd);

    printf("\n");
    printf("YOUR WIFI FREQUENCY: %f Ghz\n", wifiAux.frequency);
    printf("\n");

    fgets(buffer, 100, fp); //SIGNAL
    j = 0;
    strtok (buffer, "d");
    for (int i = 13; i<strlen(buffer)-1; i++){
      auxSig[j]=buffer[i];
      j++;
    }
    wifiAux.signalLevel=atoi(auxSig);

    printf("\n");
    printf("YOUR WIFI SIGNAL LEVEL: %d dBm\n", wifiAux.signalLevel);
    printf("\n");
    counter++;
    if (myCellList.size == 0){
      insert_first_point(&myCellList, wifiAux);
    }else{
      aux=getLast(&myCellList);
      insert_next_point(&myCellList, aux, wifiAux);
    }
    /*//Deallocating more memory dimamicly
    if(counter%5==0){
      info_cell=(WIFI*)realloc(info_cell,((INFO_SIZE + counter)) * sizeof(WIFI));
  		printf(
  									"* * * Deallocating %d more positions of memory (total %d)\n",
  									INFO_SIZE, INFO_SIZE + counter);
    }*/
  }
  
  fclose (fp);
}
