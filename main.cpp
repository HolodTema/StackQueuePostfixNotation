#include <iostream>

#include "StackArray.h"
#include "stackExceptions.h"

#include "postfixFromInfix.h"

void testCreateWrongSizeStack() {
    std::cout << "#########################\n";
    std::cout << "test: create wrong size stack\n";
    try {
        StackArray<int> stack(-4);
        std::cout << "Exception was not thrown.\n";
    }
    catch (const WrongStackSizeException& e) {
        std::cout << e.what();
        std::cout << "Exception was thrown.\n";
    }
    std::cout << "#########################\n";
}

void testPushToStack() {
    std::cout << "#########################\n";
    std::cout << "test: push to stack\n";

    StackArray<int> stack(8);

    stack.push(9);
    std::cout << "Stack after first push:\n";
    std::cout << stack;
    std::cout << "\n";

    stack.push(5);
    std::cout << "Stack after second push:\n";
    std::cout << stack;
    std::cout << "\n";

    stack.push(12);
    std::cout << "Stack after third push:\n";
    std::cout << stack;
    std::cout << "#########################\n";
}

void testPopFromStack() {
    std::cout << "#########################\n";
    std::cout << "test: pop from stack\n";

    StackArray<int> stack(15);
    stack.push(3);
    stack.push(9);
    stack.push(1);
    stack.push(5);
    stack.push(14);

    std::cout << "Stack before pop:\n";
    std::cout << stack;
    std::cout << "\n";

    int pop1 = stack.pop();
    std::cout << "Stack after first pop:\n";
    std::cout << stack;
    std::cout << "Element from pop(): " << pop1 << "\n";
    std::cout << "\n";

    int pop2 = stack.pop();
    std::cout << "Stack after second pop:\n";
    std::cout << stack;
    std::cout << "Element from pop(): " << pop2 << "\n";
    std::cout << "\n";

    int pop3 = stack.pop();
    std::cout << "Stack after third pop:\n";
    std::cout << stack;
    std::cout << "Element from pop(): " << pop3 << "\n";
    std::cout << "#########################\n";
}

void testPushPopStack() {
    std::cout << "#########################\n";
    std::cout << "test: push and pop stack\n";

    StackArray<int> stack(15);
    stack.push(3);
    stack.push(9);
    stack.push(1);
    stack.push(5);
    stack.push(14);

    std::cout << "Created stack:\n";
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Push element 8 to stack:\n";
    stack.push(8);
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Push element 19 to stack:\n";
    stack.push(19);
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Pop element:\n";
    int pop = stack.pop();
    std::cout << "element from pop(): " << pop << "\n";
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Push element -8 to stack:\n";
    stack.push(-8);
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Pop element:\n";
    pop = stack.pop();
    std::cout << "element from pop(): " << pop << "\n";
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Pop element:\n";
    pop = stack.pop();
    std::cout << "element from pop(): " << pop << "\n";
    std::cout << stack;
    std::cout << "#########################\n";
}

void testStackOverflow() {
    std::cout << "#########################\n";
    std::cout << "test: stack overflow exception:\n";

    try {
        StackArray<int> stack(3);
        std::cout << "Created stack with capacity = 3\n";
        std::cout << "\n";

        std::cout << "Push to stack:\n";
        stack.push(88);
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Push to stack:\n";
        stack.push(88);
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Push to stack:\n";
        stack.push(88);
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Push to stack:\n";
        stack.push(88);
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Push to stack:\n";
        stack.push(88);
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Exception was not thrown\n";
    }
    catch (const StackOverflowException& e) {
        std::cout << e.what();
        std::cout << "Exception was thrown.\n";
    }
    std::cout << "#########################\n";
}

