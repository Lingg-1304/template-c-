#include<bits/stdc++.h>
using namespace std;
int main(){
	long long res=0;
    int n,d;
    cin>>n>>d;
    float a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	float kq=-1e9;
	kq=max(kq,a[n-1]=d-a[n-1]);
	for(int i=1;i<n-1;i++){
    	kq=max(kq,a[i]-a[i-1]);
	}
	kq/=2;
	cout<<fixed<<setprecision(10)<<kq;
}
