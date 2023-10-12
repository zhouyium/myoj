#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	//º∆À„±ﬂ≥§
	LL a=abs(x1-x2);
	LL b=abs(y1-y2);
	//c^2=a^2+b^2
	double c=sqrt(a*a+pow(b,2));
	cout<<fixed<<setprecision(2)<<c<<"\n";
	return 0;
}
