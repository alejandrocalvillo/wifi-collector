#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*******************************************************************************

	FileName: show_main_menu.c

	Synopsis: It will print on the screen the menu for the user to choose

*******************************************************************************/
void show_main_menu(){
	printf("\n");
	printf("=========================================\n");
	printf("   [2020] SUCEM S.L. Wifi Collector      \n");
	printf("=========================================\n");
	printf("[1] wificollector_quit\n");
	printf("[2] wificollector_collect\n");
	printf("[3] wificollector_show_data_one_network\n");
	printf("[4] wificollector_select_best\n");
	printf("[5] wificollector_delete_net\n");
	printf("[6] wificollector_sort\n");
	printf("[7] wificollector_export\n");
	printf("[8] wificollector_import\n");
	printf("option:\t");
  fflush(stdout);
}
