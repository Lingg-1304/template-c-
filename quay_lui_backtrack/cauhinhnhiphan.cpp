#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;
int n , final;
int a[20];

void sinh1(){
    for(int i = n - 1 ; i >= 0 ; i--){
        if(a[i] == 0){
            a[i] = 1;
            return;
        }
        if(a[i] == 1) a[i] = 0;
    }
}

void sinh2(){
    int i = n - 1;
    while(i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == -1){
        final = 1;
    }
    else{
        a[i] = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 0 ; i < pow(2,n) ; i++){
        for(int i = 0 ; i < n ; i++) cout << a[i];
        sinh1();
        cout << endl;
    }

    cout << endl;

    //a[1] = 1;

    // while(final == 0){
    //     for(int i = 0 ; i < n ; i++) cout << a[i];
    //     sinh2();
    //     cout << endl;
    // }

}