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
    
    freopen("10.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1000;//1000位
    ll minx = 1000;
    ll n = rand()%(maxx-minx+1)+minx;
    //n=89;
    maxx=1000;
    minx=1000;
	ll m = rand()%(maxx-minx+1)+minx;
	//m=95;
	printf("%lld %lld\n", n, m);

    maxx=2000;
    minx=1;
    for (ll i=1; i<=n; i++) {
	    ll t = rand()%(maxx-minx+1)+minx; 
	    printf("%lld ", t);
	}
	printf("\n");
	
    for (ll i=1; i<=m; i++) {
    	ll x,y;
	    maxx=50;
	    minx=1;
    	x = rand()%(maxx-minx+1)+minx; //1; 
	    maxx=n;
	    minx=n-50;
    	y = rand()%(maxx-minx+1)+minx; //1e5;
    	printf("%lld %lld\n", x, y);
	}
	
    return 0;
}
