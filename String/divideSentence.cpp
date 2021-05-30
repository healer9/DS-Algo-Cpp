#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    string str = "I'm not a robot.";
    stringstream divide(str);
    string word;
    while (divide >> word)
        cout << word << endl;
    return 0;
}