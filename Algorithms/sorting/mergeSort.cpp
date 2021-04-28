#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void merge(int arr[],int left,int mid,int right){
	int i=left;		        // starting index for left subarray
	int j=mid+1;	        // starting index for right subarray
	int k=left;		        // starting index for temporary array
	int temp[left+right+1];	//temporary array
	
	while(i<=mid && j<=right){
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			i++;
		}
		else{
			temp[k]=arr[j];
			j++;
		}
        k++;
	}
	
	while(i<=mid){
		temp[k]=arr[i];
		k++;
		i++;
	}
	while(j<=right){
		temp[k]=arr[j];
		k++;
		j++;
	}
	
	int s, n=right+1;
	for(s=left;s<n;s++)
		arr[s]=temp[s];
}

void mergeSort(int arr[], int left,int right){
	if(left<right){		// to check whether the sub-array contains single element or not
		int mid=(left+right)/2;
		
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		
		merge(arr,left,mid,right);
	}
}

int main(){
	srand(time(0));
	int i,n;

	cout<<"Enter the size:\n";
	cin>>n;
	
	int arr[n];
	for(i=0;i<n;i++){
		arr[i]=rand() % 20000;
	}
		
	cout<<"Array elements:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	mergeSort(arr,0,n-1);
	
	cout<<"Sorted Array elements:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
		
	return 0;
}
