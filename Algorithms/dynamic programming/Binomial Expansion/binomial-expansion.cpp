#include<iostream>
using namespace std;

int min(int a,int b){
	return a > b ? b : a;
}

int findBinomialCoefficient(int n,int k){
	int C[n + 1][k + 1];
	int i, j;

	for (i = 0; i <= n; i++){
		for (j = 0; j <= min(i,k); j++){
			C[i][j] = 0;
		}
	}

	for (i = 0; i <= n; i++){
		for (j = 0; j <= min(i,k); j++){
			if(j==0 || j==i){
				C[i][j] = 1;
			}else{
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
	return C[n][k];
}

int main(){
	int n, k;

	cout << "Enter the value of N: ";
	cin >> n;

	cout << "Enter the value of K: ";
	cin >> k;

	if(n>=k){
		cout << "Coeff Value: " << findBinomialCoefficient(n, k) << endl;
	}else{
		cout << "Invalid inputs\n";
	}

	return 0;
}