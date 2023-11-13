//7281: AtCoder Educational DP Contest —— I - Coins
//http://47.110.135.197/problem.php?id=7281

#include<bits/stdc++.h>
#include"../testlib.h"

using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-9;

const int N=1e3+10;

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
	T=inf.readInt();
	for (int i=1; i<=T; i++) {
		//比较答案不超过1e-9
		double res_ouf = ouf.readDouble();
		double res_ans = ans.readDouble();
		if(abs(res_ouf-res_ans)<=EPS){
			quitf(_ok, "The answer is correct.\n");
		}else{
			quitf(_wa, "The answer is not correct.\n");	
		}
	}
		
	
	return 0;
}

