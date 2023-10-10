//http://47.110.135.197/problem.php?id=7692
//7692: USACO 2016 December Contest, Bronze ¡ª¡ª Problem 1. Square Pasture
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

void solve() {
	// track the bottom, top, left, and rightmost points that need to be covered 
	int smallestX = 10;
	int largestX = 0;
	int smallestY = 10;
	int largestY = 0;

	// read in two lines, store corners of the pastures
	for(int i = 0; i < 2; i++) {
		int xLow;
		int yLow;
		int xHigh;
		int yHigh;
		cin>>xLow>>yLow>>xHigh>>yHigh;
		
		if(xLow < smallestX) {
			smallestX = xLow;
		}
		if(xHigh > largestX) {
			largestX = xHigh;
		}
		if(yLow < smallestY) {
			smallestY = yLow;
		}
		if(yHigh > largestY) {
			largestY = yHigh;
		}
	}
	
	// compute the desired side length of the square
	int desiredSideLength = largestX - smallestX;
	if(largestY - smallestY > largestX - smallestX) {
		desiredSideLength = largestY - smallestY; 
	}
	
	cout<<desiredSideLength * desiredSideLength<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
	
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

