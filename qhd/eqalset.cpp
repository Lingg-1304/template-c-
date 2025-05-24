#include<bits/stdc++.h>
using namespace std;
int f[62630];
int mod = 1e9 + 7;
int main(){
	int n; cin>>n;
	int sum = n*(n+1)/2;
	if(sum % 2 == 1){
		cout<<"0";
		return 0;
	}
	else{
		sum/=2;
		f[0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=i;j--){
				if(f[j-i] > 0){
					if(f[j] == 0) f[j] = f[j-i];
					else f[j]++; 
					f[j]%=mod;
				}
			}
			for(int i=1;i<=sum;i++) cout<<f[i]<<" ";
			cout<<endl;
		}
		cout<<f[sum];
	}
	
}
