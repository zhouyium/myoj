#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL n;
	cin>>n;
	//变量不够，那就加变量
	//不是cin读取的数据，就需要给数值 
	LL jsh=0;//奇数和
	LL osh=0;//偶数和 
	for(LL i=1; i<=n; i++){
		LL x;
		cin>>x;
		//奇偶性判定
		if(x%2==0){
			osh=osh+x;//累加求和 
		} else{
			jsh=jsh+x;
		}
	}
	
	cout<<jsh<<"\n"<<osh<<"\n";
	return 0;
}
