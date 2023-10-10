//6384: 最长合法括号子串
//http://47.110.135.197/problem.php?id=6384
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	cin>>s;
	
	stack<int> st;//保存下表索引 
	LL resl=0, resc=1;
	for (LL i=0; i<s.size(); i++) {
		if (st.size() && s[i]==')' && s[st.top()]=='(') {
			st.pop();
		} else {
			st.push(i);
		}
		
		LL r;
		if (st.size()) {
			r=i-st.top();
		} else {
			r=i+1;
		}
		
		if (r>resl) {
			resl=r;
			resc=1;
		} else if (r>0 && r==resl) {
			resc++;
		}
	}
	
	cout<<resl<<" "<<resc<<"\n";

	return 0;
}

