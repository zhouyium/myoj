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
    
    freopen("9.in", "w", stdout);
    
    //生成n,m
    ll maxx = 5e4;//1000位
    ll minx = 5e4;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=5e2+20;
    minx=5e2; 
    ll m = rand()%(maxx-minx+1)+minx;
    maxx=1.5e5;
    minx=1.5e5; 
    ll K = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld %lld\n", n, m, K);
    maxx=n;
    minx=1;
    for (int i=1; i<=m; i++) {
    	ll x=rand()%(maxx-minx+1)+minx;
    	ll y=rand()%(maxx-minx+1)+minx;
    	printf("%lld %lld\n", x, y);
	}
    for (int i=1; i<=K; i++) {
    	int t=rand()%20+1;
    	ll x=rand()%(maxx-minx+1)+minx;
    	ll y=rand()%(maxx-minx+1)+minx;
    	if (t<=15) {
    		printf("cut %lld %lld\n", x, y);
		} else{
			printf("ask %lld %lld\n", x, y);
		}
	}
    return 0;
}
