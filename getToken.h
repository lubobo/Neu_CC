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
    struct tokenNode *next;
}tokenNode, *node;
void getToken(Node *p_node);
int scaner_key(int state);
int scaner_limit(int state);
#endif
