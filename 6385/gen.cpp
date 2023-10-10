//6385

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
    
    freopen("07.in", "w", stdout);
    
    //生成n,m
    LL maxx = 1e5;//1000位
    LL minx = 1e5;
    LL n = rand()%(maxx-minx+1)+minx;
    maxx=1e5;
    minx=1e5;
    LL m = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<m<<"\n";
    
    for (int i=1; i<=m; i++) {
		maxx=n;
		minx=1;
		LL u = rand()%(maxx-minx+1)+minx;
		maxx=n;
		minx=1;
		LL v = rand()%(maxx-minx+1)+minx;
		cout<<u<<" "<<v<<"\n";
	}

    return 0;
}
