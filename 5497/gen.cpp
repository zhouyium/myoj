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
    
    freopen("2.in", "w", stdout);
    
    //生成n,m
    ll maxx = 50;//1000位
    ll minx = 40;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=n;
	minx=0;
    ll k = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n, k);

	ll t;    
    for (ll i=1; i<=k; i++) {
    	t=rand()%(maxx-minx+1)+minx;
		printf("%lld ", t);
	}
	printf("\n");

    return 0;
}
