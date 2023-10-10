#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
string name[MAXN];
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
    maxx = n;//1000位
    minx = n;
    ll m = rand()%(maxx-minx+1)+minx;
    printf("%lld %lld\n", n, m);

    maxx = 100000;//1000位
    minx = 10000;
	for (ll i=1; i<=n; i++) {
		int len=rand()%10+5;
		for (int j=1; j<len; j++) {
			char ch=rand()%26+'a';
			name[i].push_back(ch);
		}
		ll t = rand()%(maxx-minx+1)+minx;
		cout<<name[i];
	    printf(" %.3lf\n", 1.0*t/1000);
	}
	
    maxx = n;//1000位
    minx = 1;	
	for (ll i=1; i<=m; i++) {
		ll t = rand()%(maxx-minx+1)+minx;
		cout<<name[t]<<"\n";
	}

    return 0;
}
