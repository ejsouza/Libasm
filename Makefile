# LC_ALL=C make -> show error in english
NAME = libasm.a

SOURCES_DIR = srcs

OBJECTS_DIR = objs

SRCS = ./srcs/ft_strlen.s\

ASM = nasm

CC = gcc

ASM_FLAGS = -f elf64

FLAGS = -Wall -Werror -Wextra

AR = ar rcs

OBJECTS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) Makefile
	@$(AR) $@ $(OBJECTS) -o $(NAME)
	@echo "\033[0;36m		***** Creating Library *****"

$(OBJECTS_DIR)/%.o : %.s
	@$(ASM) $(ASM_FLAGS) $(srcs) -c -o $@ $< 
	@echo "\033[32m			***** Creating Objects *****"

tests: all
	@$(CC) $(FLAGS) -I /include/libasm.h -L. -lasm ./srcs/main.c -o tests

clean:
	@rm -f $(OBJECTS:%.o=$(OBJECTS_DIR)/%.o)
	@echo "\033[33m 		***** Objects  deleted *****"

fclean: clean
	@rm -f $(NAME)
	@rm -f tests
	@echo "\033[31m		**** The house is clean ****"

re: fclean all