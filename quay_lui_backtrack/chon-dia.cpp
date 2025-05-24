#include <fstream>
#include <cstring>

using namespace std;

ifstream iF("bluray.inp");
ofstream oF("bluray.out");

const short MAX_N = 10;

int n, D;
int b[MAX_N];
int t[MAX_N+1];
short c, bestc;
short x[MAX_N], bestx[MAX_N];

void branchbound(int i = 0){
    if (i == n){
        if (bestc > c){
            bestc = c;
            memmove(bestx, x, sizeof(x));
        }
        return;
    }

    for (int j = 1; j <= c; j++){
        if (t[j] + b[i] <= D){
            t[j] += b[i];
            x[i] = j;
            branchbound(i+1);
            x[i] = 0;
            t[j] -= b[i];
        }
    }

    if (i > 0 && c < n){
        c++;
        t[c] = b[i];
        x[i] = c;
        branchbound(i+1);
        x[i] = 0;
        t[c] = 0;
        c--;
    }
}

int main(){
    iF >>n >>D;
    for (int i = 0; i < n; i++)
        iF >>b[i];

    bestc = n+1;
    c = 1;
    memset(x, 0, sizeof(x));
    memset(t, 0, sizeof(t));
    branchbound();

    oF <<bestc <<endl;
    for (int i = 1; i <= bestc; i++){
        for (int j = 0; j < n; j++)
            if (bestx[j] == i)
                oF <<b[j] <<' ';
        oF <<endl;
    }

    iF.close();
    oF.close();
    return 0;
}
