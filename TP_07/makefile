# CC=gcc
# # CFLAGS=-Wall -ansi
# LDFLAGS=-lMLV
# OBJ=view.o
# # sudoku.o main.o in_out.o view.o

# view: $(OBJ)
# 	$(CC) -o view.c $(OBJ) $(LDFLAGS)

# # sudoku: $(OBJ)
# # 	$(CC) -o sudoku $(OBJ) $(CFLAGS)


# # main.o: main.c sudoku.h in_out.h
# # 	$(CC) -c main.c $(CFLAGS)

# # sudoku.o: sudoku.c sudoku.h
# # 	$(CC) -c sudoku.c $(CFLAGS)

# # in_out.o: in_out.c in_out.h
# # 	$(CC) -c in_out.c $(CFLAGS)

# clean: 
# 	rm -f *.o
# 	rm -f *~
# 	rm -f sudoku

EXEC=sudoku

CC = gcc
CFLAGS = -Wall -std=c17 # bien
LDFLAGS = -lMLV -lm

SRC_DIR = src
BIN_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

all: $(EXEC)

#executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#fichiers objets
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

#creer le dossier bin (pour y mettre les fichiers objets)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(BIN_DIR) $(EXEC)

mrproper: clean
	rm -rf *~

.PHONY: all run clean mrproper
