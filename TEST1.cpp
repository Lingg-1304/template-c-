#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int n , q;
vector<II> v;
ll val[maxn];

bool cmp(II a , II b){
    return a.fi < b.fi;
}

long long cal(int x , int y){
    return 1ll*x*x + 1ll*y*y;
}

long long xuly(ll r){
    II target = {r, 0};
    if(r < v[0].fi) return 0;
    auto it = upper_bound(v.begin(), v.end(), target, cmp);
    if (it != v.end()) {
        //cout << "Lower bound tại vị trí: " << (it - v.begin()) << ' ';
        return val[(it - v.begin()) - 1];
        //cout << "Giá trị tìm thấy: (" << it->first << ", " << it->second << ")" << endl;
    } else {
        return val[n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        int x , y , ww; cin >> x >> y >> ww;
        v.push_back({cal(x,y),ww});
    }   
    
    sort(v.begin(),v.end(),cmp);

    val[0] = v[0].se;
    for(int i = 1 ; i < n ; i++){
        val[i]= val[i-1] + v[i].se;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << val[i] << ' ';
    // }
    
    // cout << endl;

    for(int i = 0 ; i < q ; i++){
        int r; cin >> r;
        cout << xuly(1ll*r*r) << endl;
    }

}