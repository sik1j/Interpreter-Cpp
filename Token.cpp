//
// Created by sk on 9/17/23.
//

#include "Token.h"

#include <utility>


std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "type: " << token.type << " lexeme: " << token.lexeme << " literal: ";
    switch (token.type) {
        case STRING:
            os << *(std::string*)(token.literal);
            break;
        case NUMBER:
            os << *(double*)(token.literal);
            break;
        case IDENTIFIER:
            os << *(std::string*)(token.literal);
            break;
        default:
            os << "Non-literal";
    }
    return os;
}

Token::Token(TokenType type, std::string lexeme, void *literal, int line)
  : type(type), lexeme(std::move(lexeme)), literal(literal), line(line) {};
