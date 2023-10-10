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
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=1e5;
    minx=1e5; 
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n, m);
    maxx=n;
    minx=1;
    for (int i=1; i<=m; i++) {
    	int t=rand()%20+1;
    	ll x=rand()%(maxx-minx+1)+minx;
    	ll y=rand()%(maxx-minx+1)+minx;
    	if (t<=12) {
    		//C
    		printf("C %lld %lld\n", x, y);
		} else if (t<=16) {
			//Q1
			printf("Q1 %lld %lld\n", x, y);
		} else {
			//Q2
			printf("Q2 %lld\n", x);
		}
	}

    return 0;
}
