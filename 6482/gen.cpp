//6482: 线性同余方程
//http://47.110.135.197/problem.php?id=6482
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;

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
	    cout<<n<<"\n";
	    
		maxx=2e9;
		minx=1;
	    for (LL i=1; i<=n; i++) {
	    	LL a = rand()%(maxx-minx+1)+minx;
	    	LL b = rand()%(maxx-minx+1)+minx;
	    	LL m = rand()%(maxx-minx+1)+minx;
			cout<<a<<" "<<b<<" "<<m<<"\n";
		}
	}

    return 0;
}
