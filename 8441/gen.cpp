//8441: 病毒
//http://47.110.135.197/problem.php?id=8441
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e3+10;
LL a[N][N];

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
    
    //freopen("09.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//数字 n,m
		LL n = ran(2e3,2e3);
		LL m = ran(2e3,2e3);
		cout<<n<<" "<<m<<"\n";
		//有几个起点
		LL K = 10;//ran(1,10);
		cout<<K<<"\n";
		map<PLL,bool> mp;
		for (LL i=1; i<=K; i++) {
			LL x,y;
			do {
				x=ran(1,n);
				y=ran(1,m);
				if (mp.count({x,y})==0) {
					break;
				}
			} while (true);
			//对称生成 
			cout<<x<<' '<<y<<' ';
			mp[{x,y}]=1;
		}
		cout<<"\n";
	}
	
    return 0;
}
