#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a,b;
	cin>>a>>b;
	if(a<60 || b<60){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}
/*
ֻ��һ�ż���
1.��һ�Ų�����ͬʱ�ڶ��ż���a<60&&b>=60 
2.��һ�ż���ͬʱ�ڶ��Ų�����a>=60&&b<60 
1||2
*/

