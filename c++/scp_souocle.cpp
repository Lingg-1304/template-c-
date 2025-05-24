#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll n){
	int t=sqrt(n);
	if(1ll*t*t==n) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    ll n;
    cin>>n;
    if(check(n)) cout<<"YES";
    else cout<<"NO";
}
