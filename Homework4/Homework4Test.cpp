#include <iostream>
#include "HashLinear.h"
#include "HashTwoDim.h"

// Unit testing using doctest. Doctest - "lightweight and has minimal setup"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;


// SYNTAX FOR TESTING
int Add(int a, int b){ return a + b; }
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
// Same test but runs for Two Dimensional hash
TEST_CASE("Two Dimensional Hash Can insert and find") {
    HashTwoDim testTwoDim;

    int valToFind = 44;
    int notValToFind = 99;

    testTwoDim.Insert(1);
    testTwoDim.Insert(valToFind); // Collision
    testTwoDim.Insert(37);  // Most common human random num choice :)

    // CHECK(501 == testTwoDim.Find(501));
    bool found;
    try{
        testTwoDim.Find(valToFind);
        found = true;
    }
    catch(NotFound &e){
        found = false;
    }
    // It successfully inserted and found
    CHECK(found == true);
    
    try{
        testTwoDim.Find(notValToFind);
        found = true;
    }
    catch(NotFound &e){
        found = false;
    }
    // It successfully inserted and found
    CHECK(found == false);
}

TEST_CASE("Linear Hash Can Remove To Empty") {
    HashLinear testLienar;

    CHECK(testLienar.IsEmpty() == true);
    testLienar.Insert(1);
    testLienar.Insert(501);
    testLienar.Insert(2);
    testLienar.Insert(70);
    CHECK(testLienar.IsEmpty() == false);

    testLienar.Remove(1);
    testLienar.Remove(501);
    testLienar.Remove(2);
    testLienar.Remove(70);
    CHECK(testLienar.IsEmpty() == true);
}

TEST_CASE("Linear Hash Can Remove To Empty") {
    HashTwoDim testTwoDim;

    CHECK(testTwoDim.IsEmpty() == true);
    testTwoDim.Insert(1);
    testTwoDim.Insert(501);
    testTwoDim.Insert(2);
    testTwoDim.Insert(70);
    CHECK(testTwoDim.IsEmpty() == false);

    testTwoDim.Remove(1);
    testTwoDim.Remove(501);
    testTwoDim.Remove(2);
    testTwoDim.Remove(70);
    CHECK(testTwoDim.IsEmpty() == true);
}

// MAY NOT ALWAYS PASS, TESTS EFFICENCY
TEST_CASE("Linear Comparison is close to O(1) with tolerance") {
    HashLinear testLienar;
    float tolerance = .2; // How close to O(n) we should compare
    int numComps = 0;
    int numItems = 50;

    // Insert random items and get total comparisons
    srand(time(nullptr)); 
    for(int i = 0; i < numItems; i++ ){
        numComps += testLienar.Insert(rand());
    }

    bool nearO1 = false;
    if(numComps < numItems * (1 + tolerance) && numComps > numItems * (1 - tolerance) ){ nearO1 = true; }
    CHECK(nearO1 == true);

}

// MAY NOT ALWAYS PASS, TESTS EFFICENCY
TEST_CASE("Two dim Comparison is close to O(1) with tolerance") {
    HashTwoDim testLienar;
    float tolerance = .2; // How close to O(n) we should compare
    int numComps = 0;
    int numItems = 50;

    // Insert random items and get total comparisons
    srand(time(nullptr)); 
    for(int i = 0; i < numItems; i++ ){
        numComps += testLienar.Insert(rand());
    }

    bool nearO1 = false;
    if(numComps < numItems * (1 + tolerance) && numComps > numItems * (1 - tolerance) ){ nearO1 = true; }
    CHECK(nearO1 == true);
}



// g++ -c Homework4Test.cpp 
// g++ -o main.exe Homework4Test.o
// ./main.exe

// g++ -c Homework4Test.cpp HashLinear.cpp HashTwoDim.cpp
// g++ -o main.exe Homework4Test.o HashLinear.o HashTwoDim.o
// ./main.exe