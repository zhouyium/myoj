#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e1+10; 

//�������������� 
//�ӱ������忪ʼ�������ߵ�һ�������� 

//����ֵ ������(�������) ������
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
	char op;//operator  ������
	cin>>a>>op>>b;
	
	cout<<"a="<<a<<"\n";
	cout<<"op="<<op<<"\n";
	cout<<"b="<<b<<"\n";
	
	cout<<calc(a,b,op)<<"\n";
	
	return 0;
}
 
