#include <iostream>

int main() {
	int testcases{};
	std::cin >> testcases;
	for(int i{ 0 }; i < testcases; ++i) {
		int size{};
		int bound{};
		int sum{};	
		int j{ 0 };	
		std::cin >> size >> bound >> sum;
		while(++j < size && (sum / j) > bound) {
			int curr{};
			std::cin >> curr;
			if(curr <= 0) 
				continue;
			sum += curr;
		}
		std::cout << j - 1;
	}
}
/*10
10 9
16 18 19 18 17 16 19 16 20 17
6 9
20 17 16 15 17 15
10 11
20 20 18 16 18 20 18 20 18 16
8 10
18 20 18 19 16 15 16 16
10 8
15 16 16 17 15 15 16 17 18 18
8 11
16 19 18 16 19 20 20 20
9 11
20 20 16 16 15 20 17 17 15
6 9
20 17 15 17 18 17
5 8
18 16 19 16 16
5 7
15 15 16 19 16*/