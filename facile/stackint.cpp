#include "stackint.h"

StackInt::StackInt(){}
StackInt::~StackInt(){}

bool StackInt::empty() const {
	return list.empty();
}

void StackInt::push(const int& val) {
	list.insert(0, val);
}

int const & StackInt::top() const {
	return list.get(0);
}

void StackInt::pop() {
	list.remove(0);
}