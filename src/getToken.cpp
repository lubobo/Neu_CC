#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;
char *key[32]={
    "auto","short","int","long","float","double","char","struct","union","enum","typedef","const","unsigned",
    "signed","extern","register","static","volatile","void","if","else","switch","case","for","do","while",
    "goto","continue","break","default","sizeof","return"
};                                                                                            //定义语言关键字集合
char *limit[13]={">=","<=","==","=",">","<","+","++","+=","--","-=","->","."};               //定义界符集合
char token[15];                                                                             //储存令牌字符
int  sum;

typedef struct Node{
    char data;
    struct Node *pNext;
}Node, *pNode;

typedef struct tokenNode{
    int data;
    struct tokenNode *next;
}tokenNode, *node;

/********************************识别token序列模块********************************/
void getToken(Node *p_node){
    /***************链表初始化*****************/
    node tokenList=NULL;
    node listHead=(node)malloc(sizeof(tokenNode));
    listHead->data=0;
    listHead->next=NULL;
    tokenList=listHead;
    node insertNode=tokenList;
    /**************函数声明******************/
    int scaner_key(int state);
    int scaner_limit(int state);
    void insertList(tokenNode *list_node,node p,int x);
    for(int j=0;j<10;j++){
        token[j]=NULL;
    }
    int n=0;
    while(p_node!=NULL){
        int m=0;
    /************扫描标识符及关键字*************/
        if(p_node->data>='a'&&p_node->data<='z'||p_node->data>='A'&&p_node->data<='Z'){
            while(p_node->data>='a'&&p_node->data<='z'||p_node->data>='A'&&p_node->data<='Z'||p_node->data>='0'&&p_node->data<='9'||p_node->data>='_'){
                token[m++]=p_node->data;
                p_node=p_node->pNext;
            }
            token[m++]='\0';
            insertList(tokenList,insertNode,scaner_key(4));
            insertNode=insertNode->next;
        }
    /***************扫描字符串****************/
        else if(p_node->data=='\"'){
                p_node=p_node->pNext;
                while(p_node->data!='\"'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                insertList(tokenList,insertNode,1);
                insertNode=insertNode->next;
                p_node=p_node->pNext;
            }
    /***************扫描字符*****************/
        else if(p_node->data=='\''){
                p_node=p_node->pNext;
                while(p_node->data!='\''){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                insertList(tokenList,insertNode,2);
                insertNode=insertNode->next;
                p_node=p_node->pNext;
            }
    /***************扫描数字*****************/
        else if((p_node->data>='0'&&p_node->data<='9')){
                while(p_node->data>='0'&&p_node->data<='9'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                if(p_node->data=='.'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                while(p_node->data>='0'&&p_node->data<='9'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                insertList(tokenList,insertNode,3);
                insertNode=insertNode->next;
            }
    /****************扫描界符****************/
        else if(p_node->data=='<'||p_node->data=='>'||p_node->data=='='||p_node->data=='+'||p_node->data=='-'||p_node->data=='.'){
                while(p_node->data=='<'||p_node->data=='>'||p_node->data=='='||p_node->data=='+'||p_node->data=='-'||p_node->data=='.'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                insertList(tokenList,insertNode,scaner_limit(36));
                insertNode=insertNode->next;
            }
        else if(p_node->data=='['){
                    insertList(tokenList,insertNode,49);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data==']'){
                    insertList(tokenList,insertNode,50);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data=='{'){
                    insertList(tokenList,insertNode,51);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data=='}'){
                    insertList(tokenList,insertNode,52);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data=='('){
                    insertList(tokenList,insertNode,53);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data==')'){
                    insertList(tokenList,insertNode,54);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data==','){
                    insertList(tokenList,insertNode,55);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data==';'){
                    insertList(tokenList,insertNode,56);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else if(p_node->data=='#'){
                    insertList(tokenList,insertNode,57);
                    insertNode=insertNode->next;
                    p_node=p_node->pNext;
            }
        else p_node=p_node->pNext;
    }
    tokenList=tokenList->next;
    while(tokenList){
        cout<<tokenList->data<<endl;;
        tokenList=tokenList->next;
    }
}
/********************************识别关键字模块*******************************/
int scaner_key(int state){
    int flag=0;
    for(int i=0;i<32;i++){
        if(strcmp(token,key[i])==0){
            sum=state+i;
            flag+=1;
        }
    }
    if(flag==0){
        sum=0;
    }
    return sum;
}
/********************************识别界符模块********************************/
int scaner_limit(int state){
    for(int i=0;i<13;i++){
        if(strcmp(token,limit[i])==0){
            sum=state+i;
        }
    }
    return sum;
}
/*********************************入链队操作**********************************/
void insertList(tokenNode *list_node,node p,int x){
    node node_new=(node)malloc(sizeof(tokenNode));
    node_new->data=x;
    node_new->next=NULL;
    p->next=node_new;
    p=node_new;
}
