#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e6 + 5;
int n;
vector<II> hcn[1005];
vector<II> Point;

bool cmp(II a , II b){
    return a.se < b.se;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        int x , y ; cin >> x >> y;
        Point.push_back({x,y});
        int o = x/1e3;
        hcn[o + 2].push_back({x,y});
    }

    for(int i = 2 ; i <= 1005 ; i++){
        sort(hcn[i].begin() , hcn[i].end());
    }

    // for(II x : hcn[1]){
    //     cout << x.fi << ' ' << x.se << endl;
    // }

    int ans = 0;

    II* itd ; II* itc;

    for(int i = 2 ; i <= 1005 ; i++){
        if(i % 2 == 0){
            for(int pos = 0 ; pos < hcn[i].size() - 1 ; pos++){
                ans += abs(hcn[i][pos].fi - hcn[i][pos+1].fi) + abs(hcn[i][pos].se - hcn[i][pos+1].se);
            }
            if(hcn[i+1].size() > 0){
                II* it1 = &hcn[i].front();
                II* it2 = &hcn[i+1].front();

                II P1 = *it1 , P2 = *it2;
                ans += abs(P1.fi - P2.fi) + abs(P1.se - P2.se);
                cout << ans;
            }
            else{
                itc = &hcn[i].front();
            }
        }
        else{
            for(int pos = hcn[i].size() - 1 ; pos > 0 ; pos--){
                ans += abs(hcn[i][pos].fi - hcn[i][pos-1].fi) + abs(hcn[i][pos].se - hcn[i][pos-1].se);
            }
            if(hcn[i+1].size() > 0){
                II* it1 = &hcn[i].back();
                II* it2 = &hcn[i+1].back();

                II P1 = *it1 , P2 = *it2;
                ans += abs(P1.fi - P2.fi) + abs(P1.se - P2.se);
            }
            else{
                itc = &hcn[i].back();
            }
        }
    }

    cout << ans;

    for(int i = 2 ; i <= 1005 ; i++){
        if(hcn[i].size() > 0){
            if(i % 2 == 0){
                itd = &hcn[i].front();
            }
            else{
                itd = &hcn[i].back();
            }
            break;
        }
    }
    II P1 = *itd , P2 = *itc;
    ans += abs(P1.fi - P2.fi) + abs(P1.se - P2.se);

    cout << ans;
}