//
// Created by sk on 9/17/23.
//

#ifndef INTERPRETER_CPP_SCANNER_H
#define INTERPRETER_CPP_SCANNER_H


#include <string>
#include <vector>
#include "Token.h"

class Scanner {
private:
    const std::string source;
    std::vector<Token> tokens;

    // start of token being considered
    int start = 0;
    // current character being considered
    int current = 0;
    // line of file for error reporting purposes
    int line = 1;

    bool isAtEnd();
    void scanToken();
    // returns the next character in sequence while consuming it
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, void* literal);
    // checks if the next character matches the expected char
    bool match(char expected);
    // returns the next character in sequence without consuming it
    char peek();
    // responsible for handling string literals
    void string();
public:
    explicit Scanner(std::string source);
    std::vector<Token> scanTokens();

};


#endif //INTERPRETER_CPP_SCANNER_H
