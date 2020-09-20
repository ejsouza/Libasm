#ifndef LIBASM_H
# define LIBASM_H

# define RED "\e[0;31m"


# define BRED "\e[1;31m"
# define BYLW "\e[1;93m"
# define BGRN "\e[1;32m"
# define BMGNT "\e[1;35m"
# define BCYN "\e[1;36m"
# define BBL  "\e[1;34m"  

# define UPRPL "\e[4;35m"
# define UBL "\e[4;34m"
# define UYLW "\e[4;33m"

# define RST "\e[0m"

# define MAX_ARR 42
# define ARR_LEN 17
# define KB      1024

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t      ft_strlen(const char *s);
char        *ft_strcpy(char *dest, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
ssize_t     ft_write(int fd, const void *buf, size_t count);
ssize_t     ft_read(int fd, void *buf, size_t count);
char        *ft_strdup(const char *s);

# endif