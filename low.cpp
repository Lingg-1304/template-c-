#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<float,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int n , q;
vector<II> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v.push_back({1,5 , 2});
    v.push_back({2,5 , 2});
    v.push_back({4,5 , 2});
    v.push_back({6,5 , 2});
    v.push_back({9,5 , 2});

    cout << *lower_bound(v.begin() , v.end() , 6);
    return 0;
}