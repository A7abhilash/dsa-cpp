#include <iostream>
using namespace std;

class QUEUE{
    int size;
    int items[5];
    int front,rear;

    public:
        QUEUE(){
            size=5;
            front=0;
            rear=-1;
        }

        void insertRear(){
            if(rear==4){
                cout<<"Queue is full\n";
            }else{
                cout<<"Enter the new item:";
                cin>>items[++rear];
                cout<<"Item enqueued\n";
            }
        }

        void insertFront(){
            if(front==0 && rear==4){
                cout<<"Queue is full\n";
            }else{
                int item;
                cout<<"Enter the new item:";
                cin>>item;
                if(front>rear){//if queue was empty
                    items[++rear]=item;
                    cout<<"Item enqueued\n";
                }else if(front>0){
                    items[--front]=item;
                    cout<<"Item enqueued\n";
                }else cout<<"Front insertion is not possible\n";
            }
        }

        void deleteFront(){
            if(front>rear) cout<<"Queue is empty\n";
            else cout<<"Dequeued item: "<<items[front++]<<endl;
        }

        void deleteRear(){
            if(front>rear) cout<<"Queue is empty\n";
            else cout<<"Dequeued item: "<<items[rear--]<<endl;
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
    QUEUE Q;
    int choice;
    while(1){
        cout<<"\n0.Exit\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n3.Display\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 0: exit(0);
        case 1: Q.insertFront(); break;
        case 2: Q.insertRear(); break;
        case 3: Q.deleteFront(); break;
        case 4: Q.deleteRear(); break;
        case 5: Q.displayQueue(); break;
        default: cout<<"Enter proper choice\n";
        }
    }
    return 0;
}