#ifndef CASUALTY_HPP
#define CASUALTY_HPP

#include <array>

struct  Casualty
{

    typedef std::array< unsigned, 20 > row;

//               0   1   2   3   4   5   6   7    8    9   10   11   12   13   14   15   16   17   18   19        
    std::array< row, 18 > casualtyTable_ =
        {{
            row{ 0,  0,  0,  0,  0,  1,  1,  1,   1,   1,   1,   2,   2,   2,   2,   2,   2,   3,   3,   3 },
            row{ 0,  0,  0,  0,  1,  1,  1,  1,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   4,   4 },     
            row{ 0,  0,  1,  1,  1,  2,  2,  2,   3,   3,   3,   4,   4,   4,   5,   5,   5,   5,   6,   6 },
            row{ 0,  1,  2,  2,  2,  3,  3,  3,   4,   4,   4,   5,   5,   6,   6,   6,   7,   7,   8,   8 },
            row{ 1,  1,  2,  2,  3,  3,  4,  4,   5,   5,   6,   6,   7,   7,   8,   8,   9,   9,   10,  10 },
            row{ 1,  1,  2,  3,  3,  4,  4,  5,   6,   6,   7,   7,   8,   9,   9,   10,  10,  11,  12,  12 },
            row{ 1,  2,  2,  3,  4,  5,  6,  6,   7,   8,   9,   10,  10,  11,  12,  13,  14,  14,  15,  16 },
            row{ 1,  3,  4,  5,  6,  8,  9,  10,  11,  13,  14,  16,  17,  18,  19,  21,  22,  23,  24,  26 },
            row{ 2,  3,  5,  6,  8,  9,  11, 13,  14,  16,  18,  19,  21,  22,  24,  25,  27,  29,  30,  32 },
            row{ 2,  4,  6,  8,  10, 12, 14, 16,  18,  20,  22,  24,  26,  28,  30,  32,  34,  36,  38,  40 },
            row{ 3,  5,  8,  10, 13, 15, 18, 20,  23,  25,  28,  30,  33,  35,  38,  40,  43,  45,  48,  50 },
            row{ 3,  6,  9,  13, 16, 19, 22, 25,  28,  32,  35,  38,  41,  45,  48,  51,  54,  57,  60,  64 },
            row{ 4,  8,  12, 16, 20, 24, 28, 32,  36,  40,  44,  48,  52,  56,  60,  64,  68,  72,  76,  80 },
            row{ 5,  10, 15, 20, 25, 30, 35, 40,  45,  50,  55,  60,  65,  70,  75,  80,  85,  90,  95,  100 },
            row{ 6,  13, 19, 25, 32, 38, 44, 50,  57,  63,  69,  76,  82,  88,  95,  101, 108, 114, 120, 126 },
            row{ 8,  16, 24, 32, 40, 48, 56, 64,  72,  80,  88,  96,  104, 112, 120, 128, 136, 144, 152, 160 },
            row{ 10, 20, 30, 40, 50, 60, 70, 80,  90,  100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 },
            row{ 13, 25, 38, 50, 63, 76, 88, 101, 114, 126, 139, 151, 164, 176, 189, 207, 214, 227, 240, 252 }
        }}; 
};


#endif
