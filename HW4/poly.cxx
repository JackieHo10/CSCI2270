#include "poly.h"
using namespace std;

namespace main_savitch_5
{
	polynomial::polynomial(double c, unsigned int exponent)
	{
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		if (fabs(c) < EPSILON)
		{
			head_ptr = new polynode(0,0);
			recent_ptr = head_ptr;
			tail_ptr = head_ptr;
			current_degree = 0;
		}
		if (fabs(c) >= EPSILON)
		{
			if (exponent == 0)
			{
				head_ptr = new polynode(c,0);
				recent_ptr = head_ptr;
				tail_ptr = head_ptr;
				current_degree = 0;
			}
			else
			{
				head_ptr = new polynode(0,0);
				recent_ptr = new polynode(c,exponent);
				tail_ptr = recent_ptr;
				head_ptr->set_fore(recent_ptr);
				recent_ptr->set_back(head_ptr);
				current_degree = exponent;
			}
		}
    }

    polynomial& polynomial::operator=(const polynomial& source)
    {
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		if (this == &source)
		{
			return *this;
		}
		if(head_ptr != NULL)
		{
			clear();
		}
		polynode*c;
		for(c =  source.head_ptr; c!= NULL; c = c-> fore())
		{
			assign_coef(c->coef(),c->exponent());
		}
		return *this;
	
	}
	
    polynomial::polynomial(const polynomial& source)
    {
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		head_ptr = NULL;
		*this = source;
    }

    polynomial::~polynomial()
    {
		clear();
		delete head_ptr;
		head_ptr = NULL;
    }

    void polynomial::clear()
    {
		while(head_ptr->fore() != NULL)
		{
			head_ptr = head_ptr->fore();
			delete head_ptr->back();
		}
		head_ptr->set_back(NULL);
		head_ptr->set_coef(0.0);
		head_ptr->set_exponent(0);
		current_degree =0;
		
    }
    
    double polynomial::coefficient(unsigned int exponent) const
    {
		set_recent(exponent);
		if(recent_ptr->exponent() == exponent)
		{
			return recent_ptr->coef();
		}
		else
		return 0;
    }

    void polynomial::add_to_coef(double amount, unsigned int exponent)
    {
		polynode* b;
		set_recent(exponent);
		if(recent_ptr->exponent()== exponent)
		{
			double coeff = amount +recent_ptr->coef();
			if(fabs(coeff) > EPSILON)
			recent_ptr->set_coef(coeff);
			else
			if(fabs(coeff) < EPSILON)
			{
				if((recent_ptr != head_ptr)&&(recent_ptr != tail_ptr))
				{
					b = recent_ptr->back();
					b->set_fore(recent_ptr->fore());
					b = recent_ptr->fore();
					b->set_back(recent_ptr->back());
					delete recent_ptr;
				}
				if(recent_ptr == tail_ptr)
				{
					b = recent_ptr->back();
					b->set_fore(NULL);
					tail_ptr = recent_ptr-> back();
					delete recent_ptr;
					current_degree = tail_ptr->exponent();
				}
			}
		}
		if(recent_ptr-> exponent() != exponent)
		{
			if(amount !=0)
			{
				if(recent_ptr != tail_ptr)
				{
					b= new polynode(amount, exponent, recent_ptr->fore(),recent_ptr);
					recent_ptr ->set_fore(b);
					b->fore()->set_back(b);
				}
				if(recent_ptr == tail_ptr)
				{
					b = new polynode(amount,exponent,NULL,recent_ptr);
					recent_ptr ->set_fore(b);
					tail_ptr = b;
					current_degree = tail_ptr-> exponent();
				}
			}
		}
		recent_ptr = head_ptr;
	}

