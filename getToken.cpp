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
    /**************函数声明******************/
    int scaner_key(int state);
    int scaner_limit(int state);
    void insertList(tokenNode *list_node,int x);
    for(int j=0;j<10;j++){
        token[j]=NULL;
    }
    int n=0;
    while(p_node!=NULL){
        int m=0;
    /************扫描标识符及关键字*************/
        if(p_node->data>='a'&&p_node->data<='z'||p_node->data>='A'&&p_node->data<='Z'){
            while(p_node->data>='a'&&p_node->data<='z'||p_node->data>='A'&&p_node->data<='Z'||p_node->data>='0'&&p_node->data<='9'||p_node->data=='_'){
                token[m++]=p_node->data;
                p_node=p_node->pNext;
            }
            token[m++]='\0';
            insertList(tokenList,scaner_key(4));
        }
    /***************扫描字符串****************/
        else if(p_node->data=='\"'){
                p_node=p_node->pNext;
                while(p_node->data!='\"'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                //cout<<"<"<<'\"'<<token<<'\"'<<","<<2<<">"<<endl;
                p_node=p_node->pNext;
                insertList(tokenList,1);
            }
    /***************扫描字符*****************/
        else if(p_node->data=='\''){
                p_node=p_node->pNext;
                while(p_node->data!='\''){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                //cout<<"<"<<'\''<<token<<'\''<<","<<1<<">"<<endl;
                insertList(tokenList,2);
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
                //cout<<"<"<<token<<","<<3<<">"<<endl;
                insertList(tokenList,3);
            }
    /****************扫描界符****************/
        else if(p_node->data=='<'||p_node->data=='>'||p_node->data=='='||p_node->data=='+'||p_node->data=='-'||p_node->data=='.'){
                while(p_node->data=='<'||p_node->data=='>'||p_node->data=='='||p_node->data=='+'||p_node->data=='-'||p_node->data=='.'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                insertList(tokenList,scaner_key(10));
            }
        else if(p_node->data=='['){
                while(p_node->data=='['&p_node->pNext->data!='['){
                    //cout<<"<"<<'['<<","<<23<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,23);
                }
            }
        else if(p_node->data==']'){
                while(p_node->data==']'&p_node->pNext->data!=']'){
                    //cout<<"<"<<']'<<","<<24<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,24);
                }
            }
        else if(p_node->data=='{'){
                while(p_node->data=='{'&p_node->pNext->data!='{'){
                    //cout<<"<"<<'{'<<","<<25<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,25);
                }
            }
        else if(p_node->data=='}'){
                while(p_node->data=='}'&p_node->pNext->data!='}'){
                    //cout<<"<"<<'}'<<","<<26<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,26);
                }
            }
        else if(p_node->data=='('){
                while(p_node->data=='('&p_node->pNext->data!='('){
                    //cout<<"<"<<'('<<","<<27<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,27);
                }
            }
        else if(p_node->data==')'){
                while(p_node->data==')'&p_node->pNext->data!=')'){
                    //cout<<"<"<<')'<<","<<28<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,28);
                }
            }
        else if(p_node->data==','){
                while(p_node->data==','&p_node->pNext->data!=','){
                    //cout<<"<"<<','<<","<<29<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,29);
                }
            }
        else if(p_node->data==';'){
                while(p_node->data==';'&p_node->pNext->data!=';'){
                    //cout<<"<"<<';'<<","<<30<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,30);
                }
            }

        else if(p_node->data=='#'){
                while(p_node->data=='#'&p_node->pNext->data!='#'){
                    //cout<<"<"<<'#'<<","<<32<<">"<<endl;
                    p_node=p_node->pNext;
                    insertList(tokenList,32);
                }
            }
        else p_node=p_node->pNext;
    }
}
/********************************识别关键字模块*******************************/
int scaner_key(int state){
    int flag=0;
    for(int i=0;i<32;i++){
        if(strcmp(token,key[i])==0){
            sum=state+i;
            flag=++i;
        }
    }
    if(flag==0){
        sum=0;
    }
    //cout<<"<"<<token<<","<<sum<<">"<<endl;
    return sum;
}
/********************************识别界符模块********************************/
int scaner_limit(int state){
    int flag=0;
    for(int i=0;i<13;i++){
        if(strcmp(token,limit[i])==0){
            sum=state+i;
            flag=++i;
        }
    }
    if(flag==0){
        sum=0;
    }
    //cout<<"<"<<token<<","<<sum<<">"<<endl;
    return sum;
}
/*********************************入链队操作**********************************/
void insertList(tokenNode *list_node,int x){
    cout<<x<<endl;
    node node_new=(node)malloc(sizeof(tokenNode));
    node_new->data=x;
    node_new->next=NULL;
    list_node->next=node_new;
    list_node=node_new;
    cout<<list_node->data<<endl;
}
