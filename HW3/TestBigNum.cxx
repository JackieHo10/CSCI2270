#include <iostream>
#include <cstdlib>
#include "BigNum.h"
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <fstream>
#include <cstring>

using namespace std;
using namespace HW3;
ofstream grade;

#define TOTALTESTS 30

int testNo = 0;
int i = 0;
void tester(){
    cerr << "*** Running test " << (testNo + 1) << " *** "<< endl;
    grade.open ("grade.txt", ios::out | ios::app);
    if (testNo >= TOTALTESTS)
    {
        grade.close();
        cerr << "returning";
        return;
    }
    if (testNo == 0){
        //cout << "DEFAULT CONSTRUCTOR TEST" << endl;
        BigNum test1;
        if (strcmp(test1.printBigNum(), "0") == 0){
            cerr << "test 1 passed.\n";
            grade << "test 1 passed.\n";
        }else{
            grade << "test 1 failed.\n";
        }
    }
    if (testNo == 1){
        //cout << "INT CONSTRUCTOR TESTS" << endl;
        BigNum test2 = 243;
        if (strcmp(test2.printBigNum(), "243") == 0){
            cerr << "test 2 passed.\n";
            grade << "test 2 passed.\n";
        }else{
            grade << "test 2 failed.\n";
        }
    }
    if (testNo == 2){
        BigNum test3 = -243;
        if (strcmp(test3.printBigNum(), "-243") == 0){
            cerr << "test 3 passed.\n";
            grade << "test 3 passed.\n";
        }else{
            grade << "test 3 failed.\n";
        }
    }
    if (testNo == 3){
        BigNum test4 = 0;
        if (strcmp(test4.printBigNum(), "0") == 0){
            cerr << "test 4 passed.\n";
            grade << "test 4 passed.\n";
        }else{
            grade << "test 4 failed.\n";
        }
    }
    if (testNo == 4){
        BigNum test5 = 3458919;
        if (strcmp(test5.printBigNum(), "3458919") == 0){
            cerr << "test 5 passed.\n";
            grade << "test 5 passed.\n";
        }else{
            grade << "test 5 failed.\n";
        }
    }
    if (testNo == 5){ 
        //cout << "STRING CONSTRUCTOR TESTS" << endl;  
        BigNum test6 = "0";
        if (strcmp(test6.printBigNum(), "0") == 0){
            cerr << "test 6 passed.\n";
            grade << "test 6 passed.\n";
        }else{
            grade << "test 6 failed.\n";
        }
    }
    if (testNo == 6){
        BigNum test7 = "9997632187383270741827";
        if (strcmp(test7.printBigNum(), "9997632187383270741827") == 0){
            cerr << "test 7 passed.\n";
            grade << "test 7 passed.\n";
        }else{
            grade << "test 7 failed.\n";
        }
    }
    if (testNo == 7){
        BigNum test8 = "-9997632187383270741827";
        if (strcmp(test8.printBigNum(), "-9997632187383270741827") == 0){
            cerr << "test 8 passed.\n";
            grade << "test 8 passed.\n";
        }else{
            grade << "test 8 failed.\n";
        }
    }
    if (testNo == 8){
        BigNum test9 = "-0008";
        if (strcmp(test9.printBigNum(), "-8") == 0){
            cerr << "test 9 passed.\n";
            grade << "test 9 passed.\n";
        }else{
            grade << "test 9 failed.\n";
        }
    }
    if (testNo == 9){
        BigNum test10 = "-3458919728786732132";
        if (strcmp(test10.printBigNum(), "-3458919728786732132") == 0){
            cerr << "test 10 passed.\n";
            grade << "test 10 passed.\n";
        }else{
            grade << "test 10 failed.\n";
        }
    }
    if (testNo == 10){
        //cout << "COPY CONSTRUCTOR TESTS" << endl;
        BigNum test11a = 243;
        BigNum test11 = test11a;
        if (strcmp(test11.printBigNum(), "243") == 0){
            cerr << "test 11 passed.\n";
            grade << "test 11 passed.\n";
        }else{
            grade << "test 11 failed.\n";
        }
    }
    if (testNo == 11){
        BigNum test12a = "-3458919728786732132";
        BigNum test12 = test12a;
        if (strcmp(test12.printBigNum(), "-3458919728786732132") == 0){
            cerr << "test 12 passed.\n";
            grade << "test 12 passed.\n";
        }else{
            grade << "test 12 failed.\n";
        }
    }
    if (testNo == 12){
        BigNum test13a = -243;
        BigNum test13 = test13a;
        if (strcmp(test13.printBigNum(), "-243") == 0){
            cerr << "test 13 passed.\n";
            grade << "test 13 passed.\n";
        }else{
            grade << "test 13 failed.\n";
        }
    }
    if (testNo == 13){
        BigNum test14a = 3458919;
        BigNum test14 = test14a;
        if (strcmp(test14.printBigNum(), "3458919") == 0){
            cerr << "test 14 passed.\n";
            grade << "test 14 passed.\n";
        }else{
            grade << "test 14 failed.\n";
        }
    }
    //cout << "ASSIGNMENT OPERATOR TESTS" << endl;
    if (testNo == 14){
        BigNum test15;
        BigNum test15a = 3458919;
        
        test15 = test15a;
        if (strcmp(test15.printBigNum(), "3458919") == 0){
            cerr << "test 15 passed.\n";
            grade << "test 15 passed.\n";
        }else{
            grade << "test 15 failed.\n";
        }
    }
    if (testNo == 15){
        BigNum test16;
        BigNum test16a = "-3458919728786732132";
        BigNum test16b = 243;
        
        test16 = test16a = test16b;
        if (strcmp(test16.printBigNum(), "243") == 0){
            cerr << "test 16 passed.\n";
            grade << "test 16 passed.\n";
        }else{
            grade << "test 16 failed.\n";
        }
    }
    if (testNo == 16){
        BigNum test17;
        BigNum test17a;
        
        test17 = test17a;
        if (strcmp(test17.printBigNum(), "0") == 0){
            cerr << "test 17 passed.\n";
            grade << "test 17 passed.\n";
        }else{
            grade << "test 17 failed.\n";
        }
    }
    if (testNo == 17){
        BigNum test18;
        BigNum test18a = "-9997632187383270741827";
        test18 = test18a;
        if (strcmp(test18.printBigNum(), "-9997632187383270741827") == 0){
            cerr << "test 18 passed.\n";
            grade << "test 18 passed.\n";
        }else{
            grade << "test 18 failed.\n";
        }
    }
    if (testNo == 18){
        BigNum test18b = 76878;
        test18b = test18b;
        if (strcmp(test18b.printBigNum(), "76878") == 0){
            cerr << "test 19 passed.\n";
            grade << "test 19 passed.\n";
        }else{
            grade << "test 19 failed.\n";
        }
    }
    if (testNo == 19){
		BigNum test19 = "99999999999999999999999999999999";
		BigNum test19b = 1;
		test19b = test19;
        if (strcmp(test19b.printBigNum(), "99999999999999999999999999999999") == 0){
            cerr << "test 20 passed.\n";
            grade << "test 20 passed.\n";
        }else{
            grade << "test 20 failed.\n";
        }
    }
	if (testNo == 20)
	{
		BigNum test20a = "999999";
		BigNum test20b = 999998;
		
        if (test20a > test20b)
        {
            cerr << "test 21 passed.\n";
            grade << "test 21 passed.\n";
        }
        else
        {
            cerr << "test 21 failed.\n";
            grade << "test 21 failed.\n";
        }
    }
	if (testNo == 21)
	{
		BigNum test21a = "999999";
		BigNum test21b = 999998;
		
        if (test21b <= test21a)
        {
            cerr << "test 22 passed.\n";
            grade << "test 22 passed.\n";
        }
        else
        {
            cerr << "test 22 failed.\n";
            grade << "test 22 failed.\n";
        }
    }
    if (testNo == 22)
	{
		BigNum test22a = "999999";
		BigNum test22b = 999999;
		
        if (test22a == test22b)
        {
            cerr << "test 23 passed.\n";
            grade << "test 23 passed.\n";
        }
        else
        {
            cerr << "test 23 failed.\n";
            grade << "test 23 failed.\n";
        }
    }
    if (testNo == 23)
	{
		BigNum test23a = "999999";
		BigNum test23b = 999999;
		
        if (!(test23a != test23b))
        {
            cerr << "test 24 passed.\n";
            grade << "test 24 passed.\n";
        }
        else
        {
            cerr << "test 24 failed.\n";
            grade << "test 24 failed.\n";
        }
    }
    if (testNo == 24)
	{
		BigNum test24a = "-999999";
		BigNum test24b = 999999;
		
        if (test24a < test24b)
        {
            cerr << "test 25 passed.\n";
            grade << "test 25 passed.\n";
        }
        else
        {
            cerr << "test 25 failed.\n";
            grade << "test 25 failed.\n";
        }
    }
    if (testNo == 25)
	{
		BigNum test25a = "999998";
		BigNum test25b = 999999;
		
        if (test25a < test25b)
        {
            cerr << "test 26 passed.\n";
            grade << "test 26 passed.\n";
        }
        else
        {
            cerr << "test 26 failed.\n";
            grade << "test 26 failed.\n";
        }
    }
    if (testNo == 26)
	{
		BigNum test26a = "899999";
		BigNum test26b = -999999;
		
        if (test26a > test26b)
        {
            cerr << "test 27 passed.\n";
            grade << "test 27 passed.\n";
        }
        else
        {
            cerr << "test 27 failed.\n";
            grade << "test 27 failed.\n";
        }
    }
    if (testNo == 27)
	{
		BigNum test27a = "0";
		BigNum test27b = 0;
		
        if (test27a == test27b)
        {
            cerr << "test 28 passed.\n";
            grade << "test 28 passed.\n";
        }
        else
        {
            cerr << "test 28 failed.\n";
            grade << "test 28 failed.\n";
        }
    }
    if (testNo == 28)
	{
		BigNum test26a = "899999";
		BigNum test26b = -999999;
		
        if (test26a != test26b)
        {
            cerr << "test 29 passed.\n";
            grade << "test 29 passed.\n";
        }
        else
        {
            cerr << "test 29 failed.\n";
            grade << "test 29 failed.\n";
        }
    }

    if (testNo == 29)
	{
		BigNum b;
		char q;
		do
		{
			cout << "Enter a BigNum and hit Enter: ";
			cin >> b;
			cout << "You entered the number: " << b << endl;
			cout << "Type 'q' to quit or 'c' to continue: ";
			cin >> q;
		} while (q != 'Q' && q != 'q');
    }

    grade.close();
    return;
}

void termination_handler (int param)
{
    grade.close();
    if (++testNo <= TOTALTESTS){
        grade.open ("grade.txt", ios::out | ios::app);
        grade << "test " << testNo << " failed.\n";
        cerr << "\n************** test " << testNo << " failed. ***************\n"; 
        if (testNo == TOTALTESTS){
            cerr << "exiting";
            exit(1);
        }
        return tester();
    }
}
int main()
{
    grade.open ("grade.txt");
    grade.close();
    signal (SIGSEGV, termination_handler);
    signal (SIGABRT, termination_handler);
    signal (SIGFPE, termination_handler);
    signal (SIGILL, termination_handler);
    signal (SIGSEGV, termination_handler);
    signal (SIGTERM, termination_handler);
    for (testNo = 0; testNo < TOTALTESTS; testNo++){
        tester();
    }
    grade.close();
    return 0;
}