//5736
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    //����n,m
    ll maxx = 1e6;//1000λ
    ll minx = 1e6;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx = 4;//1000λ
    minx = 4;
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n, m);
    maxx=10000;
    minx=-1000;
    for (int i=1; i<=n; i++) {
    	ll t=rand()%(maxx-minx+1)+minx;
    	printf("%lld ", t);
	}
	printf("\n");

    return 0;
}
