#ifndef BOOK_H
#define BOOK_H

struct Book
{
    int id;
    char name[50];
    char author[50];
    char category[50];
    float price;
    float rating;
};


void addBook();
void removeBook();
void searchBook();
void showAuthorBooks();
void showCategoryBooks();
void updateBookData();
void displaySortedBooks();
void displayAllBooks();

#endif