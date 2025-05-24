#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<ll,ll> II;
typedef pair <int,II> III;
int mod = 1e9+7;
bool BS(int a[],int n, int x){
	int l=0 , r=n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(x == a[mid]) return true;
		else if(x < a[mid]){
			r=mid-1;
		}
		else l=mid+1;
	}
	return false;
}
int main(){
    fast;
    int n,x; cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    if(BS(a,n,x)) cout<<"YES";
    else cout<<"FALSE";
    return 0;
}
