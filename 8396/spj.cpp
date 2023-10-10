#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;
LL a[N];
 
void solve(LL T) {
	//从inf读取 
	//读取n数量 
	LL n=inf.readLong();
	//读取in文件
	unordered_map<LL,LL> mp1;
	for (LL i=1;i<=n;i++) {
		LL x;
		x=inf.readLong();
		mp1[x]++;
	}
	//从ouf中读取
	for (LL i=1;i<=n;i++) {
		LL x;
		x=ouf.readLong();
	}
	//从ans中读取 
	//读取用户答案
	unordered_map<LL,LL> mp2;
	for (LL i=1;i<=n;i++) {
		a[i]=ans.readLong();
		if (mp1.count(a[i])==0) {
			//a[i]数据不存在
			quitf(_wa, "testcase %lld:%lld is not existed.\n", T, a[i]);
			return;
		}
		mp2[a[i]]++;
		if (mp2[a[i]]>mp1[a[i]]) {
			quitf(_wa, "testcase %lld:%lld is exceed times.\n", T, a[i]);
			return;			
		}
	}
	//合法性判断
	if (n==2) {
		if (a[1]>a[2]) {
			quitf(_wa, "testcase %lld:The answer is wrong.\n", T);
		}
	} else if (n>=3) {
		for (LL i=1;i+1<=n;i++) {
			if (i%2==1) {
				//奇数
				if (a[i]>a[i+1]) {
					quitf(_wa, "testcase %lld:The answer is wrong.\n", T);
					return;				
				}
			} else {
				//偶数
				if (a[i]<a[i+1]) {
					quitf(_wa, "testcase %lld:The answer is wrong.\n", T);
					return;				
				}
			}
		}		
	}
	printf("testcase %lld:The answer is correct.\n", T);
}

int main(int argc, char *argv[]) {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	registerTestlibCmd(argc, argv);

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	T=inf.readLong();
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve(i);
	}
	quitf(_ok, "The answer is correct.\n");
	
	return 0;
}

