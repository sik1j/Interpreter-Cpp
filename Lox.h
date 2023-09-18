//
// Created by sk on 9/17/23.
//

#ifndef CLION_TEST_LOX_H
#define CLION_TEST_LOX_H


#include <string>

class Lox {
private:
    static bool hadError;

    static int runFile(std::string path);
    static int runPrompt();
    static void run(std::string source);

    static void report(int line, std::string where, std::string message);
public:
    static int runner(int argc, char *argv[]);

    static void error(int line, std::string message);
};


#endif //CLION_TEST_LOX_H
