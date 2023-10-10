#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;

const int N=1E6+10;
string s; 
LL sum[3];

LL f(LL x) {
	if (x>1) {
		return (x-1)*x/2;
	}
	return 0;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>s;
	LL r0=0;//余数为0 
	LL r1=0;//余数为1
	LL r2=0;//余数为2
	LL sum=0;
	for (LL i=0; i<s.size(); i++) {
		sum=(s[i]-'0'+sum)%3;
		if (sum==0) {
			r0++;
		} else if (sum==1) {
			r1++;
		} else {
			r2++;
		}
	}
	
	//求组合数
	LL cnt=f(r0)+f(r1)+f(r2)+r0;
	cout<<cnt<<"\n";

	return 0;
}

