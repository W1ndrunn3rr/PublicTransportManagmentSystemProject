#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ticket.h"
#include "transport.h"
int main() {
  ConnectionGraph *conGraph = CreateConnectionGraph(5);
  TimeTicket T = CreateTimeTicket(90);
  TargetTicket R;
  // printf("%s", T.acessibleTime);
  ConnectionNode *tmp = conGraph->connectionList[1];
  while (tmp != NULL) {
    if (tmp->nextVerge == NULL) {
      printf("%s", tmp->vergeName);
      break;
    }
    printf("%s->", tmp->vergeName);
    tmp = tmp->nextVerge;
  }
  return 0;
}
