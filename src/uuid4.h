#pragma once

#include <stdint.h>

#include "defines.h"

#define UUID4_LEN 37

// Генерирование UUID на основе даты и серийного номера. Результат - 16 байт
void Uuid4_Generate(CDate *date, uint8_t *serialNumber, uint8_t *uuidBin);

// Сконвертировать UUID в читаемый строковый вид типа xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx
void Uuid4_BinToString(const uint8_t *uuidBin, uint8_t *uuidString);
