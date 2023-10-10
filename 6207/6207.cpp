#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n;
	cin>>n;
	double sum=0;
	for(LL i=1;i<=n;i++){
		sum=sum+1.0/(i*(i+1));
	}
	cout<<fixed<<setprecision(2);
	cout<<sum<<"\n";
	return 0;
}
