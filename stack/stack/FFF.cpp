#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "STACK.h"
Book* push(Book* s)
{
    Book* s1 = s;
    int j = 1;
    do
    {

        if (!(s = (Book*)calloc(1, sizeof(Book))))
        {
            puts("No memory allocated!");
            return nullptr;
        }
        (s)->name = (char*)calloc(20, sizeof(char));
        printf("Name of book: ");
        rewind(stdin);
        gets_s((s)->name, 20);
        printf("Quantity of pages: ");
        while (!scanf("%d", &(s)->page_count) || (s)->page_count < 0)
        {
            printf("\nEnter the number!Quantity of pages: ");
            rewind(stdin);
        }
        printf("Select the field to add in:\n1--Author's name.\n2--Number of volumes.\nInput(1/2): ");
        while (!scanf("%d", &(s)->signal_un) || (s)->signal_un < 1 || (s)->signal_un >2)
        {
            printf("\nEnter the number(1/2)!!!\nInput(1/2): ");
            rewind(stdin);
        }
        switch ((s)->signal_un)
        {
        case 1:
            printf("Author's name:");
            rewind(stdin);
            gets_s((s)->a_name);

            break;
        case 2:
            printf("Number of volumes: ");
            while (!scanf("%d", &(s)->volume_count) || (s)->volume_count < 0)
            {
                printf("\nEnter the number!!!Number of volumes:\n");
                rewind(stdin);
            }
            break;
        }
        (s)->l = s1;
        s1 = s;
        printf("Do you want to continue typing(1/0)? ");
        while (!scanf("%d", &j) || j < 0 || j>1)
        {
            printf("Error!Do you want to continue typing(1/0)? ");
            rewind(stdin);
        }
        if (j == 0) break;
    } while (1);
    return s;
}

