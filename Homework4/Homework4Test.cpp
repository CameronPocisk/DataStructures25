#include <iostream>
#include "HashLinear.h"
#include "HashTwoDim.h"

// Unit testing using doctest. Doctest - "lightweight and has minimal setup"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

int Add(int a, int b){
    return a + b;
}

TEST_CASE("Basic test") {
    CHECK(Add(1, 2) == 3);
    CHECK(Add(0, 0) == 0);
    CHECK(Add(1, -2) == -1);
}

TEST_CASE("Linear Hash Can insert and find") {
    HashLinear testLienar;

    int valToFind = 501;
    int notValToFind = 250;

    testLienar.Insert(1);
    testLienar.Insert(valToFind); // Collision
    testLienar.Insert(37);  // Most common human random num choice :)

    // CHECK(501 == testLienar.Find(501));
    bool found;
    try{
        testLienar.Find(valToFind);
        found = true;
    }
    catch(NotFound &e){
        found = false;
    }
    // It successfully inserted and found
    CHECK(found == true);
    
    try{
        testLienar.Find(notValToFind);
        found = true;
    }
    catch(NotFound &e){
        found = false;
    }
    // It successfully inserted and found
    CHECK(found == false);
}



// g++ -c Homework4Test.cpp 
// g++ -o main.exe Homework4Test.o
// ./main.exe

// g++ -c Homework4Test.cpp HashLinear.cpp HashTwoDim.cpp
// g++ -o main.exe Homework4Test.o HashLinear.o HashTwoDim.o
// ./main.exe