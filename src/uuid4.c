#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "uuid4.h"

#define UUID_NUM_OF_BYTES   16

static uint64_t xorshift128plus(uint8_t *seedBuffer)
{
    uint64_t *s = (uint64_t *)seedBuffer;
    /* http://xorshift.di.unimi.it/xorshift128plus.c */
    uint64_t s1 = s[0];
    const uint64_t s0 = s[1];
    s[0] = s0;
    s1 ^= s1 << 23;
    s[1] = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
    return s[1] + s0;
}

static void generateSeed(CDate *date, uint8_t *serialNumber, uint8_t *seedBuffer)
{
    for (int i = 0; i < 10; ++i)
    {
        seedBuffer[i] = serialNumber[i];
    }

    seedBuffer[10] = date->dostime.second;
    seedBuffer[11] = date->dostime.minute;
    seedBuffer[12] = date->dostime.hour;

    seedBuffer[13] = date->dosdate.day;
    seedBuffer[14] = date->dosdate.month;
    seedBuffer[15] = date->dosdate.year - 2000;
}

void Uuid4_Generate(CDate *date, uint8_t *serialNumber, uint8_t *uuidBin)
{
    assert(uuidBin != NULL);
    union { unsigned char b[UUID_NUM_OF_BYTES]; uint64_t word[2]; } s;

    uint8_t seed[UUID_NUM_OF_BYTES];
    generateSeed(date, serialNumber, seed);

    s.word[0] = xorshift128plus(seed);
    s.word[1] = xorshift128plus(seed);

    memcpy(uuidBin, s.b, sizeof(s));
}

void Uuid4_BinToString(const uint8_t *uuidBin, uint8_t *uuidString)
{
    assert(uuidBin != NULL);
    assert(uuidString != NULL);

    static const char *template = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";
    static const char *chars = "0123456789abcdef";

    const char *p;
    p = template;
    int i = 0;
    
    while (*p)
    {
        int n;
        n = uuidBin[i >> 1];
        n = (i & 1) ? (n >> 4) : (n & 0xf);
        switch (*p)
        {
        case 'x'  : *uuidString = chars[n];              i++;  break;
        case 'y'  : *uuidString = chars[(n & 0x3) + 8];  i++;  break;
        default   : *uuidString = *p;
        }
        uuidString++, p++;
    }
    *uuidString = '\0';
}
