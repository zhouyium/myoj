//8912: 极值的和
//http://47.110.135.197/problem.php?id=8912
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e3+10;
bool a[N][N];

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
    
    freopen("14.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(5e5,5e5);
		cout<<n<<"\n";
		//ai
		for (LL i=n;i>=1;i--) {
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
