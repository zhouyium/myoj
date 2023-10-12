//8549: Cross Point
//http://47.110.135.197/problem.php?id=8549
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

//�жϷ��� 
inline int sign(const double &r) {
	return r <= -EPS ? -1 : r >= EPS ? 1 : 0;
}
//�Ƚ���� 
inline bool equals(const double &a, const double &b) {
	return abs(a - b) < EPS;
}	 

void solve(LL T) {
	//��inf��ȡ 
	LL a,b;
	LL q=inf.readLong();
	while(q--){
		a=inf.readDouble();
		b=inf.readDouble();
	}
	//��ouf�ж�ȡ
	double x=ouf.readDouble();

	//��ans�ж�ȡ 
	double ansx=ans.readDouble();

	//�Ƚϴ�
	if (abs(x-ansx)/x>EPS) {
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

