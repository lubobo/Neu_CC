#ifndef GETTOKEN_H
#define GETTOKEN_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;
typedef struct Node{
    char data;
    struct Node *pNext;
}Node, *pNode;
typedef struct tokenNode{
    int data;
    char tokens;
    struct tokenNode *next;
}tokenNode, *node;
tokenNode * getToken(Node *p_node,node tokenNode);
int scaner_key(int state);
int scaner_limit(int state);
#endif
