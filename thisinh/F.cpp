#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;
char a[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        if(a[i] == a[i+1]){
            cnt++;
        }
    }
    cout << cnt;
}