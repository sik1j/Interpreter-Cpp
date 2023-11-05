//
// Created by sk on 9/17/23.
//

#include <iostream>
#include <sysexits.h>
#include <fstream>
#include <utility>
#include <vector>
#include "Lox.h"

bool Lox::hadError = false;

// interpret source file
int Lox::runFile(std::string path) {
    std::ifstream file;
    file.open(path);

    if (!file.is_open()) {
        std::cout << "closed" << std::endl;
        file.close();
        return EX_OSFILE;
    }

    // convert entire file into a string
    std::string line;
    std::string source;
    while (std::getline(file, line)) {
        source += line + '\n';
    }

    run(source);
    // dont execute code if error present
    if (hadError) {
        return EX_DATAERR;
    }

    return EX_OK;
}

// runner for REPL environment
int Lox::runPrompt() {
    while (true) {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);

        if (line == "") {
            return EX_OK;
        }
        run(line);
        hadError = false;
    }
}

// run interpreter on command line
// run from source:
//   jlox [script]
// or as REPL:
//   jlox
int Lox::runner(int argc, char *argv[]) {
    // if more than 1 file path is passed, correct user
    // `argc > 2` because argc[0] is program name
    if (argc > 2) {
         std::cout << "Usage: jlox [script]";
         return EX_USAGE;
    }
    // run file from source
    else if (argc == 2){
        return runFile(argv[1]);
    }
    // run as REPL
    else {
        return runPrompt();
    }
}

// Lexer
#include "Scanner.h"
void Lox::run(std::string source) {
    Scanner scanner(source);
    auto tokens = scanner.scanTokens();
    for (auto &token : tokens) {
        std::cout << token << ", " << std::endl;
    }
}

void Lox::error(int line, std::string message) {
    report(line, "", message);
}

void Lox::report(int line, std::string where, std::string message) {
    std::cerr << "[line " << line << "] Error" << where << ": " << message;
    hadError = true;
}
