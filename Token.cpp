//
// Created by sk on 9/17/23.
//

#include "Token.h"

#include <utility>


std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "type: " << token.type << " lexeme: " << token.lexeme;
    return os;
}

Token::Token(TokenType type, std::string lexeme, void *literal, int line)
  : type(type), lexeme(std::move(lexeme)), literal(literal), line(line) {};
