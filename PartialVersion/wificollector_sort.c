#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wificollector_collect.h"

/******************************************************************************************************

  FileName: wificollector_sort.c

  Synopsis: The goal of this function is to sort the dinamic acording to the calculated signal quality

*******************************************************************************************************/

/******************************************************************************************************
  Function: printDynamicArray
  Synopsis: Prints access point data in a single line
*******************************************************************************************************/
extern int counter;
extern LIST myCellList;
void printDynamicArray(WIFI pWifiAux)
{
  printf("\n");printf("|");
  printf("ADDRESS: %s\n", pWifiAux.address);printf("|");
  printf("ESSID: %s\n", pWifiAux.essid);printf("|");
  printf("MODE: %s\n", pWifiAux.mode);printf("|");
  printf("CHANNEL: %d\n", pWifiAux.channel);printf("|");
  printf("ENCRYPTION KEY: %s\n", pWifiAux.encryptionKey);printf("|");
  printf("QUALITY: %s\n", pWifiAux.quality);printf("|");
  printf("FREQUENCY: %f Ghz\n", pWifiAux.frequency);printf("|");
  printf("SIGNAL LEVEL: %d dBm\n", pWifiAux.signalLevel);printf("|");
  printf("\n");
}

/******************************************************************************************************
  Function: pNChar
  Synopsis: Prints pNTimes times pChar character
*******************************************************************************************************/
void pNChar(char pChar, int pNTimes)
{
  int i;
  for (i=1; i<=pNTimes; i++){
      printf("%c", pChar);
  }
}
/******************************************************************************************************
  Function: printDynamicDivision
  Synopsis: Prints line header cells table
*******************************************************************************************************/
void printDynamicDivision(){
  printf("|");pNChar('-',5);printf("|");
  pNChar('-',17);printf("|");
  pNChar('-',28);printf("|");
  pNChar('-',15);printf("|");
  pNChar('-',10);printf("|");
  pNChar('-',15);printf("|");
  pNChar('-',10);printf("|");
  pNChar('-',12);printf("|");
  pNChar('-',12);printf("|");
}

/******************************************************************************************************
  Function: printDynamicArrayColumnHeader
  Synopsis: Prints literals header cells table
*******************************************************************************************************/
void printDynamicArrayColumnHeader()
{
  printf("\n");
  printf("|");printf("%-5s" , "CELL");printf("|");
  printf("%-17s", "ADDRESS");printf("|");
  printf("%-28s", "ESSID");printf("|");
  printf("%-15s", "MODE");printf("|");
  printf("%-10s", "CHANNEL");printf("|");
  printf("%-15s", "ENCRYPTION KEY");printf("|");
  printf("%-10s", "QUALITY");printf("|");
  printf("%-12s", "FREQUENCY");printf("|");
  printf("%-12s", "SIGNAL LEVEL");printf("|");
  printf("\n");
  printDynamicDivision();
  printf("\n");
}
/******************************************************************************************************
  Function: printDynamicArrayColumnRow
  Synopsis: Prints data line cells table
*******************************************************************************************************/
void printDynamicArrayColumnRow(POINT *current)
{
  printf("|");printf(" %-4d", current->myCell.cell);printf("|");
  printf("%-17s", current->myCell.address);  printf("|");
  printf("%-28s", current->myCell.essid);  printf("|");
  printf("%-15s", current->myCell.mode);  printf("|");
  printf("%-10d", current->myCell.channel);  printf("|");
  printf("%-15s", current->myCell.encryptionKey);  printf("|");
  printf("%-10s", current->myCell.quality);  printf("|");
  printf("%-12f", current->myCell.frequency);  printf("|");
  printf("%-12d", current->myCell.signalLevel);  printf("|");
  printf("\n");
}
/******************************************************************************************************
  Function: ListTravel
  Synopsis: Prints all the contents of the list 
*******************************************************************************************************/
void ListTravel(LIST myCellList){
  
POINT *auxPoint=getFirst(&myCellList);
printDynamicArrayColumnHeader();
 for (int i = 0; i<myCellList.size; i++){
  
    
    printDynamicArrayColumnRow(auxPoint);
    auxPoint=getNext(auxPoint);

  }
printDynamicDivision(); 

}
/******************************************************************************************************
  Function: wifiCollector_sortList
  Synopsis: Sorts the cells that have been collected and sorts them
*******************************************************************************************************/
void wifiCollector_sortList(LIST myCellList){
   WIFI wifiAux = {};
double signal_quality_j1;
double signal_quality_j;
int first_value, second_value;
char quality_pointerA[2] = "";
char quality_pointerB[2] = "";


printf("\n");printf("|");pNChar('=',61);printf("   INPUT  "); pNChar('=',61);printf("|");
ListTravel(myCellList);
printf("\n");

POINT *currentPoint, *nextPoint;
  currentPoint=getFirst(&myCellList);
    while(getNext(currentPoint)!=NULL){
      nextPoint=getNext(currentPoint);
        while(nextPoint!=NULL){

           //we calculate the signal quality of current element  
          
          quality_pointerA[0] = currentPoint->myCell.quality[0];
          quality_pointerA[1] = '\0';
          quality_pointerB[0] = currentPoint->myCell.quality[1];
          quality_pointerB[1] = '\0';
          first_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
          quality_pointerA[0] = currentPoint->myCell.quality[3];
          quality_pointerB[0] = currentPoint->myCell.quality[4];
          second_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
          if (second_value == 0){
                    signal_quality_j = 0;
          }
          else{
                    signal_quality_j = (double)first_value / (double)second_value;
          }
          //we calculate the signal quality of the next element
          quality_pointerA[0] = nextPoint->myCell.quality[0];
          quality_pointerA[1] = '\0';
          quality_pointerB[0] = nextPoint->myCell.quality[1];
          quality_pointerB[1] = '\0';
          first_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
          quality_pointerA[0] = nextPoint->myCell.quality[3];
          quality_pointerB[0] = nextPoint->myCell.quality[4];
          second_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
          if (second_value == 0){
                    signal_quality_j1 = 0;
          }
          else{
                    signal_quality_j1 = (double)first_value / (double)second_value;
          }


          if (signal_quality_j < signal_quality_j1)
            {
              wifiAux = nextPoint->myCell;
              nextPoint->myCell = currentPoint->myCell;
              currentPoint->myCell = wifiAux;
            }
          nextPoint = getNext(nextPoint);


        }
          currentPoint=getNext(currentPoint);
          nextPoint=getNext(currentPoint);
    }

printf("\n");
printf("\n");printf("|");pNChar('=',61);printf("   OUTPUT  "); pNChar('=',60);printf("|");
ListTravel(myCellList);
printf("\n");
}

