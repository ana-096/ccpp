#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t sum(size_t array[], size_t size)
{
    size_t sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

size_t digit_sum(size_t n)
{
    size_t sum = 0;

    sum += n % 10;
    n /= 10;
    sum += n % 10;

    return sum;
}

int main(int argc, char **argv)
{
    long number;
    size_t dgt_a[8];
    size_t i = 0;
    size_t dgt_b[8];
    size_t j = 0;
    size_t first_two;
    size_t checksum = 0;
    size_t length;
    char out[14] = "INVALID\n";

    number = get_long("Number:");

    if (number < 1000000000000 || number >= 10000000000000000)
    {
        printf("%s", out);
        return 0;
    }

    while (number > 0)
    {
        dgt_a[i++] = number % 10;
        number /= 10;
        if (number == 0)
            break;
        dgt_b[j++] = number % 10;
        number /= 10;
    }

    if (j < i)
    {
        first_two = dgt_a[i - 1] * 10 + dgt_b[j - 1];
    }
    else
    {
        first_two = dgt_b[j - 1] * 10 + dgt_a[i - 1];
    }

    for (size_t k = 0; k < j; k++)
    {
        checksum += digit_sum(dgt_b[k] * 2);
    }

    checksum += sum(dgt_a, i);

    if (checksum % 10 == 0)
    {
        length = i + j;
        if (first_two / 10 == 4 && (length == 13 || length == 16))
            strncpy(out, "VISA\n", 13);
        else
        {
            switch (first_two)
            {
                case 34:
                case 37:
                    if (length == 15)
                        strncpy(out, "AMEX\n", 13);
                    break;
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    if (length == 16)
                        strncpy(out, "MASTERCARD\n", 13);
                    break;
                
                // no need for default as default out is invalid
            }
        }
    }

    printf("%s", out);

    return 0;
}
