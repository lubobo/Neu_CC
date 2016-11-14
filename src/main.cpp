#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "../headers/getToken.h"
#include "../headers/gammarAnalysis.h"
using namespace std;
int main(){
    fstream testFile;
    int i=0;
    testFile.open("test/hello.txt",ios::in);
    /***************************存储源码链表初始化****************************/
    pNode pTail=NULL,pNew=NULL;
    pNode pHead=(pNode)malloc(sizeof(Node));
    pHead->data=0;
    pHead->pNext=NULL;
    pTail=pHead;

    while(!testFile.eof()){
        pNode p_new=(pNode)malloc(sizeof(Node));
        p_new->data=testFile.get();
        p_new->pNext=NULL;
        pTail->pNext=p_new;
        pTail=p_new;
    }
    testFile.close();
    /**************************存储token序列链表初始化************************/
    node tokenList=NULL;
    node listHead=(node)malloc(sizeof(tokenNode));
    listHead->data=0;
    listHead->next=NULL;
    tokenList=listHead;
    /**************************词法分析调用模块************************/
    node token_list=getToken(pHead->pNext,tokenList);

    /*while(token_list){
        cout<<token_list->data<<endl;
        token_list=token_list->next;
    }
    /**************************语法分析调用模块************************/
    /*while(token_list){
        token_list=token_list->next;
    }
    cout<<token_list<<endl;*/
    analysis(token_list);
    return 0;
}
