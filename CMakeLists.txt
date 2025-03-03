cmake_minimum_required(VERSION 3.28)
project(StackArray)

set(CMAKE_CXX_STANDARD 17)

add_executable(StackArray main.cpp
        stackExceptions.h
        StackArray.h
        postfixFromInfix.h
        Queue.h
        QueueList.h)
