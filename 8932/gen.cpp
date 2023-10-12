//8932: IAI 2023年7月月赛乙组 T3 —— 订单安排
//http://47.110.135.197/problem.php?id=8932
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
		LL n = ran(1e5,1e5);
		LL m = ran(1,n);
		cout<<n<<" "<<m<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			LL x = ran(9e4,1e5);
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
