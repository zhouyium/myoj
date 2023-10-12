//8463: ITP1_10_D : Distance II
//http://47.110.135.197/problem.php?id=8463
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-5;

void solve(LL T) {
	//从inf读取 
	int n  = inf.readInt();
	for(int i=1;i<=n;i++){
		int x1 = inf.readInt();
		int y1 = inf.readInt();
	}
    
	double p1=ouf.readDouble();
	double p2=ouf.readDouble();
	double p3=ouf.readDouble();
	double p4=ouf.readDouble();
	//从ans中读取 
	double ans1=ans.readDouble();
	double ans2=ans.readDouble();
	double ans3=ans.readDouble();
	double ans4=ans.readDouble();
	//比较答案
	if (abs(p1-ans1)>EPS||abs(p2-ans2)>EPS||abs(p3-ans3)>EPS||abs(p4-ans4)>EPS){
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

