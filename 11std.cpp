#include<stdio.h>
#include<conio.h> 
#include<string.h> 
#include<ctype.h> 
int is_palindrome(char str[]) 
{ 
     int start = 0; 
     int end = strlen(str) - 1; 
     while (start < end) 
     { 
     if (tolower(str[start]) != tolower(str[end])) 
     { 
         return 0; 
     } 
         start++; 
         end--; 
     } 
     return 1; 
} 
int main() 
{ 
     char str[100]; 
     printf("Enter a string: "); 
     fgets(str, sizeof(str), stdin); 
     // Remove newline character if present
     str[strcspn(str, "\n")] = 0; 
     if (is_palindrome(str)) 
     { 
     printf("'%s' is a palindrome.\n", str); 
     } 
     else 
     { 
         printf("'%s' is not a palindrome.\n", str); 
     }  
     getch(); 
} 

