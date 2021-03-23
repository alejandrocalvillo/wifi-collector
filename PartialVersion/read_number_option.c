#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*********************************************************************************

	FileName: read_number_option.c

	Synopsis: The goal od this function is to read the user entry for choosing the option he/she
				 wants to activate. It makes you choose between 1 and 8.

**********************************************************************************/
int read_number_option(){
	int flag = 0;
	int x;
  while ((flag = scanf("%d", &x))!= EOF && (flag == 1)) {
    	if (x < 1 || x > 8)
    		{
		        printf("please enter a number between 1-8: \t");
    	 	}
      else
      {return x;}
    fflush(stdin);
    }
    return 99;
}
