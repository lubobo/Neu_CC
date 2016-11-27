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
    Next();
    E1();
    cout<<"R0"<<endl;
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
    cout<<"R1"<<endl;
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
        cout<<"R2"<<endl;
        GEQAdd();
        E2();
    }else if(p->tokens=='-'){
        Next();
        T1();
        cout<<"R3"<<endl;
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
    cout<<"R4"<<endl;
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
        cout<<"R5"<<endl;
        GEQMul();
        T2();
    }else if(p->tokens=='/'){
        Next();
        F1();
        cout<<"R6"<<endl;
        GEQDiv();
        T2();
    }
}
void F1(){
    void Next();
    void E1();
    if(p->tokens=='a'||p->tokens=='b'||p->tokens=='c'){
        semz.push(p->tokens);
        Next();
    }else if(p->tokens=='('){
        Next();
        E1();
        cout<<"R7"<<endl;
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
    cout<<'('<<'+'<<'\t'<<m<<'\t'<<n<<'\t'<<n+m<<')'<<endl;
    semz.push((char)(n+m));
}
void GEQSub(){
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'-'<<'\t'<<m<<'\t'<<n<<'\t'<<n-m<<')'<<endl;
    semz.push((char)(n-m));
}
void GEQMul(){
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'*'<<'\t'<<m<<'\t'<<n<<'\t'<<m*n<<')'<<endl;
    semz.push(m*n);
}
void GEQDiv(){
    char n=semz.top();
    semz.pop();
    char m=semz.top();
    semz.pop();
    cout<<'('<<'/'<<'\t'<<m<<'\t'<<n<<'\t'<<m/n<<')'<<endl;
    semz.push(m/n);
}
