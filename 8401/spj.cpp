//8401: 鹦鹉学习浮点数 II
//http://47.110.135.197/problem.php?id=8401
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-4;

const int N=2e6+10;
 
void solve(LL T) {
	//从inf读取 
	double x=inf.readDouble();
	//从ouf中读取
	double res1=ouf.readDouble();
	//从ans中读取 
	double res2=ans.readDouble();

	//合法性判断
	double eps=abs(res2-x);
	if (eps<=EPS) {
		quitf(_ok, "The answer is correct.\n");
	} else {
		quitf(_wa, "The answer is wrong.\n");
	}
}

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	registerTestlibCmd(argc, argv);

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//T=inf.readLong();
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve(i);
	}
	
	return 0;
}

