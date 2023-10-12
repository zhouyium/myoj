#include <cstdio>
int main() {
	int x;
	scanf("%d",&x);
	int y;
	y = x * 2 - 1;
	int i,j;
	for(i=0; i<y; i++) {
		for(j=0; j<y; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
