CC = gcc
INCLUDE = -Iinclude -Ilib
CFLAGS = -Wall -Wextra $(INCLUDE)

SRC_DIR = src
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.c)
BIN = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRC))

all: $(BIN)

$(BIN_DIR)/%: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.exe

run:
	$(BIN)

.PHONY: clean