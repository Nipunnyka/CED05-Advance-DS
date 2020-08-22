#include<bits/stdc++.h>
#include<iostream>

#define MAX_STACK 10000

using namespace std;

void menu(int& choice){
    cout<<"*************************************************"<<endl;
    cout<<"This program implements a Stack using array"<<endl;
    cout<<"1. push an element"<<endl;
    cout<<"2. pop an element"<<endl;
    cout<<"3. peek at the top element"<<endl;
    cout<<"4. check if the stack is empty"<<endl;
    cout<<"enter your choice(0 to exit)"<<endl;
    cin>>choice;
    cout<<"*************************************************"<<endl;
}

class Stack{
    int top=-1;
    public:
    int arr[MAX_STACK];
    bool push(int x);
    bool pop();
    bool isEmpty();
    int peek();
};

bool Stack::pop() 
{ 
    if (top < 0) { 
        cout << "STACK UNDERFLOW!!"<<endl; 
        return false;; 
    } 
    top--;
    return true;
}

int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "STACK UNDERFLOW!!"<<endl;  
        return INT_MAX; 
    } 
    else { 
        int x = arr[top]; 
        return x; 
    } 
}

bool Stack::isEmpty() 
{ 
    return (top < 0); 
}

bool Stack::push(int x){
    if(top>=MAX_STACK-1){
        cout<<"STACK OVER FLOW!!"<<endl;
        return false;
    }
    arr[++top]=x;
    return true;
}

int main(){
    bool exit_flag=false;
    int choice=-1;
    Stack s;
    srand(time(0));
    while(!exit_flag){
        menu(choice);

        switch(choice){
            case 0:
                exit_flag=true;
                break;
            case 1:{
                int temp=rand();
                if(s.push(temp))
                    cout<<"Successfully pushed "<<temp<<" onto stack"<<endl;
                else
                    cout<<"Operation failed ..."<<endl;
                }
                break;
            case 2:{
                if(s.pop())
                    cout<<"Successfully popped the top from stack"<<endl;
                }
                break;
            case 3:{
                int ans=s.peek();
                if(ans<INT_MAX)
                    cout<<"the top element is "<<ans<<endl;
                }
                break;
            case 4:{
                if(s.isEmpty())
                    cout<<"stack is empty"<<endl;
                else
                    cout<<"stack still has space"<<endl;
                }
                break;
        }
    }
    return 0;
}