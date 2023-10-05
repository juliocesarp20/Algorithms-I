# flags
CC = g++

# pastas
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# source, objetos, include
MAIN = main
TARGET = tp03
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(TARGET)*
