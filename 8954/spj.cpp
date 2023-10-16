//8954: A. Sum of Three
//http://47.110.135.197/problem.php?id=8954

#include<bits/stdc++.h>
#include"../testlib.h"

using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-4;

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
		int n = inf.readInt();
		string s_out = ouf.readString();
		string s_ans = ans.readString();
		if(s_out=="NO"){
			if(s_out!=s_ans){
				quitf(_wa, "Testcase %d, The answer NO, but your answer is %s.\n", i, s_ans.c_str());	
			}
		} else if(s_out=="YES"){
			if(s_out!=s_ans){
				quitf(_wa, "Testcase %d, The answer NO, but your answer is %s.\n", i, s_ans.c_str());	
			}
			int xx= ans.readInt();
			int yy= ans.readInt();
			int zz= ans.readInt();
			s_ans = ans.readString();
			
			int x = ouf.readInt();
			int y = ouf.readInt();
			int z = ouf.readInt();
			s_out = ouf.readString();
			if(x%3==0||y%3==0||z%3==0||x+y+z!=n){
				quitf(_wa, "Testcase %d, The answer %d+%d+%d=%d not equal %d.\n", i, x, y, z, x+y+z, n);	
			}
		} else {
			quitf(_wa, "Testcase %d, The answer NO, but your answer is %s.\n", i, s_ans.c_str());
		}
	}
	quitf(_ok, "The answer is correct.\n");	
	
	return 0;
}

