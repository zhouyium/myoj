//5737
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
    
    //生成n,m
    ll maxx = 10000;//1000位
    ll minx = 10000;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);
    maxx=10000;
    minx=-10000;
    for (int i=1; i<=n; i++) {
    	ll t=rand()%(maxx-minx+1)+minx;
    	printf("%lld ", t);
	}
	printf("\n");
	
    maxx=1e5;
    minx=1e5;
	ll m = rand()%(maxx-minx+1)+minx;
	printf("%lld\n", m);
    for (int i=1; i<=m; i++) {
	    maxx=n/4;
	    minx=1;
    	ll pos=rand()%(maxx-minx+1)+minx;
	    maxx=n;
	    minx=n*4/5;
    	ll val=rand()%(maxx-minx+1)+minx;
    	
    	printf("%lld %lld\n", pos, val);
	}
	
    return 0;
}
