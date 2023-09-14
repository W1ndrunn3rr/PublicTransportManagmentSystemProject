#include "transport.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *Creating one verge on line
void GenerateVerge(ConnectionGraph **graph, char *vergeName, int *arraySize) {
  char *newVergeName = (char *)malloc(strlen(vergeName) + 1);  // ! +1 for NULL
  if (newVergeName == NULL) {
    perror("ERROR - VERGE NOT GENERATED");
    exit(EXIT_FAILURE);
  }
  strcpy(newVergeName, vergeName);
  (*graph)->vergeList[(*arraySize)++] = newVergeName;
}

// *Linked List to make connection with verges
void GenerateConnection(ConnectionNode **headNode, char *vergeName,
                        int distance) {
  ConnectionNode *routeNode = (ConnectionNode *)malloc(sizeof(ConnectionNode));

  if (routeNode == NULL) {
    perror("ERROR - CONNECTION NOT GENERATED");
    exit(EXIT_FAILURE);
  }

  routeNode->vergeName = strdup(vergeName);
  routeNode->routeDistance = distance;
  routeNode->nextVerge = NULL;

  if (*headNode == NULL) {
    *headNode = routeNode;
    return;
  }

  ConnectionNode *tmp = *headNode;
  while (tmp->nextVerge != NULL) {
    tmp = tmp->nextVerge;
  }
  tmp->nextVerge = routeNode;
}

// * Generating map for connection - graph with linked list
ConnectionGraph *CreateConnectionGraph(size_t initialSize) {
  int vergesNumber = 0;  // helps for allocation in array

  ConnectionGraph *graph = (ConnectionGraph *)malloc(sizeof(ConnectionGraph));
  if (graph == NULL) {
    perror("ERROR - GRAPH NOT GENERATED");
    exit(EXIT_FAILURE);
  }

  graph->vergeList = (char **)malloc(initialSize * sizeof(char *));

  if (graph->vergeList == NULL) {
    perror("ERROR - VERGE LIST NOR GENERATED");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < initialSize; i++) {
    graph->vergeList[i] = NULL;
  }

  graph->connectionList =
      (ConnectionNode **)malloc(2 * sizeof(ConnectionNode *));
  if (graph->connectionList == NULL) {
    perror("ERROR CONNECTION LIST NOT GENERATED");
    exit(EXIT_FAILURE);
  }

  // ? This is for testing part - in future need an update to read from CSV
  // ? or JSON to read lines from file ( for now i do it manually to test
  // ? funcionality)

  ConnectionNode *sixteenLine = NULL;
  GenerateConnection(&sixteenLine, "Tarnogaj", 0);
  GenerateConnection(&sixteenLine, "Plac Grunwaldzki", 2);
  GenerateConnection(&sixteenLine, "ZOO", 1);

  graph->connectionList[0] = sixteenLine;

  ConnectionNode *nineteenLine = NULL;
  GenerateConnection(&nineteenLine, "Górnicza", 0);
  GenerateConnection(&nineteenLine, "Dubois", 2);
  GenerateConnection(&nineteenLine, "ZOO", 1);

  // ?

  graph->connectionList[1] = nineteenLine;

  return graph;
}
