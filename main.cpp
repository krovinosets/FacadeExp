#include <iostream>
#include "facade.h"

using namespace std;

void autoMode();
void proMode();

int main()
{
    autoMode();
    proMode();
    return 0;
}

void autoMode(){
    System sys = System::getInstance();
    sys.start();
    cout << endl << endl;
}

void proMode(){
    enum applications {
        Console, Proxy, DataBase
    };

    System sys = System::getInstance();
    sys.checkOnStatus(Console);
    sys.startApplication(Console);
    sys.checkOnStatus(Console);
    cout << endl << endl;
}
