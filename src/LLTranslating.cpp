#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <map>
using namespace std;
typedef struct tokenNode{
    int data;
    struct tokenNode *next;
}tokenNode, *node;
char Nonterminal[5]={'E','F','T','H','G'};
int lists[5][8]={
    {1,0,0,0,0,1,0,0},
    {0,2,3,0,0,0,4,4},
    {5,0,0,0,0,5,0,0},
    {0,8,8,6,7,0,8,8},
    {9,0,0,0,0,10,0,0}
};
int Ter,Non,gra;
void LLTranslating(node tokenLists){
    char swapKey(int x);
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
    stack<char>table;
    table.push('#');
    table.push('E');
    stack<char>sem;
    char ter,y;
    while(tokenLists->data!='#'){
        ter=swapKey(tokenLists->data);
        if(table.top()=='E'||table.top()=='F'||table.top()=='T'||table.top()=='H'||table.top()=='G'){
            for(int a=1;a<=5;a++){
                if(Nonterminal[a]==table.top()){
                    Non=a;
                }
            }
        }
        if(Non!=0){
            for(int x=1;x<=5;x++){
                for(int y=1;y<=8;y++){
                    if(lists[x][y]!=0){
                        gra=lists[x][y];
                    }
                }
            }
            table.pop();
            for(int x=grammar[gra].length()-1;x>=0;x--){
                y=(char)(grammar[gra][x]);
                table.push(y);
            }
        }
    }
}
void GEQ1(){

}
void GEQ2(){

}
void GEQ3(){

}
void GEQ4(){

}
void push(char y){

}
char swapKey(int x){
    if(x==0||x==3){
        Ter=1;
        return 'i';
    }
    if(x==42){
        Ter=2;
        return '+';
    }
    if(x==43){
        Ter=3;
        return '-';
    }
    if(x==58){
        Ter=4;
        return '*';
    }
    if(x==59){
        Ter=5;
        return '/';
    }
    if(x==54){
        Ter=6;
        return '(';
    }
    if(x==55){
        Ter=7;
        return ')';
    }
    if(x==60){
        Ter=8;
        return '#';
    }
}
