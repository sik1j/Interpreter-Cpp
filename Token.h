//
// Created by sk on 9/17/23.
//

#ifndef INTERPRETER_CPP_TOKEN_H
#define INTERPRETER_CPP_TOKEN_H

#include <string>
#include <ostream>

enum TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    LOX_EOF
};

class Token {
private:

    const TokenType type;
    const std::string lexeme;
    // literal type defined by TokenType
    void* literal;
    int line;

public:
    Token(TokenType type, std::string lexeme, void* literal, int line);

    friend std::ostream &operator<<(std::ostream &os, const Token &token);

};



#endif //INTERPRETER_CPP_TOKEN_H
