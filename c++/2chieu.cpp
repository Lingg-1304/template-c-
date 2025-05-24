#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1]={0};
	for(int i=1;i<=n;i++){
		for(int	j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int	j=1;j<=m;j++){
			if(a[i][j] > a[i-1][j] && a[i][j] > a[i-1][j-1] && a[i-1][j+1] > a[i-1][j] &&)
		}
	}
}
