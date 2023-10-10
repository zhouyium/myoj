//http://47.110.135.197/problem.php?id=1026
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[102];
int main() {
	//freopen("8.in", "r", stdin);
	//freopen("8.out", "w", stdout);
	gets(s);
	
	int len=strlen(s);
	for (int i=0; i<len-1; i++) {
		printf("%c", s[i]+s[i+1]);
	}
	printf("%c\n", s[len-1]+s[0]);

	return 0;
}

