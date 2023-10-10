#include <cstdio>
#include <algorithm>

bool mycmp(int x, int y) {
	return x > y;
}

int main() {
	int arre[10];
	int idxe = 0;
	int arro[10];
	int idxo = 0;
	
	int i;
	int shu;
	for (i=0; i<10; i++) {
		scanf("%d", &shu);
		if (shu%2==0) {
			//Å¼Êý
			arre[idxe++] = shu;
		} else {
			//ÆæÊý
			arro[idxo++] = shu;
		}
	}
	
	std::sort(arre, arre+idxe);
	std::sort(arro, arro+idxo, mycmp);
	
	for (i=0; i<idxo; i++) {
		printf("%d ", arro[i]);
	}
	for (i=0; i<idxe; i++) {
		printf("%d ", arre[i]);
	}
	printf("\n");
	
	return 0;
}
