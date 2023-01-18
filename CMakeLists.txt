cmake_minimum_required(VERSION 3.24)
project(KNN_classification_server)

set(CMAKE_CXX_STANDARD 14)

include_directories(command)
include_directories(IO)
include_directories(runner)
include_directories(utilities)

add_executable(KNN_classification_server
        command/Command.cpp
        command/Command.h
        command/OptionEight.cpp
        command/OptionEight.h
        command/OptionFive.cpp
        command/OptionFive.h
        command/OptionFour.cpp
        command/OptionFour.h
        command/OptionOne.cpp
        command/OptionOne.h
        command/OptionTwo.cpp
        command/OptionTwo.h
        command/OptionThree.cpp
        command/OptionThree.h
        IO/DefaultIO.cpp
        IO/DefaultIO.h
        IO/StandardIO.cpp
        IO/StandardIO.h
        runner/CLI.cpp
        runner/CLI.h

        utilities/Distance.cpp
        utilities/Distance.h
        utilities/KNN.cpp
        utilities/KNN.h
        utilities/LabeledVector.cpp
        utilities/LabeledVector.h
        utilities/LoadData.cpp
        utilities/LoadData.h
        utilities/Server.cpp
        utilities/Server.h
        utilities/UnlabeledVector.cpp
        utilities/UnlabeledVector.h
        utilities/Utilities.cpp
        utilities/Utilities.h IO/SocketIO.h IO/SocketIO.cpp)
