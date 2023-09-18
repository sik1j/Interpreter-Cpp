//
// Created by sk on 9/17/23.
//

#ifndef CLION_TEST_LOX_H
#define CLION_TEST_LOX_H


#include <string>

class Lox {
private:
    int runFile(std::string path);
    int runPrompt();
    void run(std::string source);
public:
    int runner(int argc, char *argv[]);
};


#endif //CLION_TEST_LOX_H
