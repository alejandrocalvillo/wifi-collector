#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "header_struct.h"

/*
****************************************************************************

  FileName: insert_list.c

  Synopsis: Making all needed structures and functions to making a list

****************************************************************************
*/
typedef struct NODE{
  WIFI myCell;
  struct NODE *next;
}POINT; //this is for making all the points of the list (POINT = NODE)

typedef struct {
  POINT *first;
  POINT *last;
  int size;
}LIST; //this is for making the List

void set_null_list(LIST *ourList){
  ourList->first=NULL;
  ourList->last=NULL;
  ourList->size=0;
}
POINT *getFirst(LIST *ourList){
  return ourList->first;
}

POINT *getNext(POINT *current){
  return current->next;
}
POINT *getLast(LIST *ourList){
  return ourList->last;
}

int insert_first_point(LIST *ourList, WIFI Cell){
  POINT *newPoint;
  if (((newPoint=(POINT*)malloc(sizeof(POINT)))==NULL)){
    return -1;
  }/*
  if (((newPoint->myCell)=(WIFI*)malloc(50*sizeof(WIFI)))){
    return -1;
  }*/
  newPoint->myCell=Cell;
  newPoint->next = NULL;
  ourList->first = newPoint;
  ourList->last = newPoint;
  ourList->size++;
  return 0;
}

int insert_next_point(LIST *ourList, POINT *current, WIFI cell){
  POINT *newPoint;
  if ((newPoint=(POINT*)malloc(sizeof(POINT)))==NULL){
    return -1;
  }/*
  if (((newPoint->myCell)=(WIFI*)malloc(50*sizeof(WIFI)))){
    return -1;
  }*/
  newPoint->myCell=cell;
  newPoint->next = NULL;
  if (ourList->size == 1){
    ourList->first->next=newPoint;
    ourList->last = newPoint;
  }else{
    current->next=newPoint;
    ourList->last = newPoint;
  }
  ourList->size++;
  return 0;
}
