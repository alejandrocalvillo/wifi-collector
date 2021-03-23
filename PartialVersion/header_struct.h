#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int cell;
  char address[18];
  char essid[10];
  char mode[10];
  int channel;
  char encryptionKey[4];
  char quality[6];
  double frequency;
  int signalLevel;
}WIFI;
