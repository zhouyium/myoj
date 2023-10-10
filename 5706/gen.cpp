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
    
    int T=1;
    while (T--) {
	    //生成n,m
	    ll maxx = 1e5;//1000位
	    ll minx = 1e5;
	    ll n = rand()%(maxx-minx+1)+minx;
	    maxx = 1.6e5;//1000位
	    minx = 1.5e5;
	    ll m = rand()%(maxx-minx+1)+minx;
	    printf("%lld %lld\n", n,m);
	    
#if 1 
	    for (int i=1; i<=n-1; i++) {
	    	ll u,v,w;
		    u = n-i+1;
		    v = n-i;
		    maxx = 1e5;//1000位
		    minx = 1e4;
		    w = rand()%(maxx-minx+1)+minx;
	    	printf("%lld %lld %lld\n", u, v, w);	    	
		}
#endif
	    for (int i=n; i<=m; i++) {
	    	ll u,v,w;
		    maxx = n;//1000位
		    minx = 1;
		    u = rand()%(maxx-minx+1)+minx;
		    v = rand()%(maxx-minx+1)+minx;
		    maxx = 1e5;//1000位
		    minx = 1e4;
		    w = rand()%(maxx-minx+1)+minx;
	    	printf("%lld %lld %lld\n", u, v, w);
		}
	}
    
    return 0;
}
