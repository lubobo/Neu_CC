#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "getToken.h"
using namespace std;
int main(){
    fstream testFile;
    int i=0;
    testFile.open("test.txt",ios::in);
    pNode pTail=NULL,pNew=NULL;
    pNode pHead=(pNode)malloc(sizeof(Node));
    pHead->data=0;
    pHead->pNext=NULL;
    pHead->pPre=NULL;
    pTail=pHead;
    while(!testFile.eof()){
        pNode p_new=(pNode)malloc(sizeof(Node));
        p_new->data=testFile.get();
        p_new->pNext=NULL;
        p_new->pPre=pTail;
        pTail->pNext=p_new;
        pTail=p_new;
    }
    testFile.close();
    getToken(pHead->pNext);
    return 0;
}
