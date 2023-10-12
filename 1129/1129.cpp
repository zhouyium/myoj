#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a;
	cin>>a;
	if(((a%4==0) && (a%100!=0)) || (a%400==0)){
		cout<<"Y\n";
	}else{
		cout<<"N\n";
	}
	return 0;
}
