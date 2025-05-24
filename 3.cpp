#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int a[105];
int f[1000001];
int main(){
    fast;
    int n,s; cin>>n>>s;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	f[0]=1;
    for(int j=0;j<n;j++){
    	for(int i=a[j];i<=s;i++){
    		if(f[i-a[j]]>0){
    			f[i]+=f[i-a[j]]%mod;
			}
		}
	}
    cout<<f[s]%mod;
}
