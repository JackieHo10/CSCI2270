

// FILENAME: BigNum.h
// This is the definition of the BigNum class.

// CONSTRUCTORS and DESTRUCTORS for the BigNum class
//
//   BigNum() : Default constructor for the BigNum class. A positive BigNum with default value 0
//      is created after this constructor.
//
//   BigNum(int num) : A BigNum with the same value and sign as num is created after this function.
//
//   BigNum(const char string[]) : A BigNum with the corresponding interger value of string[] is
//      created after this function.
//
//   BigNum(const BigNum& anotherBigNum) : A BigNum with the corresponding interger value of string[] is
//      created after this function.
//
//   ~BigNum() : Dynamic memory allocated for the BigNum is released after this function.
//
// PUBLIC MEMBER FUNCTIONS of the BigNum class:
//
//    BigNum& operator=(const BigNum& anotherBigNum) : The BigNum has been assigned the same value
//       as anotherBigNum after this function is executed.
//
//    BigNum& operator+=(const BigNum& addend) : Addend has been added to this BigNum after this
//       function is executed.
//
//    BigNum& operator-=(const BigNum& subtractand) : Subtractand has been subtracted from this 
//       BigNum after this function is executed.
//
//    BigNum& operator*=(const BigNum& multiplicand) : This BigNum has been multiplied by multiplicand 
//       and the result is stored in this BigNum after this function  is executed.
//
//    BigNum& operator/=(const BigNum& divisor) : This BigNum has been divided by divisor and the
//       result has been stored in this BigNum after this function is executed.
//
//    BigNum& operator%=(const BigNum& divisor) : This BigNum has been taken modulus by divisor and 
//       the result has been stored in this BigNum after this function is executed.
//    
//    BigNum& operator++() : This BigNum has been incremented by 1 after this function is executed.
//
//    BigNum& operator--() : This BigNum has been decremented by 1 after this function is executed.
//
//    BigNum operator+(const BigNum& addend) : The result of the addition of this BigNum and addend
//       has been returned after this function is executed and neither this BigNum nor addend has been
//       changed.
//
//    BigNum operator-(const BigNum& subtractand) : This BigNum has been subtracted by subtractand and 
//       neither this BigNum nor subtractand has been changed and the result has been returned after 
//       this function is executed. 
//
//    BigNum operator*(const BigNum& multiplicand) : This BigNum has been multilpied by multiplicand and
//       neither this BigNum nor multiplicand has been changed and the result has been returned after 
//       this function is executed.
//
//    BigNum operator/(const BigNum& divisor) : This BigNum has been divided by divisor and neither this
//       BigNum nor divisor has been changed and the result has been returned after this function 
//       is executed.
//   
//    BigNum operator%(const BigNum& divisor) : This BigNum has been taken modulus by divisor and neither
//       this BigNum nor divisor has been changed and the result has been returned after this function
//       is executed.
//
//    bool operator>(const BigNum& anotherBigNum) : True will be returned if this BigNum is bigger than
//       anotherBigNum, otherwise false will be returned.
//
//    bool operator>=(const BigNum& anotherBigNum) : True will be returned if this BigNum is bigger than
//       or equal to anotherBigNum, otherwise false will be returned.
//
//    bool operator<(const BigNum& anotherBigNum) :  True will be returned if this BigNum is smaller than
//       anotherBigNum, otherwise false will be returned.
//
//    bool operator<=(const BigNum& anotherBigNum) :  True will be returned if this BigNum is smaller than
//       or equal to anotherBigNum, otherwise false will be returned.
//
//    bool operator==(const BigNum& anotherBigNum) :  True will be returned if this BigNum is equal to 
//       anotherBigNum, otherwise false will be returned.
//
//    bool operator!=(const BigNum& anotherBigNum) : True will be returned if this BigNum is not equal to
//       anotherBigNum, otherwise false will be returned.
//
//    BigNum factorial() : Factorial of this BigNum has been returned after this function is executed.
//
//    unsigned int get_used() const : Length of this BigNum has been returned after this function is executed.
//
//    unsigned int get_capacity() const : Size of the memory allocated for this BigNum has been returned after this 
//       function is executed.
//    
// Private MEMBER FUNCTIONS of the BigNum class:
//
//    void  resize(unsigned int n) : Size of the memory allocated for this BigNum has been changed to n
//      after this function is executed. If n is smaller than the length of this BigNum, this BigNum
//      will not be resized. The n value will be chosen for efficiency; resizing should generally double the
//      number's capacity.
//           
//    BigNum  diff(const BigNum& subtractand) : Precondition is that both this BigNum 
//      and subtractand are positive, and also that this BigNum >= subtractand. The result of subtraction
//      has been returned after this function is executed.
//
//    BigNum sum(const BigNum& addend) :  Precondition is that both this BigNum
//      and addend are positive. The result of addition has been returned after this function is executed.
//
//  FRIEND FUNCTIONS of the BigNum class:
//    friend std::ostream& operator<<(std::ostream &os, const BigNum& bignum) : This bignum has been
//      output to the console after this function is executed.
//
//    friend std::istream& operator>>(std::istream &is, BigNum& bignum) : This BigNum entered from the
//      console has been stored in bignum after this function is executed.
//



#ifndef LAB4_LCS_H
#define LAB4_LCS_H
#include <cstdlib>  // Provides unsigned int
#include <iostream> // Provides istream and ostream

namespace Lab5
{
    class Aligner 
    {
    public:
	
	// CONSTRUCTORS and DESTRUCTORS
	Aligner();                            
	~Aligner();
	
	// MEMBER FUNCTIONS
	std::string& get_sequence1() const;
	std::string& get_sequence2() const;

	unsigned int get_rows() const;
	unsigned int get_cols() const;

	bool is_matched() const;
	
	char get_seq1_letter(unsigned int index) const;
	char get_seq2_letter(unsigned int index) const;
	
	unsigned int get_match(unsigned int i, unsigned int j) const;
	void initialize();
	unsigned int match();
	
	// FRIEND FUNCTIONS
	friend std::ostream& operator<<(std::ostream& os, const Aligner& a);
	
  private:
	
	unsigned int count_digits(int num) const;
	void clear();
	
	unsigned int** matches;         // Pointer to the 2D array of matched letters 
	unsigned int** breadcrumbs;
	std::string sequence1;
	std::string sequence2;
	unsigned int rows;
	unsigned int cols;
	unsigned int maximum_match;
	bool matched;	          		// Indicates whether matching is done yet
	
    };

}

#endif

