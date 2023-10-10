#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("5.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    n=1200;
	maxx=1e4;
	minx=1e4;
    ll q = rand()%(maxx-minx+1)+minx;
    q=6000;
    printf("%lld %lld\n", n, q);

	maxx=300;
	minx=1;
    for (int i=1; i<=n; i++) {
    	a[i]=rand()%(maxx-minx+1)+minx;
	}
	sort(a+1, a+n+1);
    for (int i=1; i<=n; i++) {
    	printf("%lld ", a[i]);
	}
	printf("\n");
	//q个查询 
	maxx=10000;
	minx=1;
	for (int i=1; i<=q; i++) {
		ll t=rand()%(maxx-minx+1)+minx;
		printf("%lld\n", t);
	}

    return 0;
}
