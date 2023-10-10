//8568: Intersection of a Circle and a Polygon
//http://47.110.135.197/problem.php?id=8568
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-5;

void solve(LL T) {
	//��inf��ȡ 
	int n = inf.readInt();
	int r = inf.readInt();
	for(int i=1;i<=n;i++){
		int a = inf.readInt();
		int b = inf.readInt();
	}
    
	double a=ouf.readDouble();
	//��ans�ж�ȡ 
	double ansa=ans.readDouble();
	//�Ƚϴ�
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
