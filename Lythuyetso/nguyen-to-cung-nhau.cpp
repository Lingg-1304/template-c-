#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("divinat.inp","r",stdin);
	// freopen("divinat.out","w",stdout);
	int n; cin>>n;
	int k = n;
	for(int i = 2 ; i <= sqrt(k) ; i++){
		if(k % i == 0) v.push_back(i);
		while(k % i == 0) k /= i;
	}
	if(k != 1) v.push_back(k);
	long long kq = n , c = 1;
	int sz = v.size();
	for(int i = 0 ; i < sz ; i++){
		int x = v[i];
		kq *= x - 1;
		c *= x;
	}
	cout<< kq/c;
}