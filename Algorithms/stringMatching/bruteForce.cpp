#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void stringMatch(char T[],char P[]){
    int m=strlen(P);
    int n=strlen(T);
    int pos=-1,i,j;
    
    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            if(P[j]==T[i+j]) continue;
            else break;
        }
        if(j==m){
            pos= i;
            break;
        }
    }
    if(pos!=-1){
		cout << "String pattern found from position: "<<pos+1<<" to "<<pos+m<<endl;
    }else{
		cout << "Pattern match not found!!!\n";
	}
}

int main(){
    char text[100],pattern[100];

	cout << "Enter the text: ";
	// cin >> text;
	gets(text); 

	cout << "Enter the pattern to be matched: ";
	cin >> pattern;

	stringMatch(text,pattern);

    return 0;
}
