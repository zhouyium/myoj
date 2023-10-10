#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main() {
	LL n;
	cin>>n;
	double sum=0;
	for(LL i=1;i<=n;i++){
		double x,y;
		LL a;
		cin>>x>>y>>a;
		double t=pow(x,2)+pow(y,2);
		t=sqrt(t);
		sum+=t/25.0;
		sum+=a*1.5;
	}
	LL ans=ceil(sum);
	cout<<ans<<"\n";
	return 0;
}


