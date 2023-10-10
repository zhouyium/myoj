//5735
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
    ll maxx = 1e4;//1000位
    ll minx = 1e4;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);
    maxx=1e4;
    minx=-1e4;
    for (int i=1; i<=n; i++) {
    	ll t=rand()%(maxx-minx+1)+minx;
    	printf("%lld ", t);
	}
	printf("\n");

    return 0;
}
