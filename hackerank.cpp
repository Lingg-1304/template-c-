#include <bits/stdc++.h>
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0)
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
using ll = long long;
int main(){
    fast;
    ll n;
	int kq=-10,dem=0; cin>>n;
    ll a[n];
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    int l=0;
    for(int r=0;r<n;r++){
    	mp[a[r]]++;
    	while(mp[a[r]]>1){
    		mp[a[l]]--;
    		l++;
		}
		kq=max(r-l+1,kq);
	}
    cout<<kq;
}
