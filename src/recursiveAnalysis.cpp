#include <iostream>
using namespace std;
typedef struct tokenNode{
    int data;
    struct tokenNode *next;
}tokenNode, *node;
extern node p;
char w;
void recursive(){
    void next();
    void E();
    next();
    E();
    if(w=='#'){
        cout<<endl;
        cout<<"The analysis result is:"<<endl;
        cout<<"YES"<<endl;
    }else{
        cout<<endl;
        cout<<"The analysis result is:"<<endl;
        cout<<"NO0"<<endl;
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
    void F();
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
            cout<<endl;
            cout<<"The analysis result is:"<<endl;
            cout<<"NO2"<<endl;
        }
    }else{
        cout<<endl;
        cout<<"The analysis result is:"<<endl;
        cout<<"NO1"<<endl;
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
