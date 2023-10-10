#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("6.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e6;//1000位
    ll minx = 1e6;
    ll n = rand()%(maxx-minx+1)+minx;
    //n=1200;
    printf("%lld\n", n);

	maxx=1e9;
	minx=1;
	a[0]=2;
    for (int i=1; i<=n; i++) {
    	a[i]=rand()%(maxx-minx+1)+minx;
	}
	sort(a+1, a+n+1);
    for (int i=1; i<=n; i++) {
    	printf("%lld ", a[i]);
	}
	printf("\n");

    return 0;
}
