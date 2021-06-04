#include<iostream>
using namespace std;

int min(int a,int b){
	return a > b ? b : a;
}

int main(){
	int i, j, k, n;

	cout << "Enter the no. of vertices: ";
	cin >> n;

	int A[n][n], D[n][n];
	cout << "Enter the adjacency matrix(with the weights corresponding edges)of the graph\n";
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cin >> A[i][j];
			D[i][j] = A[i][j];
		}
	}

	//all pair shortest path 
	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	cout << "All pairs shortest path: Adjacency matrix(with the weights corresponding edges) of the graph:\n";
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cout << D[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}