#include <bits/stdc++.h>
using namespace std;
using LL=long long;

//BIT
const int N=1E6+10;
LL bit[N];

// 快速求出最低位的bit。這是其中一種方式。
int lower_bit(int x) {
    return x & -x;
}

// value[1] + value[2] + ... + value[n]
LL sum(int n) {
    LL s = 0;
    while (n > 0) {
        s += bit[n];
        n -= lower_bit(n);
    }
    return s;
}

// value[n] += d
void add(int n, LL d) {
    while (n <= N) {
        bit[n] += d;
        n += lower_bit(n);
    }
}

// value[a] + value[a+1] + ... + value[b]
LL query(int a, int b) {
    if (a > b) {
    	swap(a, b);
    }
    return sum(b) - sum(a-1);
} 

int main() {
	int n,q;
	cin>>n>>q;
	for (int i=1; i<=q; i++) {
		LL op;
		cin>>op;
		if (op==1) {
			LL pos,x;
			cin>>pos>>x;
			add(pos,x);
		} else {
			LL l,r;
			cin>>l>>r;
			cout<<query(l,r)<<"\n";
		}
	}
	
	return 0;
}
