#include<bits/stdc++.h>

using namespace std;

struct node{
    int key;
    node *next;
    node(){
        this->key=NULL;
        this->next=NULL;
    }
} top;

bool push(int data){
    node* temp=new node();
    if(!temp){
        cout<<"HEAP OVERFLOW!"<<endl;
        return false;
    }
    if(top->key==NULL){
        top->key=data;
        return true;
    }
    temp->key=data;
    temp->next=top;
    top=temp;
    return true;
}

bool isEmpty(){
    return top==NULL;
}

int peek(){
    if(!isEmpty())
        return top->key;
    else 
        return INT_MAX;
}

bool pop(){
    node* temp;
    if(top==NULL){
        cout<<"STACK UNDERFLOWW!!"<<endl;
        return false;
    }
    temp=top;
    top=top->next;
    temp->next=NULL;
    delete(temp);
    return true;
}

void menu(int& choice){
    cout<<"*************************************************"<<endl;
    cout<<"This program implements a Stack using linkedlist"<<endl;
    cout<<"1. push an element"<<endl;
    cout<<"2. pop an element"<<endl;
    cout<<"3. peek at the top element"<<endl;
    cout<<"4. check if the stack is empty"<<endl;
    cout<<"enter your choice(0 to exit)"<<endl;
    cin>>choice;
    cout<<"*************************************************"<<endl;
}


int main(){
    bool exit_flag=false;
    int choice=-1;
    srand(time(0));
    while(!exit_flag){
        menu(choice);

        switch(choice){
            case 0:
                exit_flag=true;
                break;
            case 1:{
                int temp=rand();
                if(push(temp))
                    cout<<"Successfully pushed "<<temp<<" onto stack"<<endl;
                else
                    cout<<"Operation failed ..."<<endl;
                }
                break;
            case 2:{
                if(pop())
                    cout<<"Successfully popped the top from stack"<<endl;
                }
                break;
            case 3:{
                int ans=peek();
                if(ans<INT_MAX)
                    cout<<"the top element is "<<ans<<endl;
                }
                break;
            case 4:{
                if(isEmpty())
                    cout<<"stack is empty"<<endl;
                else
                    cout<<"stack still has space"<<endl;
                }
                break;
        }
    }
    return 0;
}