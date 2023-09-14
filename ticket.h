typedef struct TimeTicket {
  float price;
  char acessibleTime[11];
  char boughtHour[6];
  char boughtDate[11];
  char ID[11];
} TimeTicket;

typedef struct TargetTicket {
  float price;
  char boughtHour[6];
  int targetID;
  char boughtDate[11];
  char ID[11];
} TargetTicket;

TargetTicket CreateTargetTicket(int targetSerialNumber);

TimeTicket CreateTimeTicket(float duration);
