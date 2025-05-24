#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, a, b, c;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        c = a * (a + 1) / 2;
        if ((c - b) % 2 != 0 || (b = (c - b) / 2) < 0 || b > c)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
