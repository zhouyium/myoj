#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n;
	cin>>n;
	
	LL sum=0;
	for(LL i=1; i<=n; i++){
		LL a;
		cin>>a;
		sum=sum+a;
	}
	
	double pj=1.0*sum/n;
	cout<<fixed<<setprecision(5);
	cout<<sum<<" "<<pj<<"\n";
	
	return 0;
}
