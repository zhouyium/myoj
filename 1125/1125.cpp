#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	double x;
	cin>>x;
	double res;
	if((0<=x) && (x<5)){
		res=x+2.5;
	}else if((5<=x) && (x<10)){
		res=2-1.5*pow(x-3,2);
	}else{
		res=x/2-1.5;
	}
	cout<<fixed<<setprecision(3);
	cout<<res<<"\n";
	return 0;
}


