//5736
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
    
    freopen("04.in", "w", stdout);
    
    //生成n,m
    ll maxx = 70;//1000位
    ll minx = 60;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);
    maxx=100;
    minx=-100;
    for (int i=1; i<=n; i++) {
    	ll t=rand()%(maxx-minx+1)+minx;
    	printf("%lld ", t);
	}
	printf("\n");
	
    maxx=3000;
    minx=2000;
	ll m = rand()%(maxx-minx+1)+minx;
	printf("%lld\n", m);
    for (int i=1; i<=m; i++) {
	    maxx=n;
	    minx=1;
    	ll pos=rand()%(maxx-minx+1)+minx;
	    maxx=1e4;
	    minx=-1e4;
    	ll val=rand()%(maxx-minx+1)+minx;
    	
    	printf("%lld %lld\n", pos, val);
	}
	
    return 0;
}
