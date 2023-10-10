//7989: ABC255 ¡ª¡ª B - Light It Up
//http://47.110.135.197/problem.php?id=7989
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int AC=0;
const int WA=1;

const int N=2e5+10;
const double EPS=1e-5;

int main(int argc,char *args[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif

    ifstream f_in;
    f_in.open(args[1]); 
    ifstream f_out;
    f_out.open(args[2]); 
    ifstream f_user;
    f_user.open(args[3]); 

	//¶ÁÈ¡´ð°¸
	double ans1;
	f_out>>ans1;
	double ans2;
	f_user>>ans2;
	double dif=abs(ans1-ans2);
	dif=dif/ans1;
	cerr<<fixed<<setprecision(7)<<dif<<"\n";
	if (dif>EPS) {
		return WA;
	}
	
	return AC;
}
