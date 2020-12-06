#include<iostream>
#include<stdlib.h>
using namespace std;

class STACK{
    int top;
    int stack[5];

    public:    
        STACK(){
            top=-1;
        }

        int isEmpty(){
            if(top==-1) return  1;
            return 0;
        }

        int isFull(){
            if(top==4) return  1;
            return 0;
        }

        void push(){
            if(isFull()) cout<<"Stack overflow\n";
            else{
                int data;
                cout<<"Enter the data:";
                cin>>data;
                stack[++top]=data;
                cout<<"Item pushed\n";
            }
        }

        void pop(){
            if(isEmpty()) cout<<"Stack underflow\n";
            else{
                cout<<"Item popped: "<<stack[top--]<<endl;
            }
        }

        void peek(){
            if(isEmpty()) cout<<"Stack is empty\n";
            else cout<<"Top of stack: "<<stack[top]<<endl;
        }

        void display(){
            if(isEmpty()) cout<<"Stack is empty\n";
            else{
                cout<<"Stack:\n";
                for(int i=top;i>=0;i--)
                    cout<<stack[i]<<endl;
            }
        }
};

int main(){
    // STACK S = new STACK();
    STACK S;
    int choice;
    while(1){
        cout<<"\n0.Exit\n1.Push\n2.Pop\n3.Peek top\n4.Display\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 0: exit(0);
        case 1: S.push(); break;
        case 2: S.pop(); break;
        case 3: S.peek(); break;
        case 4: S.display(); break;
        default: cout<<"Enter proper choice\n";
        }
    }
    return 0;
}