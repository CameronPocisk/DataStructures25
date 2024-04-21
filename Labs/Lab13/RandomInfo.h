#ifndef RANDOMINFO_H
#define RANDOMINFO_H

#include <string>
using namespace std;
// First names

class RandomNames{
    string Firsts[100];
    string Lasts[100];

    public:
    RandomNames(){
    // Copied this code from somewhere
    Firsts [0] = "Johnny";
    Firsts [1] = "Erik";
    Firsts [2] = "Jacob";
	Firsts [3] = "Michael";
	Firsts [4] = "Joshua";
	Firsts [5] = "Matthew";
	Firsts [6] = "Ethan";
	Firsts [7] = "Andrew";
	Firsts [8] = "Daniel";
	Firsts [9] = "William";
	Firsts [10] = "Joseph";
	Firsts [11] = "Christopher";
	Firsts [12] = "Anthony";
	Firsts [13] = "Ryan";
	Firsts [14] = "Nicholas";
	Firsts [15] = "David";
	Firsts [16] = "Alexander";
	Firsts [17] = "Tyler";
	Firsts [18] = "James";
	Firsts [19] = "John";
	Firsts [20] = "Dylan";
	Firsts [21] = "Nathan";
	Firsts [22] = "Jonathan";
	Firsts [23] = "Brandon";
	Firsts [24] = "Samuel";
	Firsts [25] = "Christian";
	Firsts [26] = "Benjamin";
	Firsts [27] = "Zachary";
	Firsts [28] = "Logan";
	Firsts [29] = "Jose";
	Firsts [30] = "Noah";
	Firsts [31] = "Justin";
	Firsts [32] = "Elijah";
	Firsts [33] = "Gabriel";
	Firsts [34] = "Caleb";
	Firsts [35] = "Kevin";
	Firsts [36] = "Austin";
	Firsts [37] = "Robert";
	Firsts [38] = "Thomas";
	Firsts [39] = "Connor";
	Firsts [40] = "Evan";
	Firsts [41] = "Aidan";
	Firsts [42] = "Luke";
	Firsts [43] = "Jack";
	Firsts [44] = "Jordan";
	Firsts [45] = "Angel";
	Firsts [46] = "Isaiah";
	Firsts [47] = "Isaac";
	Firsts [48] = "Jason";
	Firsts [49] = "Jackson";
	Firsts [50] = "Hunter";
	Firsts [51] = "Cameron";
	Firsts [52] = "Mason";
	Firsts [53] = "Gavin";
	Firsts [54] = "Aaron";
	Firsts [55] = "Juan";
	Firsts [56] = "Kyle";
	Firsts [57] = "Charles";
	Firsts [58] = "Luis";
	Firsts [59] = "Adam";
	Firsts [60] = "Brian";
	Firsts [61] = "Aiden";
	Firsts [62] = "Eric";
	Firsts [63] = "Jayden";
	Firsts [64] = "Alex";
	Firsts [65] = "Sean";
	Firsts [66] = "Bryan";
	Firsts [67] = "Lucas";
	Firsts [68] = "Owen";
	Firsts [69] = "Nathaniel";
	Firsts [70] = "Ian";
	Firsts [71] = "Jesus";
	Firsts [72] = "Carlos";
	Firsts [73] = "Adrian";
	Firsts [74] = "Diego";
	Firsts [75] = "Julian";
	Firsts [76] = "Cole";
	Firsts [77] = "Ashton";
	Firsts [78] = "Jeremiah";
	Firsts [79] = "Steven";
	Firsts [80] = "Timothy";
	Firsts [81] = "Seth";
	Firsts [82] = "Devin";
	Firsts [83] = "Chase";
	Firsts [84] = "Jaden";
	Firsts [85] = "Cody";
	Firsts [86] = "Colin";
	Firsts [87] = "Landon";
	Firsts [88] = "Hayden";
	Firsts [89] = "Xavier";
	Firsts [90] = "Carter";
	Firsts [91] = "Wyatt";
	Firsts [92] = "Dominic";
	Firsts [93] = "Richard";
	Firsts [94] = "Antonio";
	Firsts [95] = "Jesse";
	Firsts [96] = "Blake";
	Firsts [97] = "Miguel";
	Firsts [98] = "Sebastian";
	Firsts [99] = "Jake";

    Lasts[0] = "Smith";
    Lasts[1] = "Johnson";
    Lasts[2] = "Williams";
    Lasts[3] = "Brown";
    Lasts[4] = "Jones";
    Lasts[5] = "Garcia";
    Lasts[6] = "Miller";
    Lasts[7] = "Davis";
    Lasts[8] = "Rodriguez";
    Lasts[9] = "Martinez";
    Lasts[10] = "Hernandez";
    Lasts[11] = "Lopez";
    Lasts[12] = "Gonzalez";
    Lasts[13] = "Wilson";
    Lasts[14] = "Anderson";
    Lasts[15] = "Thomas";
    Lasts[16] = "Taylor";
    Lasts[17] = "Moore";
    Lasts[18] = "Jackson";
    Lasts[19] = "Martin";
    Lasts[20] = "Lee";
    Lasts[21] = "Perez";
    Lasts[22] = "Thompson";
    Lasts[23] = "White";
    Lasts[24] = "Harris";
    Lasts[25] = "Sanchez";
    Lasts[26] = "Clark";
    Lasts[27] = "Ramirez";
    Lasts[28] = "Lewis";
    Lasts[29] = "Robinson";
    Lasts[30] = "Walker";
    Lasts[31] = "Young";
    Lasts[32] = "Allen";
    Lasts[33] = "King";
    Lasts[34] = "Wright";
    Lasts[35] = "Scott";
    Lasts[36] = "Torres";
    Lasts[37] = "Nguyen";
    Lasts[38] = "Hill";
    Lasts[39] = "Flores";
    Lasts[40] = "Green";
    Lasts[41] = "Adams";
    Lasts[42] = "Nelson";
    Lasts[43] = "Baker";
    Lasts[44] = "Hall";
    Lasts[45] = "Rivera";
    Lasts[46] = "Campbell";
    Lasts[47] = "Mitchell";
    Lasts[48] = "Carter";
    Lasts[49] = "Roberts";
    Lasts[50] = "Gomez";
    Lasts[51] = "Phillips";
    Lasts[52] = "Evans";
    Lasts[53] = "Turner";
    Lasts[54] = "Diaz";
    Lasts[55] = "Parker";
    Lasts[56] = "Cruz";
    Lasts[57] = "Edwards";
    Lasts[58] = "Collins";
    Lasts[59] = "Reyes";
    Lasts[60] = "Stewart";
    Lasts[61] = "Morris";
    Lasts[62] = "Morales";
    Lasts[63] = "Murphy";
    Lasts[64] = "Cook";
    Lasts[65] = "Rogers";
    Lasts[66] = "Gutierrez";
    Lasts[67] = "Ortiz";
    Lasts[68] = "Morgan";
    Lasts[69] = "Cooper";
    Lasts[70] = "Peterson";
    Lasts[71] = "Bailey";
    Lasts[72] = "Reed";
    Lasts[73] = "BabyGronk";
    Lasts[74] = "Kelly";
    Lasts[75] = "Howard";
    Lasts[76] = "Ramos";
    Lasts[77] = "Kim";
    Lasts[78] = "Cox";
    Lasts[79] = "Ward";
    Lasts[80] = "Richardson";
    Lasts[81] = "Watson";
    Lasts[82] = "Brooks";
    Lasts[83] = "Chavez";
    Lasts[84] = "Wood";
    Lasts[85] = "James";
    Lasts[86] = "Bennett";
    Lasts[87] = "Gray";
    Lasts[88] = "Mendoza";
    Lasts[89] = "Ruiz";
    Lasts[90] = "Hughes";
    Lasts[91] = "Price";
    Lasts[92] = "Alvarez";
    Lasts[93] = "Castillo";
    Lasts[94] = "Sanders";
    Lasts[95] = "Patel";
    Lasts[96] = "Myers";
    Lasts[97] = "Long";
    Lasts[98] = "Ross";
    Lasts[99] = "Foster";
    }


    string GetRandomFirst(){ return Firsts[rand() % 100];}
    string GetRandomLast(){ return Lasts[rand() % 100];}
};

//Last names



#endif