#include <iostream>
#include "FOMS.cpp"

using namespace std;


int main() {

    try {
        FOMS sys;
        sys.start();
    }catch (invalid_argument args){
        cout << "Invalid Argument Exception Caught: ";
        cout << args.what() << '\n';
    }catch(...){
        cout << "\n\nUnexpected Error!!\n\n";
    }
    system("pause");

    return 0;
}

