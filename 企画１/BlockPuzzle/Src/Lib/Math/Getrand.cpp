#include "getrand.h"
#include <random>

using namespace std;

int CRand::Rand(int min,int max) {
	random_device rd;
	mt19937 mt(rd());
	//min‚©‚çmax‚Ü‚Å‚Ì—”‚ğ¶¬
	uniform_int_distribution<int> dist(min, max);

	return dist(mt);
}

float CRand::Rand(float min, float max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> dist(min, max);

	return dist(mt);
}

