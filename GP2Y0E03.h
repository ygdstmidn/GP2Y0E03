/// @copyright Copyright © 2025 ygdstmidn
/// @license This file is released under the MIT License(https://opensource.org/license/mit)
#ifndef __INCLUDE_GP2Y0E03_H
#define __INCLUDE_GP2Y0E03_H

#include <main.h>

namespace GP2Y0E03
{
    /// 8bit
    constexpr uint8_t SLAVE_ADDRESS_LIST[16] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};

    constexpr uint8_t LOCATION_ShiftBit = 0x02;
    constexpr uint8_t LOCATION_Distance = 0x5E;
    constexpr uint8_t LOCATION_Distance2 = 0x5F;

    constexpr uint8_t DEFAULT_ShiftBit = 0x02;

    class GP2Y0E03
    {
    public:
        GP2Y0E03(I2C_HandleTypeDef *hi2c, uint8_t address);
        ~GP2Y0E03(void);
        double read(void);

    private:
        I2C_HandleTypeDef *_hi2c;
        uint8_t _address;
        uint8_t _ShiftBit = DEFAULT_ShiftBit;
        uint8_t _rx;
        uint8_t _rxArray[2]; // 最長:distanceのデータ

        void readchar(uint8_t location);
        void readstring(uint8_t location, uint16_t size);
        void writechar(uint8_t location, uint8_t value);
        void writestring(uint8_t location, uint8_t *values, uint8_t size);
    };
} // namespace GP2Y0E03

#endif // __INCLUDE_GP2Y0E03_H