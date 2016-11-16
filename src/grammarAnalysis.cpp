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
char Nonterminal[5]={'E','F','G','H','I'};
char Terminal[6]={'i','w','x','(',')','#'};
int List[5][6]={
    {1,0,0,1,0,0},
    {0,2,0,0,3,3},
    {4,0,0,4,0,0},
    {0,6,5,0,6,6},
    {7,0,0,8,0,0}
};
void analysis(node tokenLists){
    char swapToken(int x);
    map<int,string>production;
    production[1]="GF";
    production[2]="wGF";
    production[3]="";
    production[4]="IH";
    production[5]="xIH";
    production[6]="";
    production[7]="i";
    production[8]="(E)";
    stack<char>table;
    table.push('#');
    table.push('E');
    int a,b,c,l;
    a=b=c=l=0;
    char n,q;
    while(tokenLists->data!='#'){
        n=swapToken(tokenLists->data);
        cout<<"初始元素:";
        cout<<table.top()<<","<<n<<","<<table.size()<<endl;
        if(table.top()=='i'||table.top()=='w'||table.top()=='x'||table.top()=='('||table.top()==')'||table.top()=='#'){
            for(int t=0;t<5;t++){
                if(table.top()==Terminal[t]){
                    q=Terminal[t];
                }
            }
            if(n==q){
                table.pop();
                tokenLists=tokenLists->next;
            }else{
                break;
            }
        }
        else if(table.top()=='E'||table.top()=='F'||table.top()=='G'||table.top()=='H'||table.top()=='I'){
            for(int f=0;f<5;f++){
                if(n==Terminal[f]){
                    l=f;
                }
            }
            for(int j=0;j<=4;j++){
                if(table.top()==Nonterminal[j]){
                    b=j;
                }
            }
            c=List[b][l];
            if(c!=0&&c!=3&&c!=6){
                table.pop();
                cout<<"栈内个数:";
                cout<<table.size()<<endl;
                char y;
                for(int x=production[c].length()-1;x>=0;x--){
                    y=(char)(production[c][x]);
                    table.push(y);
                    cout<<"压栈元素:";
                    cout<<x<<","<<production[c][x]<<endl;
                }
                cout<<"栈内个数:";
                cout<<table.size()<<endl;
                cout<<endl;
            }else{
                cout<<"压栈为空*"<<endl;
                table.pop();
            }
        }else{
            break;
        }
    }
    if(swapToken(tokenLists->data)=='#'&&table.top()=='#'){
        cout<<endl;
        cout<<"The grammarAnalysis result is:"<<endl;
        cout<<"Right"<<endl;
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"The grammarAnalysis result is:"<<endl;
        cout<<"Warning"<<endl;
        cout<<endl;
    }
}
char swapToken(int x){
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
