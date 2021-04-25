#include<iostream>
#include<stdlib.h>
using namespace std;

typedef class Heap* heap;

class Heap{
    int *arr;
    int count;
    int capacity;

    public:
        Heap(){
            count=0;
            capacity=1;
            arr = new int[capacity];
        }
        
        int parentIndex(int i){
            if(i<=0 || i>=count) return -1;
            return (i-1)/2;
        }

        int leftChildIndex(int i){
            int left=2*i+1;
            if(left>=count) return -1;
            return left;
        }

        int rightChildIndex(int i){
            int right=2*i+2;
            if(right>=count) return -1;
            return right;
        }

        void getMaxElement(){
            if(count==0) {
                cout<<"Heap is empty\n";
            }
            else cout<<"Max element: "<<arr[0]<<endl;
        }

        void swap(int *a,int *b){
            int c=*a;
            *a=*b;
            *b=c;
        }

        //Heapifying the element(at location i) downwards.
        void percolateDown(int i){
            int max,temp;
            int left=leftChildIndex(i);
            int right=rightChildIndex(i);

            if(left!=-1 && arr[left]>arr[i])
                max=left;
            else max=i;
            if(right!=-1 && arr[right]>arr[max])
                max=right;
            
            if(max!=i){
                //swap elements at i & max
                swap(&arr[i],&arr[max]);
                percolateDown(max);
            }
        }

        void insert(){
            if(count==capacity){
                capacity*=2;
                arr=(int*)realloc(arr,sizeof(int)*capacity);
                cout<<"Memory reallocated\n";
            }
            count++;
            int data,temp;
            cout<<"Enter the new data:";
            cin>>data;

            int i=count-1;
            //percolate up
            while(i>=0 && data>arr[parentIndex(i)]){
                //swap elements at i & it's parent
                swap(&arr[i],&arr[parentIndex(i)]);
                i=parentIndex(i);
            }
            arr[i]=data;
            cout<<"New data inserted\n";
            percolateDown(0);
        }

        void deleteMax(){
            if(count==0){
                cout<<"Heap is empty\n";
                return;
            }
            int data=arr[0];
            arr[0]=arr[--count];
            percolateDown(0);
            cout<<"Deleted Max element: "<<data<<endl;
        }

        void displayHeap(){
            if(count==0){
                cout<<"Heap is empty\n";
                return;
            }
            cout<<"Heap: ";
            for(int i=0;i<count;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Heap H;
    int choice;

    while(1){
        cout<<"\n0.Exit\n1.Insert\n2.Display\n3.Delete\n4.Get max element\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 0: exit(0);
            case 1: H.insert(); break;
            case 2: H.displayHeap(); break;
            case 3: H.deleteMax(); break;
            case 4: H.getMaxElement(); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}