//7743: USACO 2022 December Contest, Bronze —— Problem 2. Feeding the Cows
//http://47.110.135.197/problem.php?id=7743
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int AC=0;
const int WA=1;

const int N=2e5+10;

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
	LL T;
	f_in>>T;
	for (LL i=1; i<=T; i++) {
		cerr<<"\nTestcase "<<i<<":\n";
		//读取in 
		LL n,K;
		f_in>>n>>K;
		cerr<<"n="<<n<<",K="<<K<<"\n";
		string sCow;
		f_in>>sCow;
		
		//读取out
		LL n1;
		f_out>>n1;
		string sOut;
		f_out>>sOut;
		
		//读取usr
		LL n2;
		f_user>>n2;
		string sUser;
		f_user>>sUser;
		cerr<<"cow:\n"<<sCow<<"\n";
		cerr<<sUser<<"\n";
		
		if (n1!=n2) {
			return WA;
		}
		if (sOut==sUser) {
			continue;
		}
		if (sUser.size()!=n) {
			return WA+1;
		}
		
		//检查用户输出是否符合要求
		vector<LL> vpg;//G位置 
		vector<LL> vph;//H位置 
		for (LL i=0; i<n; i++) {
			if (sUser[i]=='G') {
				vpg.push_back(i);
			} else if (sUser[i]=='H') {
				vph.push_back(i);
			}
		}
		cerr<<"vpg ";
		for (const auto &x:vpg) {
			cerr<<x<<" ";
		}
		cerr<<"\n";
		cerr<<"vph ";
		for (const auto &x:vph) {
			cerr<<x<<" ";
		}
		cerr<<"\n";
		for (LL i=0; i<n; i++) {
			LL res=0;
			vector<LL>::iterator pos;
			if (sCow[i]=='G') {
				//在vpg中找位置
				pos = lower_bound(vpg.begin(), vpg.end(), i);
				if (pos==vpg.end()) {
					res = abs(vpg[vpg.size()-1]-i);
				} else {
					if (pos==vpg.begin()) {
						res = abs(*pos-i);
					} else {
						res = min(abs(*pos-i), abs(*(pos-1)-i));
					}
				}
			} else {
				//在vph中找位置
				pos = lower_bound(vph.begin(), vph.end(), i);
				if (pos==vph.end()) {
					res = abs(vph[vph.size()-1]-i);
				} else {
					if (pos==vph.begin()) {
						res = abs(*pos-i);
					} else {
						res = min(abs(*pos-i), abs(*(pos-1)-i));
					}
				}
			}
			cerr<<i<<"-th cow is "<<sCow[i]<<". distance is "<<res<<"\n";
			if (res>K) {
				cerr<<i<<" err\n";
				return WA+2;
			}
		}
	}
	
	return AC;
}
