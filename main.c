#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ticket.h"
int main() {
  srand(time(NULL));
  printf("%s", GenerateTicketID());
}