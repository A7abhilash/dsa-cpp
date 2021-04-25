#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
    srand(time(0));

	int n,e,pos=-1,count=0;

	cout<<"Enter the size: ";
	cin>>n;

	int arr[n], first=0,last=n-1,mid;

	arr[0]=rand() % 100;
	for(int i=1;i<n;i++){
		arr[i]=arr[i-1] + rand() % 100;
        //This type of assignment makes the i+1'th element to be more the i'th element always.
	}

	cout<<"Array elements are:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;

	cout<<"Enter the element to be searched: ";
	cin>>e;

	while(first<=last){
		count++;
		mid=(first+last)/2;
		if(arr[mid]==e){
				pos=mid+1;
				break;
		}
		if(arr[mid]<=e) first=mid+1;
		else last=mid-1;
	}

	if(pos==-1){
		cout<<"Element not found\n";
	}else{
        cout<<"Element found at position: "<<pos<<"\nCount: "<<count<<endl;
	}
    return 0;
}