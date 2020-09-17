# include "include/libasm.h"

size_t      ft_strlen(const char *s);

void strlen_test()
{
    printf("----- ft_strlen -----\n");
    // hello_world();
    printf("lib : %zu\n", ft_strlen("Toto"));
}

int main(void)
{
    printf("Testing... %d\n", TOTO);


    strlen_test();
    return (0);
}