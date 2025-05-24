#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 2e5 + 5;
ll a[maxn] , tree[maxn * 4] ;
int n;
void build(int id , int l , int r){
	if(l == r) tree[id] = a[l];
	else{
		int mid = (l+r)/2;
		build(2*id , l , mid);
		build(2*id+1 , mid + 1 , r);
		tree[id] = min(tree[2*id] , tree[2*id+1]);
	}
}
void update(int id , int l , int r , int pos , ll val){
	if(pos < l || pos > r) return;
	if(l == r){
		tree[id] = val;
		return;
	}
	int mid = (l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	tree[id] = min(tree[2*id] , tree[2*id+1]);
}
ll get(int id , int l , int r ,int u , int v){
    if(r < u || v < l) return 1e9;
    if(u <= l && r <= v) return tree[id];
    int mid = (l+r)/2;
	int x = get(2*id,l,mid,u,v);
	int y = get(2*id+1,mid+1,r,u,v);
	return min(x,y);
}	
int main(){
	int q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	build(1,1,n);
	while(q--){
		int x; cin >> x;
		if(x == 1){
			int pos ;ll val; cin >> pos >> val;
			update(1,1,n,pos,val);
		}
		else{
			int l , r; cin >> l >> r;
			cout<<get(1,1,n,l,r)<<endl;
		}
	}

}