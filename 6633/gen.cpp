//6630: 加边的无向图
//http://47.110.135.197/problem.php?id=6630
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e2+10;
bool a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=200;
    cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 170;
	    LL minx = 160;
	    LL n = rand()%(maxx-minx+1)+minx;
		maxx=160;
		minx=150;
	    LL m = rand()%(maxx-minx+1)+minx;
	    cout<<n<<' '<<m<<"\n";
	    
		maxx=170;
		minx=1;
	    for (LL i=1; i<=n; i++) {
	    	memset(a, false, sizeof a);
		    	for (LL j=1; j<=m; ) {
	    		LL x = rand()%(maxx-minx+1)+minx;
	    		if (a[x]==false) {
	    			a[x]=true;
	    			cout<<x<<" ";
	    			j++;
				}
			}
			cout<<"\n";
		}

		maxx=200;
		minx=1;
    	memset(a, false, sizeof a);
		for (LL j=1; j<=m; ) {
    		LL x = rand()%(maxx-minx+1)+minx;
    		if (a[x]==false) {
    			a[x]=true;
    			cout<<x<<" ";
    			j++;
			}
		}
		cout<<"\n";
	}

    return 0;
}
