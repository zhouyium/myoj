//http://47.110.135.197/problem.php?id=7490
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("04.in", "w", stdout);
    
    LL maxx = 2e4;
    LL minx = 2e4;
    LL T = rand()%(maxx-minx+1)+minx;
	//cout<<n<<"\n";
	
	LL cnt=1e7;
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=1;
		maxx=cnt;
		LL n = rand()%(maxx-minx+1)+minx;
		
		//n个数据
		for (LL j=1; j<=n; j++) {
			minx=-1e4;
			maxx=1e4;
			LL x = rand()%(maxx-minx+1)+minx;
			cout<<x<<" ";
		}
		cout<<"\n";
		
		cnt -= n;
		if (cnt<=0) {
			break;
		}
	}
	
    return 0;
}
