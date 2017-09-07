#pragma once

#include <stdint.h>

#include "defines.h"

#define UUID4_LEN 37

void Uuid4_Generate(CDate *date, uint8_t *serialNumber, uint8_t *uuidBin);
void Uuid4_BinToString(uint8_t *uuidBin, uint8_t *uuidString);
