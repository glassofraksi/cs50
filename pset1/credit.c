//by glassofraksi
//cs50 2020
//a crude implementation of Luhn's algorithm to check validity of credit cards

#include <stdio.h>
#include <cs50.h>

int main(void)
{

    long int num, dum, bit13, bit14, bit15, bit16; //individual bits
    int count = 0, nonDouble = 0, d0uble = 0, a = 0;


    do
    {
        num = get_long("Number: ");
    }
    while (num < 1);

    dum = num; //dummy variable so original number isnt altered


    while (dum > 0)
    {
        switch (count) //stores bits to check later for companies
        {
            case 12:
                bit13 = dum % 10;
                break;
            case 13:
                bit14 = dum % 10;
                break;
            case 14:
                bit15 = dum % 10;
                break;
            case 15:
                bit16 = dum % 10;
                break;
        }

        if (count % 2 == 0) //last digit and every other bit, not multiplied by 2
        {
            nonDouble += dum % 10;

        }
        else //for second to last bit and every other bit, multiplied by 2
        {
            a = (dum % 10) * 2;

            if (a < 10)
            {
                d0uble += a ;
            }
            else
            {
                d0uble += (a % 10);
                d0uble += (a / 10);
            }
        }

        dum = dum / 10;
        count++;
    }

    a = d0uble + nonDouble; //checksum

    if (a % 10 != 0 || count < 13 || count == 14 || count > 16)
    {
        printf("INVALID\n");

    }
    else if (bit15 == 3 && (bit14 == 4 || bit14 == 7))
    {
        printf("AMEX\n");
    }
    else if (bit16 == 4 || bit13 == 4)
    {
        printf("VISA\n");
    }
    else if (bit16 == 5 && (bit15 == 1 || bit15 == 2 || bit15 == 3 || bit15 == 4 || bit15 == 5))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}