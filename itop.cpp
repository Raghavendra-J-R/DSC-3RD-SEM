#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
    char data;
    struct node *next;
}*top=NULL;

void Push(char x){
    struct node *t=new node;
    if(!t){
        cout<<"stack overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void Display(struct node *p){
while(p){
    cout<<p->data<<endl;
    p=p->next;
}
}

char Pop(){
    struct node *q=NULL;
    char x=-1;
    if(top==NULL){
        cout<<"stack underflow"<<endl;
    }
    else{
        q=top;
        top=top->next;
        x=q->data;
        delete q;
    }
    return x;
}
int Peek(struct node *p,int pos){
    int x=-1;
    struct node *q=p;
    for(int i=0;q!=NULL && i<pos-1;i++){
        q=q->next;
    }
    if(q){
        return q->data;
    }
    else{
        return x;
    }
}

int Stacktop(){
    if(top){
        return top->data;
    }else{
        return -1;
    }
}

bool isEmpty(){
    return top?0:1;
}
bool isFull(){
    struct node *t=new node;
    bool r=t?1:0;
    delete t;
    return r;
}

int pre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    else{
        return 0;
    }
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

char *IntoPost(char *infix){
    char *postfix=new char[strlen(infix)+2];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i]>pre(top->data))){
                Push(infix[i++]);
            }
            else{
                postfix[j++]=Pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++]=Pop();
    }
    postfix[j]='\0';
    return postfix;
}


int main(){
char *infix="a+b*c";
Push('#');
char *postfix=IntoPost(infix);
printf("%s",postfix);

}