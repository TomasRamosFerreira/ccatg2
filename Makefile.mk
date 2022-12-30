### Avaiable Comands ###
# 1. Compile C file (without the .c extension) 	-> make path/to/file.c
# 2. Clean generated files from compilation 	-> make clean

# Name of the file to be compiled (without the .c extension)
FILE = $(1)

# Name of the executable to be generated
EXE = $(2)

# Compilation flags
CFLAGS = -Wall -Wextra -O2 -lgmp

# Dependencies of the file (other .c or .h files included by the main file)
DEPS = $(wildcard $(FILE).h)

# Rules

# Default rule (executes the first rule found)
all: $(EXE)

# Compiles the main file and all its dependencies
$(EXE): $(FILE).c $(DEPS)
    gcc $(CFLAGS) -o $@ $<

# Cleans up the files generated during compilation
clean:
    rm -f $(EXE)
