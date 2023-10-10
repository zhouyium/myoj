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
    
    freopen("7.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    n=1e5;
    printf("%lld\n", n);

    maxx=1e4;
    minx=300;
    for (ll i=1; i<=n; i++) {
	    ll t = rand()%(maxx-minx+1)+minx; 
	    printf("%lld ", t);
	}
	printf("\n");
	
	ll m=1e5;
	printf("%lld\n", m);
    for (ll i=1; i<=m; i++) {
    	ll l,r;
	    maxx=100;
	    minx=1;
    	l = rand()%(maxx-minx+1)+minx; //1; 
	    maxx=1e5;
	    minx=1e5-20;
    	r = rand()%(maxx-minx+1)+minx; //1e5;
    	printf("%lld %lld\n", l, r);
	}
	
    return 0;
}
