#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int n , k , a[100] , cnt = 1, final;
vector<int> v;

void sinh(){
    int i = cnt;
    while (i >= 1 && a[i] == 1)
    {
        i--;
    }

    if(i == 0){
        final = 1;
    }
    else{
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d/a[i];
        int r = d%a[i];
        for(int j = 1 ; j <= q ; j++){
            a[i+j] = a[i];
            ++cnt;
        }
        if(r != 0){
            cnt++;
            a[cnt] = r;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hi.inp" , "r" , stdin);
    freopen("hi.out" , "w" , stdout);
    
    cin >> n;
    
    a[1] = n;

    while(final == 0){
        for(int i = 1 ; i <= cnt ; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        sinh();
    }
    
}