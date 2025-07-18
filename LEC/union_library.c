#include <stdio.h>
#include <string.h>

// Group 2:
// 2802658250 - Hasbi Rajab Assadiqi
// 2802669746 - Yosua Maranatha Siahaan
// 2802663931 - Septia Dini Rahayu
// 2802658263 - Fikry Fahrezy Ramadhan
// 2802680225 - Ranidya Putri Hantari

union MediaType
{
    char book[5];     // "BOOK"
    char magazine[10]; // "MAGAZINE"
};

struct LibraryCollections
{
    char title[100];
    int year;
    char typeTag; // 'B' for Book, 'M' for Magazine
    union MediaType mediaType;
};

int main()
{
    struct LibraryCollections collections[100];
    int itemSize;
    char mediaChoice;

    printf("Welcome to the Binus Library System!\n");
    printf("How many items do you want to enter? ");
    scanf("%d", &itemSize);
    printf("\nOkay! You'll be asked to enter info for %d media items\n", itemSize);
    printf("For each item, choose its type (B for Book, M for Magazine)\n");

    for (int itemIdx = 0; itemIdx < itemSize; itemIdx++)
    {
        int number = itemIdx + 1;
        printf("\nInput Item %d \n", number);
        printf("Enter media type:");
        scanf(" %c", &mediaChoice);

        if (mediaChoice == 'B' || mediaChoice == 'b')
        {
            // Assinging "BOOK" to the book field in the union
            strcpy(collections[itemIdx].mediaType.book, "BOOK"); 
            // Set type tag for book
            collections[itemIdx].typeTag = 'B';                 
        }
        else if (mediaChoice == 'M' || mediaChoice == 'm')
        {
            // Assinging "MAGAZINE" to the magazine field in the union
            strcpy(collections[itemIdx].mediaType.magazine, "MAGAZINE");
             // Set type tag for magazine
            collections[itemIdx].typeTag = 'M';                         
        }
        else
        {
            printf("Invalid media type! Please input B for book or M for magazine\n");
            itemIdx--;
            continue; // Skip this iteration and ask for input again
        }

        printf("Enter title:");
        scanf(" %[^\n]", collections[itemIdx].title); //%[^\n] -> Read string from input with spaces character
        printf("Enter published year:");
        scanf("%d", &collections[itemIdx].year);
    }

    printf("\n\n=== Binus Library Collection ===\n");
    printf("\nTotal items: %d\n", itemSize);

    for (int resultIdx = 0; resultIdx < itemSize; resultIdx++)
    {   
        printf("\nItem %d:\n", resultIdx + 1);

        if (collections[resultIdx].typeTag == 'B'){
            //Print media type from union 
            printf("\nMedia Type: %s \n", collections[resultIdx].mediaType.book);
        } else {
            //Print media type from union
            printf("\nMedia Type: %s \n", collections[resultIdx].mediaType.magazine);
        }

        printf("Title: %s\n", collections[resultIdx].title);
        printf("Year: %d\n", collections[resultIdx].year);
    }

    printf("\nThank you for using Binus Library System!\n");

    return 0;
}
