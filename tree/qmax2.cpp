#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 1e5 + 5;
ll a[maxn] , n , t , tree[maxn * 4] , lazy[maxn * 4];
void build(int id , int l , int r){
    if(l == r) tree[id] = a[l];
    else{
        int mid = (l+r) / 2;
        build(2*id , l , mid);
        build(2*id + 1 , mid + 1 , r);
        tree[id] = max(tree[2*id] , tree[2*id+1]);
    }
}
void down(int id) {
    int t = lazy[id];
    lazy[id*2] += t;
    tree[id*2] += t;

    lazy[id*2 + 1] += t;
    tree[id*2 + 1] += t;

    lazy[id] = 0;
}
void update(int id , int l , int r , int u , int v , int val){
    if(u > r || v < l) return;
    else if(u <= l && r <= v){
        tree[id] += val;
        lazy[id] += val;
    }
    else{
        down(id);
        int mid = (l+r)/2;
        update(2*id , l , mid , u , v , val);
        update(2*id+1 , mid + 1 , r , u , v , val);
        tree[id] = max(tree[2*id] , tree[2*id + 1]);
    }
}
ll get(int id , int l , int r , int u , int v){
    if(u > r || v < l) return -1e9;
    if(u <= l && r <= v) return tree[id];
    down(id);
    int mid = (l+r)/2;
    ll x = get(2*id , l , mid , u , v);
    ll y = get(2*id+1 , mid+1 , r , u , v);
    return max(x,y);
}
int main(){
    cin>>n>>t;
    // for(int i = 1; i <= n; i++){
    //     cin>>a[i];
    // }
    //build(1,1,n);
    while(t--){
        int x; cin>>x;
        if(x == 0){
            int l,r,val; cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else{
            int l,r; cin >> l >> r;
            cout<<get(1,1,n,l,r)<<endl;
        }
    }
}
