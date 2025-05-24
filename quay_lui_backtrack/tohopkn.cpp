#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;
int n , k , final;
int a[20];

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }
    if(i == 0){
        final = 1;
    }
    else{
        a[i]++;
        for(int j = i + 1 ; j <= k ; j++){
            a[j] = a[j-1] + 1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;

    for(int i = 1 ; i <= k ; i++) a[i] = i;

    while(final == 0){
        for(int i = 1 ; i <= k ; i++) cout << a[i];
        sinh();
        cout << endl;
    }

}