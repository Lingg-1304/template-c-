#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 2e5 + 5;
int n , a[maxn];

map<int,vector<int>> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    int cnt = 0;

    for(int i = 1 ; i <= n ; i++){

        if(mp[a[i]%23].size() > 0){
            vector<int> v = mp[a[i]%23];
            auto pos = upper_bound(v.begin() , v.end() , i - 5);
            if(pos != v.end()){
                cout << a[i] << ' ' <<  a[pos - v.begin()] << endl;
                cnt += (pos - v.begin());
            }
        }

        mp[a[i] % 23].push_back(i);
    }
    cout << cnt;
}