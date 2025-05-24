#include <bits/stdc++.h>
#define maxn 100005

using namespace std;
typedef long long lint;

int n, a[maxn], b[maxn];
lint f[maxn], bit[maxn];

lint get(int u) {
    lint kq=bit[u];
    while (u) {
        kq=max(kq,bit[u]);
        u&=(u-1);
    }
    return kq;
}

void update(int u,lint val) {
    while (u<=100000) {
        bit[u]=max(bit[u],val);
        u+=u & (-u);
    }
}


int main() {
    freopen("ISS.INP","r",stdin);
    freopen("ISS.OUT","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) {
        f[i]=get(a[i]-1)+b[i];
        update(a[i],f[i]);
    }
    long long ds=f[1];
    for(int i=1;i<=n;i++) ds=max(ds,f[i]);
    printf("%I64d",ds);
}