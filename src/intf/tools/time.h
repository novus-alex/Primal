#pragma once

#include <stdint.h>

typedef struct
{
    uint32_t hour;
    uint32_t second;
    uint32_t minute;

} Time;

Time getTime();