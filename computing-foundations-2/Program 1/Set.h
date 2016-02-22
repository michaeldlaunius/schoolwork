//Michael Launius
//Schneider
//Program 1 - Set.h

#include <string>

using namespace std;


#ifndef SET_H
#define SET_H
class Set
{
	private:
		string operation;
		char setID;
		
	public:
		
		Set(){}; //Default constructor
		void getInput();
		void setOperation(string oper);
		string getOperation();
		void coutCVector();
		char getSetID();
		void assign(int array[]);
		void clear();
		void intersection(int array1[], int array2[]);
		void unn(int array1[], int array2[]);
		void diff(int array1[], int array2[]);
		
		int cVector[13];
		char arg1, arg2;
};
#endif
