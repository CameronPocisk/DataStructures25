#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <iostream>
#include <stdexcept>
using namespace std;

class OverflowError : public exception
{
public:
    const char *what()
{
        return "Overflow Error Occured";
    }
};

class UnderflowError : public exception
{
public:
    const char *what()
    {
        return "Underflow Error Occured";
    }
};

class NotFound : public exception
{
public:
    const char *what()
    {
        return "Item Not Found";
    }
};

#endif