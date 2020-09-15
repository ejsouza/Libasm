NAME = libasm.a

SOURCES_DIR = srcs

OBJECTS_DIR = objs

SRCS = ft_strlen.s

ASAM = nasam

AR = ar rcs

OBJECTS = $(SRCS:.s=.o)

$(NAME)/%.o: $(OBJECTS:%.o=$(OBJECTS_DIR)/%.o) Makefile
	@$(AR) $@ $(OBJECTS:%.o=$(OBJECTS_DIR)/.o)
	@echo "\033[0;36m		***** Creating Library *****"

$(OBJECTS_DIR)/%.O: $(SOURCES_DIR)/%.c
	@$(ASAM) $(srcs) -c $< -o $@
	@echo "\033[32m			***** Creating Objects *****"

all: $(NAME)

clean:
	@rm -f $(OBJECTS:%.o=$(OBJECTS_DIR)/%.o)
	@echo "\033[33m 		***** Objects deleted *****"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31			**** The house is clean ***"

re: fclean all