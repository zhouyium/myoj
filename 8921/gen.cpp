//8921: 素数行列
//http://47.110.135.197/problem.php?id=8921
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
    
    freopen("11.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1e3,1e3);
		cout<<n<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=n;j++){
				LL x = ran(5e4,1e5);
				cout<<x<<" ";
			}
			cout<<'\n';
		}
	}
	
    return 0;
}
