#include <iostream>
#include <cstdlib>
#include "BigNum.h"
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"Testing"<<endl;
	
	BigNum testDefaultConstructor;
	if(strcmp(testDefaultConstructor.printBigNum(), "0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	// at first test the default constructor, create an isntance of BigNum using the default constructor and 
	// then check the if the BigNum is initialized with the value you intended it to be initialized with. the default 
	// constructor is the one that does not take any parameters.
	BigNum testIntConstructor;
	if(strcmp(testIntConstructor.printBigNum(), "0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testIntConstructor.printBigNum(), "+0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testIntConstructor.printBigNum(), "-0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testIntConstructor.printBigNum(), "+123") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testIntConstructor.printBigNum(), "-123") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testIntConstructor.printBigNum(), "123456789") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	// now check the int constructor. Send different critical inputs as the parameter of the constructor and
	// check if there're any possible set of inputes for which the constructor is not working. The way to check
	// this is to use the printBigNum function.
	BigNum testStringConstructor;
	if(strcmp(testStringConstructor.printBigNum(), "0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testStringConstructor.printBigNum(), "+0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testStringConstructor.printBigNum(), "-0") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testStringConstructor.printBigNum(), "+123") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testStringConstructor.printBigNum(), "-123") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	
	if(strcmp(testStringConstructor.printBigNum(), "+0035") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	if(strcmp(testStringConstructor.printBigNum(), "-123456789") == 0)
		cout<<"pass";
	else
		cout<<"fail to pass";
	//now check the string constructor. Again send as the parameter a string and check if the constructor is working as it is supposed to do.
	
	
	
	
	
	
	
	// now check the copy constructor. Send a BigNum instance as the parameter of the constructor and then check if it is working accordingly.
	
	
	
	
	// now check the assignment operation. here if test1 and test2 are two BigNum instances then after
	// writing test1=test2, test1 should contain the bignum stored in test2.
	
	
	
	
	
	// check the operators +=,-=,*=,%=,/=. here if test ere if test1 and test2 are two BigNum instances then after
	// writing test1+=test2, the function should add the bignums of test1 and test2 and then store the result of the 
	// operation in the test1's bignum.
	
	
	
	
	
	//check the ++,-- operators. here if test ere if test1 and test2 are two BigNum instances then after
	// writing test1++, the bignum of test1 should be incremented by 1.
	
	
	
	
	
	
	
	//check the +,-,*,/,% operators. here if test ere if test1 and test2 are two BigNum instances then after
	//writing test3 = test1+test2, test3's bignum wil contain the result of the addition of test1 and test2's bignums. 
	
	
	
	
	//check the ==,<=,>=,!= operators. here if test ere if test1 and test2 are two BigNum instances then 
	// the logical check of test1 == test2 should return true if the two bignums stored by test1 and test2 are equal.
	//otherwise the operation should return false.
	return 0;

}
