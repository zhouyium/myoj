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
    
    freopen("9.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    printf("%lld\n", n);

	maxx=1e9;
	minx=1;
    for (int i=1; i<=n; i++) {
    	ll x=rand()%(maxx-minx+1)+minx;
    	printf("%lld ", x);
	}
	printf("\n"); 

    return 0;
}
