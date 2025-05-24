#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n , a[maxn] , tree[maxn * 4];
void build(int id , int l , int r){
	if(l == r) tree[id] = a[l];
	else{
		int mid = (l+r)/2;
		build(2*id,l,mid);
		build(2*id+1,mid+1,r);
		tree[id] = max(tree[2*id] , tree[2*id+1]);
	}
}
void update(int id , int l , int r , int pos , int val){
	if(l == r){
		tree[id] = val;
		return;
	}
	if(pos < l || pos > r) return;
	
	int mid = (l+r)/2;
	update(2*id , l , mid , pos , val);
	update(2*id + 1 , mid + 1 , r , pos , val);
	tree[id] = max(tree[2*id] , tree[2*id+1]);
}
int get(int id , int l , int r , int u , int v){
	if(l > v || r < u) return -1e9;
	if(l >= u && r <= v) return tree[id];
	int mid = (l+r)/2;
	int x = get(2*id , l , mid , u , v);
	int y = get(2*id + 1 , mid + 1 , r , u , v);
	return max(x,y);
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	build(1,1,n);
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		if(x == 0){
			int pos , val; cin >> pos >> val;
			update(1,1,n,pos,val);
		}
		else{
			int l,r; cin >> l >> r;
			cout<<get(1,1,n,l,r)<<endl;
		}
	}
}