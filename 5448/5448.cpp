#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	deque<int> dq;
	for (int i=1; i<=n; i++) {
		string op;
		cin>>op;

		int x;
		if ("push_back"==op) {
			cin>>x;
			dq.push_back(x);
			cout<<dq.size()<<"\n";
		} else if ("push_front"==op) {
			cin>>x;
			dq.push_front(x);
			cout<<dq.size()<<"\n";
		} else if ("operator[]"==op) {
			cin>>x;
			if (x>dq.size()) {
				cout<<"Invalid\n";
			} else {
				cout<<dq[x-1]<<"\n";
			}
		} else if ("pop_back"==op) {
			if (0==dq.size()) {
				cout<<"Empty\n";
			} else {
				dq.pop_back();
			}
		} else if ("pop_front"==op) {
			if (0==dq.size()) {
				cout<<"Empty\n";
			} else {
				dq.pop_front();
			}
		} else if ("size"==op) {
			cout<<dq.size()<<"\n";
		} else if ("front"==op) {
			if (0==dq.size()) {
				cout<<"Empty\n";
			} else {
				cout<<dq.front()<<"\n";
			}
		} else if ("back"==op) {
			if (0==dq.size()) {
				cout<<"Empty\n";
			} else {
				cout<<dq.back()<<"\n";
			}
		}
	}

	for (int i=dq.size(); i>0; i--) {
		cout<<dq[i-1]<<" ";
	}
	cout<<"\n";
	for (int i=0; i<dq.size(); i++) {
		cout<<dq[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
