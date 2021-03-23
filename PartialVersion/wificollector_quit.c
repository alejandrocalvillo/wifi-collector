#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******************************************************************************

  FileName: wificollector_quit.c

  Synopsis: The goal of this function is to shut down the program
  
******************************************************************************/
int wifiCollectorQuit(){
  int  salirQuit = 0;
  char answer = 'F';
	printf("\nAre you sure you want to exit?[Y/N]:\t");

  scanf("%s", &answer);
  fflush(stdin);
  while ( (answer!='Y') && (answer!='N') )
		{
		    printf("please enter Y/N: \t");
		    scanf("%s", &answer);
	 	}
  fflush(stdin);
	if ( answer=='Y' )
	{
		salirQuit = 1;
	} else {
		salirQuit = 0;
	}
    return salirQuit;
}
