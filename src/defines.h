#pragma once

typedef struct
{
    unsigned char day;      /* 1-31 */
    unsigned char month;    /* 1-12 */
    unsigned short year;    /* 1980-2078 */
} date_r;

typedef struct
{
    unsigned char hour;     /* 0-23 */
    unsigned char minute;   /* 0-59 */
    unsigned char second;   /* 0-59 */
} time_r;

typedef struct
{
    date_r dosdate;
    time_r dostime;
} CDate;