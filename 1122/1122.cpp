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
只有一门及格
1.第一门不及格同时第二门及格a<60&&b>=60 
2.第一门及格同时第二门不及格a>=60&&b<60 
1||2
*/

