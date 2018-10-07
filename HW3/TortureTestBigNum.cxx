#include <iostream>
#include <cstdlib>
#include "BigNum.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fstream>
#include <cstring>

using namespace std;
using namespace HW3;
ofstream grade;

#define TOTALTESTS 75
int passed = 0;
int testNo = 0;
int i = 0;
void tester(){
    cerr << "*** Running test " << (testNo + 1) << " *** "<< endl;
    grade.open ("extra_modulus.txt", ios::out | ios::app);
    if (testNo >= TOTALTESTS)
    {
        grade.close();
        cerr << "returning";
        return;
    }
    BigNum test1a;
    BigNum test2a = 243;
    BigNum test3a = -243;
    BigNum test4a = 0;
    BigNum test5a = 3458919;
    BigNum test6a = "0";
    BigNum test7a = "9997632187383270741827";
    BigNum test8a = "-9997632187383270741827";
    BigNum test9a = "-0008";
    BigNum test10a = "-3458919728786732132";
    BigNum test11a = test2a;
    BigNum test12a = test10a;
    BigNum test13a = test3a;
    BigNum test14a = test5a;
    BigNum test15a;
    test15a = test5a;
    BigNum test16a;
    test16a = test10a = test11a;
    BigNum test17a;
    test17a = test1a;
    BigNum test18a;
    test18a = test8a;
    BigNum test18b = 76878;
    test18b = test18b;
    if (testNo == 0){
        grade << "ADDITIONS" << endl;
        BigNum test1 = test1a + test1a;
        if (strcmp(test1.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 1){
        BigNum test2 = test2a + test3a;
        if (strcmp(test2.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 2){
        BigNum test3 = test2a + test7a;
        if (strcmp(test3.printBigNum(), "9997632187383270742070") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 3){
        BigNum test4 = test2a + test8a;
        if (strcmp(test4.printBigNum(), "-9997632187383270741584") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 4){
        BigNum test5 = test3a + test7a;
        if (strcmp(test5.printBigNum(), "9997632187383270741584") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 5){ 
        BigNum test6 = test3a + test8a;
        if (strcmp(test6.printBigNum(), "-9997632187383270742070") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 6){
        BigNum test7 = test3a + test3a;
        if (strcmp(test7.printBigNum(), "-486") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 7){
        BigNum test8 = test3a + test1a;
        if (strcmp(test8.printBigNum(), "-243") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 8){
        BigNum test9b = "32143655476587695870980986696";
        BigNum test9 = test9b + test5a;
        if (strcmp(test9.printBigNum(), "32143655476587695870984445615") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 9){
        BigNum test10 = "-71889374873827490481898349832873483782";
        test10 += test1a;
        if (strcmp(test10.printBigNum(), "-71889374873827490481898349832873483782") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 10){
        BigNum test11 = "-718";
        test11 += test2a;
        
        if (strcmp(test11.printBigNum(), "-475") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 11){
        BigNum test12 = "718";
        test12 += test2a;
        
        if (strcmp(test12.printBigNum(), "961") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 12){
        BigNum test13 = "-146";
        test13 += test2a;
        if (strcmp(test13.printBigNum(), "97") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 13){
        BigNum test14 = "146";
        test14 += test2a;
        
        if (strcmp(test14.printBigNum(), "389") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 14){
        BigNum test15b = 76878;
        test15b += test15b;
        
        if (strcmp(test15b.printBigNum(), "153756") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 15){
        grade << "SUBTRACTION OPERATORS" << endl;
        BigNum test16 = test1a - test1a;
        
        if (strcmp(test16.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 16){
        BigNum test17 = test2a - test2a;
  
        if (strcmp(test17.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 17){
        BigNum test18 = test2a - test7a;
  
        if (strcmp(test18.printBigNum(), "-9997632187383270741584") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 18){
        BigNum test19 = test2a - test8a;
        
        if (strcmp(test19.printBigNum(), "9997632187383270742070") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 19){
        BigNum test20 = test3a - test7a;
        
        if (strcmp(test20.printBigNum(), "-9997632187383270742070") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 20){
        BigNum test21 = test3a - test8a;
        
        if (strcmp(test21.printBigNum(), "9997632187383270741584") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 21){
        BigNum test22 = test3a - test2a;
        
        if (strcmp(test22.printBigNum(), "-486") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 22){
        BigNum test23 = test3a - test1a;
        
        if (strcmp(test23.printBigNum(), "-243") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 23){
        BigNum test24 = test1a - test3a;
        
        if (strcmp(test24.printBigNum(), "243") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 24){
        BigNum test25a = "32143655476587695870980986696";
        BigNum test25 = test25a - test5a;
        
        if (strcmp(test25.printBigNum(), "32143655476587695870977527777") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 25){
        BigNum test26 = "-71889374873827490481898349832873483782";
        test26 -= test1a;
        
        if (strcmp(test26.printBigNum(), "-71889374873827490481898349832873483782") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 26){
        BigNum test27 = "-718";
        test27 -= test2a;
        
        if (strcmp(test27.printBigNum(), "-961") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 27){
        BigNum test28 = "718";
        test28 -= test2a;
        
        if (strcmp(test28.printBigNum(), "475") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 28){
        BigNum test29 = "-146";
        test29 -= test2a;
        
        if (strcmp(test29.printBigNum(), "-389") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 29){
        BigNum test30 = "146";
        test30 -= test2a;
        
        if (strcmp(test30.printBigNum(), "-97") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 30){
        BigNum test31b = 76878;
        test31b -= test31b;
        
        if (strcmp(test31b.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 31){
        grade << "RELATIONAL <, <=" << endl;
        if (test1a < test7a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 32){
        if (!(test1a < test1a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 33){
        if (!(test1a < test8a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 34){
        if (test8a < test7a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 35){
        if (test1a <= test1a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 36){
        if (test1a <= test7a){
            passed++;
            cerr << "test 19 passed.\n";
            grade << "test 19 passed.\n";
        }
        else{
            grade << "test 19 failed.\n";
        }
    }
    if (testNo == 37){
        if (!(test1a <= test8a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 38){
        if (test8a <= test7a){
            passed++;
            cerr << "test 19 passed.\n";
            grade << "test 19 passed.\n";
        }
        else{
            grade << "test 19 failed.\n";
        }
    }
    if (testNo == 39){
        grade << "RELATIONAL >, >=," << endl;
        if (!(test1a > test7a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 40){
        if (!(test1a > test1a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 41){
        if (test1a > test8a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 42){
        if (!(test8a > test7a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 43){
        if (test1a >= test1a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 44){
        if (!(test1a >= test7a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 45){
        if (test1a >= test8a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 46){
        if (!(test8a >= test7a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 47){
        grade << "RELATIONAL ==, !=" << endl;
        
        if (!(test1a == test7a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 48){
        if (test1a == test1a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 49){
        if (!(test1a == test8a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 50){
        if (!(test8a == test7a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 51){
        if (test8a == test8a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 52){
        if (!(test1a != test1a)){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 53){
        if (test1a != test7a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 54){
        if (test1a != test8a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 55){
        if (test8a != test7a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 56){
        if (test8a == test8a){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 57){
        grade << "MULTIPLICATION" << endl;
        BigNum test57a = 645;
        BigNum test57b = 873;
        BigNum test57c = test57a * test57b;
        
        if (strcmp(test57c.printBigNum(), "563085") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 58){
        BigNum test58 = test2a * test7a;
        
        if (strcmp(test58.printBigNum(), "2429424621534134790263961") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 59){
        BigNum test59 = test2a * test8a;
        
        if (strcmp(test59.printBigNum(), "-2429424621534134790263961") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 60){
        BigNum test60 = test3a * test7a;
        
        if (strcmp(test60.printBigNum(), "-2429424621534134790263961") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 61){
        BigNum test61 = test3a * test8a;
        
        if (strcmp(test61.printBigNum(), "2429424621534134790263961") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 62){
        BigNum test62 = test2a * test1a;
        
        if (strcmp(test62.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 63){
        BigNum test63 = test1a * test2a;
        
        if (strcmp(test63.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 64){
        BigNum test64 = test1a * test1a;
        
        if (strcmp(test64.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 65){
        BigNum test65 = "92384908132098";
        test65 *= test7a;
        
        if (strcmp(test65.printBigNum(), "923630331169909444911734445369863046") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 66){
        BigNum test66 = "-92384908132098";
        test66 *= test7a;
        
        if (strcmp(test66.printBigNum(), "-923630331169909444911734445369863046") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 67){
        BigNum test67 = "92384908132098";
        test67 *= test67;
        
        if (strcmp(test67.printBigNum(), "8534971250576187171417881604") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 68){
        BigNum test68 = "92384908132098";
        test68 *= test1a;
        
        if (strcmp(test68.printBigNum(), "0") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }

    // EXTRA CREDIT
    if (testNo == 69){
        BigNum test69a = 827;
        BigNum test69 = test69a.factorial();
        
        if (strcmp(test69.printBigNum(), "2974447562153555952704514919341849516481814375270856075664100659476687582721147973658883027886919270999460576712985486089630933780330351044190064251910893785319525233477574181051018636644453452961456328698035240259506771469450803869908213118713104455843692652339189481177217861007350577565738220163826226240905604073491102330492258255553817195073881419596078031052885692566128382480520047625904687556967459433697513539163232311588097856149991142472347116424659137975425417691234627859924522833935141626367102968792807972200462455089442700433792429181127035763686045983290438931500790116316494373965931142917992112419922257009302872298759292212446783563948757783200689987348044076338669123531256366254646836915787622861597110522664489342079620713395290823839050597448098795628446114300359005768202983710591188424850417097986081190914014235540673570350935670225469401839511148851769504049803200133652570260687848975134349709992979745978587749453689494526027681114604471872627974307714686238046109742150490752142703239472525571379846246133565781896818193472190837304045918486360405518341248770329964042512281999992080853959462684575432688805349794999457560415972127283224083934643794197143272214279367635448644264580970825510826594144037111965897799635227291789631431255318860167757302922990584189464994495542059319102527696613388141714428336588749693012368864637590200695284014829667844067594711000286983316702463707137471316201034517720056124997994728093872080155081098513789349024736680260767414097341772853942398872491275654968922885753505262634834931937762961416890189672938595537060825558742527715906464380259837748800413582067605677580436914249380196225625523410626288424845584156913347176044054235646841400803154571801975671667039292527242657612970508276465472751126495864354375887234933594275085727589697002904945606448610393070334967730657034240000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }

    if (testNo == 70){
        BigNum test70 = test1a.factorial();
        
        if (strcmp(test70.printBigNum(), "1") == 0){
            passed++;
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 71){
        grade << "DIVISION TEST" << endl;
        BigNum test71a = 827;
        BigNum test71 = test71a / test2a;
        
        if (strcmp(test71.printBigNum(), "3") == 0){
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 72){
        BigNum test72a = 0;
	BigNum test72b = 1;
        BigNum test72 = test72a / test72b;
        
        if (strcmp(test72.printBigNum(), "0") == 0){
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }

    if (testNo == 73){
        grade << "MODULUS TEST" << endl;
        BigNum test73a = 827;
        BigNum test73 = test73a % test2a;
        
        if (strcmp(test73.printBigNum(), "98") == 0){
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    if (testNo == 74){
        BigNum test74a = -729;
        BigNum test74 = test74a % test2a;
        
        if (strcmp(test74.printBigNum(), "0") == 0){
            cerr << "test " << (testNo + 1) << " passed.\n";
            grade << "test " << (testNo + 1) << " passed.\n";
        }else{
            grade << "test " << (testNo + 1) << " failed.\n";
        }
    }
    
    
    grade.close();
    return;
}

void termination_handler (int param)
{
    grade.close();
    if (++testNo <= TOTALTESTS){
        grade.open ("extra_modulus.txt", ios::out | ios::app);
        grade << "test " << testNo << " failed.\n";
        cerr << "\n************** test " << testNo << " failed. ***************\n"; 
        if (testNo == TOTALTESTS){
            cerr << "exiting";
            grade << "total: " << passed++ << endl;
            exit(1);
        }
        return tester();
    }
}
int main()
{
    grade.open ("extra_modulus.txt");
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
    grade.open ("extra_modulus.txt", ios::out | ios::app);
    grade << "total: " << passed << endl;
    grade.close();
    return 0;
}
