#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <complex>

#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,a) for(int i = 0; i < a; ++i)
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;

const int MN = 1000111;

int n, a[MN];
long long l[MN], r[MN];

//Buffer reading
int INP,AM;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        if (feof(stdin)) memset(BUF, 0, sizeof BUF); else fread(BUF,1,BUFSIZE,stdin); \
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}
//End of buffer reading

const long long oo = 1000111000111000111LL;

int main() {
    GN(n);
    FOR(i,1,n) GN(a[i]);
    FOR(i,1,n) l[i] = l[i-1] + a[i];
    FORD(i,n,1) r[i] = r[i+1] + a[i];

    long long res = -1, cnt = 0, ln = -oo, nn = oo, c1 = 0, c2 = 0, now;
    FOR(i,1,n-1) {
        if (l[i] < nn) {
            nn = l[i];
            c1 = 1;
        }
        else if (l[i] == nn) {
            ++c1;
        }

        if (l[i] > ln) {
            ln = l[i];
            c2 = 1;
        }
        else if (l[i] == ln) {
            ++c2;
        }

        now = ln - r[i+1];
        if (now > res) {
            res = now;
            cnt = c2;
        }
        else if (now == res) {
            cnt += c2;
        }

        now = r[i+1] - nn;
        if (now > res) {
            res = now;
            cnt = c1;
        }
        else if (now == res) cnt += c1;
    }
    if (!res) cnt /= 2;
    cout << res << ' ' << cnt ;
    return 0;
}
