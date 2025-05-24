#include<bits/stdc++.h>
using namespace std;
int sum(int n){
	int res = 0;
	for(int i = 1 ; i <= sqrt(n) ; i++){
		if(n % i == 0){
			if(i != n/i) res += i + n/i;
			else res += i;
		}
	}
	res -= n;
	return res;
}
int main(){
	int dem = 0;
	int a,b; cin>>a>>b;
	for(int i = a ; i <= b ; i++){
		if(sum(i) > i) dem++;
	}
	cout<<dem;
}
