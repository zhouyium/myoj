//5777
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
    
    freopen("12.in", "w", stdout);
    ll maxx = 100;//1000位
    ll minx = 100;
    ll T = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", T);    
    while (T--) {
	    //生成n
	    maxx = 100;//1000位
	    minx = 100;
	    ll n = rand()%(maxx-minx+1)+minx;
	    maxx = 1e4;//1000位
	    minx = 1e4;
	    ll m = rand()%(maxx-minx+1)+minx;
	    printf("%lld %lld\n", n, m);
	    maxx = 100;//1000位
	    minx = 30;
	    for (int i=1; i<=n; i++) {
	    	ll x,y;
	    	x = rand()%(maxx-minx+1)+minx;
	    	y = rand()%(maxx-minx+1)+minx;
	    	printf("%lld %lld\n", x, y);
		}
	}

    return 0;
}
