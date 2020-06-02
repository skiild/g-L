#include "Mesure.h"
#include <iostream>
using namespace std;

int main() {
	Mesure m = { 0.5, 1, Mesure::O3, time(0) };
	cout << m.getValeur();
	return 0;
}
