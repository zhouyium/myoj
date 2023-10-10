#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500+10;
ll a[MAXN][MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("9.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1000;//1000位
    ll minx = 1000;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx = 1000;//1000位
    minx = 1000;
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n,m);

	for (ll i=1; i<=n; i++) {
		for (ll j=1; j<=m; j++) {
	    	ll t=rand()%2;
	    	if (0==t) {
	    		printf(".");
			} else {
				printf("#");
			}
		}
		printf("\n");
	}

    return 0;
}
