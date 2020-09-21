# include "include/libasm.h"

char array[MAX_ARR][KB] =
{
    {"\0"},
    {"\n"},
    {""},
    {"0\0"},
    {"42\0"},
    {"Holla\0"},
    {"123456\0"},
    {"hello, world\0"},
    {"toto titi tata\0"},
    {"                              \0"},
    {"The library must be called libasm.a\0"},
    {"Qu'est-ce que le Lorem Ipsum?\0"},
    {"Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression\0"},
    {"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi nec condimentum magna.\0"},
    {"Vestibulum rutrum dapibus dolor, ac faucibus nibh maximus vel. Nam vulputate condimentum erat, sollicitudin viverra urna ultrices at. Nulla congue dignissim pellentesque. Praesent eros est, egestas eu fringilla nec, ornare a nisl. Aenean euismod interdum nisl, sit amet pellentesque quam venenatis in. Nulla facilisis nulla nunc, in vulputate nibh tincidunt vitae.\0"},
    {"a���4�+ҁx���l�J��2�h���ݱO?�O�����KekR��5��pK���r���HF�g0.F������>W"},
    {"                                                                 [a!�<�/�K=�<W�Ar����LFl�4�3E�����;�ɛ�����:��ȵ׿�@]09HرAڬ�<=k�:�{�v�T]x��ۧ�S��   ���Uk?g�k�y�?��Ɵ���9 �Ŧ��p/���:�wy��w��̙�ed.��2�lY+|��&��؊��%w�&�@Nu�Hs_��(���ͮ���R���B��Ƨ�g|�O��x����5��$fCȤrG%\0"},

};
char cmp_s1[MAX_ARR][KB] =
{
    {""},
    {"12"},
    {"->\n\n\n\0"},
    {"toto"},
    {"Bonjour"},
    {"strcmp, strncmp - compare two strings"},
    {"The  strcmp()  function compares the two strings s1 and s2."},
    {"It returns an integer less than, equal to,"},
    {"or greater than zero if s1 is found,"},
    {"\0-"},
    {"\\\\\\\\\\\\"},
    {"!@#$%^&*("},
    {"4242424242424242424242424242424242424242424242424242424242.42"},
    {"aabbbcccddddeeeeefffffffggggggggg"},
    {"Hello world!"},
    {"<<<<<<<<<<<=>>>>>>>>>>>>"},
    {"testing..."}

};
char cmp_s2[MAX_ARR][KB] =
{
    {" \0"},
    {"123\0"},
    {"->\n\n\n\0 "},
    {"tota\0"},
    {"Bonj\nour\0"},
    {"strcmp, strncmp - compare twO strings\0"},
    {"The  strcmp()  function compares the two strings s1 and s3.\0"},
    {"It returns an integer less than, equal to\0"},
    {"or greater than zero if  s1 is found,\0"},
    {"-\0"},
    {"\\\\\\\\\\\0"},
    {"!@#$%^&*()\0"},
    {"4242424242424242424242424242424242424242424242424242424242,42\0"},
    {"aabbbcccddddeeeeefffffffgggggggg'g'\0"},
    {"Hello world\0"},
    {"<<<<<<<<<<<=>>>>>>>>>>>\0"},
    {"testing,,,\0"}
};

void strlen_test(int flag)
{
    size_t mine, sys, i;
    mine = sys = i = 0;
    printf(UPRPL "------------------ ft_strlen(START) ------------------\n" RST);
    for (; i < ARR_LEN; i++)
    {
        if (flag)
        {
            printf(BCYN"%s\t" RST, array[i]);
        }
        mine = ft_strlen(array[i]);
        sys = strlen(array[i]);
        mine == sys ? printf(BGRN"OK \u2705\n" RST) :  printf(BRED"KO \u274c\t"UYLW"mine %zu" "\t" BRED"\u2260"RST "  " UBL"sys %zu\n" RST, mine, sys);
    }
    printf(UPRPL"\n------------------ ft_strlen(END) ------------------\n\n"RST);

}

void strcpy_test(int flag)
{
    char dest_usr[1024];
    char dest_sys[1024];
    int i;
    i = 0;
    printf(UPRPL "------------------ ft_strcpy(START) ------------------\n" RST);


    for (; i < ARR_LEN; i++)
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
    
    printf(UPRPL "------------------ ft_strcpy(END) ------------------\n\n" RST);

}

