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
    
    freopen("10.in", "w", stdout);
    
    //生成n,m
    ll maxx = 2e5;//1000位
    ll minx = 2e5;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx=500;
    ll m=1;
    printf("%lld %lld\n", n, maxx);
    do {
    	//
    	for (int i=1; i<=m+1; i++) {
	    	cout<<"get "<<i<<"\n";
		}
    	cout<<"union "<<m<<" "<<m+1<<"\n";
    	m++;
	} while (m<maxx);

    return 0;
}
