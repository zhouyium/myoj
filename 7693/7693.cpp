#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=30;
LL blocksNeeded[N];

void solve() {
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		string firstWord;
		string secondWord;
		cin>>firstWord>>secondWord;
		
		LL firstFrequency[N]={};
		LL secondFrequency[N]={};
		// get the frequency counts
		for (LL j=0; j<firstWord.size(); j++) {
			firstFrequency[firstWord[j]-'a']++;
		}
		for (LL j=0; j<secondWord.size(); j++) {
			secondFrequency[secondWord[j]-'a']++;
		}
		
		// update the number of blocks needed
		for(int j = 0; j < 26; j++) {
			if(firstFrequency[j] > secondFrequency[j]) {
				blocksNeeded[j] += firstFrequency[j];
			}
			else {
				blocksNeeded[j] += secondFrequency[j];
			}
		}
	}
	
	// print the answer
	for(int i = 0; i < 26; i++) {
		cout<<blocksNeeded[i]<<"\n";
	}
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