void strcmp_test(int flag)
{
    printf(UPRPL "------------------ ft_strcmp(START) ------------------\n" RST);
    int     i, usr, sys;


    i = usr = sys = 0;
    printf(BYLW"======================== EQUAL ========================\n"RST);
    for (; i < ARR_LEN; i++)
    {
        usr = ft_strcmp(array[i], array[i]);
        sys = strcmp(array[i], array[i]);
        if (usr == sys)
        {
            printf(BGRN"OK \u2705\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\t" "%d\n" RST, array[i], usr);
                printf(BBL"SYS: %s\t" "%d\n" RST, array[i], sys);
            }
        }
        else
        {
            printf(BRED"KO \u274c\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\t" "%d\n" RST, array[i], usr);
                printf(BBL"SYS: %s\t" "%d\n" RST , array[i], sys);
            }
        }
    }
    printf(BYLW"======================== !EQUAL ========================\n"RST);
    for (i = 0; i < ARR_LEN; i++)
    {
        usr = ft_strcmp(cmp_s1[i], cmp_s2[i]);
        sys = strcmp(cmp_s1[i], cmp_s2[i]);
        if ((usr < 0 && sys < 0) || (usr == 0 && sys == 0) || (usr > 0 && sys > 0))
        {
            printf(BGRN"OK \u2705\n" RST);
            if (flag)
            {
                printf(BYLW"USR s1: %s\nUSR s2: %s\t" "%d\n" RST, cmp_s1[i], cmp_s2[i], usr);
                printf(BBL"SYS s1: %s\nSYS s2: %s\t" "%d\n\n" RST, cmp_s1[i], cmp_s2[i], sys);
            }
        }
        else
        {
            printf(BRED"KO \u274c\n" RST);
            if (flag)
            {
                printf(BYLW"USR s1: %s\nUSR s2: %s\t" "%d\n" RST, cmp_s1[i], cmp_s2[i], usr);
                printf(BBL"SYS s1: %s\nSYS s2: %s\t" "%d\n\n" RST, cmp_s1[i], cmp_s2[i], sys);
            }
        }
    }
    printf(UPRPL "------------------ ft_strcmp(END) ------------------\n\n" RST);

}

void write_test(void)
{
    int i, usr, sys;
    printf(UPRPL "------------------ ft_write(START) ------------------\n" RST);
    printf(BYLW"\n======================== NULL ========================\n"RST);
    usr = ft_write(-1, "Hell", 4);
    sys = write(-1, "Hell", 4);
    if (usr != sys) printf(BRED"KO \u274c\t" BRED"Does't return -1 for negative fd\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle negative fd\n" RST));
    usr = ft_write(1, NULL, 4);
    sys = write(1, NULL, 4);
    if (usr != sys) printf(BRED"KO \u274c\t" BYLW "Does't return -1 for NULL pointer\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle NULL pointer\n" RST));
    usr = ft_write(1, "Hell", -4);
    sys = write(1, "Hell", -4);
    if (usr != sys) printf(BRED"KO \u274c\t" BRED"Does't return -1 for negative length\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle negative length\n" RST));
    usr = ft_write(1, "\0\0\0\0", 4);
    sys = write(1, "\0\0\0\0", 4);
    if (usr != sys) printf(BRED"KO \u274c\t" BRED"Does't work with '\\0'\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle '\\0'\n" RST)); 
    printf(BYLW"====================== STANDARD 1 ======================\n"RST);
    for (i = 0; i < ARR_LEN; i++)
    {
       ft_write(1, "\033[1;36m", 9);
       usr = ft_write(1, array[i], strlen(array[i]));
       sys = write(1, array[i], strlen(array[i]));
       if (usr != sys)
       {
             printf(BRED"\tKO \u274c\n" RST);   
       }
       else
       {
           printf(BGRN"\tOK \u2705\n" RST);
       }
       ft_write(1, "\033[0m", 6);
    }
    printf(BYLW"====================== STANDARD 2 ======================\n"RST);
    for (i = 0; i < ARR_LEN; i++)
    {
       ft_write(1, "\033[1;36m", 9);
       usr = ft_write(2, cmp_s2[i], strlen(cmp_s2[i]));
       sys = write(2, cmp_s2[i], strlen(cmp_s2[i]));
       if (usr != sys)
       {
             printf(BRED"KO \u274c\n" RST);   
       }
       else
       {
           printf(BGRN"\tOK \u2705\n" RST);
       }
       ft_write(1, "\033[0m", 6);
    }
   
    printf(UPRPL "\n------------------ ft_write(END) ------------------\n" RST);

}

