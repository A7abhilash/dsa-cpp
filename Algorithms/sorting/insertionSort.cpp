#include<iostream>
#include<time.h>
using namespace std;

void insertionSort(int arr[],int n){
	int i,j,key,count=0;
	
	for(i=0;i<n;i++){
		key=arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
            count++;
		}
		
		arr[j+1]=key;
	}

	cout<<"Sorted Array: \n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\nCount: "<<count<<endl;
}

int main(){
	srand(time(0));
	int i,n;
	
	cout<<"Enter the size: \n";	
	cin>>n;
	
	int arr[n];
	for(i=0;i<n;i++){
		arr[i]=rand() % 20000;
	}
		
	cout<<"Array elements: \n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	insertionSort(arr,n);

	return 0;
}
