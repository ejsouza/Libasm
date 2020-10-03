# LC_ALL=C make -> show error in english

NAME = libasm.a

SOURCES_DIR = srcs/
BONUS_SRCS = bonus_srcs/
OBJECTS_DIR = objs/
INCLUDE = include/

SRCS =  ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s\

SRCS_BONUS = ft_atoi_base_bonus.s\
			 ft_list_push_front_bonus.s\
			 ft_list_size_bonus.s\
			 ft_list_sort_bonus.s \
			 ft_list_remove_if_bonus.s\

SOURCES = ${addprefix $(SOURCES_DIR), ${SRCS}}

SOURCES_BONUS = ${addprefix $(BONUS_SRCS), ${SRCS_BONUS}} 

OBJECTS = ${patsubst ${SOURCES_DIR}%.s,${OBJECTS_DIR}%.o,${SOURCES}}
OBJECTS_BONUS = ${patsubst ${BONUS_SRCS}%.s,${OBJECTS_DIR}%.o,${SOURCES_BONUS}}

all: ${NAME}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.s
	@mkdir -p ${OBJECTS_DIR}
	@nasm -f elf64 $< -o $@

${NAME}: ${OBJECTS} Makefile
	@ar rcs ${NAME} ${OBJECTS}
	@printf '\e[1;36mLIBRIRY ASM\e[0m \e[1;32m \u2705\e[0m\n'

tests : ${NAME}
	@gcc -g main.c -I include ${NAME} -o tests
	@printf '\e[1;36mMAIN TESTS\e[0m \e[1;32m \u2705\e[0m\n'

${OBJECTS_DIR}%.o : ${BONUS_SRCS}%.s
	@mkdir -p ${OBJECTS_DIR}
	@nasm -f elf64 $< -o $@

bonus: ${NAME}  ${OBJECTS_BONUS}
	@ar rcs ${NAME}  ${OBJECTS_BONUS}
	@printf '\e[1;36mBONUS ADDED TO LIBRIRY\e[0m \e[1;32m \u2705\e[0m\n'


bonus_tests : ${NAME} bonus
	gcc -g bonus.c -I include ${NAME} -o bonus
	@printf '\e[1;36mBONUS TESTS\e[0m \e[1;32m \u2705\e[0m\n'

clean:
	@rm -f ${OBJECTS} ${OBJECTS_BONUS}
	@printf '\e[1;93mOBJECTS REMOVED\e[0m \e[1;32m \u2705\e[0m\n'

fclean: clean
	@rm -f ${NAME}
	@rm -f tests
	@rm -f bonus
	@printf '\e[1;31mEVERYTHING REMOVED\e[0m \e[1;32m \u2705\e[0m\n'

re: fclean all
	@printf '\e[1;32mHOUSE IS CLEAN, REBUILDING...\e[0m \e[1;32m \u2705\e[0m\n'
