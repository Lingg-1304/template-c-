#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("inp.txt","r",stdin);
// 	freopen("out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	int l,k;
	while(k<m){
		if(a[l]<=a[k]){
			cout<<a[l]<<" ";
			l++;
		}
		else if(a[k]<=a[l]){
			cout<<a[k]<<" ";
			k++;
		}
	}
}
