# include "include/libasm.h"

void read() { printf("\033[1;31m"); }
void yellow(){ printf("\033[1;33m"); }
void green(){ printf("\033[1;32m"); }
void magenta() { printf("\033[1;35m"); }
void cyan() { printf( "\033[1;36m" ); }


void reset()
{
    printf("\033[0m");
}

char array[MAX_ARR][1024] =
{
    {"\0"},
    {"\n"},
    {""},
    {"0"},
    {"42"},
    {"123456"},
    {"hello, world"},
    {"Holla"},
    {"toto titi tata"},
    {"                              "},
    {"The library must be called libasm.a"},
    {"Qu'est-ce que le Lorem Ipsum?"},
    {"Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression"},
    {"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi nec condimentum magna."},
    {"Vestibulum rutrum dapibus dolor, ac faucibus nibh maximus vel. Nam vulputate condimentum erat, sollicitudin viverra urna ultrices at. Nulla congue dignissim pellentesque. Praesent eros est, egestas eu fringilla nec, ornare a nisl. Aenean euismod interdum nisl, sit amet pellentesque quam venenatis in. Nulla facilisis nulla nunc, in vulputate nibh tincidunt vitae."},

};

size_t      ft_strlen(const char *s);

void strlen_test()
{
    size_t mine, sys, i;
    mine = sys = i = 0;
    magenta();
    printf("----- ft_strlen -----\n");
    reset();
    for (; i < 15; i++)
    {
        cyan();
        printf("%s\t", array[i]);
        reset();
        mine = ft_strlen(array[i]);
        sys = strlen(array[i]);
        mine == sys ? printf("\033[1;32mOK \u2705\n\033[0m") :  printf("\033[1;31mKO \u274c\033[0m\t\033[1;33mmine %zu\tsys %zu\n", mine, sys);
        reset();
    }
}

int main(void)
{
    strlen_test();
    return (0);
}