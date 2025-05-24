#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int a[maxn];
int n;
int tree[4*maxn];
void build(int v,int l,int r){
    if(l == r) tree[v] = a[l];
    else{
        int mid = (l+r)/2;
        build(2*v , l, mid);
        build(2*v+1,mid+1,r);
        tree[v] = max(tree[2*v],tree[2*v+1]);
    }
}
int mint(int u,int tl,int tr,int l,int r){
    if(l > r) return -1e9;
    if(l == tl && r == tr) return tree[u];
    int mid = (tl + tr)/2;
    return max( mint(2*u , tl , mid , l , min(r,mid) ) , mint(2*u+1 , mid+1 , tr , max(l,mid+1) , r) );
}

void update(int u, int l, int r, int pos, int val){
	if(l == r) tree[u] = val;
	else{
		int mid = (l+r)/2;
		if(pos <= mid){
			update(2*u, l, mid, pos, val);
		}
		else{
			update(2*u+1, mid+1, r, pos, val);
		}
		tree[u] = max(tree[2*u] , tree[2*u+1]);
	}
}
int main(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	build(1,1,n);
	int t; cin>>t;
	while(t--){
		int k; cin>>k;
		if(k == 1){
			int pos,val; cin>>pos>>val;
			update(1 , 1 , n , pos , val);
		}
		else{
			int l , r; cin>>l>>r;
			cout<<mint(1 , 1 , n , l , r)<<endl;
		}
	}
}