#include <iostream>
#include <fstream>
#include "calculator.h"

using namespace std;

int main(int argc, char **argv) {

    streambuf *stream;
    ifstream fin;
    if (argc != 2)
        cout << "file not found, please, type your arguments" << endl;
    else {
        fin.open(argv[1]);
        if (!fin)
            return 0;
        stream = fin.rdbuf();
        cin.rdbuf(stream);
    }

    calculator newCalc;
    newCalc.treatment();

}
