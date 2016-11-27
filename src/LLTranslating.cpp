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
char Nonter[5]={'E','F','T','H','G'};
int lists[5][8]={
    {1,0,0,0,0,1,0,0},
    {0,2,3,0,0,0,4,4},
    {5,0,0,0,0,5,0,0},
    {0,8,8,6,7,0,8,8},
    {9,0,0,0,0,10,0,0}
};
int Ter,Non,gra;
stack<char>table;
stack<char>sem;
void LLTranslating(){
    char swapKey(int x);
    void GEQ1();
    void GEQ2();
    void GEQ3();
    void GEQ4();
    map<int,string>grammar;
    grammar[1]="TF";
    grammar[2]="+T1F";  //1对应GEQ(+)=>GEQ1()
    grammar[3]="-T2F";  //2对应GEQ(-)=>GEQ2()
    grammar[4]="";
    grammar[5]="GH";
    grammar[6]="*G3H";  //3对应GEQ(*)=>GEQ3()
    grammar[7]="/G4H";  //4对应GEQ(/)=>GEQ4()
    grammar[8]="";
    grammar[9]="i0";    //0对应push(i)
    grammar[10]="(E)";
    table.push('#');
    table.push('E');
    int y;
    char ter;
    ter=swapKey(p->data);
    while(ter!='#'){
        ter=swapKey(p->data);
        if(table.top()=='E'||table.top()=='F'||table.top()=='T'||table.top()=='H'||table.top()=='G'){
            for(int a=0;a<5;a++){
                if(Nonter[a]==table.top()){
                    Non=a;
                }
            }
            if(lists[Non][Ter]!=0&&lists[Non][Ter]!=9){
                y=lists[Non][Ter];
                table.pop();
                if(y==4||y==8){
                    continue;
                }else{
                    for(int x=grammar[y].length()-1;x>=0;x--){
                        table.push((char)(grammar[y][x]));
                    }
                }
            }else if(lists[Non][Ter]==9){
                table.pop();
                table.push(ter);
                table.push('0');
            }
        }else if(table.top()=='1'){
            GEQ1();
            table.pop();
        }else if(table.top()=='2'){
            GEQ2();
            table.pop();
        }else if(table.top()=='3'){
            GEQ3();
            table.pop();
        }else if(table.top()=='4'){
            GEQ4();
            table.pop();
        }else if(table.top()=='0'){
            sem.push(ter);
            table.pop();
        }else if(table.top()==ter){
            p=p->next;
            table.pop();
        }else{
            break;
        }
    }
    if(ter=='#'){
        cout<<"Success!!!"<<endl;
    }else{
        cout<<"Wrong!!!"<<endl;
    }
}
void GEQ1(){
    char n=sem.top();
    sem.pop();
    char m=sem.top();
    sem.pop();
    cout<<'('<<'+'<<'\t'<<n<<'\t'<<m<<'\t'<<n+m<<')'<<endl;
    sem.push(n+m);
}
void GEQ2(){
    char n=sem.top();
    sem.pop();
    char m=sem.top();
    sem.pop();
    cout<<'('<<'-'<<'\t'<<n<<'\t'<<m<<'\t'<<n-m<<')'<<endl;
    sem.push(n-m);
}
void GEQ3(){
    char n=sem.top();
    sem.pop();
    char m=sem.top();
    sem.pop();
    cout<<'('<<'*'<<'\t'<<n<<'\t'<<m<<'\t'<<n*m<<')'<<endl;
    sem.push(n*m);
}
void GEQ4(){
    char n=sem.top();
    sem.pop();
    char m=sem.top();
    sem.pop();
    cout<<'('<<'/'<<'\t'<<n<<'\t'<<m<<'\t'<<n/m<<')'<<endl;
    sem.push(n/m);
}
char swapKey(int x){
    if(x==0||x==3){
        Ter=0;
        return 'i';
    }
    if(x==42){
        Ter=1;
        return '+';
    }
    if(x==43){
        Ter=2;
        return '-';
    }
    if(x==58){
        Ter=3;
        return '*';
    }
    if(x==59){
        Ter=4;
        return '/';
    }
    if(x==54){
        Ter=5;
        return '(';
    }
    if(x==55){
        Ter=6;
        return ')';
    }
    if(x==60){
        Ter=7;
        return '#';
    }
}
