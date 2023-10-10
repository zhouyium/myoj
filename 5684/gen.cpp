#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500+10;
ll a[MAXN][MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    //freopen("9.in", "w", stdout);
    
    //生成n,m
    ll maxx = 3;//1000位
    ll minx = 3;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);
    maxx=30;
	minx=-5;
    for (ll i=1; i<=n; i++) {
    	for (ll j=1; j<=i; j++) {
    		a[i][j]=rand()%(maxx-minx+1)+minx;
    		printf("%lld ", a[i][j]);
		}
		printf("\n");
	}

    return 0;
}
