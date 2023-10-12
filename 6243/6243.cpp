#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int main(){
	LL n,m;
	cin>>n>>m;
	for(LL i=n; i>=1; i=i-m){
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
} 

