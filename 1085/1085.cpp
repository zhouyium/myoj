#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e1+10; 


//返回值 函数名(输入参数) 函数体
LL max(LL a, LL b, LL c) {
	LL res=a;
	if (res<b){
		res=b;
	}
	if (res<c){
		res=c;
	}
	return res;
}

int main() {
	LL a,b,c;
	cin>>a>>b>>c;
	double res=max(a,b,c)/(max(a+b,b,c)*max(a,b,b+c));
	cout<<fixed<<setprecision(3)<<res<<"\n";
	return 0;
}
 
