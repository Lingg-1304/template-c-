#include <bits/stdc++.h>
//#define ff first;
//#define ss second;
#define fast ios::sync_with_stdio(0)
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
using ll=long long;
int main(){
    fast;
    multiset<int> ms;
    int n,m;
	ll res=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	int x; cin>>x;
    	ms.insert(x);
	}
	for(int i=0;i<m;i++){
		int x; cin>>x;
		auto it=ms.upper_bound(x);
		if(it==ms.begin()){
			cout<<"-1"<<endl;
		}
		else{
			it--;
			cout<<*it<<endl;
			ms.erase(it);
		}
	}
    
}
