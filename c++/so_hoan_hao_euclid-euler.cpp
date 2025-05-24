#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[10000001];
void sang(){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=sqrt(1e7);i++){
        for(int j=i*i;j<=1e7;j+=i){
            dp[j]=1;
        }
    }
}
bool nt(int n){
	if(n==0||n==1) return false;
	if(n==2) return true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

bool check(ll n){
	for(int i=2;i<=1e7;i++){
		int k=pow(2,i)-1;
        if(dp[i]==0 && nt(k)){
        	if(n == 1ll*k*pow(2,i-1)){
        		return true;
			}
		}
    }
    return false;
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    sang();
    ll n;
    cin>>n;
    if(check(n)) cout<<"YES";
    else cout<<"NO";
}
