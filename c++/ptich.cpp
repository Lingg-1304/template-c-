#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
using ll = long long;
int tong(int n){
	int s=0;
	while(n>0){
		s+=n%10;
		n/=10;
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
    	while(n%i==0){
    		cout<<i<<" ";
    		n/=i;
		}
	}
}
