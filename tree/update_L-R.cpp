#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int n;
ll a[maxn] , tree[maxn * 4] , add[maxn * 4];
void build(int u ,int l, int r){
    if(l == r){
        tree[u] = a[l];
    }
    else{
        int mid = (l+r)/2;
        build(2*u , l , mid);
        build(2*u+1 , mid + 1 , r);
        tree[u] = max(tree[2*u] , tree[2*u+1]);
    }
}
void update(int id , int l , int r , int u , int v , int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        tree[id] += val;
        add[id] += val;
    }
    else{
        int mid = (l+r)/2;
        update(2*id , l , mid , u , v , val);
        update(2*id+1 , mid+1 , r , u , v , val);
        tree[id] = max( tree[2*id] , tree[2*id+1] ) + add[id];
    }
}
ll get(int id , int l , int r , int u , int v){
    if(l > v || r < u) return -1e9;
    if(u <= l && r <= v) return tree[id];
    int mid = (l+r)/2;
    ll x = get(2*id , l , mid , u , v);
    ll y = get(2*id+1 , mid+1 , r , u , v);
    return (max(x,y)) + add[id];
}
int main(){
    cin>>n; 
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    build(1,1,n);
    int q ; cin>>q;
    while(q--){
        int k; cin >> k;
        if(k == 1){
            int l , r ,val; cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<get(1,1,n,l,r)<<endl;
        }
    }
}