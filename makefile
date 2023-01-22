# Compiler and flags
CC = g++
CFLAGS = -Wall -std=c++11

# Source files for program1
SRC1 = $(wildcard command/*.cpp) $(wildcard utilities/*.cpp) $(wildcard IO/*.cpp) runner/CLI.cpp runner/server.cpp
OBJS1 = $(SRC1:.cpp=.o)

# Source files for program2
SRC2 = runner/client.cpp $(wildcard IO/*.cpp)
OBJS2 = $(SRC2:.cpp=.o)

# Executables
EXE1 = server.out
EXE2 = client.out

all: $(EXE1) $(EXE2)

# Build program1
$(EXE1): $(OBJS1)
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJS1)

# Build program2
$(EXE2): $(OBJS2)
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJS2)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files and executables
clean:
	rm -f $(OBJS1) $(OBJS2) $(EXE1) $(EXE2)