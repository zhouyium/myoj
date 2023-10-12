//http://47.110.135.197/problem.php?id=6261
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
    
    //生成n个顶点，m条边 
    LL maxx = 1e6;
    LL minx = 1e6;
    LL n = rand()%(maxx-minx+1)+minx;
    maxx = 1e6;
    minx = 9e5;
    LL m = rand()%(maxx-minx+1)+minx;
	cout<<n<<" "<<m<<"\n";
	
	for (LL i=1; i<=m; i++) {
	    minx = 1;
	    maxx = n;
	    LL u = rand()%(maxx-minx+1)+minx;
	    LL v = rand()%(maxx-minx+1)+minx;
	    minx = 1;
	    maxx = n;
	    LL w = rand()%(maxx-minx+1)+minx;
		cout<<u<<" "<<v<<" "<<w<<"\n";
	}
    
    minx = 7*n/8;
    maxx = n;
    LL q = rand()%(maxx-minx+1)+minx;
    cout<<q<<"\n";
	for (LL i=1; i<=q; i++) {
	    minx = 1;
	    maxx = n;
	    LL u = rand()%(maxx-minx+1)+minx;
	    cout<<u<<"\n";
	}

    return 0;
}
