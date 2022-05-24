cmake_minimum_required(VERSION 3.20)
project(HW3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW3
        HealthPoints.cpp
        HealthPoints.h
        HealthPointsExampleTest.cpp
        QueueExampleTests.cpp
        TestMain.cpp
        TestUtils.h Queue.h Node.h)
