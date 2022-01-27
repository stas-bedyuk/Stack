#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "STACK.h"
int main()
{
	Book* s = nullptr;
    Book* h=nullptr;
    int j=1;
    int i = 0;
    while (j!=0)
    {
     printf("\n\nSelect an action:\n0--EXIT\n1--ADD A STACK\n2--SHOW STACK\n3--DELETE AN ELEMENT FROM THE STACK\n4--STACK SEARCH\n5--WRITING A STACK TO A FILE\n6--READING STACK FROM THE FILE\n\nCHOOSE(0-6): ");
     while (!scanf("%d", &j) || j < 0 || j>6)
     {
         printf("ERROR!Choose: ");
         rewind(stdin);
     }
     switch (j)
     {
     case 0:
     break;
     break;
     case 1:
         if(i==1) s = reverse(s);
         s = push(s);
         s = reverse(s);
         i = 1;
     break;
     case 2:
         show(s);
     break;
     case 3:
         s = deleteALL(s);
     break;
     case 4:
         search(s);
     break;
     case 5:
         save(s);
     break;
     case 6:
        s= read(h);
     break;
     }
    }
	while (s)
	{
		free(s->name);
		s = s->l;
	}
	free(s);
    while (h)
    {
        free(h->name);
        h = h->l;
    }
    free(h);

	return 0;
}

