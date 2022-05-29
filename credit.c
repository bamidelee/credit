#include <stdio.h>
#include <cs50.h>

bool checkvalidity(long ccn);
int len(long ccn);
int firsttwo(long ccn, int length);

int main(void)
{
    long n = get_long("card number: "); // collecting credit card number
    int length = len(n);
    int firsttwonum = firsttwo(n, length);
    int firstnum = firsttwonum / 10;


    // displaying credit card type
    if (checkvalidity(n) == false && length == 15 && (firsttwonum == 34 || firsttwonum == 37)) // checking for amex
    {
        printf("AMEX\n");
    }
    else if (checkvalidity(n) == false && length == 16 && firsttwonum > 50 && firsttwonum < 56) // checking for mastercard
    {
        printf("MASTERCARD\n");
    }
    else if (checkvalidity(n) == false && (length == 13 || length == 16) && firstnum == 4) // checking for visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checkvalidity(long ccn)  // checking credit card validity
{

    int sum = 0;
    for (int i = 0; ccn >= 1; ccn /= 10, i++)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int odd = (ccn % 10) * 2;
            sum += (odd / 10) + (odd % 10);
        }

    }
    return sum % 10;

}

int len(long ccn) // checking credit card length
{
    int l = 0;
    for (int i = 0; ccn != 0; ccn /= 10)
    {
        l++;
    }
    return l;
}

int firsttwo(long ccn, int length) // collecting first two digit of credit card
{
    int f = 0;
    for (int i = length; i != 0; ccn /= 10, i--)
    {
        if (i == 2)
        {
            f += ccn;
        }
    }
    return f;
}
