# include "include/libasm.h"

void read() { printf("\033[1;31m"); }
void yellow(){ printf("\033[1;33m"); }
void green(){ printf("\033[1;32m"); }
void magenta() { printf("\033[1;35m"); }
void cyan() { printf( "\033[1;36m" ); }
void purple_underline() { printf("\033[4;35m"); }
void reset() { printf("\033[0m"); }

char array[MAX_ARR][1024] =
{
    {"\0"},
    {"\n"},
    {""},
    {"0"},
    {"42"},
    {"Holla"},
    {"123456"},
    {"hello, world"},
    {"toto titi tata"},
    {"                              "},
    {"The library must be called libasm.a"},
    {"Qu'est-ce que le Lorem Ipsum?"},
    {"Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression"},
    {"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi nec condimentum magna."},
    {"Vestibulum rutrum dapibus dolor, ac faucibus nibh maximus vel. Nam vulputate condimentum erat, sollicitudin viverra urna ultrices at. Nulla congue dignissim pellentesque. Praesent eros est, egestas eu fringilla nec, ornare a nisl. Aenean euismod interdum nisl, sit amet pellentesque quam venenatis in. Nulla facilisis nulla nunc, in vulputate nibh tincidunt vitae."},
    {"a���4�+ҁx���l�J��2�h���ݱO?�O�����KekR��5��pK���r���HF�g0.F������>W"},
    {"                                                                 [a!�<�/�K=�<W�Ar����LFl�4�3E�����;�ɛ�����:��ȵ׿�@]09HرAڬ�<=k�:�{�v�T]x��ۧ�S��   ���Uk?g�k�y�?��Ɵ���9 �Ŧ��p/���:�wy��w��̙�ed.��2�lY+|��&��؊��%w�&�@Nu�Hs_��(���ͮ���R���B��Ƨ�g|�O��x����5��$fCȤrG%"},

};

void strlen_test(int flag)
{
    size_t mine, sys, i;
    mine = sys = i = 0;
    printf(UPRPL "--------------- ft_strlen(START) ---------------\n" RST);
    for (; i < 17; i++)
    {
        if (flag)
        {
            printf(BCYN"%s\t" RST, array[i]);
        }
        mine = ft_strlen(array[i]);
        sys = strlen(array[i]);
        mine == sys ? printf(BGRN"OK \u2705\n" RST) :  printf(BRED"KO \u274c\t"UYLW"mine %zu" "\t" BRED"\u2260"RST "  " UBL"sys %zu\n" RST, mine, sys);
    }
    printf(UPRPL"\n--------------- ft_strlen(END) ---------------\n\n"RST);

}


void strcpy_test(int flag)
{
    char dest_usr[1024];
    char dest_sys[1024];
    int ret, i;
    ret = i = 0;
    printf(UPRPL "--------------- ft_strcpy(START) ---------------\n" RST);


    for (; i < 17; i++)
    {
        ft_strcpy(dest_usr, array[i]);
        strcpy(dest_sys, array[i]);
        if (strcmp(dest_usr, dest_sys))
        {
            printf(BRED"KO \u274c\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\n" RST, dest_usr);
                printf(BBL"SYS: %s\n"RST, dest_sys);
            }
            
        }
        else 
        {
            printf(BGRN"OK \u2705\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\n" RST, dest_usr);
                printf(BBL"SYS: %s\n"RST, dest_sys);
            }
        }

    }
    
    printf(UPRPL "--------------- ft_strcpy(END) ---------------\n" RST);

}

int main(int argc, char **argv)
{
    int flag = 0;
    if (argc == 2)
    {
        if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--verbose") == 0)
            flag = 1;
    }
    strlen_test(flag);
    strcpy_test(flag);
    return (0);
}