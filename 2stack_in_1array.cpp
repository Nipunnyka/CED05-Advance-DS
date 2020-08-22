#include <iostream> 
#include <stdlib.h> 
  
using namespace std; 
  
class twoStacks { 
    int* arr; 
    int size; 
    int top1, top2; 
  
public: 
    // Constructor 
    twoStacks(int n) 
    { 
        size = n; 
        arr = new int[n]; 
        top1 = n / 2 + 1; 
        top2 = n / 2; 
    } 
  
    // Method to push an element x to stack1 
    void push1(int x) 
    { 
        // There is at least one empty 
        // space for new element 
        if (top1 > 0) { 
            top1--; 
            arr[top1] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        } 
    } 
  
    // Method to push an element 
    // x to stack2 
    void push2(int x) 
    { 
  
        // There is at least one empty 
        // space for new element 
        if (top2 < size - 1) { 
            top2++; 
            arr[top2] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        } 
    } 
  
    // Method to pop an element from first stack 
    int pop1() 
    { 
        if (top1 <= size / 2) { 
            int x = arr[top1]; 
            top1++; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
  
    // Method to pop an element 
    // from second stack 
    int pop2() 
    { 
        if (top2 >= size / 2 + 1) { 
            int x = arr[top2]; 
            top2--; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
}; 
  
/* Driver program to test twStacks class */
int main() 
{ 
    int t;
    twoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    while(true){
        cout << "Enter choice" << endl;
        cin >> t;
        if(t == 1){
            ts.pop1();
            cout << "Popped element from stack1 is "
             << " : " << ts.pop1() 
             << endl;
        }
        if(t == 2){
        ts.pop2(); 
        cout << "\nPopped element from stack2 is "
             << ": " << ts.pop2() 
             << endl;
        } 
        if(t == 3){
            int x;
            cout << "Enter the element to push into first stack" << endl;
            ts.push1(x);
        }
        if(t == 4){
            int x;
            cout << "Enter the element to push into the second stack" << endl;
            ts.push2(x);
        } 
        if(t==0){
            return 0;
        }
    }
     
} 