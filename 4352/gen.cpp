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
    
    freopen("09.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e4;//1000位
    ll minx = 1e4;
    ll n = rand()%(maxx-minx+1)+minx;
	maxx=100;
	minx=100;
	ll m = rand()%(maxx-minx+1)+minx;
	cout<<n<<" "<<m<<"\n";
    for (int i=1; i<=m; i++) {
		maxx=n/3;
		minx=0;
    	ll x=rand()%(maxx-minx+1)+minx;
    	cout<<x<<" ";
    	
		maxx=300;
		minx=-300;
    	ll t=rand()%(maxx-minx+1)+minx;
    	x=x+t;
    	if (x<0) {
    		x=0;
		}
		
		maxx=n;
		minx=x;		
    	ll y=rand()%(maxx-x+1)+minx;
    	cout<<y<<"\n";
	}

    return 0;
}
