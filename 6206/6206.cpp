#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	double r,x,p;
	cin>>r>>x>>p;
	double res=x*pow((100+r)/100,p);
	cout<<fixed<<setprecision(2)<<res<<"\n";
	return 0;
}
