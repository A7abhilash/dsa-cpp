#include<iostream>
#include<stdlib.h>
using namespace std;

class STACKNODE{
    public:
        int data;
        STACKNODE* link;

        STACKNODE(){
            link = NULL;
        }
};
typedef STACKNODE* stacknode;

class STACK{
    stacknode top;

    public:
        STACK(){
            top = NULL;
        }

        int isEmpty(){
            if(top==NULL) return  1;
            return 0;
        }

        void push(){
            stacknode n =new STACKNODE();
            cout<<"Enter the data:";
            cin>>n->data;
            n->link=top;
            top=n;
            cout<<"Item pushed\n";
        }

        void pop(){
            if(isEmpty()) cout<<"Stack underflow\n";
            else{
                stacknode temp = top;
                top=top->link;
                cout<<"Item popped: "<<temp->data<<endl;
                delete temp;
            }
        }

        void peek(){
            if(isEmpty()) cout<<"Stack is empty\n";
            else cout<<"Top of stack: "<<top->data<<endl;
        }

        void display(){
            if(isEmpty()) cout<<"Stack is empty\n";
            else{
                stacknode temp = top;
                cout<<"Stack:\n";
                while(temp!=NULL){
                    cout<<temp->data<<endl;
                    temp=temp->link;
                }
            }
        }
};

int main(){
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