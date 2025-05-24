#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	int n,dem=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=i){
				if(gcd(a[i],a[j])==1){
					dem++;
				}
			}
		}
	}
	cout<<dem/2;
}
