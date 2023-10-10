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
    
    //freopen("8.in", "w", stdout);
    
    //生成n,m
    ll maxx = 90;//1000位
    ll minx = 70;
    ll n = rand()%(maxx-minx+1)+minx;
	maxx=43;
	minx=33;
    for (int i=1; i<=n; i++) {
    	ll t=rand()%(maxx-minx+1)+minx;
    	printf("%c", (char)t);
	}
	printf("\n");

    return 0;
}