void testStackUnderflow() {
    std::cout << "#########################\n";
    std::cout << "test: stack underflow exception:\n";

    try {
        StackArray<int> stack(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        std::cout << "Created stack:\n";
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Pop stack:\n";
        int pop = stack.pop();
        std::cout << "Element from pop(): " << pop << "\n";
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Pop stack:\n";
        pop = stack.pop();
        std::cout << "Element from pop(): " << pop << "\n";
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Pop stack:\n";
        pop = stack.pop();
        std::cout << "Element from pop(): " << pop << "\n";
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Pop stack:\n";
        pop = stack.pop();
        std::cout << "Element from pop(): " << pop << "\n";
        std::cout << stack;
        std::cout << "\n";

        std::cout << "Exception was not thrown\n";
    }
    catch (const StackUnderflowException& e) {
        std::cout << e.what();
        std::cout << "Exception was thrown.\n";
    }
    std::cout << "#########################\n";
}

void testStackIsEmpty() {
    std::cout << "#########################\n";
    std::cout << "test: stack isEmpty():\n";

    StackArray<char> stack(10);
    std::cout << "Created empty stack:\n";
    std::cout << stack;
    std::cout << "isEmpty(): " << stack.isEmpty() << "\n";
    std::cout << "\n";

    stack.push('A');
    stack.push('E');
    std::cout << "Now stack is not empty:\n";
    std::cout << stack;
    std::cout << "isEmpty(): " << stack.isEmpty() << "\n";
    std::cout << "#########################\n";
}

void testStackCopyConstructor() {
    std::cout << "#########################\n";
    std::cout << "test: stack copy constructor:\n";

    StackArray<int> stack1(10);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);

    std::cout << "Created stack1:\n";
    std::cout << stack1;
    std::cout << "\n";

    StackArray<int> stack2(stack1);
    std::cout << "Created stack2 as stack1 copy:\n";
    std::cout << "Stack 1:\n";
    std::cout << stack1;
    std::cout << "Stack 2:\n";
    std::cout << stack2;
    std::cout << "\n";

    std::cout << "Push to stack1:\n";
    stack1.push(5);
    stack1.push(6);
    std::cout << "Stack 1:\n";
    std::cout << stack1;
    std::cout << "Stack 2:\n";
    std::cout << stack2;
    std::cout << "#########################\n";
}

void testStackCopyAssignment() {
    std::cout << "#########################\n";
    std::cout << "test: stack copy assignment:\n";

    StackArray<int> stack1(10);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);

    std::cout << "Created stack1:\n";
    std::cout << stack1;
    std::cout << "\n";

    StackArray<int> stack2(10);
    stack2.push(10);
    stack2.push(20);

    std::cout << "Created stack2:\n";
    std::cout << stack2;
    std::cout << "\n";

    std::cout << "make stack2 = stack1:\n";
    stack2 = stack1;
    std::cout << "stack1:\n";
    std::cout << stack1;
    std::cout << "stack2:\n";
    std::cout << stack2;
    std::cout << "\n";

    std::cout << "push to stack1:\n";
    stack1.push(8);
    stack1.push(200);
    std::cout << "stack1:\n";
    std::cout << stack1;
    std::cout << "stack2:\n";
    std::cout << stack2;
    std::cout << "\n";

    std::cout << "push to stack2:\n";
    stack2.push(9);
    std::cout << "stack1:\n";
    std::cout << stack1;
    std::cout << "stack2:\n";
    std::cout << stack2;
    std::cout << "#########################\n";
}

void testStackMoveConstructor() {
    std::cout << "#########################\n";
    std::cout << "Create stack1 with simple constructor and push to it:\n";
    std::cout << "ATTENTION: this test affects double delete[] invokation for the same pointer. I know it.\n";
    StackArray<int> stack1(10);
    stack1.push(100);
    stack1.push(50);
    stack1.push(20);
    std::cout << "stack1:\n";
    std::cout << stack1;

    std::cout << "Create stack2(std::move(stack1)) - with move constructor:\n";
    StackArray<int> stack2(std::move(stack1));
    std::cout << "stack2:\n";
    std::cout << stack2;

    //there is double delete[] operator invokation,
    //because private pointers in stack1 and stack2 are cleared twice.
    //it is impossible to avoid this effect during the test without making
    //this test function friend for StackArray class.
    std::cout << "#########################\n";
}

void testStackMoveAssignment1() {
    std::cout << "#########################\n";
    std::cout << "test: stack move assignment1:\n";

    StackArray<int> stack(5);
    stack.push(100);
    stack.push(200);
    stack.push(500);
    std::cout << "Created stack via simple constructor:\n";
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Make stack = rvalue:\n";
    stack = StackArray<int>(20);
    std::cout << stack;
    std::cout << "\n";

    std::cout << "Push to stack:\n";
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << stack;
    std::cout << "#########################\n";
}

void testStackMoveAssignment2() {
    std::cout << "#########################\n";
    std::cout << "test: stack move assignment2:\n";
    std::cout << "ATTENTION: this test affects double delete[] invokation for the same pointer. I know it.\n";

    StackArray<int> stack1(5);
    stack1.push(100);
    stack1.push(200);
    stack1.push(500);
    std::cout << "Created stack1 via simple constructor:\n";
    std::cout << stack1;
    std::cout << "\n";

    StackArray<int> stack2(10);
    stack2.push(1000);
    stack2.push(300);
    std::cout << "Created stack2 via simple constructor:\n";
    std::cout << stack2;
    std::cout << "\n";

    std::cout << "Try: stack2 = std::move(stack1):\n";
    stack2 = std::move(stack1);
    std::cout << "stack2:\n";
    std::cout << stack2;

    //there is double delete[] operator invokation,
    //because private pointers in stack1 and stack2 are cleared twice.
    //it is impossible to avoid this effect during the test without making
    //this test function friend for StackArray class.
    std::cout << "#########################\n";
}



