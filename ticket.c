#include "ticket.h"

#include <stdio.h>
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
  char *actualTime = (char *)malloc(6 * sizeof(char));
  if (actualTime == NULL) {
    return NULL;
  }

  time_t now;
  struct tm *now_tm;
  int hour, minutes;

  now = time(NULL);
  now_tm = localtime(&now);
  hour = now_tm->tm_hour;
  minutes = now_tm->tm_min;

  sprintf(actualTime, "%02d:%02d", hour, minutes);

  return actualTime;
}

char *GetDate() {
  char *actualDate = (char *)malloc(11 * sizeof(char));
  if (actualDate == NULL) {
    return NULL;
  }

  time_t now;
  struct tm *now_tm;
  now = time(NULL);
  now_tm = localtime(&now);
  int day, month, year;

  day = now_tm->tm_mday;
  month = now_tm->tm_mon + 1;
  year = now_tm->tm_year + 1900;

  sprintf(actualDate, "%02d.%02d.%04d", day, month, year);

  return actualDate;
}

//  *TODO Zrobić obsługę dodania dnia na następny po przekroczeniu godziny 00:00

char *CalculateAcessTime(float duration) {
  char *actualTime = (char *)malloc(6 * sizeof(char));
  if (actualTime == NULL) {
    return NULL;
  }

  time_t now;
  struct tm *now_tm;
  int hour, minutes;

  now = time(NULL);
  now_tm = localtime(&now);
  hour = now_tm->tm_hour;
  minutes = now_tm->tm_min + duration;

  while (minutes > 60) {
    hour++;
    minutes -= 60;
  }

  while (hour >= 24) {
    hour -= 24;
  }

  // Convert integers to character representation and null-terminate the
  // string
  sprintf(actualTime, "%02d:%02d", hour, minutes);

  return actualTime;
}

TimeTicket CreateTimeTicket(int targetSerialNumber, float duration) {
  TimeTicket ticket;
  strncpy(ticket.acessibleTime, CalculateAcessTime(duration), 11);
  strncpy(ticket.boughtHour, GetHour(), 6);
  strncpy(ticket.boughtDate, GetDate(), 11);
  strncpy(ticket.ID, GenerateTicketID(), 11);
  ticket.price = 1.5 + duration / 15;
  return ticket;
}
TargetTicket CreateTargetTicket(int targetSerialNumber) {
  TargetTicket ticket;
  ticket.targetID = targetSerialNumber;
  strncpy(ticket.boughtHour, GetHour(), 6);
  strncpy(ticket.boughtDate, GetDate(), 11);
  strncpy(ticket.ID, GenerateTicketID(), 11);
  ticket.price = 3;
  return ticket;
}