void show(Book* s)
{
    int j = 0;
    if (!s)
    {
        puts("Error!");
        return;
    }
    printf("\n");
    for (int i = 0; i < 90; i++) printf("-");
    printf("\n");
    printf("| Book: |   Name of book:   | Number of pages: |   Author's name:   | Number of volumes: |\n");
    do
    {
        if (strlen(s->name) > 17)
            s->name[17] = '\0';
        if (strlen(s->a_name) > 18)
            s->a_name[18] = '\0';
        for (int i = 0; i < 90; i++) printf("-");
        printf("\n");
        if ((s)->signal_un == 1)
        {

            printf("| %-5d | %-17s | %-16d | %-18s |", j + 1, (s)->name, (s)->page_count, s->a_name);
            for (int j = 0; j < 20; j++) printf(" ");
            printf("|\n");
        }
        if ((s)->signal_un == 2)
        {
            printf("| %-5d | %-17s | %-16d |", j + 1, (s)->name, (s)->page_count);
            for (int j = 0; j < 20; j++) printf(" ");
            printf("| %-18d |\n", (s)->volume_count);
        }
        j++;
        (s) = (s)->l;
    } while (s);
    for (int i = 0; i < 90; i++) printf("-");
}
Book* deleteALL(Book* h)
{
    int j = 0;
    int i = 2;
    printf("\nEnter the numbr of structure to delete: ");
    while (!scanf("%d", &j) || j < 1)
    {
        printf("ERROR!!!Enter the numbr of structur to delete: ");
        rewind(stdin);
    }
    Book* curr = h->l;

    Book* prev = h;
    if (j == 1)
    {
        free(h);
        return curr;
    }
    while (i != j && curr && j > 1)
    {
        prev = curr;
        curr = curr->l;
        i++;
    }

    if (!curr)
    {
        printf("ERROR!");
        return h;
    }

    if (j > 1) prev->l = curr->l;
    return h;
}
void search(struct Book* s)
{
    int g, b;
    int p = 0;
    char h[40] = { '1','\0' };
    int i = 0;
    if (!s)
    {
        puts("Error!");
        return;
    }
    printf("\nSelect the structure parameter to search:");
    printf("\n1--Name of book.\n2--Number of pages.\n3--Author's name.\n4--Number of volumes.\n");
    printf("Choice(1-4):");
    while (!scanf("%d", &g) || (g < 1 || g>4))
    {
        printf("Enter the number!!!Choice(1-4):\n");
        rewind(stdin);
    }
    switch (g)
    {
    case 1:

        printf("Name of book: ");
        rewind(stdin);
        gets_s(h);
        printf("\nRESULT OF SEARCH:\n");
        do
        {

            if (strcmp(h, s->name) == 0)
            {
                for (int i = 0; i < 90; i++) printf("-");
                if (s->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-18s |", i + 1, s->name, s->page_count, s->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (s->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, s->name, s->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", s->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (s) = (s)->l;
        } while (s);
        if (p == 0)
        {
            printf("No matches found!!!");
        }
        break;
    case 2:
        printf("Quantity of pages: ");

        while (!scanf("%d", &b))
        {
            printf("Enter the number!!!Quantity of pages:\n");
            rewind(stdin);

        }
        printf("\nRESULT:\n");
        do
        {
            if (b == s->page_count)
            {
                for (int i = 0; i < 90; i++) printf("-");
                if (s->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-18s |", i + 1, s->name, s->page_count, s->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (s->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, s->name, s->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", s->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (s) = (s)->l;
        } while (s);
        if (p == 0)
        {
            printf("No matches found!!!");
        }
        break;
    case 3:
        printf("Author's name: ");
        rewind(stdin);
        gets_s(h);
        printf("\nRESULT OF SEARCH:\n");
        while (s)
        {
            if (strcmp(h, s->a_name) == 0)
            {

                for (int i = 0; i < 90; i++) printf("-");
                if (s->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-18s |", i + 1, s->name, s->page_count, s->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (s->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, s->name, s->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", s->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (s) = (s)->l;
        }

        if (!p)
        {
            printf("No matches found!!!");
        }
        break;
    case 4:
        printf("Number of volumes: ");

        while (!scanf("%d", &b))
        {

            printf("Enter the number!!!Number of volumes:\n");
            rewind(stdin);
        }
        printf("\nRESULT:\n");
        while (s)
        {
            if (b == s->volume_count)
            {
                for (int i = 0; i < 90; i++) printf("-");
                if (s->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-20s |", i + 1, s->name, s->page_count, s->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (s->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, s->name, s->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", s->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (s) = (s)->l;
        }
        if (!p)
        {
            printf("No matches found!!!");
        }
        break;
    }

}
void save(struct Book* s)
{
    FILE* f = nullptr;
    int i = 0;
    if (!s)
    {
        puts("Error!");
        return;
    }
    printf("\nSelect the file type to write:\n1--Text file\n2--Binary file\nChoose:");
    while (!scanf_s("%d", &i) || i < 1 || i>2)
    {
        printf("ERROR!Choose: ");
        rewind(stdin);
    }
    switch (i)
    {
    case 1:
        if (!(f = fopen("boom.txt", "w")))
        {
            puts("File not open!");
            return;
        }
        while (s)
        {

            if (s->signal_un == 1)  fprintf(f, " %d %s %d %s", s->signal_un, s->name, s->page_count, s->a_name);
            if (s->signal_un == 2)  fprintf(f, " %d %s %d %d", s->signal_un, s->name, s->page_count, s->volume_count);
            (s) = (s)->l;
        }

        break;
    case 2:
        if (!(f = fopen("boob.bin", "wb")))
        {
            puts("File not open!");
            return;
        }
        while (s)
        {
            fwrite(&s->signal_un, 4, 1, f);
            fwrite(s->name, 20, 1, f);
            fwrite(&s->page_count, 4, 1, f);
            if (s->signal_un == 1)
            {
                fwrite(s->a_name, 20, 1, f);
            }
            if (s->signal_un == 2)
            {
                fwrite(&s->volume_count, 4, 1, f);
            }
            (s) = (s)->l;
        }
        break;
    }
    fclose(f);
}
Book* read(Book* h)
{
    FILE* f;
    Book* s1 = h;
    int i = 0;
    printf("\nSelect the file type to read:\n1--Text file\n2--Binary file\nChoose:");
    while (!scanf_s("%d", &i) || i < 1 || i>2)
    {
        printf("ERROR!Choose: ");
        rewind(stdin);
    }
    switch (i)
    {
    case 1:
        if (!(f = fopen("boom.txt", "r")))
        {
            puts("File not open!");
            return nullptr;
        }
        while (!feof(f))
        {
            if (!(h = (Book*)calloc(1, sizeof(Book))))
            {
                puts("No memory allocated!");
                return nullptr;
            }
            (h)->name = (char*)calloc(30, sizeof(char));
            fscanf(f, "%d", &h->signal_un);
            if (h->signal_un == 1)
            {
                fscanf(f, "%s", h->name);
                fscanf(f, "%d", &h->page_count);
                fscanf(f, "%s", &h->a_name);
            }
            if (h->signal_un == 2)
            {
                fscanf(f, "%s", h->name);
                fscanf(f, "%d", &h->page_count);
                fscanf(f, "%d", &h->volume_count);

            }
            (h)->l = s1;
            s1 = h;
        }
        fclose(f);
        break;
    case 2:
        if (!(f = fopen("boob.bin", "rb")))
        {
            puts("File not open!");
            return nullptr;
        }

        while (!feof(f))
        {
            if (!(h = (Book*)calloc(1, sizeof(Book))))
            {
                puts("No memory allocated!");
                return nullptr;
            }
            (h)->name = (char*)calloc(20, sizeof(char));
            fread(&h->signal_un, 4, 1, f);
            fread(h->name, 20, 1, f);
            fread(&h->page_count, 4, 1, f);
            if (feof(f))
            {
                continue;
            }
            if (h->signal_un == 1)
            {
                fread(h->a_name, 20, 1, f);
            }
            if (h->signal_un == 2)
            {
                fread(&h->volume_count, 4, 1, f);
            }
            (h)->l = s1;
            s1 = h;

        }
        fclose(f);
        break;
    }
    s1 = reverse(s1);
    show(s1);
    return s1;
}
Book* reverse(Book* s)
{
    if (!s)
    {
        puts("Error!");
        return nullptr;
    }
    Book* e = nullptr;
    Book* s1 = e;
    int i = 0;
    do
    {
        if (!(e = (Book*)calloc(1, sizeof(Book))))
        {
            puts("No memory allocated!");
            return nullptr;
        }
        (e)->name = (char*)calloc(20, sizeof(char));
        e->name = s->name;
        e->signal_un = s->signal_un;
        e->page_count = s->page_count;
        if (s->signal_un == 1)
        {
            for (i = 0; i < 20; i++) e->a_name[i] = s->a_name[i];
        }
        if (s->signal_un == 2)  e->volume_count = s->volume_count;
        (e)->l = s1;
        s1 = e;
        (s) = (s)->l;
    } while (s);
    return e;
}