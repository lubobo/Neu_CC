#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "../headers/getToken.h"
#include "../headers/gammarAnalysis.h"
#include "../headers/recursiveAnalysis.h"
#include "../headers/LLTranslating.h"
#include "../headers/reTranslating.h"
using namespace std;
node p;
int main(){
    fstream testFile;
    int i=0;
    testFile.open("test/hello.txt",ios::in);
    /**************************存储源码链表初始化**********************/
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
    /************************存储token序列链表初始化*******************/
    node tokenList=NULL;
    node listHead=(node)malloc(sizeof(tokenNode));
    listHead->data=0;
    listHead->next=NULL;
    tokenList=listHead;
    /**************************词法分析调用模块************************/
    node token_list=getToken(pHead->pNext,tokenList);
    /**************************语法分析调用模块************************/
    /***********LL(1)分析方法*********/
    //analysis(token_list);
    /***********递归下降自程序*********/
    p=token_list;
    //recursive();
    /**************************语义分析调用模块************************/
    /***********LL(1)分析方法*********/
    //LLTranslating();
    /***********递归下降自程序*********/
    reTranslating();
    /**************************Token序列*****************************/
    cout<<endl;
    cout<<"Token序列:"<<endl;
    while(token_list){
        cout<<token_list->tokens;
        token_list=token_list->next;
    }
    return 0;
}
