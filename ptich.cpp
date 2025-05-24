#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    ll n;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++){
    	int dem=0;
    	if(n%i==0){
    	    while(n%i==0){
    		    n/=i;
    		    dem++;
		    }
		}
        if(dem>0) cout<<i<<"^";dem;
        if(n>1) cout<<" * ";
	}
    return 0;
}
