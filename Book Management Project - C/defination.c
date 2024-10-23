#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaration.h"

#define MAX_BOOKS 100

struct Book books[MAX_BOOKS];
int num_books = 0;  

void addBook()
{
    if (num_books == MAX_BOOKS)
    {
        printf("Cannot add more books\n");
        return;
    }

    struct Book book;   

    printf("\n\t\tEnter Book ID: ");
    scanf("%d", &book.id);

    printf("\t\tEnter Book Name: ");
    scanf("%s", book.name);

    printf("\t\tEnter Author Name: ");
    scanf("%s", book.author);

    printf("\t\tEnter Category: ");
    scanf("%s", book.category);

    printf("\t\tEnter Price: ");
    scanf("%f", &book.price);

    printf("\t\tEnter Rating: ");
    scanf("%f", &book.rating);

    books[num_books++] = book;

    printf("\n ********* Book added successfully *********\n");
}

void removeBook()
{
    int id, i, j;

    printf("\n\t\tEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < num_books; i++)
    {
        if (books[i].id == id)
        {
            for (j = i; j < num_books - 1; j++)
            {
                books[j] = books[j + 1];
            }
            num_books--;
            printf("********* Book removed successfully *********\n");
            return;
        }
    }

    printf("==> Book not found\n");
}

void searchBook()
{
    int choice;
    printf("\n\t\t1. Search by ID\n");
    printf("\t\t2. Search by Name\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int id, i;
        printf("\n\t\tEnter Book ID: ");
        scanf("%d", &id);

        for (i = 0; i < num_books; i++)
        {
            if (books[i].id == id)
            {
                printf("\n\t\tBook ID: %d\n", books[i].id);
                printf("\t\tBook Name: %s\n", books[i].name);
                printf("\t\tAuthor Name: %s\n", books[i].author);
                printf("\t\tCategory: %s\n", books[i].category);
                printf("\t\tPrice: %.2f\n", books[i].price);
                printf("\t\tRating: %.2f\n", books[i].rating);
                return;
            }
        }

        printf("==> Book not found\n");
    }
    else if (choice == 2)
    {
        char name[50];
        int i, found = 0;
        printf("\n\t\tEnter Book Name: ");
        scanf("%s", name);

        for (i = 0; i < num_books; i++)
        {
            if (strcasecmp(books[i].name, name) == 0)
            {
                printf("\n\t\tBook ID: %d\n", books[i].id);
                printf("\t\tBook Name: %s\n", books[i].name);
                printf("\t\tAuthor Name: %s\n", books[i].author);
                printf("\t\tCategory: %s\n", books[i].category);
                printf("\t\tPrice: %.2f\n", books[i].price);
                printf("\t\tRating: %.2f\n", books[i].rating);
                found = 1;
            }
        }

        if (!found)
        {
            printf("==> Book not found\n");
        }
    }
    else
    {
        printf("Invalid choice\n");
    }
}

void showAuthorBooks()
{
    char author[50];
    int i, count = 0;

    printf("\n\tEnter Author Name: ");
    scanf("%s", author);

    for (i = 0; i < num_books; i++)
    {
        if (strcasecmp(books[i].author, author) == 0)
        {
            printf("\n\t\t\n\t\tBook ID: %d\n", books[i].id);
            printf("\t\tBook Name: %s\n", books[i].name);
            printf("\t\tAuthor Name: %s\n", books[i].author);
            printf("\t\tCategory: %s\n", books[i].category);
            printf("\t\tPrice: %.2f\n", books[i].price);
            printf("\t\tRating: %.2f\n", books[i].rating);
            count++;
        }
    }

    if (count == 0)
    {
        printf("==> No books found for author %s\n", author);
    }
}
 
void showCategoryBooks()
{
    char category[50];
    int i, count = 0;

    printf("\n\tEnter Category: ");
    scanf("%s", category);

    for (i = 0; i < num_books; i++)
    {
        if (strcasecmp(books[i].category, category) == 0)
        {
            printf("\n\t\tBook ID: %d\n", books[i].id);
            printf("\t\tBook Name: %s\n", books[i].name);
            printf("\t\tAuthor Name: %s\n", books[i].author);
            printf("\t\tCategory: %s\n", books[i].category);
            printf("\t\tPrice: %.2f\n", books[i].price);
            printf("\t\tRating: %.2f\n", books[i].rating);
            count++;
        }
    }

    if (count == 0)
    {
        printf("==> No books found for category %s\n", category);
    }
}

void updateBookData()
{
    int id, i;

    printf("\n\t\tEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < num_books; i++)
    {
        if (books[i].id == id)
        {
            printf("\n\t\tEnter new Price: ");
            scanf("%f", &books[i].price);

            printf("\t\tEnter new Rating: ");
            scanf("%f", &books[i].rating);

            printf("********* Book data updated successfully *********\n");
            return;
        }
    }

    printf("==> Book not found\n");
}
 
void displaySortedBooks()
{
    int i, j;
    struct Book temp;

    for (i = 0; i < num_books - 1; i++)
    {
        for (j = i + 1; j < num_books; j++)
        {
            if (books[i].price > books[j].price)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("\n\tTop 3 books based on price:\n");
    for (i = 0; i < 3 && i < num_books; i++)
    {
        printf("\n\t\t%d. %s by %s - RS.%.2f\n", i + 1, books[i].name, books[i].author, books[i].price);
    }

    for (i = 0; i < num_books - 1; i++)
    {
        for (j = i + 1; j < num_books; j++)
        {
            if (books[i].rating < books[j].rating)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("\n\tTop 3 books based on rating:\n");
    for (i = 0; i < 3 && i < num_books; i++)
    {
        printf("\n\t\t%d. %s by %s - %.2f stars\n", i + 1, books[i].name, books[i].author, books[i].rating);
    }
}
 
void displayAllBooks()
{
    int i;

    printf("\n\tAll books in the database:\n");
    for (i = 0; i < num_books; i++)
    {
        printf("\n\t\tBook ID: %d\n", books[i].id);
        printf("\t\tBook Name: %s\n", books[i].name);
        printf("\t\tAuthor Name: %s\n", books[i].author);
        printf("\t\tCategory: %s\n", books[i].category);
        printf("\t\tPrice: %.2f\n", books[i].price);
        printf("\t\tRating: %.2f\n", books[i].rating);
    }
}

