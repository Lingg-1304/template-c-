#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int a[maxn], w[maxn], n, t;
int bit[maxn], f[maxn];
void update(int pos, int val){
	for(int i = pos; i<=n; i+= i & (-i)){
		bit[i]+=val;
	}
}
int sum(int pos){
	int kq = 0;
	for(int i = pos; i>=1; i-= i & (-i)){
		kq += bit[i];
	}
	return kq;
}
int main(){
	cin>>n>>t;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	f[1] = a[1];
	for(int i = 2; i <= n; i++){
		f[i] = a[i] - a[i-1];
		update(i,f[i]);
	}
	while(t--){
		int x; cin>>x;
		if(x == 1){
			int l,r,val; cin>>l>>r>>val;
			update(l,val);
			update(r+1,val);
		}
		else{
			int u; cin>>u;
			cout<<bit[u]<<endl;
		}
	}
}
