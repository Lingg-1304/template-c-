#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 50005;

int n;
int dp[maxn];
vector<int> v;
void sang(){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=sqrt(50000);i++){
        for(int j=i*i;j<=50000;j+=i){
            dp[j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nt;
    cin >> n;
    sang();
    for(int i = n - 1 ; i >= 2 ; i--){
        if(dp[i] == 0){
            nt = i;
            break;
        }
    }
    int cnt = 0;
    for(int i = nt ; i >= 2 ; i--){
        if(dp[i] == 0){
            v.push_back(i);
        }
    }

    for(int i = n - 1 ; i >= 2 ; i--){
        for(int j = 0 ; j < v.size() ; j++){
            if(i >= v[j]){
                cnt += v.size() - j;
                break;
            }
        }
    }

    ll c2;
    ll ni = 1;
    ll ni2 = 1;
    for(int i = 2 ; i <= n - 2 ; i++){
        ni2 *= i;
    }
    ni = ni2;
    for(int i = n - 1 ; i <= n ; i++){
        ni *= i;
    }
    //cout << ni << ' ' << ni2 << endl;
    c2 = ni/(2*ni2);
    double C2 = c2;
    double Cnt = cnt;
    double ans = Cnt / C2;
    cout << setprecision(9) << fixed << ans;
}