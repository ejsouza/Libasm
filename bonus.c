# include "include/libasm.h"

char        nb[MAX_ARR][KB] =
{
  {" "},  
  {""}, 
  {"0.1"},  
  {"\0"},  
  {"bonjour"},  
  {"     1    "},  
  {"\t\n\v\r\b2"},  
  {"+123"},  
  {"4B.42"},  
  {"42 42"},  
  {"202o"},  
  {"2147483647"},  
  {"2147483648"},  
  {"-2147483648"},  
  {"000000000000"},  
  {"           42"},  
  {"2 * 21"},  
};

char        hex[MAX_ARR][KB] =
{
  {"A"},  
  {"b"}, 
  {"C"},  
  {"12"},  
  {"12fdb3"},  
  {"7E4"},  
  {"2a"},  
  {"75bcd15"},  
  {"1092"},  
  {"7FFFFFFF"},  
  {"0"},  
  {"f"},  
  {"7e1"},  
  {"400"},  
  {"1000"},  
  {"45"},  
  {"15"},  
};

int       number[MAX_ARR][KB] =
{
  {10},
  {11},
  {12},
  {18},
  {1244595},
  {2020},
  {42},
  {123456789},
  {4242},
  {2147483647},
  {0},
  {15},
  {2017},
  {1024},
  {4096},
  {69},
  {21},
};

char       oct_number[MAX_ARR][KB] =
{
  {"12"},
  {"13"},
  {"14"},
  {"22"},
  {"4576663"},
  {"3744"},
  {"52"},
  {"726746425"},
  {"10222"},
  {"17777777777"},
  {"0"},
  {"17"},
  {"3741"},
  {"2000"},
  {"10000"},
  {"105"},
  {"25"},
};

char       binary[MAX_ARR][KB] =
{
  {"1010"},
  {"1011"},
  {"1100"},
  {"10010"},
  {"100101111110110110011"},
  {"11111100100"},
  {"101010"},
  {"111010110111100110100010101"},
  {"1000010010010"},
  {"1111111111111111111111111111111"},
  {"0"},
  {"1111"},
  {"11111100001"},
  {"10000000000"},
  {"1000000000000"},
  {"1000101"},
  {"10101"},
};

void        atoi_base_test(int flag)
{
  int   usr, sys, i;

  usr = sys = i = 0;
  printf(UPRPL "------------------ atoi_base(10) START ------------------\n" RST);

  for(; i < ARR_LEN; i++)
  {
    usr = ft_atoi_base(nb[i], "10");
    sys = atoi(nb[i]);
    if (usr != sys)
    {
      printf(BRED"KO \u274c\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, nb[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"SYS: %d\n"RST, sys);
      }
    }
    else
    {
      printf(BGRN"OK \u2705\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, nb[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"SYS: %d\n"RST, sys);
      }
    }
  }
  printf(UPRPL "------------------- atoi_base(10) END -------------------\n" RST);
  printf(UPRPL "\n------------------ atoi_base(HEX) START -----------------\n" RST);
  for (i = 0; i < ARR_LEN; i++)
  {
    usr = ft_atoi_base(hex[i], "16");
    if (usr == *number[i])
    {
      printf(BGRN"OK \u2705\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, hex[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"NBR: %d\n"RST, *number[i]);
      }
    }
    else
    {
      printf(BRED"KO \u274c\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, hex[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"NBR: %d\n"RST, *number[i]);
      }
    }
  }
  printf(UPRPL "------------------ atoi_base(HEX) END -------------------\n" RST);

  printf(UPRPL "\n---------------- atoi_base(OCTAL) START -----------------\n" RST);
  for (i = 0; i < ARR_LEN; i++)
  {
    usr = ft_atoi_base(oct_number[i], "8");
    if (usr == *number[i])
    {
      printf(BGRN"OK \u2705\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, oct_number[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"NBR: %d\n"RST, *number[i]);
      }
    }
    else
    {
      printf(BRED"KO \u274c\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, oct_number[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"NBR: %d\n"RST, *number[i]);
      }
    }
  }
  printf(UPRPL "----------------- atoi_base(OCTAL) END ------------------\n" RST);

   printf(UPRPL "\n---------------- atoi_base(BINARY) START ----------------\n" RST);
  for (i = 0; i < ARR_LEN; i++)
  {
    usr = ft_atoi_base(binary[i], "2");
    if (usr == *number[i])
    {
      printf(BGRN"OK \u2705\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, binary[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"NBR: %d\n"RST, *number[i]);
      }
    }
    else
    {
      printf(BRED"KO \u274c\n" RST);
      if (flag)
      {
        printf(BCYN"NBR: %s\n"RST, binary[i]);
        printf(BYLW"USR: %d\n" RST, usr);
        printf(BBL"NBR: %d\n"RST, *number[i]);
      }
    }
  }
  printf(UPRPL "----------------- atoi_base(BINARY) END -----------------\n" RST);
}


