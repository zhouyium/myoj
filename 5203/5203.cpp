#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	cout<<"小写a="<<(LL)'a'<<"\n";//97
	cout<<"大写a="<<(LL)'A'<<"\n";//65
	char a='b';
	cout<<a<<"\n";
	cin>>a;
	char b=a-32;//小写变大写 
	//cout<<b<<"\n";
	cout<<(char)(a-32)<<"\n";
	return 0;
} 
