//6882: 矩阵距离
//http://47.110.135.197/problem.php?id=6882
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
    
    freopen("00.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//数字 n,m
		LL n = ran(1e3,1e3);
		LL m = ran(1e3,1e3);
		cout<<n<<" "<<m<<"\n";
		
		//有几个起点
		LL K = 11;
		for (LL i=1; i<=K; i++) {
			LL x=ran(1,n);
			LL y=ran(1,m);
			a[x][y]=1;
		}
		
		for (LL i=1;i<=n;i++) {
			for (LL j=1;j<=m;j++) {
				cout<<a[i][j];
			}
			cout<<"\n";
		}
	}
	
    return 0;
}
