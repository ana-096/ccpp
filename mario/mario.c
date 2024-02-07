#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    size_t height = 0;
    size_t width;

    char whitespace[] = "        ";
    char pounds[] = "########";
    char newline[] = "\n";
    char out[145];

    while (height < 1 || height > 8)
    {
        printf("What is your desired height (1-8):");
        scanf("%d", &height);
    }
    
    width = height * 2 + 2;
    
    for (size_t i = 0; i < height; i++)
    {
        strncat(out, whitespace, height - i - 1);
        strncat(out, pounds, i+1);
        strncat(out, whitespace, 2);
        strncat(out, pounds, i+1);
        strncat(out, newline, 1);
    }
    
    printf("%s", out);

    return 0;
}