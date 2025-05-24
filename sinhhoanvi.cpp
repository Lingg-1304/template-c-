#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[5] = {1,2,3};
	do{
		for(int i=0;i<3;i++) cout<<a[i]<<" ";
		cout<<endl;
	}while(next_permutation(a,a+3));
}
