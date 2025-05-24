#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

void Solve(){
    int a,b,c; cin >> a >> b >> c;
    if(c == 0){
        cout << "NO CURVE";
    }
    else if(c > 0){
        cout << "CURVE UP";
    }
    else if(c < 0){
        cout << "CURVE DOWN";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test; cin >> test;
    while(test--){
        Solve();
    }
}