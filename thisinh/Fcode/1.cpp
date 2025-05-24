#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int Change(string s){
    int sum = 0;
    for(int i = 0 ; i < s.size() ; i++){
        sum += (s[i] - 48);
        sum *= 10;
    }
    return sum/10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    cout << Change(s);
    
}