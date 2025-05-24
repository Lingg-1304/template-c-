#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
bool check(int n){
	for(int i = 2; i <= sqrt(n);i++){
		if(n % i == 0) return  false;
	}
	return n > 1;
}
int bfs(int s,int t){
	set<int> se;
	queue<pair<int,int>> q;
	q.push({s,0});
	se.insert(s);
	while(!q.empty()){
		pair<int,int> k = q.front(); q.pop();
		if(k.fi == t) return k.se;
		int n = k.fi;
		string s = to_string(n), digit = "0123456789";
		for(int i = 0; i < 4; i++){
			char tmp = s[i];
            for(char x : digit){
                s[i] = x;
                if(s[0] != '0'){
                    if(check(stoi(s)) && se.count(stoi(s)) == 0){
                        q.push({stoi(s), k.se + 1});
                        se.insert(stoi(s));
                    }
                }
            }
            s[i] = tmp;
		}
	}
	return 0;
} 
int main(){
	int t; cin>>t;
	while(t--){
		int s,t; cin>>s>>t;
		cout<<bfs(s,t)<<endl;
	}
}
