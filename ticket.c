#include "ticket.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *GenerateTicketID() {
  char *id = (char *)(malloc(11 * sizeof(char)));
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // *Generator losowego id
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

char *GetActualTime() {
  // *time.h - dokumentation
  time_t now;
  struct tm *now_tm;
  int hour, minutes;
  char *actualTime = (char *)malloc(6 * sizeof(char));

  if (actualTime == NULL) {
    return NULL;
  }

  now = time(NULL);
  now_tm = localtime(&now);
  hour = now_tm->tm_hour;
  minutes = now_tm->tm_min;

  sprintf(actualTime, "%02d:%02d", hour, minutes);

  return actualTime;
}

char *GetActualDate() {
  int day, month, year;
  time_t now;
  struct tm *now_tm;
  char *actualDate = (char *)malloc(11 * sizeof(char));

  if (actualDate == NULL) {
    return NULL;
  }

  now = time(NULL);
  now_tm = localtime(&now);
  day = now_tm->tm_mday;
  month = now_tm->tm_mon + 1;
  year = now_tm->tm_year + 1900;

  sprintf(actualDate, "%02d.%02d.%04d", day, month, year);

  return actualDate;
}

//  *TODO Zrobić obsługę dodania dnia na następny po przekroczeniu godziny 00:00
// Calculating time of ticket
char *CalculateAccessTime(float duration) {
  char *actualTime = (char *)malloc(6 * sizeof(char));
  time_t now;
  struct tm *now_tm;
  int hour, minutes;

  if (actualTime == NULL) {
    return NULL;
  }

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

  sprintf(actualTime, "%02d:%02d", hour, minutes);

  return actualTime;
}

TimeTicket CreateTimeTicket(float duration) {
  TimeTicket ticket;
  strncpy(ticket.acessibleTime, CalculateAccessTime(duration), 11);
  strncpy(ticket.boughtHour, GetActualTime(), 6);
  strncpy(ticket.boughtDate, GetActualDate(), 11);
  strncpy(ticket.ID, GenerateTicketID(), 11);
  ticket.price = 1.5 + duration / 15;
  return ticket;
}

TargetTicket CreateTargetTicket(int targetSerialNumber) {
  TargetTicket ticket;
  ticket.targetID = targetSerialNumber;
  strncpy(ticket.boughtHour, GetActualTime(), 6);
  strncpy(ticket.boughtDate, GetActualDate(), 11);
  strncpy(ticket.ID, GenerateTicketID(), 11);
  ticket.price = 3;
  return ticket;
}