void read_test()
{
    int fd_usr, fd_sys, usr, sys;

    fd_usr = open("Makefile", O_RDONLY);
    fd_sys = open("main.c", O_RDONLY);

    printf(UPRPL "------------------- ft_read(START) -------------------\n" RST);
    printf(BYLW"\n======================== NULL ========================\n"RST);
    usr = ft_read(-1, array[40], KB);
    sys = read(-1, array[40], KB);
    if (usr != sys) printf(BRED"KO \u274c\t" BRED"Does't return -1 for negative fd\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle negative fd\n" RST));
    usr = ft_read(fd_usr, NULL, KB);
    sys = read(fd_sys, NULL, KB);
    if (usr != sys) printf(BRED"KO \u274c\t" BYLW "Does't return -1 for NULL pointer\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle NULL pointer\n" RST));
    usr = ft_read(fd_usr, array[40], -42);
    sys = read(fd_sys, array[40], -42);
    if (usr != sys) printf(BRED"KO \u274c\t" BRED"Does't return -1 for negative length\n" RST);
    else (printf(BGRN"OK \u2705\t" BCYN "Handle negative length\n" RST));
    close(fd_usr);
    close(fd_sys);
    printf(BYLW"\n=================== READ MAKEFILE ====================\n"RST);
    
    bzero(array[40], KB);
    bzero(array[41], KB);
    fd_usr = open("Makefile", O_RDONLY);
    usr = ft_read(fd_usr, array[40], KB);
    close(fd_usr);
    fd_sys = open("Makefile", O_RDONLY);
    sys = read(fd_sys, array[41], KB);
    if (usr != sys)
    {
        printf(BRED"KO \u274c\t" BRED"ft_read: %d\tread: %d\n" RST, usr, sys);
    }
    else
    {
        printf(BGRN"OK \u2705\t" BCYN "ft_read = %d\tread: %d\n" RST, usr, usr);
    }
    close(fd_sys);
    bzero(array[40], KB);
    bzero(array[41], KB);
    printf(BYLW"\n===================== STD ENTRY ======================\n"RST);
    printf(BMGNT"Enter some text and press return\n");
    usr = ft_read(0, array[40], KB);
    if (ft_strlen(array[40]))
    {
        printf(BGRN"OK \u2705\t %s", array[40]);
    }
    else
    {
        printf(BRED"KO \u274c\t ft_read() doesn work on the standard entroy\n");
    }
    printf(UPRPL "-------------------- ft_read(END) --------------------\n" RST);
    
}

void strdup_test(int flag)
{
    char *usr, *sys;
    int     i;

    printf(UPRPL "------------------- ft_strdup(START) -------------------\n" RST);
    for ( i = 0; i < ARR_LEN; i++)
    {
        usr = ft_strdup(array[i]);
        sys = strdup(array[i]);
        if (strcmp(usr, sys))
        {
            printf(BRED"KO \u274c\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\n"  RST, array[i]);
                printf(BBL"SYS: %s\n"  RST, array[i]);
            }

        }
        else
        {
            printf(BGRN"OK \u2705\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\n" RST, array[i]);
                printf(BBL"SYS: %s\n" RST , array[i]);
            }
        }
        free(usr);
        free(sys);
        usr = ft_strdup(cmp_s1[i]);
        sys = strdup(cmp_s1[i]);
        if (strcmp(usr, sys))
        {
            printf(BRED"KO \u274c\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\n" RST, cmp_s1[i]);
                printf(BBL"SYS: %s\n" RST, cmp_s1[i]);
            }

        }
        else
        {
            printf(BGRN"OK \u2705\n" RST);
            if (flag)
            {
                printf(BYLW"USR: %s\n" RST, cmp_s1[i]);
                printf(BBL"SYS: %s\n" RST , cmp_s1[i]);
            }
        }
        free(usr);
        free(sys);
    }
    
    printf(UPRPL "-------------------- ft_strdup(END) --------------------\n" RST);

}

int main(int argc, char **argv)
{
    int flag = 0;
    if (argc == 2)
    {
        if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--verbose") == 0)
            flag = 1;
    }
    if (flag == 0)
    {
        ;
    }
    // strlen_test(flag);
    // strcpy_test(flag);
    // strcmp_test(flag);
    // write_test();
    // read_test();
    // strdup_test(flag);
    printf("%d\n", ft_atoi_base("\v    \t\f \v\t\n  \f\t\b\r\n +1", 10));
    return (0);
}