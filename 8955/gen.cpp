//8955: B. Fear of the Dark
//http://47.110.135.197/problem.php?id=8955

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="0123456789. -$!_-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
	int seed = time(NULL);
	if (argc>1) {
		//有参数
		seed = atoi(argv[1]);
	}
	srand(seed);
	
	freopen("09.in", "w", stdout);
	
	LL T = ran(1e4,1e4);
	cout<<T<<"\n";
	
	while (T--)	{
		LL x,y;
		//Monocarp's house
		x = ran(0,2e3)-1e3;
		y = ran(0,2e3)-1e3;
		cout<<x<<" "<<y<<"\n";
		//the location of the first lantern
		x = ran(0,2e3)-1e3;
		y = ran(0,2e3)-1e3;
		cout<<x<<" "<<y<<"\n";
		//the location of the second lantern
		x = ran(0,2e3)-1e3;
		y = ran(0,2e3)-1e3;
		cout<<x<<" "<<y<<"\n";
	}

	return 0;
}
