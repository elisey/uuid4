#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "uuid4.h"

int main(void)
{
    uint8_t uuidValue[16];
    CDate date;
    date.dostime.second = 23;
    date.dostime.minute = 24;
    date.dostime.hour = 12;

    date.dosdate.day = 25;
    date.dosdate.month = 1;
    date.dosdate.year = 2017;

    uint8_t serialNumber[11] = "0128000001";

    for (int i = 0; i < 10; ++i)
    {
        Uuid4_Generate(&date, serialNumber, uuidValue);
        for (int j = 0; j < 16; ++j)
        {
            printf("%02X ", uuidValue[j]);
        }
        printf("\n");
        uint8_t buf[UUID4_LEN];
        Uuid4_BinToString(uuidValue, buf);
        printf("%s\n", buf);

        date.dostime.second++;
    }    

    return EXIT_SUCCESS;
}
