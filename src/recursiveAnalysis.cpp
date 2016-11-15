#include <iostream>
using namespace std;
typedef struct tokenNode{
    int data;
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
    if(w=='#'&&a!=1){
        cout<<endl;
        cout<<"The recursiveAnalysis result is:"<<endl;
        cout<<"Right"<<endl;
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"The recursiveAnalysis result is:"<<endl;
        cout<<"Warning0"<<endl;
        cout<<endl;
        return 0;
    }
}
void E(){
cout<<"E"<<endl;
    void T();
    void next();
    T();
    if(w=='w'){
        next();
        T();
    }
}
void T(){
cout<<"T"<<endl;
    int F();
    void next();
    F();
    if(w=='x'){
        next();
        F();
    }
}
void F(){
cout<<"F"<<endl;
    void E();
    void next();
    if(w=='i'){
        next();
    }else if(w=='('){
        next();
        E();
        if(w==')'){
            next();
        }else{
            a=1;
            cout<<endl;
            cout<<"The recursiveAnalysis result is:"<<endl;
            cout<<"Warning2"<<endl;
            cout<<endl;
        }
    }else{
        a=1;
        cout<<endl;
        cout<<"The recursiveAnalysis result is:"<<endl;
        cout<<"Warning1"<<endl;
        cout<<endl;
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
