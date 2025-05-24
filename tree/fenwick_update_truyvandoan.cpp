#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int n,a[maxn];
vector<int> bit1, bit2;
/* 
    Các hàm update và sum cần làm việc trên một trong hai BIT riêng biệt.
    Sử dụng vector cho phép truyền BIT vào làm việc trực tiếp dễ dàng hơn.
*/

void updatePoint(vector<int>& b, int u, int v) {
    int idx = u;
    while (idx <= n) {
        b[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateRange(int l, int r, int v) {
    updatePoint(bit1, l, (n - l + 1) * v);
    updatePoint(bit1, r + 1, -(n - r) * v);
    updatePoint(bit2, l, v);
    updatePoint(bit2, r + 1, -v);
}

int getSumOnBIT(vector<int>& b, int u) {
    int idx = u, ans = 0;
    while (idx > 0) {
        ans += b[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

int prefixSum(int u) {
    return getSumOnBIT(bit1, u) - getSumOnBIT(bit2, u) * (n - u);
}

int rangeSum(int l, int r) {
    return prefixSum(r) - prefixSum(l - 1);
}
int main(){
	int q;
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		updatePoint(bit1,i,a[i]);
	}
	while(q--){
		int x; cin >> x;
		if(x == 2){
			int l , r; cin >> l >> r;
			cout<<rangeSum(l,r)<<endl;
		}
		else{
			int l , r , v; cin >> l >> r >> v;
			updateRange(l,r,v);
		}
	}
}
