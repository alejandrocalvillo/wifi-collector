#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "wificollector_sort.h"



/******************************************************************************************************

  FileName: show_wifi_one_network.c

  Synopsis: The goal of this function is to print the first WIFI that mach with the ESSID scanned

*******************************************************************************************************/

extern int counter;
extern LIST myCellList;


void show_wifi_one_network(){
  int flag=-1;
  int n = counter;
  char aux_essid[9];

  printf("\n");
	printf("Please enter a valid ESSID to search: ");
	printf("\n");
  scanf("%s", aux_essid);
	printf("\n");

  POINT *newPoint =getFirst(&myCellList);

  for (int i = 0; i<myCellList.size; i++){
    if (!strcmp(newPoint->myCell.essid, aux_essid)){
      flag=1; //When this condition is satisfied the loop will stop
      break;
    }else if(strcmp(newPoint->myCell.essid, aux_essid)){
      newPoint=getNext(newPoint);
    }
  };


  //Print the array founded
  if (flag != -1){
    printf("\n");printf("|");pNChar('=',61);printf("   OUTPUT  "); pNChar('=',60);printf("|");
    printDynamicArrayColumnHeader();
    printDynamicArrayColumnRow(newPoint);
    printDynamicDivision();
  }else{
    printf("Wifi %s not found.\n", aux_essid);
  }





}
