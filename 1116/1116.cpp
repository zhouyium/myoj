#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n;
	cin>>n;
	//��ż���жϣ�����2������ 
	LL res=n%2;
	if(res==0){
		//even
		cout<<"even\n";
	} else{
		//odd
		cout<<"odd\n";
	}
	return 0;
}

