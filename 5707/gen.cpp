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
    
    freopen("00.in", "w", stdout);
    
    int T=1;
    while (T--) {
	    //生成n,m
	    ll maxx = 50;//1000位
	    ll minx = 30;
	    ll n = rand()%(maxx-minx+1)+minx;
	    maxx = 250;//1000位
	    minx = 200;
	    ll m = rand()%(maxx-minx+1)+minx;
	    printf("%lld %lld\n", n,m);
	    
#if 0 
	    for (int i=1; i<=n-1; i++) {
	    	ll u,v,w;
		    u = i;
		    v = i+1;
		    maxx = 1000;//1000位
		    minx = 100;
		    w = rand()%(maxx-minx+1)+minx;
	    	printf("%lld %lld %lld\n", u, v, w);	    	
		}
#endif
	    for (int i=1; i<=m; i++) {
	    	ll u,v,w;
		    maxx = n;//1000位
		    minx = 1;
		    u = rand()%(maxx-minx+1)+minx;
		    v = rand()%(maxx-minx+1)+minx;
		    maxx = 1e5;//1000位
		    minx = 1;
		    w = rand()%(maxx-minx+1)+minx;
	    	printf("%lld %lld %lld\n", u, v, w);
		}
	}
    
    return 0;
}
