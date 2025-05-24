#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e6 + 5;
int n , a[maxn] , b[maxn];
map<int , int> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    b[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        b[i] = b[i-1] + a[i];
    }
    int sum = 0, maxs = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum < 0) sum = 0;
        maxs = max(maxs , sum);

    }
    sum = 0;
    int pos1 , pos2;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum < 0) sum = 0;
        if(sum == maxs){
            pos2 = i;
            break;
        }
    }
    if(b[pos2] == maxs){
        //cout << "0" << ' ' << pos2 << endl; 
        for(int i = 0 ; i <= pos2 ; i++) cout << i << ' ';
        cout << endl << maxs;
        return 0;
    }
    for(int i = 0 ; i < pos2 ; i++){
        if(b[pos2] - b[i] == maxs){
            pos1 = i;
            break;
        }
    }
    for(int i = pos1 + 1 ; i <= pos2 ; i++) cout << i << ' ';
    cout << endl << maxs;
    //cout << pos1 + 1 << ' ' << pos2 << endl; 
}