//5562: DP44 兑换零钱
//http://47.110.135.197/problem.php?id=5562

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
	
	freopen("10.in", "w", stdout);
	
	LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(200,200);
		LL m = ran(5e5,5e5);
		cout<<n<<" "<<m<<"\n";
		//ai
		vector<LL> v;
		for(LL i=1;i<=200;i++){
			v.push_back(i);
		}
		for(LL i=1;i<=n;i++){
			LL x = ran(0, v.size()-1);
			cout<<v[x]<<" ";
			v.erase(v.begin()+x);
		}
		cout<<"\n";
	}
	
	return 0;
}
