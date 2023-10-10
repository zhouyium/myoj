//8441: 病毒
//http://47.110.135.197/problem.php?id=8441
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
    
    freopen("00.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//数字 n,m
		LL n = ran(30,40);
		LL m = ran(30,40);
		cout<<n<<" "<<m<<"\n";
		//生成草地
		LL cnt=ran(1,4);
		for (LL i=1;i<=cnt;i++) {
			LL x=ran(1,n);
			LL y=ran(1,m);
			a[x][y]=true;
		}
		//输出草地
		for (LL i=1;i<=n;i++) {
			for (LL j=1;j<=m;j++) {
				if (a[i][j]) {
					cout<<'g';
				} else {
					cout<<'.';
				}
			}
			cout<<"\n";
		}
		//几个月 
		LL K = ran(3,4);
		cout<<K<<"\n";
	}
	
    return 0;
}
