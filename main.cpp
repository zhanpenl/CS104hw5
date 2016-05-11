#include <iostream>
#include <vector>
#include "msort.h"
using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(12);
	v.push_back(-1);
	v.push_back(5);

	cout << "before: ";
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	AscComp comp1;
	// if (comp1(1, 8)) cout << "1 < 8" << endl;
	// if (comp1(2, 1)) cout << "2 < 1" << endl;

	mergeSort(v, comp1);
	cout << "after: ";
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}