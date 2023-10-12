#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
LL a[N];

void solve() {
	LL n,K;
	cin>>n>>K;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	//等差数列三要素：a1,n,K 
	LL minx=9e18;
	LL cur = 0;
	for (LL a1=1; a1<=1000; a1++) {//找a1 
		//将a1=i，构造一个差为d的等差数列
		//在所有答案中找到一个操作最小的 
		LL cnt=0;//数字变化的值
		LL d=a1;//变化后对于a[i]的值 
		for (LL i=1; i<=n; i++) {//遍历所有数字 
			if (a[i]!=d) {
				cnt++; 
			}
			d=d+K;//变化后的数字 
		}
		if (cnt<minx) {
			cur=a1;
			minx=cnt;
		}
	}	
	
	cout<<minx<<"\n";
	if (cur==0) {
		return;
	}
	for (LL i=1; i<=n; i++) {
		if (a[i]>cur) {
			cout<<"- "<<i<<" "<<a[i]-cur<<"\n";
		} else if (a[i]<cur) {
			cout<<"+ "<<i<<" "<<cur-a[i]<<"\n";
		}
		cur+=K;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

