#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1e5 + 5;
int n , q;
ll bit[maxn] , a[maxn];
void update(int pos , int val){
	for(int i = pos ; i <= n ; i += i & (-i)){
		bit[i] += val;
	}
}
ll get(int pos){
	ll kq = 0;
	for(int i = pos ; i >= 1 ; i -= i & (-i)){
		kq += bit[i];
	}
	return kq;
}
int main(){
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		update(i,a[i]);
	}
	while(q--){
		int x; cin >> x;
		if(x == 1){
			int pos , val; cin >> pos >> val;
			update(pos , val);
		}
		else{
			int l,r; cin >> l >> r;
			cout<<get(r) - get(l-1)<<endl;
		}
	}
}