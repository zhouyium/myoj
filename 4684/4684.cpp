//4685: Priority_Queue����ʹ�ã�����Priority_Queue���� I
//http://47.110.135.197/problem.php?id=4684
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <cstdio>

int main () {
	freopen("06.in", "r", stdin);
	freopen("06.out", "w", stdout);
	std::priority_queue<int, std::vector<int>, std::greater<int> >q;
	//std::priority_queue<int>q;
	int n;
	std::cin >> n;
	
	int i;
	int shu;
	for (i=0; i<n; i++) {
		std::cin >> shu;
		q.push(shu);
	}
	
	while (!q.empty()) {
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << '\n';
	
	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
