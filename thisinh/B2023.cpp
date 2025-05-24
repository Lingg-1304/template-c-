#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;
int a[105][25];

bool Run(){
    int n , m; cin >> n >> m;
    int doi[105] , bai[25];
    for(int i = 1 ; i <= n ; i++){
        doi[i] = 0;
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
    for(int j = 1 ; j <= m ; j++){
        bai[j] = 0;
    }
    for(int i = 1 ; i <= n ; i++){
        doi[i] = 0;
        for(int j = 1 ; j <= m ; j++){
            doi[i] += a[i][j];
            bai[j] += a[i][j];
        }
    }

    for(int j = 1 ; j <= m ; j++){
        if(bai[j] == 0){
            return false;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(doi[i] == 0 || doi[i] == m) return false;
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        if(Run()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}