#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e1+10; 

//变量的生命周期 
//从变量定义开始，向上走第一个大括号 

//返回值 函数名(输入参数) 函数体
LL calc(LL x, LL y, char ch) {
	LL res;
	if (ch=='+') {
		res=x+y;
	} else if (ch=='-') {
		res=x-y;
	} else if (ch=='*') {
		res=x*y;
	} else if (ch=='/') {
		res=x/y;
	} else if (ch=='%') {
		res=x%y;
	}
	return res;
}

int main() {
	LL a,b;
	char op;//operator  操作符
	cin>>a>>op>>b;
	
	cout<<"a="<<a<<"\n";
	cout<<"op="<<op<<"\n";
	cout<<"b="<<b<<"\n";
	
	cout<<calc(a,b,op)<<"\n";
	
	return 0;
}
 
