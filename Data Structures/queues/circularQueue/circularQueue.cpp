#include <iostream>
using namespace std;

class QUEUE{
    int size,count;
    int items[5];
    int front,rear;

    public:
        QUEUE(){
            size=5;
            count=0;
            front=0;
            rear=-1;
        }

        void enqueue(){
            if(count==size){
                cout<<"Queue is full\n";
            }else{
                cout<<"Enter the new item:";
                rear=(rear+1)%size;
                cin>>items[rear];
                count++;
                cout<<"Item enqueued\n";
            }
        }

        void dequeue(){
            if(count==0){
                cout<<"Queue is empty\n";
            }else{
                cout<<"Dequeued item: "<<items[front]<<endl;
                front=(front+1)%size;
                count--;
            }
        }

        void displayQueue(){
            if(count==0){
                cout<<"Queue is empty\n";
            }else{
                cout<<"Queue items:\n";
                int j=front;
                for(int i=1;i<=count;i++){
                    cout<<items[j]<<" ";
                    j=(j+1)%size;
                }
                cout<<endl;
            }
        }
};

int main(){
    QUEUE Q;
    int choice;
    while(1){
        cout<<"\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 0: exit(0);
        case 1: Q.enqueue(); break;
        case 2: Q.dequeue(); break;
        case 3: Q.displayQueue(); break;
        default: cout<<"Enter proper choice\n";
        }
    }
    return 0;
}