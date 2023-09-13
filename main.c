#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ticket.h"
int main() {
  TimeTicket T = CreateTimeTicket(193, 90);
  TargetTicket R;
  printf("%s", T.acessibleTime);
}