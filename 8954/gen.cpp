//8954: A. Sum of Three
//http://47.110.135.197/problem.php?id=8954

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="0123456789. -$!_-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
	int seed = time(NULL);
	if (argc>1) {
		//有参数
		seed = atoi(argv[1]);
	}
	srand(seed);
	
	freopen("09.in", "w", stdout);
	
	LL T = 1e4;
	cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(9e8+9e7,1e9);
		cout<<n<<"\n";
	}
	
	return 0;
}
