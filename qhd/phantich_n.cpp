#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[105][105];
int main(){
	cin>>n>>m;
	for(int i=0;i<=m;i++) f[i][0]=1;
	for(int i=0;i<=n;i++){
		f[0][i]=0;
		f[1][i]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j<i){
				f[i][j]=f[i-1][j];
			}
			if(j>=i){
				f[i][j]=f[i-1][j]+f[i][j-i];
			}
		}
	}
	cout<<f[m][n];
}