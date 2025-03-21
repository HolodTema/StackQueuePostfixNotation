#include <iostream>
#include <queue>

#include "StackArray.h"
#include "stackExceptions.h"

#include "postfixFromInfix.h"

#include "QueueList.h"
#include "queueExceptions.h"

void testCreateWrongSizeStack() {
    std::cout << "#########################\n";
    std::cout << "test: create wrong size stack\n";
    try {
        StackArray<int> stack(-4);
        std::cout << "Exception was not thrown.\n";
    }
    catch (const WrongStackSize& e) {
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
    catch (const StackOverflow& e) {
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
    catch (const StackUnderflow& e) {
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
void testErrorStackMoveConstructor() {
    std::cout << "#########################\n";
    std::cout << "Create stack1 with simple constructor and push to it (error):\n";
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
void testStackMoveAssignment() {
    std::cout << "#########################\n";
    std::cout << "test: stack move assignment:\n";

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
void testErrorStackMoveAssignment() {
    std::cout << "#########################\n";
    std::cout << "test: stack move assignment (error):\n";
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

    testStackMoveAssignment();
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



void testQueueEnQueue() {
    std::cout << "#########################\n";
    std::cout << "test queue enqueue:\n\n";

    QueueList<int> queue;

    queue.enQueue(5);
    std::cout << "after first enqueue:\n";
    std::cout << queue;

    queue.enQueue(3);
    std::cout << "after second enqueue:\n";
    std::cout << queue;

    queue.enQueue(100);
    std::cout << "after third enqueue:\n";
    std::cout << queue;
    std::cout << "#########################\n";
}

void testQueueDeQueue() {
    std::cout << "#########################\n";
    std::cout << "test queue dequeue:\n\n";

    QueueList<int> queue;
    queue.enQueue(100);
    queue.enQueue(150);
    queue.enQueue(30);
    queue.enQueue(0);

    std::cout << "Created queue:\n";
    std::cout << queue;
    std::cout << "\n";

    int e1 = queue.deQueue();
    std::cout << "After first dequeue:\n";
    std::cout << queue;
    std::cout << "Element from dequeue(): " << e1 << "\n\n";

    int e2 = queue.deQueue();
    std::cout << "After second dequeue:\n";
    std::cout << queue;
    std::cout << "Element from dequeue(): " << e2 << "\n\n";

    int e3 = queue.deQueue();
    std::cout << "After third dequeue:\n";
    std::cout << queue;
    std::cout << "Element from dequeue(): " << e3 << "\n";
}

void testQueueEnQueueDeQueue() {
    std::cout << "#########################\n";
    std::cout << "test queue dequeue:\n\n";

    QueueList<char> queue;
    queue.enQueue('A');
    queue.enQueue('B');
    queue.enQueue('C');
    queue.enQueue('D');

    std::cout << "Created queue:\n";
    std::cout << queue;
    std::cout << "\n";

    char e1 = queue.deQueue();
    std::cout << "After dequeue:\n";
    std::cout << queue;
    std::cout << "Element from dequeue(): " << e1 << "\n\n";

    std::cout << "Enqueue some elements:\n";
    queue.enQueue('X');
    queue.enQueue('Y');
    std::cout << queue;
    std::cout << "\n";

    char e2 = queue.deQueue();
    std::cout << "After dequeue:\n";
    std::cout << queue;
    std::cout << "Element from dequeue(): " << e2 << "\n\n";
    std::cout << "#########################\n";
}
void testQueueIsEmpty() {
    std::cout << "#########################\n";
    std::cout << "test queue isEmpty():\n";

    QueueList<int> queue;
    std::cout << "Created empty queue:\n";
    std::cout << queue;
    std::cout << "isEmpty(): " << queue.isEmpty() << "\n\n";

    std::cout << "enqueue some elements:\n";
    queue.enQueue(5);
    queue.enQueue(7);
    queue.enQueue(3);
    std::cout << queue;
    std::cout << "isEmpty(): " << queue.isEmpty() << "\n";
    std::cout << "#########################\n";
}
void testQueueUnderflow() {
    std::cout << "#########################\n";
    std::cout << "test queue underflow:\n";

    QueueList<int> queue;
    std::cout << "Created empty queue:\n\n";
    std::cout << queue;

    std::cout << "Try to call deQueue():\n";
    try {
        queue.deQueue();
    }
    catch (const QueueUnderflow& e) {
        std::cout << e.what();
    }
    std::cout << "#########################\n";
}
void testQueueCopyConstructor() {
    std::cout << "#########################\n";
    std::cout << "test queue copy constructor:\n";

    QueueList<char> queue1;
    queue1.enQueue('a');
    queue1.enQueue('b');
    queue1.enQueue('c');
    queue1.enQueue('d');
    std::cout << "Created queue1:\n";
    std::cout << queue1;
    std::cout << "\n";

    std::cout << "try: queue2(queue1):\n";
    QueueList<char> queue2(queue1);
    std::cout << "queue1:\n" << queue1;
    std::cout << "queue2:\n" << queue2 << "\n";

    std::cout << "add some elements to queue1:\n";
    queue1.enQueue('X');
    queue1.enQueue('Y');
    queue1.enQueue('Z');
    std::cout << "queue1:\n" << queue1;
    std::cout << "queue2:\n" << queue2 << "\n";
    std::cout << "#########################\n";
}
void testQueueCopyAssignment() {
    std::cout << "#########################\n";
    std::cout << "test queue copy assignment:\n";

    QueueList<char> queue1;
    queue1.enQueue('a');
    queue1.enQueue('b');
    queue1.enQueue('c');
    queue1.enQueue('d');
    std::cout << "Created queue1:\n";
    std::cout << queue1;
    std::cout << "\n";

    QueueList<char> queue2;
    queue2.enQueue('k');
    queue2.enQueue('l');
    queue2.enQueue('m');
    queue2.enQueue('n');
    std::cout << "Created queue2:\n";
    std::cout << queue2;
    std::cout << "\n";

    std::cout << "try: queue2 = queue1:\n";
    queue2 = queue1;
    std::cout << "queue1:\n" << queue1;
    std::cout << "queue2:\n" << queue2 << "\n";

    std::cout << "add some elements to queue2:\n";
    queue2.enQueue('X');
    queue2.enQueue('Y');
    queue2.enQueue('Z');
    std::cout << "queue1:\n" << queue1;
    std::cout << "queue2:\n" << queue2;
    std::cout << "#########################\n";
}
void testErrorQueueMoveConstructor() {
    std::cout << "#########################\n";
    std::cout << "test queue move constructor (error):\n";
    std::cout << "ATTENTION: there is double delete operator invokations in this test.\n\n";

    QueueList<int> queue1;
    queue1.enQueue(5);
    queue1.enQueue(7);
    queue1.enQueue(1);
    queue1.enQueue(4);
    std::cout << "created queue1:\n";
    std::cout << queue1 << "\n";

   std::cout << "try: queue2(std::move(queue1));\n";
    QueueList<int> queue2(std::move(queue1));
    std::cout << "queue1:\n" << queue1;
    std::cout << "queue2:\n" << queue2;
    std::cout << "#########################\n";
}
void testErrorQueueMoveAssignment() {
    std::cout << "#########################\n";
    std::cout << "test queue move assignment (error):\n";
    std::cout << "ATTENTION: there is double delete operator invokations in this test.\n\n";

    QueueList<int> queue1;
    queue1.enQueue(5);
    queue1.enQueue(50);
    queue1.enQueue(500);
    queue1.enQueue(0);
    std::cout << "created queue1:\n";
    std::cout << queue1 << "\n";

    QueueList<int> queue2;
    queue2.enQueue(1);
    queue2.enQueue(2);
    queue2.enQueue(3);
    queue2.enQueue(4);
    std::cout << "created queue2:\n";
    std::cout << queue2 << "\n";

    std::cout << "try: queue2 = std::move(queue1):\n";
    queue2 = std::move(queue1);
    std::cout << "queue1:\n";
    std::cout << queue1;
    std::cout << "queue2:\n";
    std::cout << queue2;

}


void myQueueTests() {
    testQueueEnQueue();
    testQueueDeQueue();
    testQueueEnQueueDeQueue();
    testQueueIsEmpty();
    testQueueUnderflow();
    testQueueCopyConstructor();
    testQueueCopyAssignment();
}

void stackTest()
{
  std::cout << "--stackTest begin--\n";

  Stack<int>* intStack = new StackArray<int>(5);

  std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

  intStack->push(1);
  intStack->push(2);
  intStack->push(3);
  intStack->push(4);
  intStack->push(5);

  std::cout << intStack->pop() << '\n';
  std::cout << intStack->pop() << '\n';

  std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

  intStack->push(7);
  intStack->push(8);

  std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

  std::cout << intStack->pop() << '\n';
  std::cout << intStack->pop() << '\n';
  std::cout << intStack->pop() << '\n';
  std::cout << intStack->pop() << '\n';
  std::cout << intStack->pop() << '\n';

  std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

  delete intStack;

  std::cout << "--stackTest end--\n";
}
void stackExceptionTest()
{
  std::cout << "--stackExceptionTest begin--\n";

  // для StackArray
  try
  {
    StackArray<int> intStack(0);
  }
  catch (const WrongStackSize& e)
  {
    std::cout << "WrongStackSize exception\n";
  }

  StackArray<int> intStack(3);
  //StackVector<int> intStack;
  //StackList<int> intStack;

  intStack.push(1);
  intStack.push(2);
  intStack.push(3);

  // для StackArray
  try
  {
    intStack.push(4);
  }
  catch (const StackOverflow& e)
  {
    std::cout << "StackOverflow exception\n";
  }

  intStack.pop();
  intStack.pop();
  intStack.pop();

  try
  {
    std::cout << intStack.pop() << '\n';
  }
  catch (const StackUnderflow& e)
  {
    std::cout << "StackUnderflow exception\n";
  }

  std::cout << "--stackExceptionTest end--\n";
}
void queueTest()
{
  std::cout << "--queueTest begin--\n";

  // Queue<std::string>* strQueue = new QueueArray<std::string>(5);
  //Queue<std::string>* strQueue = new QueueVector<std::string>;
  Queue<std::string>* strQueue = new QueueList<std::string>;

  std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

  strQueue->enQueue("ab");
  strQueue->enQueue("cd");
  strQueue->enQueue("ef");
  strQueue->enQueue("gh");
  strQueue->enQueue("ij");

  std::cout << strQueue->deQueue() << '\n';
  std::cout << strQueue->deQueue() << '\n';

  std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

  strQueue->enQueue("kl");
  strQueue->enQueue("mn");

  std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

  std::cout << strQueue->deQueue() << '\n';
  std::cout << strQueue->deQueue() << '\n';
  std::cout << strQueue->deQueue() << '\n';
  std::cout << strQueue->deQueue() << '\n';
  std::cout << strQueue->deQueue() << '\n';

  std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

  delete strQueue;

  std::cout << "--queueTest end--\n";
}
void queueExceptionTest()
{
  std::cout << "--queueExceptionTest begin--\n";

  // для QueueArray
  // try
  // {
  //   QueueArray<int> intQueue(0);
  // }
  // catch (const WrongQueueSize& e)
  // {
  //   std::cout << "WrongQueueSize exception\n";
  // }
  //
  // QueueArray<int> intQueue(3);
  //QueueVector<int> intQueue;
  QueueList<int> intQueue;

  intQueue.enQueue(1);
  intQueue.enQueue(2);
  intQueue.enQueue(3);

  // для QueueArray
  // try
  // {
  //   intQueue.enQueue(4);
  // }
  // catch (const QueueOverflow& e)
  // {
  //   std::cout << "QueueOverflow exception\n";
  // }

  intQueue.deQueue();
  intQueue.deQueue();
  intQueue.deQueue();

  try
  {
    std::cout << intQueue.deQueue() << '\n';
  }
  catch (const QueueUnderflow& e)
  {
    std::cout << "QueueUnderflow exception\n";
  }

  std::cout << "--queueExceptionTest end--\n";
}
void bracketsTest()
{
  // Если нет в вашем варианте, замените на
  std::cout << "not implemented\n";
}
void postfixTest()
{
  // Если нет в вашем варианте, замените на
  // std::cout << "not implemented\n";

  std::cout << "--postfixTest begin--\n";

  char postfix[10];
  // исправьте количество аргументов
  getPostfixFromInfix("1+2*3", postfix, 10);
  std::cout << postfix << '\n';
  getPostfixFromInfix("(1+2)*3+4", postfix, 10);
  std::cout << postfix << '\n';
  getPostfixFromInfix("4+(1+2)/3", postfix, 10);
  std::cout << postfix << '\n';
  try
  {
    getPostfixFromInfix("1+2*3+", postfix, 10);
  }
  catch (const std::exception&)
  {
    std::cout << "error\n";
  }
  try
  {
    getPostfixFromInfix("1+23", postfix, 10);
  }
  catch (const std::exception&)
  {
    std::cout << "error\n";
  }

  std::cout << "--postfixTest end--\n";
}
int dlTestsNew()
{
  int i = 0;
  std::cin >> i;
  switch (i)
  {
  case 1:
    stackTest();
    break;
  case 2:
    stackExceptionTest();
    break;
  case 3:
    queueTest();
    break;
  case 4:
    queueExceptionTest();
    break;
  case 5:
    bracketsTest();
    break;
  case 6:
    postfixTest();
    break;
  }

  return 0;
}


int main() {
    // myStackTests();
    // myPostfixFromInfixTests();
    // myQueueTests();

    // dlTestsNew();

    char* postfix = new char[100];
    try {
        getPostfixFromInfix("1+2*3+", postfix, 100);
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    std::cout << postfix << '\n';

    return 0;
}
