#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <map>
using namespace std;
typedef struct stringToken{
    char tokens[15];
}stringToken, *stringT;
typedef struct tokenNode{
    int data;
    stringT token;
    struct tokenNode *next;
}tokenNode, *node;
extern node p;
stack<string>semz;
char y='1';
void reTranslating(){
    void Next();
    void E1();
    E1();
    if(p->token->tokens[0]=='#'){
        cout<<"Success!!!"<<endl;
    }else{
        cout<<"Wrong!!!"<<endl;
    }
}
void E1(){
    void Next();
    void T1();
    void GEQAdd();
    void GEQSub();
    void E2();
    T1();
    E2();
}
void E2(){
    void Next();
    void T1();
    void GEQAdd();
    void GEQSub();
    if(p->token->tokens[0]=='+'){
        Next();
        T1();
        GEQAdd();
        y++;
        E2();
    }else if(p->token->tokens[0]=='-'){
        Next();
        T1();
        GEQSub();
        y++;
        E2();
    }
}
void T1(){
    void Next();
    void F1();
    void GEQMul();
    void GEQDiv();
    void T2();
    F1();
    T2();
}
void T2(){
    void Next();
    void F1();
    void GEQMul();
    void GEQDiv();
    if(p->token->tokens[0]=='*'){
        Next();
        F1();
        GEQMul();
        y++;
        T2();
    }else if(p->token->tokens[0]=='/'){
        Next();
        F1();
        GEQDiv();
        y++;
        T2();
    }
}
void F1(){
    void Next();
    void E1();
    if(p->data==0||p->data==3){
        semz.push((string)(p->token->tokens));
        Next();
    }else if((string)(p->token->tokens)=="("){
        Next();
        E1();
        if((string)(p->token->tokens)==")"){
            Next();
        }else{
            cout<<"Wrong2!!!"<<endl;
        }
    }else{
        cout<<"Wrong1!!!"<<endl;
    }
}

void Next(){
    p=p->next;
}

void GEQAdd(){
    string n=semz.top();
    semz.pop();
    string m=semz.top();
    semz.pop();
    cout<<'('<<'+'<<'\t'<<m<<'\t'<<n<<'\t'<<"t"<<y<<')'<<endl;
    char t[3]={'t',y,'\0'};
    semz.push((string)(t));
}
void GEQSub(){
    string n=semz.top();
    semz.pop();
    string m=semz.top();
    semz.pop();
    cout<<'('<<'-'<<'\t'<<m<<'\t'<<n<<'\t'<<"t"<<y<<')'<<endl;
    char t[3]={'t',y,'\0'};
    semz.push((string)(t));
}
void GEQMul(){
    string n=semz.top();
    semz.pop();
    string m=semz.top();
    semz.pop();
    cout<<'('<<'*'<<'\t'<<m<<'\t'<<n<<'\t'<<"t"<<y<<')'<<endl;
    char t[3]={'t',y,'\0'};
    semz.push((string)(t));
}
void GEQDiv(){
    string n=semz.top();
    semz.pop();
    string m=semz.top();
    semz.pop();
    cout<<'('<<'/'<<'\t'<<m<<'\t'<<n<<'\t'<<"t"<<y<<')'<<endl;
    char t[3]={'t',y,'\0'};
    semz.push((string)(t));
}
