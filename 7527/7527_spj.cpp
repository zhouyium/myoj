//7527: [CSES Problem Set] Sum of Four Values
//http://47.110.135.197/problem.php?id=7527
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int AC=0;
const int WA=1;

const int N=5e3+10;
LL a[N];

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

	string strOut;
	getline(f_out, strOut);
	cerr<<strOut<<"\n";
	
	string strUser;
	getline(f_user, strUser);
	cerr<<strUser<<"\n";
	
	if (strOut==strUser) {
		cerr<<"OK 1\n";
		return 0;
	} else if (strOut=="IMPOSSIBLE") {
		cerr<<"Wrong 1\n";
		return WA;
	}

	//检查答案 
	//读取输入文件
	LL n,x;
	f_in>>n>>x;
	for (LL i=1; i<=n; i++) {
		f_in>>a[i];
	}
	
	f_user.close();
	f_user.open(args[3]); 
	LL t;
	LL cnt=0;
	LL sum=0;
	while (f_user>>t) {
		if (t<1||t>n) {
			cerr<<"Wrong 2\n";
			return WA+1;
		}
		cerr<<a[t]<<" ";
		cnt++;
		sum+=a[t];		
	}
	
	//是否是4个数字
	cerr<<"\n";
	if (cnt!=4) {
		cerr<<"Wrong 3\n";
		return WA+2;
	}
	if (sum!=x) {
		cerr<<"Wrong 4\n";
		return WA+3;
	}

	cerr<<"OK 2\n";
	return 0;
}
