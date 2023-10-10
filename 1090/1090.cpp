#include <iostream>

using namespace std;

void subsets(char s[], int length) {
    cout << "{}" << endl;

    unsigned int i = 1, judgeEnd = (1 << length) - 1; //judgeEnd�����ж�i ��������ֹ
    unsigned int mask = 0; //mask�����˳� i ��ÿһλ
    int j = 0;
    for(; (i & judgeEnd) > 0; ++i, cout << "}"<< endl){
        for(cout << "{",mask = 1 << (length - 1), j = 0; j < length; ++j, mask = mask >> 1){
            if(mask & i) {
				cout << s[j];
			} 
        }
    }
}

int main() {
	freopen("07.out", "w", stdout);
	int n;
	char a[64];
	char mark[64] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	subsets(a, n);

	return 0;
}

