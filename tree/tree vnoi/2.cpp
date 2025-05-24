#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int n,q;
ll tree[maxn*4];
int a[maxn];
void build(int u , int l , int r){
	if(l == r) tree[u] = a[l];
	else{
		int mid = (l+r)/2;
		build(2*u , l , mid);
		build(2*u + 1 , mid + 1 , r);
		tree[u] = tree[2*u] + tree[2*u+1];
	}
}
void update(int u , int l , int r , int pos , int val){
	if(l == r) tree[u] = val;
	else{
		int mid = (l+r)/2;
		if(pos <= mid){
			update(2*u , l , mid , pos , val);
		}
		else{
			update(2*u+1 , mid + 1 , r , pos , val);
		}
		tree[u] = tree[2*u] + tree[2*u+1];
	}
}
ll sum(int u , int tl , int tr , int l , int r){
	if(l > r) return 0;
	if(l == tl && r == tr) return tree[u];
	int mid = (tl+tr)/2;
	return sum(2*u , tl , mid , l , min(mid,r)) + sum(2*u+1 , mid+1 , tr , max(mid+1,l) , r);
}
int main(){
	cin >> n >> q;
	build(1,1,n);
    while(q--){
        int x; cin>>x;
        if(x == 1){
            int pos,val; cin>>pos>>val;
            update(1,1,n,pos,val);
        }
        else{
            int l , r; cin>>l>>r;
            cout<<sum(1,1,n,l,r)<<endl;
        }
    }
}