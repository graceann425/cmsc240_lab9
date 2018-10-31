#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Person.h"

using namespace std;

int main()
{
	//testing linked list class
	cout << "*****************************************" << endl;
	cout << "Testing LinkedList" << endl;
	cout << "*****************************************" << endl << endl;

	//testing person constructors (put print statment in each constructor)
	cout << "*****************************************" << endl;
	cout << "Constructors" << endl;
	cout << "*****************************************" << endl << endl;

	cout << "Default constructor:" << endl;
	cout << "LinkedList<int> intList;" << endl; 
	LinkedList<int> intList;
	cout << "LinkedList<char> charList;" << endl; 
	LinkedList<char> charList;
	cout << "LinkedList<double> doubleList;" << endl; 
	LinkedList<double> doubleList;

	cout << endl << "Copy constructor:" << endl;
	cout << "LinkedList<int> intList2(intList);" << endl; 
	LinkedList<int> intList2(intList);
	cout << "LinkedList<char> charList2(charList);" << endl; 
	LinkedList<char> charList2(charList);
	cout << "LinkedList<double> doubleList2(doubleList);" << endl; 
	LinkedList<double> doubleList2(doubleList);

	//testing add, get, and remove methods
	cout << endl << "*****************************************" << endl;

	cout << "Add, Get, Remove, and Size Methods" << endl; 
	cout << "*****************************************" << endl << endl;

	cout << "intList.add(25);" << endl; 
	intList.add(25); 
	cout << "intList.add(3);" << endl; 
	intList.add(3); 
	cout << "intList.add(75);" << endl << endl; 
	intList.add(75); 

	cout << "doubleList.add(2.2);" << endl; 
	doubleList.add(2.2); 
	cout << "doubleList.add(3.3);" << endl; 
	doubleList.add(3.3); 
	cout << "doubleList.add(4.4);" << endl << endl; 
	doubleList.add(4.4); 	

	cout << "charList.add('h');" << endl; 
	charList.add('h'); 	
	cout << "charList.add('i');" << endl; 
	charList.add('i'); 
	cout << "charList.add('!');" << endl << endl; 
	charList.add('!'); 

	cout << "intList.size()" << endl;
	cout << intList.size() << " [Expected: 3]" << endl;
	cout << "doubleList.size()" << endl;
	cout << doubleList.size() << " [Expected: 3]" << endl;	
	cout << "charList.size()" << endl;
	cout << charList.size() << " [Expected: 3]" << endl << endl;

	cout << "intList.get(0)" << endl;
	cout << intList.get(0) << " [Expected: 25]" << endl;
	cout << "doubleList.get(1)" << endl;
	cout << doubleList.get(1) << " [Expected: 3.3]" << endl;	
	cout << "charList.get(2)" << endl;
	cout << charList.get(2) << " [Expected: !]" << endl << endl;

	cout << "intList.remove(0)" << endl;
	cout << intList.remove(0) << " [Expected: 25]" << endl;
	cout << "intList.remove(0)" << endl;
	cout << intList.remove(0) << " [Expected: 3]" << endl;
	cout << "intList.remove(0)" << endl;
	cout << intList.remove(0) << " [Expected: 75]" << endl;
	cout << "doubleList.remove(1)" << endl;
	cout << doubleList.remove(1) << " [Expected: 3.3]" << endl;
	cout << "doubleList.remove(0)" << endl;
	cout << doubleList.remove(0) << " [Expected: 2.2]" << endl;	
	cout << "charList.remove(2)" << endl;
	cout << charList.remove(2) << " [Expected: !]" << endl << endl;	
	
	cout << "intList.size()" << endl;
	cout << intList.size() << " [Expected: 0]" << endl;
	cout << "doubleList.size()" << endl;
	cout << doubleList.size() << " [Expected: 1]" << endl;	
	cout << "charList.size()" << endl;
	cout << charList.size() << " [Expected: 2]" << endl << endl;
	
	//testing exceptions in add and remove methods
	cout << "*****************************************" << endl;
	cout << "Exceptions in Add and Remove Methods" << endl; 
	cout << "*****************************************" << endl << endl;
	cout << "try: intList.get(1);" << endl;
    try {intList.get(1);}
    catch (std::const exception& e) 
    {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }

	cout << "try: intList.remove(1);" << endl;
	try {intList.remove(1);}
    catch (std::const exception& e)
    {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }

	cout << "try: doubleList.get(8);" << endl;
    try {doubleList.get(8);}
    catch (std::const exception& e)
    {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }

	cout << "try: doubleList.remove(-1);" << endl;
	try {doubleList.remove(-1);}
    catch (std::const exception& e)
    {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }

	cout << endl << "*****************************************" << endl;
	cout << "toArray and operator+= Methods" << endl; 
	cout << "*****************************************" << endl << endl;

	cout << "intList += 1" << endl;
	intList+=1;
	cout << "intList += 2" << endl;
	intList+=2;
	cout << "intList += 3" << endl;
	intList+=3;
	cout << "intList += 4" << endl;
	intList+=4;
	cout << "intList += 5" << endl;
	intList+=5;
	cout << endl << "intList.toArray()" << endl;
	vector<int> v1 = intList.toArray();
  	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    	cout << ' ' << *it;
  	cout << " [Expected: 1 2 3 4 5]" << endl;

	return 0;

}
