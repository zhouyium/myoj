#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

//Find greatest common divisors of two numbers
LL gcd(LL a,LL b) {
    if(a == 0) {
        return b;
	}
    return gcd(b%a,a);
}

void solve() {
	//Take number as string
	string str;
	cin>>str;
	
	//Represent number in num/den form
	//as for 2.25 represent it as 225/100
	bool flag = false;
	LL num=0,den=1;
	for (LL i=0;i<str.length();i++) {
	    if(flag) {
	        den = den*10 ;
		}
	    if(str[i] == '.') {
	        flag = true;
	        continue;
	    }
	    num = num*10 + (str[i]-'0');
	}
	
	//Now find gcd of num and den as it can divide both
	LL GCD = gcd(num,den);
	
	//Divide den by gcd and print
	cout<<(den/GCD)<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	LL T;
	cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}

