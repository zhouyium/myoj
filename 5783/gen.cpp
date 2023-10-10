//5783
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e2+10;
int a[MAXN][MAXN];

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif	
    int seed = time(NULL);
    if (argc>1) {
        //ÓÐ²ÎÊý
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("12.in", "w", stdout);
	
	ll maxx=5e5;
	ll minx=5e5;
	ll n = rand()%(maxx-minx+1)+minx;
	ll a,b,c;
	while (n--) {
		maxx=1e9;
		minx=1e3;
		a=rand()%(maxx-minx+1)+minx;
		maxx=2e4;
		minx=1e4;
		b=rand()%(maxx-minx+1)+minx;
		maxx=4e4;
		minx=1e2;
		c=rand()%(maxx-minx+1)+minx;
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}

    return 0;
}
