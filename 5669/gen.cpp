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
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=1e5;
	minx=1e5;
    ll s = rand()%(maxx-minx+1)+minx;
    maxx=10000;
	minx=100;
	ll sum=0;
    for (ll i=1; i<=n; i++) {
    	a[i]=rand()%(maxx-minx+1)+minx;
    	sum+=a[i];
	}

    printf("%lld %lld\n", n, s);
    for (ll i=1; i<=n; i++) {
    	printf("%lld ", a[i]);
	}
	printf("\n");

    return 0;
}
