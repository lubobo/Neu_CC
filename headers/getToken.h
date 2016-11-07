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
    struct Node *pPre;
}Node, *pNode;
void getToken(Node *p_node);
void scaner_key(int state);
void scaner_limit(int state);
#endif
