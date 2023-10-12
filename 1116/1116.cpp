#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n;
	cin>>n;
	//奇偶性判断，看对2的余数 
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

