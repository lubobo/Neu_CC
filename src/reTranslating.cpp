#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <map>
using namespace std;
typedef struct tokenNode{
    int data;
    char tokens;
    struct tokenNode *next;
}tokenNode, *node;
extern node p;
stack<char>semz;
void reTranslating(){
    void Next();
    void E1();
    E1();
    if(p->tokens=='#'){
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
    if(p->tokens=='+'){
        Next();
        T1();
        GEQAdd();
        E2();
    }else if(p->tokens=='-'){
        Next();
        T1();
        GEQSub();
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
    if(p->tokens=='*'){
        Next();
        F1();
        GEQMul();
        T2();
    }else if(p->tokens=='/'){
        Next();
        F1();
        GEQDiv();
        T2();
    }
}
void F1(){
    void Next();
    void E1();
    if(p->data==0||p->data==3){
        semz.push(p->tokens);
        Next();
    }else if(p->tokens=='('){
        Next();
        E1();
        if(p->tokens==')'){
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
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'+'<<'\t'<<m<<'\t'<<n<<'\t'<<m+n<<')'<<endl;
    semz.push((char)(m+n));
}
void GEQSub(){
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'-'<<'\t'<<m<<'\t'<<n<<'\t'<<m-n<<')'<<endl;
    semz.push((char)(m-n));
}
void GEQMul(){
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'*'<<'\t'<<m<<'\t'<<n<<'\t'<<m*n<<')'<<endl;
    semz.push((char)(m*n));
}
void GEQDiv(){
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'/'<<'\t'<<m<<'\t'<<n<<'\t'<<m/n<<')'<<endl;
    semz.push((char)(m/n));
}
