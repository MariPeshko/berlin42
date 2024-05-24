#include <stdio.h>

// int main(void)
// {
//     FILE *fp;                      // Variable to represent open file

//     fp = fopen("hello.txt", "r");  // Open file for reading

//    // int c = fgetc(fp);             // Read a single character
//    // printf("%c\n", c);             // Print char to stdout

//    int  c;
//    while ((c = fgetc(fp)) != EOF)
//         printf("%c", c);

//     fclose(fp);                    // Close the file when done
// }

int main (void)
{
    FILE *fp;
    char s[1024];  // Big enough for any line this program will encounter
    int linecount = 0;

    fp = fopen("hello.txt", "r");

    while (fgets(s, sizeof s, fp) != NULL) 
        printf("%d: %s", ++linecount, s);

    fclose(fp);
}