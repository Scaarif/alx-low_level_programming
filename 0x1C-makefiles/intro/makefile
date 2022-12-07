# Patterns and Functions Example

# Usage:
# make		# compile all binary
# make claen	# remove ALL binaries and objects

.PHONY = all clean

CC = gcc 	# compiler to use
LINKERFLAG = -lm

SRCS := $(wildcard *.c) 	# src files (all .c files)
BINS := $(SRCS:%.c=%) 		# a substitution reference (foo.c to foo)

all: ${BINS} 		# run all values in BINS as targets

# Rules

%: %.o
	@echo "Checking.." 	# the @ prevents the recipe(cmd) from displaying
	${CC} ${LINKERFLAG} $< -o $@
	# i.e. gcc -lm .o(prerequisite) file -o binary/executable(target)
%.o: %.c
	@echo "Creating object..."
	${CC} -c $<
	# i.e. create (target)object file (compile) from prerequisite(.c file)

clean:
	@echo "Claening up..."
	rm -rvf *.o ${BINS} 		# i.e. remove all object and binary files

