#include <iostream>
#include <cstdio>
using namespace std;

int f[60600];

int main()
{
    int n,x,ans=0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        
        for (int i=x+1;i<=60000;i+=i&-i) ans+=f[i];
        for (int i=x;i;i-=i&-i) f[i]++;
    }
    cout << ans << endl;
}