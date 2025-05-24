#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k; cin>>n>>k;
	int f[n+1];
	for(int i=0;i<k;i++) f[i]=1;
	for(int i=2;i<=n;i++){
		f[i]=0;
		for(int j=1;j<=i;j++){
			f[i]+=f[i-j];
		}
	}
	cout<<f[n];
}
