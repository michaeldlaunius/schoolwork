//Result.h
//Assignment 4: Result class header
//Michael Launius
//Schneider

#include <string>
#ifndef RESULT_H
#define RESULT_H

using namespace std;

class Result{
friend class Calculator;

private:
	Result(){}//Default constructor
	int classIntResult;
	string classStrResult;
	int getResult(int givenResult);
};

#endif //END Result class header