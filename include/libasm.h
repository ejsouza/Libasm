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

# define MAX_ARR    42
# define ARR_LEN    17
# define LIST_LEN   36
# define KB         1024

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct      s_list
{
    void            *data;
    struct s_list   *next; 
    
}                   t_list;


size_t      ft_strlen(const char *s);
char        *ft_strcpy(char *dest, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
ssize_t     ft_write(int fd, const void *buf, size_t count);
ssize_t     ft_read(int fd, void *buf, size_t count);
char        *ft_strdup(const char *s);

/*
** bonus
*/

int         ft_atoi_base(const char *str, char *base);
void        ft_list_push_front(t_list **begin_list, void *data);
int         ft_list_size(t_list *begin_list);
void	    ft_list_sort(t_list **begin_list,int(*cmp)());
void	    ft_list_remove_if(t_list **begin_list,void*data_ref,int(*cmp)());


# endif
