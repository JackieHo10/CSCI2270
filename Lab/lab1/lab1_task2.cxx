
#include <iostream>  // Provides cout, cin
#include <cstdlib>   // Provides EXIT_SUCCESS
using namespace std;


double underflow_double( );

float underflow_float( );

int main( )
{
    cout << underflow_float() << endl;
    cout << underflow_double() << endl;
    return EXIT_SUCCESS;
}

double underflow_double( )
{
    double n1 = 1;
    double n2 = 0;
    while (n1 > 0){
		n2 = n1;
		n1 = 0.5 * n1;
	}
	return n2;
}

float underflow_float( )
{
    float n1 = 1;
    float n2 = 0;
    while (n1 > 0){
		n2 = n1;
		n1 = 0.5 * n1;
	}
	return n2;
}
