#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	double p=(a+b+c)/2;
	double s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<fixed<<setprecision(4)<<s<<"\n";
	return 0;
}
