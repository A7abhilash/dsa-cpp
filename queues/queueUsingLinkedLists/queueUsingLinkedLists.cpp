#include<iostream>
#include<stdlib.h>
using namespace std;

class QUEUENODE{
    public:
        int data;    
        QUEUENODE* link;

        QUEUENODE(){
            link=NULL;
        }
};
typedef class QUEUENODE* queuenode;

class QUEUE{
    queuenode front,rear;

    public:
        QUEUE(){
            front=NULL;
            rear=NULL;
        }
        
        void enqueue(){
            queuenode n = new QUEUENODE();
            cout<<"Enter the data:";
            cin>>n->data;
            if(rear!=NULL){
                rear->link=n;
            }
            rear=n;
            if(front==NULL) front=rear;
            printf("Node item enqueued\n");
        }
        
        void dequeue(){
            if(front==NULL){
                cout<<"Queue is empty\n";
                return;
            }
            queuenode temp= front;
            cout<<"Dequeued node item: "<<temp->data<<endl;
            front=front->link; 
            if(front==NULL) rear=front;
            free(temp);
        }   

        void display(){
            if(front==NULL){
                cout<<"Queue is empty\n";
                return;
            }
            int count=0;
            queuenode temp= front;
            cout<<"Queue:\n";
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->link;
                count++;
            }
            cout<<"\nNo. of items in Queue: "<<count<<endl;
        }

};




int main(){
    QUEUE Q;
    int choice;

    while(1){
        cout<<"\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 0: exit(0);
            case 1: Q.enqueue(); break;
            case 2: Q.dequeue(); break;
            case 3: Q.display(); break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}