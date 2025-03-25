#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <time.h>

#define N 8

using namespace std;

const int Array_size = 15;

long long int Primes[Array_size] = {
100000000000000003,100000000000000013, 100000000000000019,
100000000000000021, 100000000000000049, 100000000000000081,
100000000000000099, 100000000000000141,100000000000000181,
100000000000000337, 100000000000000339, 100000000000000369,
100000000000000337, 100000000000000339, 100000000000000369 };

//This function test the given number for primality
bool is_Prime(long long int x)
{
	if (x % 2 == 0) return false;
	long long int p = 3;
	long long int psqr = p * p;
	while (psqr <= x) {
		if (x % p == 0)
			return false;
		p += 2;
		psqr = p * p;

	}
	return true;
}

int main()
{

	int count = 0;
	double elapsed_time;
	clock_t start, end;
	start = clock();

#pragma omp parallel for 
	for (int i = 0; i < 15; i++) {
		if (is_Prime(Primes[i]))
			count++;
	}
	end = clock();
	elapsed_time = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Total number of primes found: " << count << "\n";
	cout << "Time taken to execute: " << elapsed_time << "\n";
	return 0;
}
