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
    
    freopen("8.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1;
    ll n = rand()%(maxx-minx+1)+minx;
    n=1e5; 
    maxx=4e9;
	minx=3e9;
    ll s = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n, s);
    maxx=1e5;
	minx=5e4;
    for (ll i=1; i<=n; i++) {
    	a[i]=rand()%(maxx-minx+1)+minx;
	}

    for (ll i=1; i<=n; i++) {
    	printf("%lld ", a[i]);
	}
	printf("\n");

    return 0;
}
