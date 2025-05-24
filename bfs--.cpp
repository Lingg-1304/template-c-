#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool nt(ll n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
int bfs(int s, int t){
    queue<pair<int, int>> q;
    //trang thai 1 so, so luong thao tac s =>
    q.push({s, 0});
    set<int> se;
    while(!q.empty()){
        pair<int, int> x1 = q.front(); q.pop();
        if(x1.first == t)
            return x1.second;
        int n = x1.first; // 1 chu so cua n thanh so khac

        string s = to_string(n), digit = "0123456789";
        for(int i = 0; i < 4; i++){
            //s[i] => so khac
            char tmp = s[i];
            for(char x : digit){
                s[i] = x;
                if(s[0] != '0'){
                    if(nt(stoi(s)) && se.count(stoi(s)) == 0){
                        q.push({stoi(s), x1.second + 1});
                        se.insert(stoi(s));
                    }
                }
            }
            s[i] = tmp;
        }
    }
    return -1;
}

int main(){
    int t; cin >> t;
    while(t--){
        int S, T;
        cin >> S >> T;
        cout << bfs(S, T) << endl;
    }
}
