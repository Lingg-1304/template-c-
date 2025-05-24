#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
bool cmp1(string x,string y){
	if(mp[x] == mp[y]){
		return x<y;
	}
	return mp[x]<mp[y];
}
bool cmp2(string x,string y){
	if(mp[x] == mp[y]){
		return x>y;
	}
	return mp[x]<mp[y];
}
int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string tmp;
	vector<string> v;
	while(cin>>tmp){
		v.push_back(tmp);
		mp[tmp]++;
	}
	sort(v.begin(),v.end(),cmp1);
	auto it1=v.rbegin();
	cout<<*it1<<" "<<mp[*it1];
	cout<<endl;
	sort(v.begin(),v.end(),cmp2);
	auto it2=v.begin();
	cout<<*it2<<" "<<mp[*it2];
}
