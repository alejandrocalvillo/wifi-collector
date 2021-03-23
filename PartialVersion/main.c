#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wificollector_collect.h"
#include "wificollector_quit.h"
#include "show_main_menu.h"
#include "read_number_option.h"
#include "show_wifi_one_network.h"




/******************************************************************************

	FileName: main.c

	Synopsis: Manage all function of the program

*******************************************************************************/

extern int counter;

LIST myCellList; //This list is where all "info_cells" are stored


//WIFI *info_cell; //our dimamic arra to store all WIFIS

int main(int argc, char const *argv[]) {
	//info_cell=(WIFI*)calloc(INFO_SIZE, sizeof(WIFI));//Allocating memory
	int salir = 0;
	int opcion;
	

	set_null_list(&myCellList);

	while(salir == 0)
		{
			show_main_menu();

			opcion = read_number_option();

			if (opcion >= 1 && opcion <= 8)
			{
			    switch(opcion)

                            {
				case 1:
				    salir = wifiCollectorQuit();
				    break;
				case 2:
						printf("\n");
						printf("you chose option two.\n");
						printf("\n");
                        char c = 'Y';

						wificollector_collect();
						//insert_first_point(&myCellList, info_cell);
						while ( c == 'Y' ) {
							printf("\nDo you want to add another cell?[Y/N]:\t");
							scanf("%s",&c );
							while ( (c != 'Y') && (c != 'N') ) {
								printf("please enter Y/N: \t");
								scanf("%s", &c);
							}
							if (c == 'Y'){
							//aux=getLast(&myCellList);
							wificollector_collect();
							//insert_next_point(&myCellList, aux, info_cell);
							}
						}
            break;
        case 3:
							printf("\n");
							printf("you chose option three.\n");
							printf("\n");
							show_wifi_one_network();

              break;
        case 4:
							printf("\n");
              printf("you chose option four.\n");
							printf("\n");
							break;
        case 5:
							printf("\n");
            	printf("you chose option five.\n");
							printf("\n");
							break;
        case 6:
							printf("\n");
            	printf("you chose option six.\n");
							printf("\n");
							//wifiCollector_sort(info_cell);
							//ListTravel(myCellList);
							wifiCollector_sortList(myCellList);
              break;
        case 7:
							printf("\n");
              printf("you chose option seven.\n");
							printf("\n");
							break;
        case 8:
							printf("\n");
              printf("you chose option eight.\n");
							printf("\n");
							break;
                }
			}
			else
			{
			    if (opcion == 99) {
			       salir = 1;
			    } else {
				printf("\n");
				printf("option does not exist, please enter between 1-8 numbers\n");
				printf("\n");
			    }

			}
    }
		printf("\n\n Bye! \n\n");
		return 0;
}
