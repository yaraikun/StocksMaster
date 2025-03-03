# Compiler Args
CC=gcc
INCLUDE=-Iinclude -Ilib
CFLAGS=$(INCLUDE) -Wall -Wextra

# Directories
SRC_DIR=src
BIN_DIR=bin
INPUT_DIR=input
OUTPUT_DIR=output
TEST_DIR=test

# Source Files
SRC_C7=$(SRC_DIR)/03-C7.c
SRC_C8=$(SRC_DIR)/03-C8.c

# Executable Files
BIN_C7=$(BIN_DIR)/03-C7.out
BIN_C8=$(BIN_DIR)/03-C8.out

# BB Test Files
BBTEST_SRC=$(TEST_DIR)/bbtest.c
BBTEST_BIN=$(TEST_DIR)/bbtest.out
EXPECTED_C7=$(TEST_DIR)/C7-AC-EXPECTED.TXT
EXPECTED_C8=$(TEST_DIR)/C8-AC-EXPECTED.TXT

# Input File
INPUT=$(INPUT_DIR)/AC.txt

# Executable Output Files
OUTPUT_C7=$(OUTPUT_DIR)/03-C7-AC-OUTPUT.txt
OUTPUT_C8=$(OUTPUT_DIR)/03-C8-AC-OUTPUT.txt

# Black-box Test Output Files
BBTEST_C7=$(OUTPUT_DIR)/03-C7-AC-BBTEST.txt 
BBTEST_C8=$(OUTPUT_DIR)/03-C8-AC-BBTEST.txt

# Default Target: Compiles Everything
all: compile

# Compile all executables
compile: compile_c7 compile_c8

# Run all programs
run: run_c7 run_c8

# Run all tests
test: test_c7 test_c8

# Build and test a certain program
c7: test_c7
c8: test_c8

# Compilation Rules
compile_c7: | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_C7) $(SRC_C7)

compile_c8: | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_C8) $(SRC_C8)

compile_bb:
	$(CC) -o $(BBTEST_BIN) $(BBTEST_SRC)

# Run Rules
run_c7: compile_c7 | $(OUTPUT_DIR)
	$(BIN_C7) < $(INPUT) > $(OUTPUT_C7)

run_c8: compile_c8 | $(OUTPUT_DIR)
	$(BIN_C8) < $(INPUT) > $(OUTPUT_C8)

# Test Rules
test_c7: run_c7
	$(BBTEST_BIN) $(EXPECTED_C7) $(OUTPUT_C7) > $(BBTEST_C7)

test_c8: run_c8
	$(BBTEST_BIN) $(EXPECTED_C8) $(OUTPUT_C8) > $(BBTEST_C8)

# Ensure required directories exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Clean
clean:
	rm -f $(BIN_C7) $(BIN_C8) $(OUTPUT_C7) $(OUTPUT_C8) $(BBTEST_C7) $(BBTEST_C8)
