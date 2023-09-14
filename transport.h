#include <stddef.h>

// *struct to describe element of list in graph
typedef struct ConnectionNode {
  char *vergeName;
  int routeDistance;
  struct ConnectionNode *nextVerge;
} ConnectionNode;

typedef struct ConnectionGraph {
  char **vergeList;
  ConnectionNode **connectionList;
} ConnectionGraph;

// *transport "class"
typedef struct Transport {
  int ID;
  int lineNumber;
  ConnectionNode connectionLine;
} Transport;

ConnectionGraph *CreateConnectionGraph(size_t initialSize);