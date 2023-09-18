//
// Created by sk on 9/17/23.
//

#include "Token.h"

#include <utility>

Token::Token(TokenType type, std::string lexeme, int line) : type(type), lexeme(std::move(lexeme)), line(line) {}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "type: " << token.type << " lexeme: " << token.lexeme;
    return os;
}
