#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL h,r;
	cin>>h>>r;
	//¼ÆËãÌå»ıcalculate the volumn
	double v=3.14*r*r*h/1000;
	double ans=20/v; 
	LL res=ceil(ans);
	cout<<res<<"\n";
	return 0;
}
