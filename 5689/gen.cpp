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
    
    freopen("12.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);

    maxx = 1;//1000位
    minx = 1;
	for (ll i=1; i<=n; i++) {
		ll t=rand()%(maxx-minx+1)+minx;
		printf("%lld ", t);
	}
	printf("\n");

    return 0;
}
