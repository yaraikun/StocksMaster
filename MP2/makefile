# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra

# Directories
BIN_DIR = bin
OUTPUT_DIR = output
BBTEST_DIR = bbtest

# Ensure directories exist using PowerShell
$(BIN_DIR):
	pwsh -Command "if (!(Test-Path '$(BIN_DIR)')) { New-Item -ItemType Directory -Path '$(BIN_DIR)' }"

$(OUTPUT_DIR):
	pwsh -Command "if (!(Test-Path '$(OUTPUT_DIR)')) { New-Item -ItemType Directory -Path '$(OUTPUT_DIR)' }"

# Compile BBTest
bbtest: $(BIN_DIR)/bbtest.exe

$(BIN_DIR)/bbtest.exe: $(BBTEST_DIR)/bbtest.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Compile C3
c3: $(BIN_DIR)/03-C3.exe

$(BIN_DIR)/03-C3.exe: c3/03-C3.c c3/C3.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ c3/03-C3.c

# Compile C4
c4: $(BIN_DIR)/03-C4.exe

$(BIN_DIR)/03-C4.exe: c4/03-C4.c c4/C4.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ c4/03-C4.c

# Compile C5
c5: $(BIN_DIR)/03-C5.exe

$(BIN_DIR)/03-C5.exe: c5/03-C5.c c5/C5.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ c5/03-C5.c

# Run C3 with input redirection (CMD)
r3: $(BIN_DIR)/03-C3.exe | $(OUTPUT_DIR)
	$(BIN_DIR)/03-C3.exe < $(BBTEST_DIR)/AC.txt > $(OUTPUT_DIR)/03-C3-AC-OUTPUT.txt

# Run C4 with input redirection (CMD)
r4: $(BIN_DIR)/03-C4.exe | $(OUTPUT_DIR)
	$(BIN_DIR)/03-C4.exe < $(BBTEST_DIR)/AC.txt > $(OUTPUT_DIR)/03-C4-AC-OUTPUT.txt

# Run C5 with input redirection (CMD)
r5: $(BIN_DIR)/03-C5.exe | $(OUTPUT_DIR)
	$(BIN_DIR)/03-C5.exe < $(BBTEST_DIR)/AC.txt > $(OUTPUT_DIR)/03-C5-AC-OUTPUT.txt

# Run BBTest for C3 (CMD)
t3: $(BIN_DIR)/bbtest.exe | $(OUTPUT_DIR)
	$(BIN_DIR)/bbtest.exe c3/C3-AC-EXPECTED.TXT $(OUTPUT_DIR)/03-C3-AC-OUTPUT.txt > $(OUTPUT_DIR)/03-C3-AC-BBTEST.txt

# Run BBTest for C4 (CMD)
t4: $(BIN_DIR)/bbtest.exe | $(OUTPUT_DIR)
	$(BIN_DIR)/bbtest.exe c4/C4-AC-EXPECTED.TXT $(OUTPUT_DIR)/03-C4-AC-OUTPUT.txt > $(OUTPUT_DIR)/03-C4-AC-BBTEST.txt

# Run BBTest for C5 (CMD)
t5: $(BIN_DIR)/bbtest.exe | $(OUTPUT_DIR)
	$(BIN_DIR)/bbtest.exe c5/C5-AC-EXPECTED.TXT $(OUTPUT_DIR)/03-C5-AC-OUTPUT.txt > $(OUTPUT_DIR)/03-C5-AC-BBTEST.txt

# Compile Everything
compile: bbtest c3 c4 c5

# Run Everything
run: r3 r4 r5

# Run All BBTests
test: t3 t4 t5

# Clean compiled files and outputs using PowerShell
clean:
	pwsh -Command "if (Test-Path '$(BIN_DIR)') { Remove-Item -Recurse -Force '$(BIN_DIR)' }"
	pwsh -Command "if (Test-Path '$(OUTPUT_DIR)') { Remove-Item -Recurse -Force '$(OUTPUT_DIR)' }"
