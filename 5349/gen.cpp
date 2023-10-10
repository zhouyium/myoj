#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
ll b[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("9.in", "w", stdout);
    
    //生成n,m
    ll maxx = 300000;//1000位
    ll minx = 300000;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=300000;
	minx=300000;
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n, m);
    maxx=n;
	minx=1;
    for (ll i=1; i<=m; i++) {
    	int op=rand()%1000;
    	if (op%10<2) {
			ll x=rand()%(maxx-minx+1)+minx;
			printf("get %lld\n", x);
		} else {
			ll x=rand()%(maxx-minx+1)+minx;
			ll y=rand()%(maxx-minx+1)+minx;
			printf("union %lld %lld\n", x, y);
		}
	}
	printf("\n");

    return 0;
}
