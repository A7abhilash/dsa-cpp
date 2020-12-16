#include<iostream>
using namespace std;
#include<stdlib.h>

class QUEUE{
    int items[5];
    int front,rear;

    public:
        QUEUE(){
            front=0;
            rear=-1;
        }

        void enqueue(){
            if(rear==4){
                cout<<"Queue is full\n";
            }else{
                cout<<"Enter the new item:";
                cin>>items[++rear];
                cout<<"Item enqueued\n";
            }
        }

        void dequeue(){
            if(front>rear){
                cout<<"Queue is empty\n";
            }else{
                int minI=0,min=items[0],i;
                for(i=front;i<=rear;i++){
                    if(items[i]<min){
                        min=items[i];
                        minI=i;
                    }
                }
                for(i=minI;i<rear;i++){
                    items[i]=items[i+1];
                }
                rear--;
                cout<<"Dequeued item: "<<min<<endl;
            }
        }

        void displayQueue(){
            if(front>rear){
                cout<<"Queue is empty\n";
            }else{
                cout<<"Queue items:\n";
                for(int i=front;i<=rear;i++){
                    cout<<items[i]<<" ";
                }
                cout<<endl;
            }
        }

};

int main(){
    int choice;
    QUEUE Q;
    
    while(1){
        cout<<"\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display Queue\nEnter your choice:";
		cin>>choice;
        
        switch(choice){
            case 0: exit(0);
            case 1: Q.enqueue(); break;
            case 2: Q.dequeue(); break;
            case 3: Q.displayQueue(); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}