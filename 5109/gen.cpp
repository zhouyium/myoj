#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    int T=78;
    printf("%d\n", T);
    while (T--) {
	    //生成n,m
	    ll maxx = 10000;//1000位
	    ll minx = 10000;
	    ll c = rand()%(maxx-minx+1)+minx;
	    printf("%lld\n", c);
	    
	    for (int i=1; i<=c; i++) {
		    maxx = 20;//1000位
		    minx = -10;
		    ll n = rand()%(maxx-minx+1)+minx;
		    maxx = 1e9;//1000位
		    minx = 9.6e8;
		    ll m = rand()%(maxx-minx+1)+minx;
	    	printf("%lld %lld\n", n, m);
		}
	}
    
    return 0;
}
