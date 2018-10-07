// FILE: polytest.cxx
// An Interactive test program for the polynomial ADT
// Written by: Kenneth R. Glover - gloverk@colorado.edu

#include <cctype>          // Provides toupper
#include <iostream>        // Provides cout and cin
#include <cstdlib>         // Provides EXIT_SUCCESS
#include <string>
using namespace std;


// PROTOTYPES for functions used by this test program:
bool is_palindrome(int start, int end, const string& str);

int main()
{
  string str; 
  cout << "Enter a string: ";
  cin >> str;
  int start = 0;
  int end = str.length() - 1;
  if (is_palindrome(start, end, str))
    cout << "palindrome" << endl;
  else
    cout << "not palindrome" << endl;
  return (EXIT_SUCCESS);
}

bool is_palindrome(int start, int end, const string& str)
{
	if(str[start] != str[end])
		return false;
	else if (start >= end)
		return true;
	else
		return is_palindrome(++start, --end, str);
}

