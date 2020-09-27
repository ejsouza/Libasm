# LC_ALL=C make -> show error in english

NAME = libasm.a

SOURCES_DIR = srcs/
OBJECTS_DIR = objs/
INCLUDE = include

SRCS =  ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s\
		ft_atoi_base_bonus.s\
		ft_list_push_front_bonus.s\
		ft_list_size_bonus.s\
		ft_list_sort_bonus.s \

SOURCES = ${addprefix $(SOURCES_DIR), ${SRCS}}

OBJECTS = ${patsubst ${SOURCES_DIR}%.s,${OBJECTS_DIR}%.o,${SOURCES}}

all: ${NAME}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.s
	@mkdir -p ${OBJECTS_DIR}
	@nasm -f elf64 $< -o $@

${NAME}: ${OBJECTS} Makefile
	ar rcs ${NAME} ${OBJECTS}

test : ${NAME}
	gcc -g main.c -I include ${NAME} -o simple_test

bonus : ${NAME}
	gcc -g bonus.c -I include ${NAME} -o bonus

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm -f ${NAME}
	@rm -f simple_test
	@rm -f bonus

re: fclean all
