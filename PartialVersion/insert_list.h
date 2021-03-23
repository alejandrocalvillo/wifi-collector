#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "header_struct.h"

typedef struct NODE{
  WIFI myCell;
  struct NODE *next;
}POINT; //this is for making all the points of the list (POINT = NODE)

typedef struct {
  POINT *first;
  POINT *last;
  int size;
}LIST; //this is for making the List

void set_null_list(LIST *ourList);
POINT *getFirst(LIST *ourList);
POINT *getNext(POINT *current);
POINT *getLast(LIST *ourList);
int insert_first_point(LIST *ourList, WIFI cell);
int insert_next_point(LIST *ourList, POINT *current, WIFI cell);
