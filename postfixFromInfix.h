#ifndef POSTFIX_FROM_INFIX_H
#define POSTFIX_FROM_INFIX_H

#include "StackArray.h"

class InvalidInfixCharException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: invalid characters in infix arithmetic expression.\n";
    }
};

class InvalidInfixChainException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: chain of infix arithmetic expression is invalid.\n";
    }
};

class InvalidInfixBracketsException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: invalid brackets pairs in infix arithmetic expression.\n";
    }
};

class DivisionByZeroException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: division by zero in infix arithmetic expression.\n";
    }
};

int getOperatorPriority(const char &ch) {
    if (ch == '(') {
        return 0;
    }
    if (ch == ')') {
        return 1;
    }
    if (ch == '+') {
        return 2;
    }
    if (ch == '-') {
        return 2;
    }
    if (ch == '*') {
        return 3;
    }
    if (ch == '/') {
        return 3;
    }
}

bool isOperator(const char &ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

bool isDigit(const char &ch) {
    return ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7'
            || ch =='8' || ch == '9';
}

void getPostfixFromInfix(const char *infix, char *postfix, const size_t stackSize) {
    StackArray<char> stack(stackSize);
    int i = 0;
    int resultIndex = 0;
    char ch = 0;

    bool isPrevCharOperator = false;
    bool isPrevCharDigit = false;

    while (infix[i] != '\0') {
        if (infix[i] == '/' && infix[i+1] == '0') {
            throw DivisionByZeroException();
        }

        ch = infix[i];

        if (isDigit(ch)) {
            if (isPrevCharDigit) {
                throw InvalidInfixChainException();
            }
            isPrevCharDigit = true;
        }
        else {
            isPrevCharDigit = false;
        }
        if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {
            if (isPrevCharOperator) {
                throw InvalidInfixChainException();
            }
            isPrevCharOperator = true;

        }
        else {
            isPrevCharOperator = false;
        }

        if (isOperator(ch)) {

            if (stack.isEmpty() || ch == '(') {
                stack.push(ch);
            }
            else if (ch == ')') {
                bool isOpenBracketFound = false;
                while (!stack.isEmpty()) {
                    char previousOperator = stack.pop();
                    if (previousOperator == '(') {
                        isOpenBracketFound = true;
                        break;
                    }
                    postfix[resultIndex] = previousOperator;
                    ++resultIndex;
                }
                if (!isOpenBracketFound) {
                    throw InvalidInfixBracketsException();
                }
            }
            else {
                int currentPriority = getOperatorPriority(ch);
                while (!stack.isEmpty()) {
                    char previousOperator = stack.pop();
                    int priority = getOperatorPriority(previousOperator);

                    if (priority >= currentPriority) {
                        postfix[resultIndex] = previousOperator;
                        ++resultIndex;
                    } else {
                        stack.push(previousOperator);
                        break;
                    }
                }
                postfix[resultIndex] = ch;
                ++resultIndex;
            }
        }
        else if (isDigit(ch)) {
            postfix[resultIndex] = ch;
            ++resultIndex;
        }
        else {
            throw InvalidInfixCharException();
        }
        ++i;
    }

    while (!stack.isEmpty()) {
        postfix[resultIndex] = stack.pop();
        ++resultIndex;
    }
}

#endif //POSTFIX_FROM_INFIX_H
