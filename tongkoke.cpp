#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int f[1000000][2];
int main(){
    fast;
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
    	f[i][0]=max(f[i-1][1],f[i-1][0]);
    	f[i][1]=a[i]+f[i-1][0];
	}
	cout<<max(f[n-1][0],f[n-1][1]);
}
