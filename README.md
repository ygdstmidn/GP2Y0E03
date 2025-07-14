# GP2Y0E03
STM32CubeHAL, C++,I2C

## memo
測距値=(Distance[11:4]*16+Distance[3:0])/16/2^n 
n : Shift Bit
Shift Bitのデフォルト 0x02 →0x02=最大表示距離64cm 
測定値を64で割ればOK?