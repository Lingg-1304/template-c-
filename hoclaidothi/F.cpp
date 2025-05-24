#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int n,m;
vector<int> adj[maxn];
bool visited[maxn];

void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int k = q.front(); q.pop();
        visited[k] = true;
        for(int x : adj[k]){
			if(!visited[x]){
				cout<<x<<" ";
				q.push(x);
				visited[x] = true;
			}
		}
    }
}

int Change(string s){
    int sz = s.size();
    int sum = 0;
    for(int i = 0 ; i < sz ; i++){
        sum += s[i] - '0';
        sum*=10;
    }
    //cout  << sum << endl;
    return sum/10;
}

void xuly(string s , int dinh){
    string tmp = "";
    vector<string> res;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' '){
            res.push_back(tmp);
            tmp = "";
        }
        else{
            tmp += s[i];
        }
    }
    res.push_back(tmp);

    for(string x : res){
        cout << x << ' ';
        int u = Change(x); 
        adj[dinh].push_back(u);
        adj[u].push_back(dinh);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(visited , false , sizeof(visited));

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        string s;
        getline(cin,s);
        //cout << s << endl;
        if(s[0] != '(') xuly(s , i);
    }
    int t;
    cin >> t;

    // for(int i = 1 ; i <= n ; i++){
    //     for(int x : adj[i]){
    //         cout << x <<' ';
    //     }
    //     cout << endl;
    // }
    
}