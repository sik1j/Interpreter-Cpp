//
// Created by sk on 9/17/23.
//

#ifndef CLION_TEST_LOX_H
#define CLION_TEST_LOX_H


#include <string>

class Lox {
private:
    bool hadError = false;

    int runFile(std::string path);
    int runPrompt();
    void run(std::string source);

    void error(int line, std::string message);
    void report(int line, std::string where, std::string message);
public:
    int runner(int argc, char *argv[]);
};


#endif //CLION_TEST_LOX_H
