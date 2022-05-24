#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

void printBinary(int num){
	cout<<num<<" : ";
	for (int i = 10; i >= 0; --i) {
		cout << (( num >> i ) & 1);
	}
	cout<<endl;
}

int32_t main(){
	
	cout<<INT_MAX <<endl;

	int a = (1LL <<31) -1;
	unsigned int b = (1LL <<32) -1;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	printBinary(9);

	int c = 9;
	int d = 1;

	if(( c & (1 << d)) != 0){
		cout<<d<<"th bit is set"<<endl;
	}
	else{
		cout<<d<<"th bit is not set"<<endl;
	}
	
	// bit set
	printBinary(c | (1 << 1));

	// bit unset
	printBinary(9 & ~(1 << 3));

	/* //toogle */
	printBinary(c ^ (1<<2));

	int ct = 0;
	for (int i = 31; i >= 0; i--) {
		if(( 15 & (1<<i)) != 0){
			ct++;
		}
	}
	cout<<ct<<endl;

	std::cout << __builtin_popcount(c) << std::endl;
	std::cout << __builtin_popcountll((1LL << 35) -1) << std::endl;

	for(char c = 'A'; c<= 'E'; c++){
		std::cout << c << " ";
		printBinary(int(c));
	}
	for(char c = 'a'; c<= 'e'; c++){
		std::cout << c << " ";
		printBinary(int(c));
	}
	char ch = ('A' | (1 << 5)) ;
	cout<< ch <<endl;

	char ch2 = ('a' & ~(1 << 5)) ;
	cout<< ch2 <<endl;

	cout<<char('C' | ' ')<<endl;
	cout<<char('c' & '_')<<endl;

	// clear lsb upto 
	int i3 = 59;
	printBinary(i3);
	int i4 = 4;
	int i5 = i3 & ~((1<<(i4 + 1)) -1);
	/* int i5 = (i3 & (~((1<<(i4+1)) -1))); */
	printBinary(i5);

	// clear msb upto
	int i6 = 59;
	printBinary(i6);
	int i7 = 3;
	int i8 = i6 & ((1<<(i7 + 1)) -1);
	/* int i5 = (i3 & (~((1<<(i4+1)) -1))); */
	printBinary(i8);

	if(i6 & (i6 - 1)){
		std::cout << "Not power of 2" << std::endl;
	}
	else{
		std::cout << "power of 2" << std::endl;
	}

	std::cout << 0b1001 << std::endl;

	return 0;
}

