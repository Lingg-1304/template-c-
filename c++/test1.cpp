#include<bits/stdc++.h>
using namespace std;
bool ngto(int n){
	if(n==1) return false;
	if(n==2) return true;
	if(n==0) return false;
    for(int i=2;i<=sqrt(n);i++){
    	if(n%i==0) return false;
	}
	return true;
}
int main(){
	map<int,int> dem;
	map<int,int> d;
	int n;
	vector<int> v;
	while(cin>>n){
		v.push_back(n);
	}
	for(int x:v){
		if(ngto(x)){
			d[x]++;
		}
	}
	for(int x:v){
		if(dem[x]==0&&d[x]>0){
			cout<<x<<" "<<d[x]<<endl;
			dem[x]++;
		}
	}
}
