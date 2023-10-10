//7492: [CSES Problem Set] Palindrome Reorder
//http://47.110.135.197/problem.php?id=7492
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int AC=0;
const int WA=1;

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
	//检查是否是回文
	LL n=strUser.size();
	for (LL i=0, j=n-1; i<j; i++, j--) {
		if (strUser[i]!=strUser[j]) {
			return WA+1;
		}
	}
	return AC;
}
