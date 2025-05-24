#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<ll,ll>
const int maxn = 2e5 + 5;
struct Node
{
	ll max1 , max2;
};
Node tree[maxn * 4];
ll a[maxn];
int n;

Node xuly(Node x , Node y){
	ll z[4];
	z[0] = x.max1 , z[1] = x.max2 , z[2] = y.max1 , z[3] = y.max2;
	sort(z,z+4);
	Node o;
	o.max1 = z[2] , o.max2 = z[3];
	return o;
}

void build(int id , int l , int r){
	if(l == r){
		tree[id].max1 = a[l];
		tree[id].max2 = 1;
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	tree[id] = xuly(tree[2*id] , tree[2*id+1]);
}

void update(int id , int l , int r , int pos , ll val){
	if(l == r){
		tree[id].max1 = val;
		tree[id].max2 = 1;
		return;
	}
	if(pos < l || pos > r){
		return;
	}

	int mid = (l+r)/2;
	if(pos <= mid) update(2*id , l , mid , pos , val);
	else if(pos >= mid + 1) update(2*id + 1 , mid + 1 , r , pos , val);

	tree[id] = xuly(tree[2*id] , tree[2*id+1]);
}

Node get(int id , int l , int r , int u , int v){
	if(r < u || l > v){
		Node oo;
		oo.max1 = oo.max2 = 1;
		return oo; 
	}
	if(l >= u && r <= v){
		return tree[id];
	}
	int mid = (l+r)/2;
	Node x = get(2*id , l , mid , u , v);
	Node y = get(2*id + 1 , mid + 1 , r , u , v);
	return xuly(x,y);
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	build(1,1,n);
	int q; cin >> q;
	while(q--){
		int t; cin >> t;
		if(t == 0){
			int pos; ll val; cin >> pos >> val;
			update(1,1,n,pos,val);
		}
		else{
			int l , r , mod; cin >> l >> r >> mod;
			Node kq = get(1,1,n,l,r);
			cout<<((kq.max1 % mod)*(kq.max2 % mod)) % mod<<endl;
		}
	}
}	
