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
    struct Node *pPre;
}Node, *pNode;

/********************************识别token序列模块********************************/
void getToken(Node *p_node){
    void scaner_key(int state);
    void scaner_limit(int state);
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
            scaner_key(4);
        }
    /***************扫描字符串****************/
        else if(p_node->data=='\"'){
                p_node=p_node->pNext;
                while(p_node->data!='\"'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                cout<<"<"<<'\"'<<token<<'\"'<<","<<2<<">"<<endl;
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
                cout<<"<"<<'\''<<token<<'\''<<","<<1<<">"<<endl;
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
                cout<<"<"<<token<<","<<3<<">"<<endl;
            }
    /****************扫描界符****************/
        else if(p_node->data=='<'||p_node->data=='>'||p_node->data=='='||p_node->data=='+'||p_node->data=='-'||p_node->data=='.'){
                while(p_node->data=='<'||p_node->data=='>'||p_node->data=='='||p_node->data=='+'||p_node->data=='-'||p_node->data=='.'){
                    token[m++]=p_node->data;
                    p_node=p_node->pNext;
                }
                token[m++]='\0';
                scaner_limit(10);
            }
        else if(p_node->data=='['){
                while(p_node->data=='['&p_node->pNext->data!='['){
                    cout<<"<"<<'['<<","<<23<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data==']'){
                while(p_node->data==']'&p_node->pNext->data!=']'){
                    cout<<"<"<<']'<<","<<24<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data=='{'){
                while(p_node->data=='{'&p_node->pNext->data!='{'){
                    cout<<"<"<<'{'<<","<<25<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data=='}'){
                while(p_node->data=='}'&p_node->pNext->data!='}'){
                    cout<<"<"<<'}'<<","<<26<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data=='('){
                while(p_node->data=='('&p_node->pNext->data!='('){
                    cout<<"<"<<'('<<","<<27<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data==')'){
                while(p_node->data==')'&p_node->pNext->data!=')'){
                    cout<<"<"<<')'<<","<<28<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data==','){
                while(p_node->data==','&p_node->pNext->data!=','){
                    cout<<"<"<<','<<","<<29<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else if(p_node->data==';'){
                while(p_node->data==';'&p_node->pNext->data!=';'){
                    cout<<"<"<<';'<<","<<30<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }

        else if(p_node->data=='#'){
                while(p_node->data=='#'&p_node->pNext->data!='#'){
                    cout<<"<"<<'#'<<","<<32<<">"<<endl;
                    p_node=p_node->pNext;
                }
            }
        else p_node=p_node->pNext;
    }
}
/********************************识别关键字模块*******************************/
void scaner_key(int state){
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
    cout<<"<"<<token<<","<<sum<<">"<<endl;
}
/********************************识别界符模块********************************/
void scaner_limit(int state){
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
    cout<<"<"<<token<<","<<sum<<">"<<endl;
}
