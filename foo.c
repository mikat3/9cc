// cc  -static -Wl,--omagic -o foo foo.c

char main[] = "\x48\xc7\xc0\x2a\x00\x00\x00\xc3";
// char main[] = "\0xf0\0x0f\0xc7\0xc8";    // F00F bug code

