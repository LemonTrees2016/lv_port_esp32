/*******************************************************************************
 * Size: 15 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef COURIER
#define COURIER 1
#endif

#define COURIER 1
#if COURIER

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfd, 0x80,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x24, 0x48, 0x97, 0xf4, 0xc9, 0xbf, 0xa4, 0x48,
    0x91, 0x20,

    /* U+0024 "$" */
    0x10, 0x25, 0xfc, 0x38, 0xe, 0x7, 0x41, 0x83,
    0xf8, 0x40, 0x80,

    /* U+0025 "%" */
    0x62, 0x4a, 0x25, 0x12, 0x89, 0xb3, 0x64, 0x52,
    0x29, 0x14, 0x91, 0x80,

    /* U+0026 "&" */
    0x78, 0x91, 0x3, 0x6, 0x1f, 0xe7, 0x4c, 0x7e,

    /* U+0027 "'" */
    0xff, 0x20,

    /* U+0028 "(" */
    0x6b, 0x49, 0x24, 0xc9, 0x80,

    /* U+0029 ")" */
    0xc9, 0x92, 0x49, 0x6b, 0x0,

    /* U+002A "*" */
    0x25, 0x7e, 0xe5, 0x28,

    /* U+002B "+" */
    0x10, 0x41, 0x3f, 0x10, 0x40,

    /* U+002C "," */
    0x76, 0x6c,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x2, 0xc, 0x10, 0x60, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x0,

    /* U+0030 "0" */
    0x79, 0x28, 0x61, 0x86, 0x18, 0x52, 0x78,

    /* U+0031 "1" */
    0x33, 0xc9, 0x4, 0x10, 0x41, 0x4, 0xfc,

    /* U+0032 "2" */
    0x7a, 0x38, 0x41, 0xc, 0xc6, 0x31, 0xfc,

    /* U+0033 "3" */
    0x72, 0x20, 0x82, 0x38, 0x10, 0x61, 0xf8,

    /* U+0034 "4" */
    0x8, 0x30, 0xe1, 0x46, 0x99, 0x3f, 0x84, 0x3e,

    /* U+0035 "5" */
    0x7e, 0x81, 0x3, 0xe4, 0x60, 0x40, 0xa3, 0x7c,

    /* U+0036 "6" */
    0x1d, 0x8c, 0x3e, 0xcf, 0x1c, 0x53, 0x38,

    /* U+0037 "7" */
    0xff, 0x18, 0x30, 0x41, 0x83, 0x4, 0x18, 0x20,

    /* U+0038 "8" */
    0x7b, 0x38, 0x63, 0x7b, 0x38, 0x73, 0x78,

    /* U+0039 "9" */
    0x79, 0x1a, 0x14, 0x67, 0xc0, 0x83, 0xc, 0xf0,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0x33, 0x0, 0x76, 0x6c,

    /* U+003C "<" */
    0x8, 0x63, 0x18, 0xc1, 0x83, 0x6, 0x8,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x41, 0x83, 0x6, 0xc, 0x63, 0x18, 0x40,

    /* U+003F "?" */
    0xfa, 0x10, 0x43, 0x38, 0x80, 0x8, 0x20,

    /* U+0040 "@" */
    0x3e, 0x30, 0xb7, 0xb2, 0xda, 0x4d, 0x6e, 0x7c,
    0x82, 0x3e, 0x0,

    /* U+0041 "A" */
    0x38, 0x4, 0x7, 0x2, 0x83, 0x61, 0xf0, 0x88,
    0xc6, 0xf7, 0x80,

    /* U+0042 "B" */
    0xfc, 0x42, 0x42, 0x42, 0x7e, 0x41, 0x41, 0x41,
    0xfe,

    /* U+0043 "C" */
    0x3e, 0x8e, 0xc, 0x18, 0x10, 0x20, 0x23, 0x3c,

    /* U+0044 "D" */
    0xfc, 0x42, 0x41, 0x41, 0x41, 0x41, 0x41, 0x42,
    0xfc,

    /* U+0045 "E" */
    0xfe, 0x85, 0xa, 0x57, 0x89, 0x10, 0xa1, 0xfe,

    /* U+0046 "F" */
    0xfe, 0x85, 0xa, 0x57, 0x89, 0x10, 0x20, 0xf0,

    /* U+0047 "G" */
    0x3f, 0x63, 0xc1, 0x81, 0x80, 0x8f, 0xc1, 0x61,
    0x3f,

    /* U+0048 "H" */
    0xff, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42,
    0xff,

    /* U+0049 "I" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0xfe,

    /* U+004A "J" */
    0x3f, 0x4, 0x4, 0x4, 0x84, 0x84, 0x84, 0x84,
    0x78,

    /* U+004B "K" */
    0xf7, 0xa3, 0x13, 0xf, 0x7, 0x83, 0x61, 0x10,
    0x8c, 0xf3, 0x80,

    /* U+004C "L" */
    0xf8, 0x20, 0x20, 0x20, 0x20, 0x21, 0x21, 0x21,
    0xff,

    /* U+004D "M" */
    0xe3, 0xb1, 0x9d, 0xca, 0xa5, 0x52, 0xe9, 0x24,
    0x82, 0xf7, 0x80,

    /* U+004E "N" */
    0xe7, 0xb0, 0x9c, 0x4b, 0x24, 0x92, 0x69, 0x1c,
    0x86, 0xf1, 0x0,

    /* U+004F "O" */
    0x3c, 0x42, 0x83, 0x81, 0x81, 0x81, 0x83, 0x42,
    0x3c,

    /* U+0050 "P" */
    0xfc, 0x8d, 0xa, 0x14, 0x6f, 0x90, 0x20, 0xf8,

    /* U+0051 "Q" */
    0x3c, 0x42, 0x83, 0x81, 0x81, 0x81, 0x83, 0x42,
    0x7c, 0x78, 0x4e,

    /* U+0052 "R" */
    0xfc, 0x42, 0x42, 0x42, 0x7c, 0x4c, 0x44, 0x46,
    0xf3,

    /* U+0053 "S" */
    0x3f, 0x8e, 0xe, 0x7, 0xc1, 0xe0, 0xe3, 0xfc,

    /* U+0054 "T" */
    0xff, 0x91, 0x91, 0x91, 0x10, 0x10, 0x10, 0x10,
    0x7c,

    /* U+0055 "U" */
    0xf7, 0xa0, 0x90, 0x48, 0x24, 0x12, 0x9, 0x4,
    0xc6, 0x3c, 0x0,

    /* U+0056 "V" */
    0xf7, 0xb1, 0x88, 0xc4, 0x43, 0x60, 0xa0, 0x50,
    0x38, 0x8, 0x0,

    /* U+0057 "W" */
    0xf7, 0xb0, 0x9a, 0xcd, 0x67, 0x73, 0xb8, 0xd8,
    0x6c, 0x36, 0x0,

    /* U+0058 "X" */
    0xf7, 0x99, 0xd, 0x83, 0x81, 0xc0, 0xe0, 0xd8,
    0xc6, 0xf7, 0x80,

    /* U+0059 "Y" */
    0xf7, 0x62, 0x36, 0x14, 0x1c, 0x8, 0x8, 0x8,
    0x3e,

    /* U+005A "Z" */
    0xff, 0xa, 0x30, 0xc3, 0x4, 0x58, 0xe1, 0xfe,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x93, 0x80,

    /* U+005C "\\" */
    0x1, 0x81, 0x3, 0x2, 0x6, 0x4, 0xc, 0x8,
    0x18, 0x10, 0x30, 0x60,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x27, 0x80,

    /* U+005E "^" */
    0x23, 0x95, 0xb0,

    /* U+005F "_" */
    0xff, 0xc0,

    /* U+0060 "`" */
    0xc3, 0x6,

    /* U+0061 "a" */
    0x7c, 0xcc, 0x4, 0x7e, 0x86, 0x8e, 0x7f,

    /* U+0062 "b" */
    0xc0, 0x40, 0x40, 0x7c, 0x62, 0x41, 0x41, 0x41,
    0x62, 0xfc,

    /* U+0063 "c" */
    0x3e, 0x8e, 0x1c, 0x8, 0x8, 0xcf, 0x0,

    /* U+0064 "d" */
    0xe, 0x1, 0x0, 0x87, 0xc4, 0x64, 0x12, 0x9,
    0x4, 0x46, 0x1f, 0xc0,

    /* U+0065 "e" */
    0x3c, 0x8f, 0xf, 0xfc, 0x8, 0xcf, 0x0,

    /* U+0066 "f" */
    0x1c, 0x82, 0x3f, 0x20, 0x82, 0x8, 0x23, 0xf0,

    /* U+0067 "g" */
    0x3f, 0xc6, 0x82, 0x82, 0xc6, 0x3e, 0x2, 0x42,
    0x7c,

    /* U+0068 "h" */
    0xc0, 0x20, 0x10, 0xf, 0x86, 0x22, 0x11, 0x8,
    0x84, 0x42, 0x7b, 0xc0,

    /* U+0069 "i" */
    0x30, 0x60, 0x7, 0x81, 0x2, 0x4, 0x8, 0x11,
    0xfc,

    /* U+006A "j" */
    0x18, 0xc1, 0xf0, 0x84, 0x21, 0x8, 0x43, 0xe0,

    /* U+006B "k" */
    0xc0, 0x40, 0x40, 0x4f, 0x4c, 0x58, 0x78, 0x5c,
    0x4e, 0xcf,

    /* U+006C "l" */
    0x70, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x11,
    0xfc,

    /* U+006D "m" */
    0xfe, 0x24, 0x92, 0x49, 0x24, 0x92, 0x4b, 0xb6,

    /* U+006E "n" */
    0xfc, 0x31, 0x10, 0x88, 0x44, 0x22, 0x13, 0xde,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8e, 0x0,

    /* U+0070 "p" */
    0xfc, 0x62, 0x41, 0x41, 0x41, 0x62, 0x7c, 0x40,
    0xf8,

    /* U+0071 "q" */
    0x3f, 0x46, 0x82, 0x82, 0x82, 0x46, 0x3e, 0x2,
    0x1f,

    /* U+0072 "r" */
    0xee, 0x60, 0x81, 0x2, 0x4, 0x3f, 0x0,

    /* U+0073 "s" */
    0x7e, 0x1c, 0x1f, 0x86, 0x1f, 0x80,

    /* U+0074 "t" */
    0x40, 0x83, 0xf2, 0x4, 0x8, 0x10, 0x23, 0x3c,

    /* U+0075 "u" */
    0xc6, 0x21, 0x10, 0x88, 0x44, 0x22, 0x30, 0xfe,

    /* U+0076 "v" */
    0xf7, 0x91, 0x8d, 0x86, 0xc1, 0x40, 0xe0, 0x20,

    /* U+0077 "w" */
    0xe3, 0xa4, 0x97, 0x4f, 0xe3, 0x71, 0xb0, 0xd8,

    /* U+0078 "x" */
    0xef, 0x6c, 0x38, 0x18, 0x3c, 0x66, 0xef,

    /* U+0079 "y" */
    0xf7, 0x62, 0x36, 0x14, 0x14, 0x8, 0x8, 0x18,
    0xf0,

    /* U+007A "z" */
    0xfe, 0x29, 0x8c, 0x65, 0x1f, 0xc0,

    /* U+007B "{" */
    0x34, 0x42, 0x2c, 0x44, 0x44, 0x30,

    /* U+007C "|" */
    0xff, 0xf0,

    /* U+007D "}" */
    0xc2, 0x24, 0x43, 0x44, 0x22, 0xc0,

    /* U+007E "~" */
    0x73, 0x38,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xdf, 0x80,

    /* U+00A2 "¢" */
    0x10, 0x21, 0xf6, 0x28, 0x50, 0x31, 0x3e, 0x10,
    0x20,

    /* U+00A3 "£" */
    0x3c, 0x46, 0x40, 0x40, 0xfc, 0x60, 0x60, 0x60,
    0xfe,

    /* U+00A4 "¤" */
    0x83, 0xfd, 0x12, 0x24, 0x5f, 0xe0, 0x80,

    /* U+00A5 "¥" */
    0xf7, 0xb1, 0xd, 0x83, 0x80, 0x83, 0xf0, 0x20,
    0x10, 0x3e, 0x0,

    /* U+00A6 "¦" */
    0x0,

    /* U+00A7 "§" */
    0xfb, 0x2e, 0x2c, 0xdd, 0xb3, 0xa2, 0xf8,

    /* U+00A8 "¨" */
    0x99,

    /* U+00A9 "©" */
    0x3c, 0x42, 0x9d, 0xa5, 0xa1, 0x99, 0x42, 0x3c,

    /* U+00AA "ª" */
    0x60, 0xbc, 0xf0, 0x7c,

    /* U+00AB "«" */
    0x9, 0x1b, 0x66, 0xdc, 0x76, 0x1b, 0x8,

    /* U+00AC "¬" */
    0xfe, 0x4, 0x8, 0x10,

    /* U+00AD "­" */
    0x0,

    /* U+00AE "®" */
    0x3c, 0x42, 0xbd, 0x9d, 0x99, 0xb5, 0x42, 0x3c,

    /* U+00AF "¯" */
    0x0,

    /* U+00B0 "°" */
    0x0,

    /* U+00B1 "±" */
    0x10, 0x41, 0x3f, 0x10, 0x40, 0x3f,

    /* U+00B2 "²" */
    0x0,

    /* U+00B3 "³" */
    0x0,

    /* U+00B4 "´" */
    0x3b, 0xb0,

    /* U+00B5 "µ" */
    0xce, 0x42, 0x42, 0x42, 0x42, 0x66, 0x7f, 0x40,
    0x40,

    /* U+00B6 "¶" */
    0x7f, 0xeb, 0xd7, 0xa7, 0x42, 0x85, 0xa, 0x14,
    0x7c,

    /* U+00B7 "·" */
    0x0,

    /* U+00B8 "¸" */
    0x47, 0x80,

    /* U+00B9 "¹" */
    0x0,

    /* U+00BA "º" */
    0x32, 0xd2, 0xe0, 0x7c,

    /* U+00BB "»" */
    0x90, 0xd8, 0x66, 0x3b, 0x6e, 0xd8, 0x10,

    /* U+00BC "¼" */
    0x0,

    /* U+00BD "½" */
    0x0,

    /* U+00BE "¾" */
    0x0,

    /* U+00BF "¿" */
    0x10, 0x40, 0x4, 0x73, 0x8, 0x21, 0x7c,

    /* U+00C0 "À" */
    0x18, 0x6, 0x1, 0x87, 0x0, 0x80, 0xe0, 0x50,
    0x6c, 0x3e, 0x11, 0x18, 0xde, 0xf0,

    /* U+00C1 "Á" */
    0xc, 0xc, 0xc, 0x7, 0x0, 0x80, 0xe0, 0x50,
    0x6c, 0x3e, 0x11, 0x18, 0xde, 0xf0,

    /* U+00C2 "Â" */
    0x1c, 0x1b, 0x0, 0x7, 0x0, 0x80, 0xe0, 0x50,
    0x6c, 0x3e, 0x11, 0x18, 0xde, 0xf0,

    /* U+00C3 "Ã" */
    0x3b, 0x33, 0x0, 0x7, 0x0, 0x80, 0xe0, 0x50,
    0x6c, 0x3e, 0x11, 0x18, 0xde, 0xf0,

    /* U+00C4 "Ä" */
    0x14, 0xa, 0x0, 0x7, 0x0, 0xc0, 0xe0, 0x50,
    0x6c, 0x3e, 0x11, 0x18, 0xde, 0xf0,

    /* U+00C5 "Å" */
    0x8, 0xa, 0x2, 0x7, 0x0, 0x80, 0xe0, 0x50,
    0x6c, 0x3e, 0x11, 0x18, 0xde, 0xf0,

    /* U+00C6 "Æ" */
    0x3f, 0x8c, 0x4e, 0x27, 0x52, 0xe3, 0xd1, 0x22,
    0x91, 0xef, 0x80,

    /* U+00C7 "Ç" */
    0x3f, 0x43, 0x83, 0x80, 0x80, 0x80, 0xc0, 0x43,
    0x3e, 0x18, 0x8, 0x38,

    /* U+00C8 "È" */
    0x30, 0x30, 0x17, 0xf4, 0x28, 0x52, 0xbc, 0x48,
    0x85, 0xf, 0xf0,

    /* U+00C9 "É" */
    0x18, 0x61, 0x7, 0xf4, 0x28, 0x52, 0xbc, 0x48,
    0x85, 0xf, 0xf0,

    /* U+00CA "Ê" */
    0x38, 0xd8, 0x7, 0xf4, 0x28, 0x52, 0xbc, 0x48,
    0x85, 0xf, 0xf0,

    /* U+00CB "Ë" */
    0x28, 0x50, 0x7, 0xf4, 0x28, 0x52, 0xbc, 0x48,
    0x85, 0xf, 0xf0,

    /* U+00CC "Ì" */
    0x30, 0x30, 0x37, 0xf1, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x47, 0xf0,

    /* U+00CD "Í" */
    0x18, 0x61, 0x87, 0xf1, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x47, 0xf0,

    /* U+00CE "Î" */
    0x38, 0xd8, 0x7, 0xf1, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x47, 0xf0,

    /* U+00CF "Ï" */
    0x48, 0x90, 0x7, 0xf1, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x47, 0xf0,

    /* U+00D0 "Ð" */
    0x0,

    /* U+00D1 "Ñ" */
    0x39, 0x27, 0x0, 0x1c, 0xf6, 0x13, 0x89, 0x64,
    0x92, 0x4d, 0x23, 0x90, 0xde, 0x20,

    /* U+00D2 "Ò" */
    0x38, 0xc, 0x6, 0x3c, 0x42, 0x83, 0x81, 0x81,
    0x81, 0x83, 0x42, 0x3c,

    /* U+00D3 "Ó" */
    0x1c, 0x30, 0x60, 0x3c, 0x42, 0x83, 0x81, 0x81,
    0x81, 0x83, 0x42, 0x3c,

    /* U+00D4 "Ô" */
    0x38, 0x66, 0x0, 0x3c, 0x42, 0x83, 0x81, 0x81,
    0x81, 0x83, 0x42, 0x3c,

    /* U+00D5 "Õ" */
    0x72, 0x4e, 0x0, 0x3c, 0x42, 0x83, 0x81, 0x81,
    0x81, 0x83, 0x42, 0x3c,

    /* U+00D6 "Ö" */
    0x24, 0x24, 0x0, 0x3c, 0x42, 0x83, 0x81, 0x81,
    0x81, 0x83, 0x42, 0x3c,

    /* U+00D7 "×" */
    0x0,

    /* U+00D8 "Ø" */
    0x3d, 0x42, 0x87, 0x8d, 0x99, 0xb9, 0xf1, 0x62,
    0xfc,

    /* U+00D9 "Ù" */
    0x38, 0x6, 0x0, 0x9e, 0xf4, 0x12, 0x9, 0x4,
    0x82, 0x41, 0x20, 0x98, 0xc7, 0x80,

    /* U+00DA "Ú" */
    0xe, 0xc, 0x8, 0x1e, 0xf4, 0x12, 0x9, 0x4,
    0x82, 0x41, 0x20, 0x98, 0xc7, 0x80,

    /* U+00DB "Û" */
    0x1c, 0x1b, 0x0, 0x1e, 0xf4, 0x12, 0x9, 0x4,
    0x82, 0x41, 0x20, 0x98, 0xc7, 0x80,

    /* U+00DC "Ü" */
    0x14, 0xa, 0x0, 0x1e, 0xf4, 0x12, 0x9, 0x4,
    0x82, 0x41, 0x20, 0x98, 0xc7, 0x80,

    /* U+00DD "Ý" */
    0xc, 0x18, 0x30, 0xf7, 0x62, 0x36, 0x14, 0x1c,
    0x8, 0x8, 0x8, 0x3e,

    /* U+00DE "Þ" */
    0x0,

    /* U+00DF "ß" */
    0x3e, 0x46, 0x4e, 0xdc, 0x58, 0x5e, 0x47, 0x41,
    0x41, 0xfe,

    /* U+00E0 "à" */
    0x30, 0x18, 0x4, 0x7c, 0xcc, 0x4, 0x7e, 0x86,
    0x8e, 0x7f,

    /* U+00E1 "á" */
    0x1c, 0x30, 0x60, 0x7c, 0xcc, 0x4, 0x7e, 0x86,
    0x8e, 0x7f,

    /* U+00E2 "â" */
    0x10, 0x3c, 0x66, 0x0, 0x7c, 0xcc, 0x4, 0x7e,
    0x86, 0x8e, 0x7f,

    /* U+00E3 "ã" */
    0x72, 0x5c, 0x0, 0x7c, 0xcc, 0x4, 0x7e, 0x86,
    0x8e, 0x7f,

    /* U+00E4 "ä" */
    0x24, 0x24, 0x0, 0x7c, 0xcc, 0x4, 0x7e, 0x86,
    0x8e, 0x7f,

    /* U+00E5 "å" */
    0x18, 0x2c, 0x18, 0x0, 0x7c, 0xcc, 0x4, 0x7e,
    0x86, 0x8e, 0x7f,

    /* U+00E6 "æ" */
    0xfe, 0x4c, 0x86, 0x4f, 0xf9, 0x84, 0xc1, 0xbe,

    /* U+00E7 "ç" */
    0x3e, 0x8e, 0xc, 0x8, 0x8, 0xcf, 0x8, 0x8,
    0x70,

    /* U+00E8 "è" */
    0x30, 0x10, 0x1, 0xe4, 0x78, 0x7f, 0xe0, 0x46,
    0x78,

    /* U+00E9 "é" */
    0x18, 0x40, 0x1, 0xe4, 0x78, 0x7f, 0xe0, 0x46,
    0x78,

    /* U+00EA "ê" */
    0x10, 0x71, 0x30, 0x3, 0xc8, 0xf0, 0xff, 0xc0,
    0x8c, 0xf0,

    /* U+00EB "ë" */
    0x24, 0x48, 0x1, 0xe6, 0x78, 0x7f, 0xe0, 0x62,
    0x78,

    /* U+00EC "ì" */
    0x70, 0x30, 0x37, 0x81, 0x2, 0x4, 0x8, 0x11,
    0xfc,

    /* U+00ED "í" */
    0x18, 0x61, 0x87, 0x81, 0x2, 0x4, 0x8, 0x11,
    0xfc,

    /* U+00EE "î" */
    0x10, 0x73, 0x18, 0xf, 0x2, 0x4, 0x8, 0x10,
    0x23, 0xf8,

    /* U+00EF "ï" */
    0x48, 0x90, 0x7, 0x81, 0x2, 0x4, 0x8, 0x11,
    0xfc,

    /* U+00F0 "ð" */
    0x0,

    /* U+00F1 "ñ" */
    0x32, 0x27, 0x0, 0x1f, 0x86, 0x22, 0x11, 0x8,
    0x84, 0x42, 0x7b, 0xc0,

    /* U+00F2 "ò" */
    0x30, 0x18, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x44,
    0x70,

    /* U+00F3 "ó" */
    0x18, 0x60, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x44,
    0x70,

    /* U+00F4 "ô" */
    0x10, 0x71, 0x10, 0x3, 0x88, 0xa0, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00F5 "õ" */
    0x77, 0xb8, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x44,
    0x70,

    /* U+00F6 "ö" */
    0x24, 0x48, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x44,
    0x70,

    /* U+00F7 "÷" */
    0xf0,

    /* U+00F8 "ø" */
    0x3e, 0x9e, 0x7d, 0xdf, 0x28, 0xbe, 0x0,

    /* U+00F9 "ù" */
    0x38, 0x6, 0x1, 0x98, 0xc4, 0x22, 0x11, 0x8,
    0x84, 0x46, 0x1f, 0xc0,

    /* U+00FA "ú" */
    0x1c, 0x18, 0x18, 0x18, 0xc4, 0x22, 0x11, 0x8,
    0x84, 0x46, 0x1f, 0xc0,

    /* U+00FB "û" */
    0x18, 0x1e, 0x19, 0x80, 0xc, 0x62, 0x11, 0x8,
    0x84, 0x42, 0x23, 0xf, 0xe0,

    /* U+00FC "ü" */
    0x24, 0x12, 0x0, 0x18, 0xc4, 0x22, 0x11, 0x8,
    0x84, 0x46, 0x1f, 0xc0,

    /* U+00FD "ý" */
    0xc, 0x10, 0x0, 0xf7, 0x62, 0x36, 0x14, 0x14,
    0x8, 0x8, 0x18, 0xf0,

    /* U+00FE "þ" */
    0x0,

    /* U+00FF "ÿ" */
    0x14, 0x14, 0x0, 0xf7, 0x32, 0x36, 0x14, 0x1c,
    0x8, 0x8, 0x8, 0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 144, .box_w = 1, .box_h = 9, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 144, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 6, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 16, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 27, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 144, .box_w = 3, .box_h = 4, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 49, .adv_w = 144, .box_w = 3, .box_h = 11, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 54, .adv_w = 144, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 144, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 63, .adv_w = 144, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 68, .adv_w = 144, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 70, .adv_w = 144, .box_w = 4, .box_h = 1, .ofs_x = 3, .ofs_y = 4},
    {.bitmap_index = 71, .adv_w = 144, .box_w = 2, .box_h = 2, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 83, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 144, .box_w = 2, .box_h = 6, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 144, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 163, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 144, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 173, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 286, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 356, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 144, .box_w = 3, .box_h = 11, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 448, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 460, .adv_w = 144, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 465, .adv_w = 144, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 468, .adv_w = 144, .box_w = 10, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 470, .adv_w = 144, .box_w = 5, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 472, .adv_w = 144, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 515, .adv_w = 144, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 523, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 532, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 144, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 561, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 144, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 144, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 612, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 621, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 144, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 144, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 144, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 658, .adv_w = 144, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 144, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 682, .adv_w = 144, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 144, .box_w = 4, .box_h = 11, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 694, .adv_w = 144, .box_w = 1, .box_h = 12, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 696, .adv_w = 144, .box_w = 4, .box_h = 11, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 702, .adv_w = 144, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 704, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 705, .adv_w = 144, .box_w = 1, .box_h = 9, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 707, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 732, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 144, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 752, .adv_w = 144, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 144, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 764, .adv_w = 144, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 771, .adv_w = 144, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 776, .adv_w = 144, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 785, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 144, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 793, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 794, .adv_w = 144, .box_w = 5, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 796, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 805, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 814, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 144, .box_w = 3, .box_h = 3, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 817, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 818, .adv_w = 144, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 822, .adv_w = 144, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 829, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 830, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 832, .adv_w = 144, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 839, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 853, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 867, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 895, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 909, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 946, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 968, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 979, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 990, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1001, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1012, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1023, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1035, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1049, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1061, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1073, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1085, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1097, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1109, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1110, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1133, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1147, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1161, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1175, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1187, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1188, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1198, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1208, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1218, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1229, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1239, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1249, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1260, .adv_w = 144, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1268, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1277, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1286, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1295, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1305, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1314, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1323, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1332, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1342, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1351, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1352, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1364, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1373, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1382, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1392, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1401, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1410, .adv_w = 144, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 1411, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1418, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1430, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1442, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1455, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1467, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1479, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1480, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 96, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_font_courier_15 = {
#else
lv_font_t lv_font_courier_15 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if COURIER*/

