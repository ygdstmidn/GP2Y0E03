/// @copyright Copyright © 2025 ygdstmidn
/// @license This file is released under the MIT License(https://opensource.org/license/mit)

#include "GP2Y0E03.h"

namespace GP2Y0E03
{
    GP2Y0E03::GP2Y0E03(I2C_HandleTypeDef *hi2c, uint8_t address)
    {
        _hi2c = hi2c;
        _address = address;
    }

    GP2Y0E03::~GP2Y0E03()
    {
    }

    double GP2Y0E03::read(void)
    {
        readstring(LOCATION_Distance, 2);
        double distance = (_rxArray[0] << 4 | _rxArray[1]) / 16.0;
        for (int i = 0; i < _ShiftBit; i++)
        {
            distance /= 2;
        }
        return distance;
    }

    void GP2Y0E03::readchar(uint8_t location)
    {
        HAL_I2C_Mem_Read(_hi2c, _address, location, 1, &_rx, 1, HAL_MAX_DELAY);
    }

    void GP2Y0E03::readstring(uint8_t location, uint16_t size)
    {
        HAL_I2C_Mem_Read(_hi2c, _address, location, 1, _rxArray, size, HAL_MAX_DELAY);
    }

    void GP2Y0E03::writechar(uint8_t location, uint8_t value)
    {
        HAL_I2C_Mem_Write(_hi2c, _address, location, 1, &value, 1, HAL_MAX_DELAY);
    }

    void GP2Y0E03::writestring(uint8_t location, uint8_t *values, uint8_t size)
    {
        HAL_I2C_Mem_Write(_hi2c, _address, location, 1, values, size, HAL_MAX_DELAY);
    }
} // namespace GP2Y0E03