void        push_front_and_size_test(int flag)
{
  printf(UPRPL "\n----------------- list_push_front START -----------------\n" RST);

  t_list    *node = malloc(sizeof(t_list));
  node->data = ft_strdup("Hello world!");
  node->next = NULL;
  t_list    *point_node = node;
  t_list    *head;
  int       len = 0;
  int       i = 0;

  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  for (; i < LIST_LEN; i++)
  {
    ft_list_push_front(&point_node, (&str[i]));
  }
  head = point_node;
  i = LIST_LEN;
  while (head != NULL)
  {
    i--;
    if (ft_strcmp(&str[i], (char *)head->data))
    {
      /* I check for "Hello world" here because it's created with an
      ** ft_strdup and it doesn't exist in the string 'str' and it is the
      ** first added to the list that will become the last in the list.
      */ 
      if (ft_strcmp((char *)head->data, "Hello world!") == 0)
      {
        if (flag)
          printf(BGRN"OK \u2705\t" BCYN"%s\t" BBL"%s\n" RST, "Hello world!", (char *)head->data);
        else
          printf(BGRN"OK \u2705\n" RST);
      }
      else
      {
        if (flag)
          printf(BRED"KO \u274c\t" BYLW"%s\t"BMGNT"%s\n" RST, &str[i], (char *)head->data);
        else
          printf(BRED"KO \u274c\n" RST);
      }
    }
    else
    { 
      if (flag)
        printf(BGRN"OK \u2705\t" BCYN"%s\t" BBL"%s\n" RST,&str[i], (char *)head->data);
      else
        printf(BGRN"OK \u2705\n" RST);
    }
    head = head->next;
  }
  printf(UPRPL "------------------ list_push_front END ------------------\n" RST);
  printf(UPRPL "\n-------------------- list_size START --------------------\n" RST);
  len = ft_list_size(NULL);
  if (len == 0)
  {
    if (flag)
      printf(BGRN"OK \u2705\t" BCYN"Hanldes NULL lists\n" RST);
    else
      printf(BGRN"OK \u2705\n" RST);

  }
  else
  {
    if (flag)
      printf(BRED"KO \u274c\t" BYLW"Doesn't handle NULL lists\n" RST);
    else
      printf(BRED"KO \u274c\n");
  }
  len = ft_list_size(node);
  if (len == 1)
  {
    if (flag)
      printf(BGRN"OK \u2705\t" BCYN"Hanldes lists with only one node\n" RST);
    else
      printf(BGRN"OK \u2705\n" RST);
  }
  else
  {
    if (flag)
      printf(BRED"KO \u274c\t" BYLW"Doesn't hanldes lists with only one node\n" RST);
    else
      printf(BRED"KO \u274c\n"RST);
  }

  len = ft_list_size(point_node);
  // LIST_LEN + 1 because the first node int the list is "Hello world!"
  if (len == LIST_LEN + 1)
  {
    if (flag)
      printf(BGRN"OK \u2705\t" BCYN"The size of the list is %d (LIST_LEN + 1)\n" RST, LIST_LEN + 1);
    else
      printf(BGRN"OK \u2705\n" RST);
  }
  else
  {
    if (flag)
      printf(BRED"KO \u274c\t" BYLW"The size of the list MUST BE %d (LIST_LEN + 1) and not %d\n" RST, LIST_LEN + 1, len);
    else
      printf(BRED"KO \u274c\n" RST);
  }
  printf(UPRPL "--------------------- list_size END ---------------------\n" RST);
}



int         main(int argc, char **argv)
{
    int flag = 0;
    if (argc == 2)
    {
        if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--verbose") == 0)
            flag = 1;
    }
    atoi_base_test(flag);
    push_front_and_size_test(flag);

    return (0);
}