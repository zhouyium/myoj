//8946: DP33 买卖股票的最好时机 IV
//http://47.110.135.197/problem.php?id=8946

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="abcdefghijklmnopqrstuvwxyz";

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
	
	freopen("12.in", "w", stdout);
	
	LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1e3,1e3);
		LL m = ran(1,100);
		cout<<n<<" "<<m<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			//模式
			LL x = ran(1,1000);
			cout<<x<<" ";				
		}
		cout<<"\n";
	}
	
	return 0;
}