void myStackTests() {
    testCreateWrongSizeStack();

    testPushToStack();
    testPopFromStack();
    testPushPopStack();

    testStackOverflow();
    testStackUnderflow();

    testStackIsEmpty();

    testStackCopyConstructor();
    testStackCopyAssignment();

    testStackMoveAssignment1();
}

void testPostfixFromInfix1() {
    std::cout << "#########################\n";
    std::cout << "test postfix from infix 1:\n";
    std::cout << "\n";

    char* expected = "62-\0";

    const char* infix = "6-2\0";
    char postfix[30];
    getPostfixFromInfix(infix, postfix, 100);

    std::cout << "expected result: " << expected << "\n";
    std::cout << "result: " << postfix << "\n";
    std::cout << "#########################\n";
}
void testPostfixFromInfix2() {
    std::cout << "#########################\n";
    std::cout << "test postfix from infix 2:\n";
    std::cout << "\n";

    char* expected = "12+34+*5-\0";

    const char* infix = "(1+2)*(3+4)-5\0";
    char postfix[30];
    getPostfixFromInfix(infix, postfix, 100);

    std::cout << "expected result: " << expected << "\n";
    std::cout << "result: " << postfix << "\n";
    std::cout << "#########################\n";
}
void testPostfixFromInfix3() {
    std::cout << "#########################\n";
    std::cout << "test postfix from infix 3:\n";
    std::cout << "\n";

    char* expected = "87-3*22+*9+\0";

    const char* infix = "(8-7)*3*(2+2)+9\0";
    char postfix[30];
    getPostfixFromInfix(infix, postfix, 100);

    std::cout << "expected result: " << expected << "\n";
    std::cout << "result: " << postfix << "\n";
    std::cout << "#########################\n";
}
void testIncorrectInfixChars() {
    std::cout << "#########################\n";
    std::cout << "test incorrect infix chars:\n";
    std::cout << "\n";

    const char* infix = "(9+B)-3\0";
    std::cout << "infix expression: " << infix << "\n";

    char postfix[30];
    try {
        getPostfixFromInfix(infix, postfix, 100);
    }
    catch(InvalidInfixCharException& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}
void testIncorrectInfixChain1() {
    std::cout << "#########################\n";
    std::cout << "test incorrect infix chain1:\n";
    std::cout << "\n";

    const char* infix = "7*3-2+(7--)+1\0";
    std::cout << "infix expression: " << infix << "\n";

    char postfix[30];
    try {
        getPostfixFromInfix(infix, postfix, 100);
    }
    catch(InvalidInfixChainException& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}
void testIncorrectInfixChain2() {
    std::cout << "#########################\n";
    std::cout << "test incorrect infix chain2:\n";
    std::cout << "\n";

    const char* infix = "(79+8)*3\0";
    std::cout << "infix expression: " << infix << "\n";

    char postfix[30];
    try {
        getPostfixFromInfix(infix, postfix, 100);
    }
    catch(InvalidInfixChainException& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}
void testInvalidBrackets1() {
    std::cout << "#########################\n";
    std::cout << "test invalid brackets1:\n";
    std::cout << "\n";

    const char* infix = "(8+3))*7-1\0";
    std::cout << "infix expression: " << infix << "\n";

    char postfix[30];
    try {
        getPostfixFromInfix(infix, postfix, 100);
    }
    catch(InvalidInfixBracketsException& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}
void testInvalidBrackets2() {
    std::cout << "#########################\n";
    std::cout << "test invalid brackets2:\n";
    std::cout << "\n";

    const char* infix = "7-3/((1-3)\0";
    std::cout << "infix expression: " << infix << "\n";

    char postfix[30];
    try {
        getPostfixFromInfix(infix, postfix, 100);
    }
    catch(InvalidInfixBracketsException& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}
void testDivisionByZero() {
    std::cout << "#########################\n";
    std::cout << "test division by zero:\n";
    std::cout << "\n";

    const char* infix = "1+2/0-3\0";
    std::cout << "infix expression: " << infix << "\n";

    char postfix[30];
    try {
        getPostfixFromInfix(infix, postfix, 100);
    }
    catch(DivisionByZeroException& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}


void myPostfixFromInfixTests() {
    testPostfixFromInfix1();
    testPostfixFromInfix2();
    testPostfixFromInfix3();

    testIncorrectInfixChars();

    testIncorrectInfixChain1();
    testIncorrectInfixChain2();

    testInvalidBrackets1();
    testInvalidBrackets2();

    testDivisionByZero();
}




int main() {
    // myStackTests();

    myPostfixFromInfixTests();

    return 0;
}
