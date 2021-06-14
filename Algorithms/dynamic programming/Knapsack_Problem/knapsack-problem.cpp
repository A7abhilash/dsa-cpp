#include<iostream>
using namespace std;

int max(int a,int b){
	return a > b ? a : b;
}

int knapSack(int i,int j,int price[],int weights[]){
	if(i==0||j==0){
		return 0;
	}

	if(weights[i-1]>j){
		return knapSack(i - 1, j, price, weights);
	}

	return max(knapSack(i - 1, j, price, weights), price[i - 1] + knapSack(i - 1, j - weights[i - 1], price, weights));
}

int main(){
	int n;
	cout << "Enter the no. of items: ";
	cin >> n;

	int price[n], weights[n];
	cout << "Enter the weight and it's price:\n";
	for (int i = 0; i < n; i++){
		cout << "Item " << (i + 1) << ": ";
		cin >> weights[i];
		cin >> price[i];
	}

	int M;
	cout << "Enter the max capacity of the knapsack: ";
	cin >> M;

	cout << "Max Profit: " << knapSack(n, M, price, weights) << endl;
}