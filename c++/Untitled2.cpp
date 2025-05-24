#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool nt(ll n){
	if(n==0||n==1) return false;
	if(n==2) return true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    ll n,kq=0; cin>>n;
    if(nt(n)) cout<<n-1;
    else{
    ll res=n;
    vector<int> v;
    for(int i=2;i<=sqrt(n);i++){
    	if(n%i==0) v.push_back(i);
    	while(n%i==0){
    		n/=i;
		}
	}
	if(n!=1) v.push_back(n);
	for(int x:v){
		ll p=1,k=1;
		while(p<res){
			kq++;
			p=x*k;
			k++;
		}
	}
	cout<<res-kq+1;
	}
}
