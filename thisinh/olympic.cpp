#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

struct Data{
    int t , d , sub , bai;
};

vector<Data> v;
int AC[5] , check[5] , a[20] , final , n;

void sinh(){
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

bool cmp(Data x , Data y){
    return x.sub < y.sub;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("hi.inp" , "r" , stdin);
    freopen("hi.out" , "w" , stdout);
    
    for(int i = 1 ; i <= 3 ; i++){
        int k ; cin >> k;
        for(int j = 1 ; j <= k ; j++){
            Data x;
            cin >> x.t >> x.d >> x.sub;
            x.bai = i;
            v.push_back(x);
        }
        cin >> AC[i];
    }

    // for(Data x : v){
    //     cout << x.t << ' ' << x.d << ' ' << x.sub << ' ' << x.bai << endl;
    // }

    n = v.size();

    float ans = 0;

    while(final == 0){
        int tg = 180;
        float point = 0;
        vector<Data> res;
        for(int i = 1 ; i <= 3 ; i++) check[i] = 0;

        for(int i = 0 ; i < n ; i++){
            if(a[i] == 1){
                res.push_back(v[i]);
            }
        }

        //sort(res.begin() , res.end() , cmp);
        for(Data x : res){
            if( check[x.bai - 1] >= AC[x.bai - 1] && check[x.bai] >= x.sub && tg - x.t >= 0){
                if(x.bai == 1){
                    point += 6.0/100*x.d;
                }
                else{
                    point += 7.0/100*x.d;
                }
                tg -= x.t;
                check[x.bai]++;
            }
            if(tg < 0) break;
        }

        cout << point << endl;

        ans = max(ans , point);

        sinh();
    }

    cout << ans;
    
}