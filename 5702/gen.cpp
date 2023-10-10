//5702
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
    
    freopen("09.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    maxx=5000;
	minx=-5000;
    for (ll i=1; i<=n; i++) {
    	ll x=rand()%(maxx-minx+1)+minx;
    	ll y=rand()%(maxx-minx+1)+minx;
    	cout<<x<<" "<<y<<"\n";
	}

    return 0;
}
