#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main() {
	LL n,b;
	cin>>n>>b;
	LL sum=0;
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		sum=(sum+x)%b;
	}
	cout<<sum<<"\n";
	return 0;
}


