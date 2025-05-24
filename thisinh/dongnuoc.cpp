#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e5;

int a[maxn] , b[maxn] , c[maxn] , d[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    int ans = 0;

    int lmax = a[1] , rmax = a[n];
    int l = 1 , r = n;
    while(l != r){
        if(a[l] <= a[r]){
            if(a[l] > lmax){
                lmax = a[l];
            }
            else{
                ans += lmax - a[l];
            }
            l++;
        }
        else{
            if(a[r] > rmax){
                rmax = a[r];
            }
            else{
                ans += rmax - a[r];
            }
            r--;
        }
    }
    cout << ans;
}