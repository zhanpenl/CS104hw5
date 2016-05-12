CC = c++
CFLAG = -g -Wall
GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread

all: test

test: test_sort.cpp msort.h
	$(CC) $(CFLAG) $^ $(GTEST_LL) -o $@

.PHONY:

clean:
	rm -rf test