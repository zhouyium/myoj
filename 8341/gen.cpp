//8341: 三次方的和
//http://47.110.135.197/problem.php?id=8341
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("07.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=4000;
		maxx=4000;
		LL n = rand()%(maxx-minx+1)+minx;
		minx=9.5e3;
		maxx=1e4;
		LL m = rand()%(maxx-minx+1)+minx;
		cout<<n<<" "<<m<<"\n";
		
		//n个数据
		LL j;
		for (j=1; j<=n; j++) {
			minx=1;
			maxx=1e3;
			LL a = rand()%(maxx-minx+1)+minx;
			cout<<a<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
