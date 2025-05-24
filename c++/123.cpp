#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, S; cin >> n >> S;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int F[S + 1] = {0};
    F[0] = 1;
    for(int i = 0; i < n; i++){
        //a[i] => j
        for(int j = S; j >= a[i]; j--){
            if(F[j - a[i]]){
                F[j] = 1;
            }
        }
    }
    for(int i = 0; i <= S; i++){
        cout << F[i] << ' ';
    }
    cout << F[S] << endl;
}
