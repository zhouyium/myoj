#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a,b,c,d;
	cin>>a>>b>>c>>d;
	//calculate the Hanmanton distance
	LL res=abs(a-c)+abs(d-b);
	cout<<res<<"\n";
	return 0;
}
