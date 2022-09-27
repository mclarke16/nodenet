#ifndef _node_h
#define _node_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int nodeID;
    int conCount;
    int *conList;
} Node;

typedef struct simLog
{
    unsigned int start_time;
    char *msg[512];
    unsigned int msg_id;
    unsigned int start_node;
    unsigned int end_node;
    int *simList;
} Log;


void buildNode(Node *nodeList, char buffer[], FILE *fp);
void build_sim(Log *simList, char buffer[], FILE *sim);

#endif
