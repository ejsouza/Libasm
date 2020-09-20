# LC_ALL=C make -> show error in english

NAME = libasm.a

SOURCES_DIR = srcs/
OBJECTS_DIR = objs/
INCLUDE = include

FLAGS = -Wall -Werror -Wextra

SRCS =  ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s\

SOURCES = ${addprefix $(SOURCES_DIR), ${SRCS}}

OBJECTS = ${patsubst ${SOURCES_DIR}%.s,${OBJECTS_DIR}%.o,${SOURCES}}

all: ${NAME}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.s
	@mkdir -p ${OBJECTS_DIR}
	@nasm -f elf64 $< -o $@

${NAME}: ${OBJECTS} Makefile
	ar rcs ${NAME} ${OBJECTS}

test : ${NAME}
	gcc ${FLAGS} -g main.c -I include ${NAME} -o simple_test

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm -f ${NAME}
	@rm -f simple_test

re: fclean all
