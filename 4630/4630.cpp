#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a,b,c;
	cin>>a>>b>>c;
	//最大值等于第一个数 
	LL maxx=a;//max x
	//比较第二个数 
	if(maxx<b){
		maxx=b;
	}
	//比较第三个数
	if(maxx<c){
		maxx=c;
	} 
	cout<<maxx<<"\n";
	return 0;
}

