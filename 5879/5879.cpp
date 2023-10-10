#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	char a;
	cin>>a;
	//大写变小写 +32
	//强制转换
	//cout<<(char)(a+32)<<"\n"; 
	//隐式转换
	char b;
	b=a+32;
	cout<<b<<"\n"; 
	return 0;
}
