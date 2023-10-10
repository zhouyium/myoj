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
    
    freopen("10.in", "w", stdout);
    
    //生成n,m
    ll maxx = 20000;//1000位
    ll minx = 20000;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx = 600;//1000位
    minx = 500;
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n,0);

    maxx = 1;//1000位
    minx = -1;
	for (ll i=1; i<=n; i++) {
		ll t = rand()%(maxx-minx+1)+minx;
	    printf("%lld ", 0);
	}
	printf("\n");

    return 0;
}
