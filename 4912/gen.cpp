//4912: 敲七
//http://47.110.135.197/problem.php?id=4912
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
    
    freopen("09.in", "w", stdout);
    LL maxx = 1e3;
    LL minx = 1;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=1000;
		maxx=1000;
		LL n = rand()%(maxx-minx+1)+minx;
		maxx=n;
		LL m = rand()%(maxx-minx+1)+minx;
		minx=1e4;
		maxx=1e5;
		LL t = rand()%(maxx-minx+1)+minx;
		cout<<n<<" "<<m<<" "<<t<<"\n";
		
		//n个名字 
		for (LL j=0; j<n; j++) {
			minx=1;
			maxx=1e6;
			LL a = rand()%(maxx-minx+1)+minx;
			LL b = rand()%(maxx-minx+1)+minx;
			LL c = rand()%(maxx-minx+1)+minx;
			minx=0;
			maxx=25;
			LL d = rand()%(maxx-minx+1)+minx;
			LL e = rand()%(maxx-minx+1)+minx;
			cout<<(char)('a'+j%26)<<a<<(char)('a'+d)<<b<<(char)('z'-e)<<c<<"\n";
		}
	}
	
    return 0;
}
