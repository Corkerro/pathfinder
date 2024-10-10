#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char buf[WCHAR_BUF_SIZE];

    int len;

    if (c <= 0x7F) {  // 127
        buf[0] = (char)c;
        len = 1;
    } else if (c <= 0x7FF) {  // 2047
        // 2-byte UTF-8 encoding
        buf[0] = (char)(0xC0 | (c >> 6));
        buf[1] = (char)(0x80 | (c & 0x3F));
        len = 2;
    } else if (c <= 0xFFFF) {  // 65535
        // 3-byte UTF-8 encoding
        buf[0] = (char)(0xE0 | (c >> 12));
        buf[1] = (char)(0x80 | ((c >> 6) & 0x3F));
        buf[2] = (char)(0x80 | (c & 0x3F));
        len = 3;
    } else if (c <= 0x10FFFF) {  // 1114111
        // 4-byte UTF-8 encoding
        buf[0] = (char)(0xF0 | (c >> 18));
        buf[1] = (char)(0x80 | ((c >> 12) & 0x3F));
        buf[2] = (char)(0x80 | ((c >> 6) & 0x3F));
        buf[3] = (char)(0x80 | (c & 0x3F));
        len = 4;
    } else
        return;

    // Write the UTF-8 encoded character to standard output
    write(STDOUT_FILENO, buf, len);
}
