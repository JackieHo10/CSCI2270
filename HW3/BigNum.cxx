// FILENAME: BigNum.cxx
// This is the implementation file of the BigNum class


#ifndef HW3_BIGNUM_CXX
#define HW3_BIGNUM_CXX
#include <algorithm>   
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "BigNum.h"
using namespace std;

namespace HW3
{
	BigNum::BigNum()
	{
		used =1;
		capacity=DEFAULT_CAPACITY;
		digits= new unsigned int[capacity];
		digits[0]=0;
		positive= true;
	}    

	BigNum::BigNum(int num)
	{
		capacity=DEFAULT_CAPACITY;	
		digits= new unsigned int[capacity];
		if(num<0)
			{
				positive= false;
				num = num*(-1);
			}
		else positive=true;
		if(num==0) 
		{
			used=1;
			digits[0]=0;
		}
		else 
		{
			int i=0;
			for(i=0;num!=0; i++)
			{
				digits[i]= num%10;
				num=num/10;
			}
			used=i;
		}
	}

    // Constructor that receives a character array, leading 0's will be ignored
	BigNum::BigNum(const char strin[])
	{
		capacity = strlen(strin);
		digits= new unsigned int[capacity];
		if(strin[0]=='-') positive=false;
		else positive=true;
		unsigned int i=0;
		while((strin[i]=='0')||(strin[i]=='-'))
		{
			if(i==capacity-1) break;
			else i++;
		}
		used = capacity-i;
		for(unsigned int j=i; j<capacity; j++)
		{
			digits[j-i] = strin[capacity-1-(j-i)]-48;
		}
	}

	BigNum::BigNum(const BigNum& anotherBigNum)
    {
		capacity = anotherBigNum.capacity;
		digits= new unsigned int[capacity];
		used = anotherBigNum.used;
		positive=anotherBigNum.positive;
		for(unsigned int index=0;index<used;index++)
			digits[index] = anotherBigNum.digits[index];
    }

    BigNum::~BigNum()
    {
		delete [] digits;
    }
    
    // public function possibly useful in +, * routines
    unsigned int BigNum::get_digit(unsigned int index) const
    {
		return digits[index];
    }

    // private function possibly useful in +, * routines
    void BigNum::set_digit(unsigned int digit, unsigned int index)
    {
		if (digit<=9) digits[index] = digit;
		else cout<<"Error";
    }
    
    // private function possibly useful in +, * routines
    void BigNum::set_used(unsigned int new_used)
    {
		used = new_used;
    }

    // public function possibly useful in +, * routines
    unsigned int BigNum::get_used() const
    {
		return used;
	}

    // public function possibly useful in +, * routines
    unsigned int BigNum::get_capacity() const
    {
		return capacity;
    }
    
    bool BigNum::get_positive() const
    {
		return positive;
    }

    void BigNum::set_positive(bool pos_or_neg)
    {
		positive = pos_or_neg;
	}
	
	void BigNum::resize(unsigned int n)
	{
			unsigned int* newdigits = new unsigned int[n];
			for(unsigned int index=0; index<n; index++)
			newdigits[index] = digits[index];
			delete[] digits;
			digits = newdigits;
			capacity = n;
	}
	
	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		positive = anotherBigNum.positive;

