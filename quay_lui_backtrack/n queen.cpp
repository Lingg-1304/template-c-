#include<bits/stdc++.h>
using namespace std;
int n, cot[100],xuoi[100],nguoc[100],dem=0;
int x[100],a[100][100];
long long maxc=-1e9;
void Try(int i){
	for(int j=1;j<=n;j++){
		if(cot[j]==0 && xuoi[i-j+n] ==0 && nguoc[i+j-1] == 0){
			x[i]=j;
			cot[j] = 1; xuoi[i-j+n] = 1; nguoc[i+j-1] = 1;
			if(i == n){
				long long s=0;
				for(int k=1;k<=n;k++){
					s+=a[k][x[k]];
				}
				maxc=max(maxc,s);
			}
			else Try(i+1);
			cot[j] = 0; xuoi[i-j+n]=0; nguoc[i+j-1]=0;
		}
	}
}
int main(){
	int n=8;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cin>>a[i][j];
		}
	}
	Try(1);
	cout<<maxc;
}
