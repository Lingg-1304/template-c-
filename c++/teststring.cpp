#include<bits/stdc++.h>
using namespace std;
bool check(string s){
	int i=0,j=s.size()-1,mid=s.size()/2-1;
	while(i<=mid){
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}
bool cmp(string x,string y){
	return x.size()<y.size();
}
int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string tmp;
	vector<string> v;
	while(cin>>tmp){
		if(check(tmp)){
			v.push_back(tmp);
		}
	}
	stable_sort(v.begin(),v.end(),cmp);
	for(string x:v) cout<<x<<" ";
}
