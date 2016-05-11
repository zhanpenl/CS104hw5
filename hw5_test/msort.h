#ifndef MSOER_H
#define MSOER_H

#include <vector>

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
	
	for (int k = 0; k < r - l + 1; k++) {
		v[l + k] = temp[k];
	}

	temp.clear();
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
void mergeSort (std::vector<T>& v, Comparator comp) {
	mergeSortHelper(v, 0, v.size() - 1, comp);
}

#endif

