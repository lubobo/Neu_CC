#include <iostream>
using namespace std;
extern int wrong;
typedef struct stringToken{
    char tokens[15];
}stringToken, *stringT;
typedef struct tokenNode{
    int data;
    stringT token;
    struct tokenNode *next;
}tokenNode, *node;
extern node p;
char w;
int a=0;
int recursive(){
    void next();
    void E();
    next();
    E();
    if(w=='#'&&a!=1&&a!=2){
        cout<<endl;
        cout<<"The recursiveAnalysis result is:"<<endl;
        cout<<"Right"<<endl;
        cout<<endl;
    }else if(w!='#'){
        cout<<endl;
        cout<<"The recursiveAnalysis result is:"<<endl;
        cout<<"Warning0"<<endl;
        wrong=1;
        return 0;
    }
}
void E(){
cout<<"E"<<endl;
    void T();
    void next();
    T();
    if(w=='w'&&a!=1&&a!=2){
        next();
        T();
    }
}
void T(){
cout<<"T"<<endl;
    int F();
    void next();
    F();
    if(w=='x'&&a!=1&&a!=2){
        next();
        F();
    }
}
int F(){
cout<<"F"<<endl;
    void E();
    void next();
    if(w=='i'&&a!=1&&a!=2){
        next();
    }else if(w=='('){
        next();
        E();
        if(w==')'&&a!=1&&a!=2){
            next();
        }else{
            a=1;
            cout<<endl;
            cout<<"The recursiveAnalysis result is:"<<endl;
            cout<<"Warning2"<<endl;
            wrong=1;
            return 0;
        }
    }else if(a!=1&&a!=2){
        a=2;
        cout<<endl;
        cout<<"The recursiveAnalysis result is:"<<endl;
        cout<<"Warning1"<<endl;
        wrong=1;
        return 0;
    }
}
void next(){
    char swapToken(int x);
    w=swapToken(p->data);
    p=p->next;

}
char swapValue(int x){
    if(x==0||x==3){
        return 'i';
    }
    if(x==42||x==43){
        return 'w';
    }
    if(x==58||x==59){
        return 'x';
    }
    if(x==54){
        return '(';
    }
    if(x==55){
        return ')';
    }
    if(x==60){
        return '#';
    }
}
