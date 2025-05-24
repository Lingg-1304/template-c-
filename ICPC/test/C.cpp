#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 2e6 + 5;

void Solve(){
    int cnt[1000];
    ll ans = 0;
    vector<int> v , pos;
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cnt[i] = 0;
        int x;
        cin >> x;
        v.push_back(x);
    }

    //for(int x : v) cout << x <<' ';

    int sz = v.size();
    pos.push_back(0);

    for(int i = 0 ; i < sz ; i++){
        cnt[v[i]]++;
        if(cnt[v[i]] == 2){
            pos.push_back(i-1);
            cnt[v[i]] = 0;
        }
    }
    pos.push_back(n);

    for(int x : pos) cout << x <<' ';

    for(int i = 0 ; i < pos.size() - 1 ; i++){
        int k = pos[i + 1] - pos[i];
        ans += 1ll*(k+1)*k/2;
    }

    cout << ans;
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