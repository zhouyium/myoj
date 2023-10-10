#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

double ans(LL n,double x){
	if(n==1){
		return sqrt(1+x);
	}else{
		return sqrt(n+ans(n-1,x));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	double x;
	cin>>x;
	LL n;
	cin>>n;
	cout<<fixed<<setprecision(2)<<ans(n,x)<<"\n";
	return 0;
}
