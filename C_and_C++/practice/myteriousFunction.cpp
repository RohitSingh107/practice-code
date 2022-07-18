#include <cstring>
#include <string>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

/* template<typename Arg1> */
/* void __f (const char* name, Arg1&& arg1) { // && is reference to r-value (values which don't have memory address) */
/* 	/1* std::cout << "Sucessfull Calling" << std::endl; *1/ */
/* 	std::cout << name << " : " << arg1 << std::endl; */
/* } */

/* template<typename Arg1, typename... Args> */
/* void __f (const char* names, Arg1&& arg1, Args&&... args){ */
/* 	/1* std::cout << "Sucessfull Calling" << std::endl; *1/ */
/* 	const char* comma = strchr(names + 1, ','); */
/* 	std::cout << "Here1" << std::endl; */
/* 	cout.write(names, comma - names) << " : " << arg1 << " | "; */ 
/* 	std::cout << "Here2" << std::endl; */
/* 	__f(comma + 1, args...); */
/* } */


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	std::cout << "Here1" << std::endl;
    const char* comma = strchr (names + 1, ',');

	std::cout << "Here2" << std::endl;
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
	std::cout << "Here3" << std::endl;
}
int32_t main(){
	/* clock_t _t = clock(); */


	/* const char* s1 = "Rohit"; */
	/* string s2 = "Singh"; */

	/* vector<string> vs = {"Rohit", "Singh"}; */

	/* string sp[2] = {"Rohit", "Singh"}; */

/* 	__f(s1, sp); */

/* 	__f("one", sp); */

/* 	__f(s1, "Singh"); */

/* 	__f(s1, true); */

	/* __f("Rohit", "Singh", "Test", "Tesy2"); */
	__f("Rohit", "Singh", "Test");



	

	

	/* cerr << "\n\n\nRun Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds"; */
	return 0;
}

