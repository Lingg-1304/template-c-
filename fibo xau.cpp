#include <bits/stdc++.h>
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
ll f[100];
void Try(ll i,ll k){
	if(i==1) cout<<"A";
	else if(i==2) cout<<"B";
	else if(k<=f[i-2]){
		Try(i-2,k);
	}
	else{
		Try(i-1,k-f[i-2]);
	}
}
int main(){
    fast;
    f[1]=1;
    f[2]=1;
    ll n,k; cin>>n>>k;
    for(int i=3;i<=92;i++){
    	f[i]=f[i-1]+f[i-2];
	}
	Try(n,k);
}
