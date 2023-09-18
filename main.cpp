#include <iostream>
#include "Lox.h"

int main(int argc, char *argv[])
{
    Lox jlox;
    jlox.runner(argc, argv);
//    std::cout << argv[0] << " | " << argv[1] << std::endl;
    return 0;
}