		if(capacity != anotherBigNum.capacity)
		{
			resize(anotherBigNum.capacity);
		}
		used = anotherBigNum.used;
		for(unsigned int i = 0 ; i < anotherBigNum.used; i++)
		{
			digits[i] = anotherBigNum.digits[i];
		}
		return *this;
	}

	BigNum& BigNum::operator+=(const BigNum& addend)  
	{
		*this=*this+addend;
		return *this;
	}

	BigNum& BigNum::operator-=(const BigNum& subtractand)
	{
		*this=*this-subtractand;
		return *this;
    }
  
	BigNum& BigNum::operator*=(const BigNum& multiplicand)
	{
		*this=*this * multiplicand;
		return *this;
	}

	BigNum& BigNum::operator/=(const BigNum& divisor)
	{
		*this=*this/divisor;
    	return *this;
	}

	BigNum& BigNum::operator%=(const BigNum& divisor)
	{
		*this=*this%divisor;
		return *this;
	}

	BigNum& BigNum::operator++()
	{
		BigNum One =1;
		*this += One;
		return *this;
	}
	
	BigNum& BigNum::operator--()
	{
		BigNum One =1;
		*this -= One;
		return *this;
	}

	BigNum BigNum::diff(const BigNum& subtractand) const
	{
		BigNum result=*this;
		int digit;
		unsigned int borrow=0;
		for(unsigned int k=0;k<used;k++)
		{
			digit=digits[k];
			if(k<subtractand.used)
				digit-=subtractand.digits[k];
			digit-=borrow;
			if(digit<0)
			{
				borrow=1;
				result.digits[k]=digit+10;
			}
			else
			{
				borrow=0;
				result.digits[k]=digit;
			}
		}
		if((result.digits[used-1]<1)||(result.digits[used-1]>9))
			result.used--;
		return result;
	}
  
	BigNum BigNum::sum(const BigNum& addend) const
	{
		BigNum result=*this;
		result.resize(used+1);
		unsigned int digit;
		unsigned int carry=0;
		for(unsigned int k=0;k<used;k++)
		{
			digit=digits[k];
			digit+=carry;
			if(k<addend.used)
				digit+=addend.digits[k];
			if(digit>9)
			{
				result.digits[k]=digit%10;
				carry=digit/10;
			}
			else
			{
				carry=0;
				result.digits[k]=digit;
			}
		}
		if(carry>0)
		{	 
			result.used++;
			result.set_digit(carry,used); 
		}
		return result;
	}

	BigNum BigNum::operator+(const BigNum& addend)
	{
		BigNum result;
		BigNum n1=*this;
		n1.positive=true;
		BigNum n2=addend;
		n2.positive=true;
		if(positive!=addend.positive)
		{
			if(n1>n2)
			{
				result=n1.diff(n2);
				result.positive=positive;
			}
			else if(n1<n2)
			{
				result=n2.diff(n1);
				result.positive=addend.positive;
			}
			else
			{
				result=0;
				result.positive=true;
			}
		}
		else
		{
			if(n1>n2) result=n1.sum(n2);
			else result=n2.sum(n1);
			result.positive=positive;
		}
		return result;
	}

	BigNum BigNum::operator-(const BigNum& subtractand)
	{
		BigNum result;
		BigNum n1=*this;
		n1.positive=true;
		BigNum n2=subtractand;
		n2.positive=true;
		if(positive!=subtractand.positive)
		{
			if(n1>n2)
			{
				result=n1.sum(n2);
				result.set_positive(positive==true);
			}
			else
			{
				result=n2.sum(n1);
				result.set_positive(positive==true);
			}
		}
		else
		{
			if(n1>n2)
			{
				result=n1.diff(n2);
				result.set_positive(positive==true);
			}
			else if(n1<n2)
			{
				result=n2.diff(n1);
				result.set_positive(positive!=true);
			}
			else
			{
				result=0;
				result.positive=true;
			}
		}
		return result;
	}
      
	BigNum BigNum::operator*(const BigNum& multiplicand)
	{
		BigNum n=multiplicand;
      	BigNum result;
      	BigNum temp;
      	if((n==0)||(*this==0))
		{
			result=0;
			result.positive=true;
		}
		else
      	{
			for(unsigned int j=0; j<multiplicand.used;j++)
			{
				unsigned int carry=0;
				unsigned int digit;
				temp=0;
				temp.resize(j+used+1);
				temp.used=j+used;
				for(unsigned k=0;k<j;k++)
					temp.digits[k]=0;
				for(unsigned int i=0;i<used;i++)
				{
						digit=digits[i]*multiplicand.digits[j]+carry;
						if(digit>9)
						{
							carry=digit/10;
							digit=digit%10;
						}
						else
						{
							carry=0;
						}
						temp.digits[i+j]=digit;
				}
				if(carry>0) 
				{
					temp.used++;
					temp.digits[j+used]=carry;
				}
				result+=temp;
			}
		}
		if(positive==multiplicand.positive) result.set_positive(true);
		else result.set_positive(false);
        return result;
	}

