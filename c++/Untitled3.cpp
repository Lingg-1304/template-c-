#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s; cin>>n>>s;
	int a[n],f[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f[0]=1;
	for(int i=s;i>=0;i--){
		for(int j=0;j<n;j++){
			if(f[i-a[j]] > 0)
		}
	}
}
