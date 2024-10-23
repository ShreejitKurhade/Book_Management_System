#include <stdio.h>
#include <stdlib.h>
#include "declaration.h"
#include "defination.c"


int main()
{
    int choice;

    while (1)
    {
        printf("\n\t\t\t Book Management System \n");
        printf("\t\t ====================================== \n");

        printf("\t\t1. Add Book \t\t\t  2. Remove Book\n");
        
        printf("\t\t3. Search Book \t\t\t  4. Show Author's Books\n");
        
        printf("\t\t5. Show Category's Books \t  6. Update Book Data\n");
       
        printf("\t\t7. Display Sorted Books \t  8. Display All Books\n");
        
        printf("\t\t9. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            showAuthorBooks();
            break;
        case 5:
            showCategoryBooks();
            break;
        case 6:
            updateBookData();
            break;
        case 7:
            displaySortedBooks();
            break;
        case 8:
            displayAllBooks();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

