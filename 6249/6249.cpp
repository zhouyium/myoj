#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a;
	cin>>a;
	LL res=0;
	LL i;
	for(i=a; i>=1; i=i/2){
		res=res+1;
	}
	cout<<res<<"\n";
	return 0;
}
