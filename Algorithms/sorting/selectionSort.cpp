#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
	int count=0,i,j; 

	for(i=0;i<n-1;i++){
		int min=i;
		
		for(j=i+1;j<n;j++){
			count++;
			if(arr[j]<arr[min]){
				min=j;
            }
		}
		
		if(i!=min){
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}

	cout<<"Sorted Array: \n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\nCount: "<<count<<endl;
}

int main(){
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

	selectionSort(arr,n);
	
	return 0;
}