BigNum BigNum::operator/(const BigNum& divisor)
  {
	BigNum result;
	BigNum number1=*this;
	BigNum number2=divisor;
	BigNum temp;
	BigNum temp2;
	number1.positive=true;
	number2.positive=true;
	unsigned int i=1;

	
		cout<<number1<<"dshfk"<<number2<<endl;
		if(number1==0 || number2==0 ){
			result=0;
		}
		else{
	if (number1>number2){
		for(;temp2.get_positive();i++){
			
			temp=number2 * i;
			temp2=number1-temp;
			
			cout<<temp2<<endl;
		}
		i=i-2;
		cout<<i<<endl;
		result=i;
	}
	else{
		for(;temp2.get_positive(); i++){
			temp=number1 * i;
			temp2=number2-temp;
			cout<<temp2<<endl;
		}
		i=i-2;
		cout<<i<<endl;
		result=i;
	}
}
	if(result!=0){
	if(positive != divisor.positive){
		result.positive=false;
	}
	else{
		result.positive=true;
	}
	}
	else{
		result.positive=true;
	}
	return result;
  }

	BigNum BigNum::operator%(const BigNum& divisor)
  {
	BigNum result;
	BigNum number1=*this;
	BigNum number2=divisor;
	BigNum temp;
	BigNum temp2;
	number1.positive=true;
	number2.positive=true;
	unsigned int i=1;

	
		cout<<number1<<"dshfk"<<number2<<endl;
	if (number1>number2){
		for(;temp2.get_positive();i++){
			
			temp=number2 * i;
			temp2=number1-temp;
			
			cout<<temp2<<endl;
		}
		i=i-2;
		cout<<i<<endl;
		result=number1-number2*i;
	}
	else{
		for(;temp2.get_positive(); i++){
			temp=number1 * i;
			temp2=number2-temp;
			cout<<temp2<<endl;
		}
		i=i-2;
		cout<<i<<endl;
		result=number2-number1*i;
	}
	if(result!=0){
	if(positive != divisor.positive){
		result.positive=false;
	}
	else{
		result.positive=true;
	}
	}
	else{
		result.positive=true;
	}

	return result;
  }


	bool BigNum::operator>(const BigNum& anotherBigNum)
	{
		if((positive==true) && (anotherBigNum.positive==false)) return true;
		else if ((positive==false) && (anotherBigNum.positive==true)) return false; 
		else if ((positive==true) && (anotherBigNum.positive==true))  
		{
			if (used>anotherBigNum.used) return true;  
			if (used<anotherBigNum.used) return false; 
			else
			{
				int i=used-1;
				while ((i>=0)&&(digits[i]==anotherBigNum.digits[i]))
				{
					i--;	 
				}
				if(digits[i]>anotherBigNum.digits[i]) return true;  
				else return false;
			}
		}
		else  
		{
			if (used>anotherBigNum.used) return false;  
			if (used<anotherBigNum.used) return true; 
			else
			{
				int i=used-1;
				while ((i>=0)&&(digits[i]==anotherBigNum.digits[i]))
				{
					i--;	 
				}
				if(digits[i]<anotherBigNum.digits[i]) return true;  
				else return false;
			}
		}
		
	}


	bool BigNum::operator>=(const BigNum& anotherBigNum)
	{
		return ((*this == anotherBigNum)||(*this > anotherBigNum));
	}

	bool BigNum::operator<(const BigNum& anotherBigNum)
	{
		if((positive==false) && (anotherBigNum.positive==true)) return true;
		else if ((positive==true) && (anotherBigNum.positive==false)) return false; 
		else if ((positive==true) && (anotherBigNum.positive==true))  
		{
			if (used<anotherBigNum.used) return true;  
			if (used>anotherBigNum.used) return false; 
			else
			{
				int i=used-1;
				while ((i>=0)&&(digits[i]==anotherBigNum.digits[i]))
				{
					i--;	
				}
				if(digits[i]<anotherBigNum.digits[i]) return true; 
				else return false;
			}
		}
		else  
		{
			if (used>anotherBigNum.used) return true;  
			if (used<anotherBigNum.used) return false; 
			else
			{
				int i=used-1;
				while ((i>=0)&&(digits[i]==anotherBigNum.digits[i]))
				{
					i--;	 
				}
				if(digits[i]>anotherBigNum.digits[i]) return true;  
				else return false;
			}
		}
	}

	bool BigNum::operator<=(const BigNum& anotherBigNum)
	{
		return ((*this == anotherBigNum)||(*this < anotherBigNum));
	}
	
	bool BigNum::operator==(const BigNum& anotherBigNum)
	{
		int eq=1;
		if (positive!=anotherBigNum.positive)
			eq=0;
		else if(used!=anotherBigNum.used) eq=0;
		else
		{ 
				for(unsigned int i=0;i<used;i++)
				{
					if (digits[i] != anotherBigNum.digits[i])
					{
						eq=0;
						break;
					}
				}
		}
		if (eq==1) return true;
		else return false;		
		   
	}

	bool BigNum::operator!=(const BigNum& anotherBigNum)
	{
		return !(*this == anotherBigNum);
	}
  
	BigNum BigNum::factorial()
	{
		unsigned int result = 1;
		unsigned int counter = 1;
		while (*this!=counter)
			result *= counter++;
		return result;
    }
  
	std::ostream& operator<<(std::ostream& os, const BigNum& bignum)
	{
		if(!bignum.get_positive())
			os << "-";
		for(unsigned int i = 0; i < bignum.get_used(); i++)
		{
			if (bignum.get_digit(bignum.get_used()-i-1) < 10)
				os << bignum.get_digit(bignum.get_used()-i-1);
			else
				os << char(bignum.get_digit(bignum.get_used()-i-1) + 'A' - 10);
		}
		return os;
	} 

	std::istream& operator>>(std::istream& is, BigNum& bignum)
	{
		char temp[] = "0";
		is >> temp;
		bignum = BigNum(temp);
		return is;
	}
	
	BigNum factorial(const BigNum& a)
	{
		BigNum result = 1;
		return result;
	}
}
#endif



