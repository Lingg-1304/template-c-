#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define II pair<int,int>
#define fi first
#define se second
int mod=1e9+7;
int main(){
	int f[10001];
	memset(f,1e6,sizeof(f));
	int n; cin>>n;
	for(int i=1;i<=sqrt(n);i++){
		f[i*i]=1;
		for(int j=i*i+1;j<=n;j++){
			if(f[j-i*i]>0) f[j]=min(f[j-i*i]+1,f[j]);
		}
		//for(int k=1;k<=n;k++) cout<<f[k]<<" ";
	}
	cout<<f[n];
}
