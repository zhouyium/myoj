//8938: IAI 2023年8月月赛乙组 T4 —— 点对之和（一）
//http://47.110.135.197/problem.php?id=8938
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

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
    
    freopen("04.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(5e5,5e5);
		LL m = ran(1,n);
		cout<<n<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			LL x = ran(9e5,1e6);
			cout<<x<<" ";
		}
		cout<<"\n";
		for(LL i=1;i<=n;i++){
			LL x = ran(9e5,1e6);
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
