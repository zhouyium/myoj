//4529
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
    
    freopen("09.in", "w", stdout);
	
	ll maxx=100;
	ll minx=100;
	ll m = rand()%(maxx-minx+1)+minx;
	maxx=100;
	minx=100;
	ll n = rand()%(maxx-minx+1)+minx;
	
	maxx=1;
	minx=0;
	ll cnt=0;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			a[i][j]=rand()%(maxx-minx+1)+minx;
			if (0==a[i][j]) {
				cnt++;
			}
		}
	}
	
	maxx=cnt;
	minx=1;	
	ll k=rand()%(maxx-minx+1)+minx;
	cout<<m<<" "<<n<<" "<<k<<"\n";
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

    return 0;
}
