#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n,x,y;
	cin>>n>>x>>y;
	//求y个小时后，虫子吃了多少苹果
	LL a=ceil(1.0*y/x); 
	//剩下几个苹果
	LL res=n-a;
	if(res<0){
		res=0;
	}
	cout<<res<<"\n"; 
	return 0;
}

