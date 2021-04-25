#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(0));
	int n,e,pos=-1,count=0;

	cout<<"Enter the size: ";
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		arr[i]=rand() % 2000;
	}

	cout<<"Array elements are:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;

	cout<<"Enter the element to be searched: ";
	cin>>e;

	for(int i=0;i<n;i++){
		count++;
		if(arr[i]==e){
				pos=i+1;
				break;
		}
	}

	if(pos==-1){
		cout<<"Element not found\n";
	}else{
        cout<<"Element found at position: "<<pos<<"\nCount: "<<count<<endl;
	}
    return 0;
}