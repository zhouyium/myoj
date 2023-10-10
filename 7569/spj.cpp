//7569: [CSES Problem Set] Monsters
//http://47.110.135.197/problem.php?id=7569
#include<bits/stdc++.h>
#include"../testlib.h"

#define __windows
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-4;

const int N=1e3+10;
char a[N][N];
LL n,m;
const LL dx[]={0,1,0,-1,0};
const LL dy[]={0,0,1,0,-1};

void solve(LL T) {
	//从inf读取 
	LL sx=-1,sy=-1;
	n=inf.readLong();
	m=inf.readLong();
	cerr<<"in:\n"<<"n="<<n<<",m="<<m<<"\n";
	char ch;
	ch=inf.readChar();//'\r'
#ifdef __windows
	ch=inf.readChar();//'\n'
#endif
	
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			a[i][j]=inf.readChar();
			//cerr<<a[i][j];
			if (a[i][j]=='A'){
				sx=i;
				sy=j;
			}
		}
		cerr<<"\n";
		ch=inf.readChar();//'\r'
#ifdef __windows
		ch=inf.readChar();//'\n'
#endif		
	}
	cerr<<"sx="<<sx<<",sy="<<sy<<"\n\n";
	
	//从ouf中读取
	string outo=ouf.readString();
	cerr<<"std:\n"<<outo<<"\n";
	LL outl;
	string outp="";
	if (outo=="YES") {
		outl=ouf.readLong();
		if (outl>0) {
			outp=ouf.readString();
			outp=ouf.readString();
			cerr<<outl<<"\n"<<outp<<"\n";
		}
	}
	cerr<<"\n";
	
	//从ans中读取 
	string anso=ans.readString();
	cerr<<"user\n"<<anso<<"\n";
	LL ansl=-1;
	string ansp="";
	if (anso=="YES") {
		ansl=ans.readLong();
		if (ansl>0) {
			ansp=ans.readString();
			ansp=ans.readString();
			cerr<<ansl<<"\n"<<ansp<<"\n";
		}
	}
	cerr<<"\n";
	
	//比较答案
	if (outo!=anso){
		quitf(_wa, "The answer is wrong 1.\n");	
		return;
	}
	if (anso=="NO"&&outo==anso) {
		quitf(_ok, "The answer is correct 1.\n");
		return;
	}
	if (ansp.size()!=ansl) {
		quitf(_wa, "The answer is wrong 2.\n");	
		return;
	}
	if (ansl<0){
		quitf(_wa, "The answer is wrong 3.\n");	
		return;
	}
	if (ansl==outl&&ansp==outp){
		quitf(_ok, "The answer is correct 2.\n");
		return;
	}
	//验证用户的路径是否可行
	LL x=sx,y=sy;
	for (LL i=0;i<ansl;i++){
		LL idx=-1;
		if (ansp[i]=='D'){
			idx=1;
		}else if (ansp[i]=='R'){
			idx=2;
		}else if (ansp[i]=='R'){
			idx=3;
		}else if (ansp[i]=='L'){
			idx=4;
		}
		if (idx==-1){
			quitf(_wa, "The answer is wrong 4.\n");
			return;
		}
		cerr<<"i="<<i<<",idx="<<idx<<",x="<<x<<",y="<<y<<"\n";
		x=x+dx[idx];
		y=y+dy[idx];
		//x,y合法性
		if (x<1||x>n||y<1||y>m) {
			cerr<<"i="<<i<<",x="<<x<<",y="<<y<<"\n"; 
			quitf(_wa, "The answer is wrong 5.\n");
			return;
		}
		if (a[x][y]!='.'){
			quitf(_wa, "The answer is wrong 6.\n");
			return;
		}
	} 
	//检查是否在边缘
	if (x==1||x==n||y==1||y==m) {
		cerr<<"out x="<<x<<",y="<<y<<"\n";
		quitf(_ok, "The answer is correct 3.\n");
		return;
	}
	quitf(_wa, "The answer is wrong 7.\n");	
}

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	registerTestlibCmd(argc, argv);

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//T=inf.readLong();
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve(i);
	}
	
	return 0;
}

