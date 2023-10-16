//1209: 密码翻译
//http://47.110.135.197/problem.php?id=1209

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="0123456789 -$!_-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
	
	LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1,1);
		//cout<<n<<"\n";
		for(LL i=1;i<=n;i++){
			//药名长度
			LL m = ran(80,80);
			for(LL j=1;j<=m;j++){
				LL x = ran(0, s.size()-1);
				cout<<s[x];
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	
	return 0;
}
