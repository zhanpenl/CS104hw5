#ifndef MSOER_H
#define MSOER_H

#include <vector>
#include <cmath>
#include <string>

struct AscComp {
	template <class T>
 	bool operator() (const T& lhs, const T& rhs) {
 		return lhs <= rhs;
 	}
};

struct DscComp {
	template <class T>
 	bool operator() (const T& lhs, const T& rhs) {
 		return lhs >= rhs;
 	}
}; 

// template <class T>
// struct AbsAscComp {
// 	bool operator() (const T& lhs, const T& rhs) {
// 		return abs(lhs) <= abs(rhs);
// 	}
// };

struct AlphaStrComp {
	bool operator() (const std::string& lhs, const std::string& rhs) {
		return lhs <= rhs;
	}
};

struct LengthStrComp {
	bool operator() (const std::string& lhs, const std::string& rhs) {
		return lhs.size() < rhs.size();
	}
};



template <class T, class Comparator>
void mergeSort (std::vector<T>& v, Comparator comp) {
	mergeSortHelper(v, 0, v.size() - 1, comp);
}

template <class T, class Comparator>
void mergeSortHelper (std::vector<T>& v, int l, int r, Comparator comp) {
	if ( l < r ) {
		int m = (l + r) / 2;
		mergeSortHelper(v, l, m, comp);
		mergeSortHelper(v, m + 1, r, comp);
		merge(v, l, r, m, comp);
	}
}

template <class T, class Comparator>
void merge (std::vector<T>& v, int l, int r, int m, Comparator comp) {
	int i = l, j = m + 1;
	std::vector<T> temp;

	while ( i <= m || j <= r ) {
		if ( i <= m && (j > r || comp(v[i], v[j])) ) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}
	}
	// std::cout << "temp: ";
	// for (unsigned int i = 0; i < temp.size(); i++) std::cout << temp[i] << " ";
	
	for (int k = 0; k < r - l + 1; k++) {
		v[l + k] = temp[k];
	}

	// std::cout << "v: ";
	// std::vector<T>::const_iterator it;
	// for (it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";
	// std::cout << std::endl;

	temp.clear();
}

#endif

