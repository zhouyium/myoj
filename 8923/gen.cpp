//8923: 下降幂多项式
//http://47.110.135.197/problem.php?id=8923
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=1e3+10;
char a[N][N];

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
		LL n = ran(3e5,3e5);
		LL m = ran(1e5,1e8);
		cout<<n<<" "<<m<<"\n";
		//ai
		for(LL i=n;i>=0;i--){
			LL x = ran(5e8,1e9);
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
