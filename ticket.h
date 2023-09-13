#include "transport.h"

typedef struct TimeTicket {
  float price;
  float acessibleTime;
  char boughtHour[3];
  char boughtDate[5];
  char ID[11];
} TimeTicket;

typedef struct TargetTicket {
  float price;
  char boughtHour[3];
  int targetID;
  char boughtDate[5];
  char ID[11];
} TargetTicket;

TargetTicket CreateTargetTicket(int targetSerialNumber);

TimeTicket CreateTimeTicket(int targetSerialNumber, float duration);

char *GenerateTicketID();