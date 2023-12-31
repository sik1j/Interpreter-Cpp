//
// Created by sk on 9/17/23.
//

#include "Scanner.h"
#include "Lox.h"

Scanner::Scanner(std::string source) : source(std::move(source)) {
    keywords["and"] =    AND;
    keywords["class"] =  CLASS;
    keywords["else"] =   ELSE;
    keywords["false"] =  FALSE;
    keywords["for"] =    FOR;
    keywords["fun"] =    FUN;
    keywords["if"] =     IF;
    keywords["nil"] =    NIL;
    keywords["or"] =     OR;
    keywords["print"] =  PRINT;
    keywords["return"] = RETURN;
    keywords["super"] =  SUPER;
    keywords["this"] =   THIS;
    keywords["true"] =   TRUE;
    keywords["var"] =    VAR;
    keywords["while"] =  WHILE;
}

// goes through the source string, adding tokens, until all tokens have been added to the vector
std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    tokens.emplace_back(LOX_EOF, "", nullptr, line);
    return tokens;
}

bool Scanner::isAtEnd() {
    return current >= source.length();
}

void Scanner::scanToken() {
    char c = advance();
    switch (c) {
        case '(':
            addToken(LEFT_PAREN);
            break;
        case ')':
            addToken(RIGHT_PAREN);
            break;
        case '{':
            addToken(LEFT_BRACE);
            break;
        case '}':
            addToken(RIGHT_BRACE);
            break;
        case ',':
            addToken(COMMA);
            break;
        case '.':
            addToken(DOT);
            break;
        case '-':
            addToken(MINUS);
            break;
        case '+':
            addToken(PLUS);
            break;
        case ';':
            addToken(SEMICOLON);
            break;
        case '*':
            addToken(STAR);
            break;
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '/':
            // a comment token
            if (match('/')) {
                // consume all the comment characters
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        case '"': string(); break;

        default:
            if (isdigit(c)) {
                number();
            }
            else if(isalpha(c)) {
                identifier();
            }
            else {
                Lox::error(line, "Unexpected character");
            }
            break;
    }
}

char Scanner::advance() {
    return source[current++];
}

void Scanner::addToken(TokenType type) {
    addToken(type, nullptr);
}

void Scanner::addToken(TokenType type, void *literal) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, text, literal, line);
}

// checks if the next character matches the expected char
// helpful for comparing and consuming 1 to 2 character tokens like < and <=
bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source[current] != expected) return false;

    // consumes character if matched with size 2 token
    current++;
    return true;
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return source[current];
}

char Scanner::peekNext() {
    if (current+1 >= source.length()) return '\0';
    return source[current+1];
}

void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') {
            line++;
        }
        advance();
    }

    if (isAtEnd()) {
        Lox::error(line, "Unterminated String");
        return;
    }

    // The closing "
    advance();

    // Trim the surrounding quotes
    auto heapString = new std::string(source.substr(start + 1, current - start - 2));
    addToken(STRING, heapString);
}

void Scanner::number() {
    while (isdigit(peek())) {
        advance();
    }

    if (peek() == '.' && isdigit(peekNext())) {
        // consume the '.'
        advance();
    }

    while (isdigit(peek())) {
        advance();
    }

    auto heapNumber = new double(std::stod(source.substr(start, current-start)));
    addToken(NUMBER, heapNumber);
}

void Scanner::identifier() {
    while (isalnum(peek())) advance();
    std::string text(source.substr(start, current-start));
    // is IDENTIFIER if text is not a keyword
    TokenType type(keywords.find(text) == keywords.end() ? IDENTIFIER : keywords[text]);
    addToken(type);
}
