#include "ticket.h"

#include <stdlib.h>
#include <string.h>

#include "time.h"

char *GenerateTicketID() {
  static char id[11];
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < 11; i++) {
    int seed = rand() % 19;
    int alphabetSeed = rand() % sizeof(alphabet);
    if (seed <= 10)
      id[i] = seed + '0';
    else if (seed > 10)
      id[i] = alphabet[alphabetSeed];
  }
  return id;
}

char *GetHour() {
  static char actualTime[3];
  time_t now;
  struct tm *now_tm;
  int hour, minutes;

  now = time(NULL);
  now_tm = localtime(&now);
  hour = now_tm->tm_hour;
  minutes = now_tm->tm_min;
  actualTime[0] = hour;
  actualTime[1] = ':';
  actualTime[2] = minutes;
  return actualTime;
}

char *GetDate() {
  static char actualDate[5];
  time_t now;
  struct tm *now_tm;
  now = time(NULL);
  now_tm = localtime(&now);
  int day, month, year;

  day = now_tm->tm_mday;
  month = now_tm->tm_mon;
  year = now_tm->tm_year;
  enum TimeDial {
    fif,
  } times;
  actualDate[3] = '.';
  actualDate[4] = year;

  return actualDate;
}

TimeTicket CreateTimeTicket(int targetSerialNumber, float duration) {
  TimeTicket ticket;
  ticket.targetID = targetSerialNumber;
  strncpy(ticket.boughtHour, GetHour(), 3);
  strncpy(ticket.boughtHour, GetDate(), 5);
  strncpy(ticket.ID, GenerateTicketID(), 11);
  ticket.price = 1.5 + duration / 2;
  return ticket;
}
TargetTicket CreateTargetTicket(int targetSerialNumber) {
  TargetTicket ticket;
  ticket.targetID = targetSerialNumber;
  strncpy(ticket.boughtHour, GetHour(), 3);
  strncpy(ticket.boughtHour, GetDate(), 5);
  strncpy(ticket.ID, GenerateTicketID(), 11);
  ticket.price = 3;
  return ticket;
}