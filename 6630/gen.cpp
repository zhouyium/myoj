//6630: 加边的无向图
//http://47.110.135.197/problem.php?id=6630
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+10;
LL a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 1e5;
	    LL minx = 1e5;
	    LL n = rand()%(maxx-minx+1)+minx;
		maxx=50;
		minx=30;	    
	    LL m = rand()%(maxx-minx+1)+minx;
	    cout<<n<<' '<<m<<"\n";
	    
	    for (LL i=1; i<=m; i++) {
			maxx=1e2;
			minx=1;
	    	LL a = rand()%(maxx-minx+1)+minx;
			maxx=n;
			minx=9.5e4;
	    	LL b = rand()%(maxx-minx+1)+minx;
			cout<<a<<" "<<b<<"\n";
		}
	}

    return 0;
}
