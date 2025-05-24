#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int a[maxn], w[maxn], n;
int bit[maxn];
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
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		update(i,a[i]);
	}
	cout<<sum(6) - sum(4);
}
