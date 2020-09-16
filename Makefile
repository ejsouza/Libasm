# LC_ALL=C make -> show error in english
NAME = libasm.a

SOURCES_DIR = srcs

OBJECTS_DIR = objs

SRCS = ./srcs/ft_strlen.s\

ASAM = nasm

ASAM_FLAGS = -f macho64

FLAGS = -Wall -Werror -Wextra

AR = ar rcs

OBJECTS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) Makefile
	@$(AR) $@ $(OBJECTS) -o $(NAME)
	@echo "\033[0;36m		***** Creating Library *****"

$(OBJECTS_DIR)/%.o : %.s
	@$(ASAM) $(ASAM_FLAGS) $(srcs) -c $< -o $@
	@echo "\033[32m			***** Creating Objects *****"



clean:
	@rm -f $(OBJECTS:%.o=$(OBJECTS_DIR)/%.o)
	@echo "\033[33m 		***** Objects deleted *****"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m			**** The house is clean ***"

re: fclean all