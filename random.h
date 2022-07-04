#include <random>
#include <chrono>

namespace Random {
	/* seed a mersenne twister with the clock (can't be changed by the user)
	if the program is run several times in quick succession, 
	the seeds generated for each run won’t be that different, 
	which can impact the quality of the random results from a statistical standpoint*/
	std::mt19937 clockMt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};
	
	std::random_device rd;
	//seed random sequence with many seeds to get more accurate result when filling mt
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(),rd(), rd(), rd(), rd() };

	std::mt19937 systemMt{ ss };
	
	int get(int min, int max) {
		std::uniform_int_distribution result{min, max};
		return result(systemMt);
	}
	
}