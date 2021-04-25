#include<iostream>
#include<time.h>
using namespace std;

void bubbleSort(int arr[],int n){
	int i,j;				
	int count=0;

	for(i=1;i<n-1;i++){
		for(j=i;j>=0;j--){
			count++;
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
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
	
	bubbleSort(arr,n);
	
	return 0;
}
