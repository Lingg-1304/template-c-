#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,t;
int tree[maxn*4] , a[maxn];
void build(int u,int l,int r){
	if(l == r) tree[u] = a[l];
	else{
		int mid = (l+r)/2;
		build(2*u , l , mid);
		build(2*u + 1, mid + 1, r);
		tree[u] = min(tree[2*u] , tree[2*u+1]);
	}
}
int mint(int u, int tl, int tr, int l, int r){
	if(l > r) return 1e9;
	if(l == tl && r == tr) return tree[u];
	int mid = (tl+tr)/2;
	int a = mint(2*u , tl , mid , l , min(mid,r));
	int b = mint(2*u + 1, mid+1, tr, max(mid+1,l),r);
	return min(a,b);
}
int main(){
	freopen("hi.inp","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>n>>t;
	for(int i = 1; i <= n; i++) cin>>a[i];
	build(1,1,n);
	while(t--){
		int l,r; cin>>l>>r;
		cout<<mint(1,1,n,l,r)<<endl;
	}
}
