//8559: Closest Pair
//http://47.110.135.197/problem.php?id=8559
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;

const int N=2e3+10;
using Real = double;
using Point=complex<double>;
const double EPS=1e-6;

void solve(LL T) {
	//从inf读取 
	double a,b,r;
	a=inf.readDouble();
	b=inf.readDouble();
	r=inf.readDouble();
	
	LL n=inf.readLong();
	while(n--){
		a=inf.readDouble();
		b=inf.readDouble();
		a=inf.readDouble();
		b=inf.readDouble();
		//从ouf中读取
		a=ouf.readDouble();
		b=ouf.readDouble();
		double c=ouf.readDouble();
		double d=ouf.readDouble();
		//从ans中读取 
		double ansa=ans.readDouble();
		double ansb=ans.readDouble();
		double ansc=ans.readDouble();
		double ansd=ans.readDouble();
		//比较答案
		if (abs(a-ansa)>EPS || abs(b-ansb)>EPS || abs(c-ansc)>EPS || abs(d-ansd)>EPS){
			quitf(_wa, "The answer is wrong.\n");
			return;
		}
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