/******************************************************************************************************
  Function: wifiCollector_sort
  Synopsis: Sorts WIFI dynamic array info_cell
*******************************************************************************************************/
/*void wifiCollector_sort(WIFI *info_cell)
{
  WIFI wifiAux = {};
  int i, j, k;
  double signal_quality_j1;
  double signal_quality_j;
  int first_value, second_value;
  char quality_pointerA[2] = "";
  char quality_pointerB[2] = "";
  printf("\n**********************    Sorting %d access points   ************************\n", counter);
    printing input cells table to sort
  printf("\n");printf("|");pNChar('=',61);printf("   INPUT   "); pNChar('=',60);printf("|");
  printDynamicArrayColumnHeader();
  for (i = 0; i < counter; i++)
  {
    wifiAux = info_cell[i];
    printDynamicArrayColumnRow(wifiAux);
  }
  printDynamicDivision();
  printf("\n");
  External loop i : for each element in array
  for (i = 0; i < counter - 1; i++)
  {

    /*Internal loop j : reamining elements not sorted
    for (j = 0; j < counter -i -1; j++)
    {

      //we calculate the signal quality of element j
      quality_pointerA[0] = info_cell[j].quality[0];
      quality_pointerA[1] = '\0';
      quality_pointerB[0] = info_cell[j].quality[1];
      quality_pointerB[1] = '\0';
      first_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
      quality_pointerA[0] = info_cell[j].quality[3];
      quality_pointerB[0] = info_cell[j].quality[4];
      second_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
      if (second_value == 0){
                signal_quality_j = 0;
      }
      else{
                signal_quality_j = (double)first_value / (double)second_value;
      }
      //we calculate the signal quality of element j + 1
      quality_pointerA[0] = info_cell[j+1].quality[0];
      quality_pointerA[1] = '\0';
      quality_pointerB[0] = info_cell[j+1].quality[1];
      quality_pointerB[1] = '\0';
      first_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
      quality_pointerA[0] = info_cell[j+1].quality[3];
      quality_pointerB[0] = info_cell[j+1].quality[4];
      second_value = (atoi(quality_pointerA) * 10) + atoi(quality_pointerB);
      if (second_value == 0){
                signal_quality_j1 = 0;
      }
      else{
                signal_quality_j1 = (double)first_value / (double)second_value;
      }

       performing swap if its needed to sort j and j+1 elements
      if (signal_quality_j1 > signal_quality_j)
      {
        wifiAux = info_cell[j];
        printf("\nSwaping subiendo (j+1)=%d : %s con (j)=%d: %s", j+1, info_cell[j+1].essid, j, info_cell[j].essid);
        printf("\nEn (j)=%d : había %s", j, info_cell[j].essid);
        info_cell[j] = info_cell[j+1];
        printf("\nDespués (j)=%d : hay %s", j, info_cell[j].essid);
        info_cell[j+1] = wifiAux;
      }
    }
  }
  printing output sorted cells table
  printf("\n");
  printf("\n");printf("|");pNChar('=',61);printf("   OUTPUT  "); pNChar('=',60);printf("|");
  printDynamicArrayColumnHeader();
  for (i = 0; i < counter; i++)
  {
    wifiAux = info_cell[i];
    printDynamicArrayColumnRow(wifiAux);
  }
  printDynamicDivision();
  printf("\n");
}*/
