#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n,x,y;
	cin>>n>>x>>y;
	//��y��Сʱ�󣬳��ӳ��˶���ƻ��
	LL a=ceil(1.0*y/x); 
	//ʣ�¼���ƻ��
	LL res=n-a;
	if(res<0){
		res=0;
	}
	cout<<res<<"\n"; 
	return 0;
}