    void polynomial::assign_coef(double coefficient, unsigned int exponent)
    {
		set_recent(exponent);
		if(fabs(coefficient) < EPSILON && exponent > current_degree)
			return;
		else
		{
			if(recent_ptr->exponent() != exponent)
			{
				polynode*P = new polynode(coefficient,exponent);
				P->set_back(recent_ptr);
			
			if(recent_ptr->fore() != NULL)
				{
					recent_ptr->fore()->set_back(P);
				}
			
			else
				{
					tail_ptr =P;
					current_degree = exponent;
				}
					P->set_fore(recent_ptr->fore());
					recent_ptr->set_fore(P);
				
			}
			else
			
				if(coefficient != 0 || exponent==0)
				{
					recent_ptr->set_coef(coefficient);
					
				}
				else
				
					if(exponent == current_degree)
					{
						polynode *handle = tail_ptr->back();
						delete tail_ptr;
						tail_ptr = handle;
						tail_ptr->set_fore(NULL);
						current_degree = tail_ptr->exponent();
						recent_ptr = tail_ptr;
					}
				
					else
					{
						recent_ptr->fore()->set_back(recent_ptr ->back());
						recent_ptr->back()->set_fore(recent_ptr->fore());
					}
		}	
    }

    unsigned int polynomial::next_term(unsigned int exponent) const
    {
			if( exponent >=current_degree)
			{
				return 0;
			}
			set_recent(exponent);
			if (recent_ptr->fore() == NULL)
			{
				return 0;
			}
			
			else
				return recent_ptr->fore()->exponent();
    }

	unsigned int polynomial::previous_term(unsigned int exponent) const
    {
		if(exponent <= 0)
		{
			recent_ptr = head_ptr;
			return UINT_MAX;
		}
		set_recent(exponent-1);
		if(recent_ptr->exponent() == 0 && recent_ptr->coef() == 0)
			{
				recent_ptr = head_ptr;
				return UINT_MAX;
			}
		else
		{
			return recent_ptr->exponent();
		}
    }
    
    void polynomial::set_recent(unsigned int exponent) const
    {
		if (exponent == 0)
		{
			recent_ptr = head_ptr;
		}
		if (exponent >= current_degree)
		{
			recent_ptr = tail_ptr;
		}
		while (recent_ptr->fore() != NULL && recent_ptr->exponent() < exponent)
		{
			recent_ptr = recent_ptr->fore();
		}
		while(recent_ptr->back() != NULL && exponent < recent_ptr->exponent())
		{
			recent_ptr = recent_ptr->back();
		}
	}
    
    double polynomial::eval(double x) const
    {
		double total = 0;
		recent_ptr = head_ptr;
		while(recent_ptr != NULL)
		{
			double power_of_x = 1.0;
			for( unsigned int k = 0; k != recent_ptr->exponent(); k++)
			{	
				power_of_x = x * power_of_x;	
			}
                        total = total + (recent_ptr->coef() * power_of_x);
                        recent_ptr = recent_ptr->fore();
		}
		return total;
	}

    polynomial polynomial::derivative() const
    {
		polynomial p_prime;
		unsigned int expo = next_term(0);
		do
		{
			p_prime.add_to_coef(expo*this->coefficient(expo),expo -1);
			expo = next_term(expo);
		}
		while(expo != 0);
		return p_prime;
    }
    
    polynomial operator+(const polynomial& p1, const polynomial& p2)
    {
		polynomial p = p1;
		unsigned int expo = 0;
		do
		{
			p.add_to_coef(p2.coefficient(expo),expo);
			expo = p2.next_term(expo);
		}
		while(expo != 0);
		return p;
    }
    
    polynomial operator-(const polynomial& p1, const polynomial& p2)
    {
		polynomial p = p1;
		unsigned int expo = 0;
		do
		{
			p.add_to_coef(-1 * p2.coefficient(expo),expo);
			expo = p2.next_term(expo);
		}
		while(expo != 0);
		return p;
    }
    
    polynomial operator*(const polynomial& p1, const polynomial& p2)
    {	
		polynomial p =p1;
		unsigned int expo = 0;
		do
		{
			p.add_to_coef(p1.coefficient(expo) * p2.coefficient(expo),expo);
			expo = p2.next_term(expo);
		}
		while(expo != 0);
		return p;
    }

    ostream& operator << (ostream& out, const polynomial& p)
    {
		
		return out;
    }
    
    void polynomial::find_root(
	double& answer,
	bool& success,
	unsigned int& iterations,
	double guess,
	unsigned int maximum_iterations,
	double epsilon) const
    {
	}
}
