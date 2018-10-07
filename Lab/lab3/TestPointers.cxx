#include "MyClass.cxx"


// Pass by value
void fun1(MyClass a)
{
	a.setX(1);
}


// Pass by reference
void fun2(MyClass& a)
{
	a.setX(2);
}



// Pass by pointer
void fun3(MyClass* a)
{
	a->setX(3);
}


// Using double pointers! Coz why stop at single pointers? :)
void fun4(MyClass** a)
{
	(*a)->setX(4);
}



int main() 
{
	MyClass a;
	MyClass* b;
	MyClass** c;
	
	cout << endl << "----Calling fun1----" << endl;
	
	fun1(a); 
	a.printX(); // Explaining output (1 point)	x=0 because this is "passed by value" means it copies an X and uses this copied x do all the calculation. But it will print out the original X which =0. 



	cout << endl << "----Calling fun2----" << endl;	
	
	fun2(a); 
	a.printX(); // Explaining output (1 point) x=2 it uses the local of x, which means it changed the original x value when it is doing the calculation.


	
	cout << endl << "----Calling fun3----" << endl;
	
	b = &a;     // Fixing compile error (1 point)
	fun3(b);   
	a.printX(); // Explaining output (1 point) x=3 it use the value that the pointer pointed to, also change the original value.



	cout << endl << "----Calling fun4----" << endl;
	
	c = &b;    // Fixing compile error (1 point)
	fun4(c);    
	a.printX(); // Explaining output (1 point) x=4 same as fun3, the difference is it change the x that pointer "a" pointed to, means original values also.
	
	//Dereferencing using single pointer
	cout << "\n\nTwo ways of dereferencing, \n1. Using '.' operator\n2. Using '->' operator\n\n";
	
	
	b->printX();          // Fixing compile error (1 point)
	(*b).printX();      // Fixing compile error (1 point) 
	
	// add a statement here!
	

	cout << "\n\n----Understanding arrays as pointers----" << endl;
	MyClass arr[5];
	
	arr[0].setX(10);
	arr[1].setX(20);
	arr[2].setX(30);
	arr[3].setX(40);
	arr[4].setX(50);
	
	cout << "----Running for loop for array variable 'arr' with 5 slots----" << endl << endl;
	
	//Explaining for loop (2 points) this loop is used to indicate all values in array and their adress in two ways: by value(with *) and by reference.
	for (unsigned int i=0; i<5; i++)
	{
		cout << "i = " << i << endl;
		cout << "memory location (arr + i) = " << arr+i << endl;
		cout << "  (*(arr + i)).printX() prints ";
		(*(arr+i)).printX();
		cout << "        arr[i].printX() prints ";
		arr[i].printX();
		cout << endl;
	}
	
	
	
	return 0;


}

