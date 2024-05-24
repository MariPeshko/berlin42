// geekforgeek

// C implementation to see how perror() function is used to 
// print the error messages. 
#include <errno.h> 
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    FILE* fp; 
  
    // If a file is opened which does not exist, 
    // then it will be an error and corresponding 
    // errno value will be set 
    fp = fopen(" GeeksForGeeks.txt ", "r"); 
  
    // opening a file which does 
    // not exist. 
    printf("Value of errno: %d\n ", errno); 
    perror("Message from perror"); 
  
    return 0; 
}