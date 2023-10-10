//8583: DPL_2_C : Bitonic Traveling Salesman Problem (Bitonic TSP)
//http://47.110.135.197/problem.php?id=8583
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-4;

void solve(LL T) {
	//从inf读取 
	int n  = inf.readInt();
	for(int i=1;i<=n;i++){
		int x1 = inf.readInt();
		int y1 = inf.readInt();
	}
    
	double a=ouf.readDouble();
	//从ans中读取 
	double ansa=ans.readDouble();
	//比较答案
	if (abs(a-ansa)>EPS){
		quitf(_wa, "The answer is wrong.\n");
		return;
	}
	quitf(_ok, "The answer is correct.\n");
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

