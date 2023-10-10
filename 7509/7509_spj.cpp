//7509: [CSES Problem Set] Sum of Two Values
//http://47.110.135.197/problem.php?id=7509
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int AC=0;
const int WA=1;

const int N=2e5+10;
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

	//读取输入文件
	string strOut;
	getline(f_out, strOut);
	
	string strUser;
	getline(f_user, strUser);
	
	if (strOut==strUser) {
		return AC;
	} else if (strOut=="NO SOLUTION") {
		return WA;
	}
	//检查是否满足要求 
	LL n,x;
	f_in>>n>>x;
	for (LL i=1; i<=n; i++) {
		f_in>>a[i];
	}
	
	//解析用户答案 
	LL cnt=0;
	LL sum=0;
	LL t;
	stringstream ss(strOut);
	while (ss>>t) {
		cnt++;
		sum+=a[t];
	}
	
	if (cnt==2 && sum==x) {
		return AC;
	} else {
		return AC+1;
	}
}
