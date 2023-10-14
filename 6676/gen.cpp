//6676: DP43 最少的完全平方数
//http://47.110.135.197/problem.php?id=6676

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="abcdefghijklmnopqrstuvwxyz";
string s1="love";

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
	char out[16];
	char in[16];
	LL sum=0;
	int cnt=1;
	do {
		sum+=cnt*cnt;
		sprintf(in, "%02d.in", cnt);
		freopen(in, "w", stdout);
		cout<<sum<<"\n";
		fclose(stdout);
		
		sprintf(out, "%02d.out", cnt);
		freopen(out, "w", stdout);
		cout<<cnt<<"\n";
		fclose(stdout);
		cnt++;
	}while (sum<10000);
	
	return 0;
}
