//4926: DP17 信封嵌套
//http://47.110.135.197/problem.php?id=4926
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e3+10;

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
		LL n = ran(2e3,2e3);
		LL m = ran(1,n);
		cout<<n<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			LL x = ran(1,2e3);
			LL y = ran(1,2e3);
			cout<<x<<" "<<y<<"\n";
		}
	}
	
    return 0;
}
