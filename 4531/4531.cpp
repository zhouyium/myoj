#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e1+10; 
LL a[N][N];

//场宽为3

int main() {
	LL n;
	cin>>n;
	//两重循环 
	//i 行
	//j 列 
	LL cnt=1;
	for (LL j=1; j<=n; j++) {//列 
		for (LL i=1; i<=n; i++) {//行 
			a[i][j]=cnt;
			cnt++;
		}
	}
	
	//输出永远是先行后列 
	//set 设置
	//width  宽度 
	for (LL i=1; i<=n; i++) {//行
		for (LL j=1; j<=n; j++) {//列 
			cout<<setw(3)<<a[i][j];
		} 
		cout<<"\n";
	}
	return 0;
}
 
