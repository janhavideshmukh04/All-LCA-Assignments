#include <stdio.h>
#include <string.h>

int main()
{
    int choice;
    char str1[100], str2[100];

    do
    {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. String Length\n");
        printf("2. String Copy\n");
        printf("3. String Concatenation\n");
        printf("4. String Comparison\n");
        printf("5. String Reverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter a string: ");
                scanf("%s", str1);
                strcpy(str2, str1);
                printf("Copied String = %s\n", str2);
                break
