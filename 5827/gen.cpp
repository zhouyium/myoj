//5827

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
    
    freopen("09.in", "w", stdout);
    
    //生成n,m
    ll maxx = 100;//1000位
    ll minx = 100;
    ll n = rand()%(maxx-minx+1)+minx;
	maxx=100;
	minx=100;
    ll m = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<m<<"\n";
    
	maxx=1;
	minx=0;
    for (int i=1; i<=n; i++) {
    	for (int j=1; j<=m; j++) {
    		ll t = rand()%(maxx-minx+1)+minx;
    		cout<<t;
		}
		cout<<"\n";
	}
	
	maxx=n;
	minx=1;
	ll x= rand()%(maxx-minx+1)+minx;
	maxx=m;
	minx=1;
	ll y= rand()%(maxx-minx+1)+minx;
	cout<<x<<" "<<y<<"\n";

    return 0;
}
