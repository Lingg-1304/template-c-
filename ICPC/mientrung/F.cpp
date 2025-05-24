#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<ll,ll> II;
typedef pair <II,int> III;
int mod = 1e9+7;

void solve(int n){
    int ans = 0;
    vector<int> v[10005];
    int a[4]; cin >> a[1] >> a[2] >> a[3];
    for(int i = 1 ; i <= 3 ; i++){
        int k; cin >> k;
        for(int j = 1 ; j <= k ; j++){
            int x; cin >> x;
            v[x].push_back(i);
        }
    }
    for(int i = 1; i <= n ; i++){
        cout << i << ": ";
        for(int x : v[i]) cout << x << ' ';
        cout << endl;
    }

    vector<int> v2 , v3;

    for(int i = 1 ; i <= n ; i++){
        if(v[i].size() == 1){
            if(a[v[i][0]] >= 1){
                a[v[i][0]]--;
                ans++;
            }
        }
        else if(v[i].size() == 2){
            v2.push_back(i);
        }
        else{
            v3.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;
        solve(n);
    }
    
}