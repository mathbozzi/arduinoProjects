//XBitmap Image used in example: "windowed.ino"
//Image description: "cartoon window"

//See https://github.com/todd-herbert/heltec-eink-modules/blob/main/docs/XBitmapTutorial/xbitmap-tutorial.md

//Source image by Arek Socha
//https://pixabay.com/users/qimono-1962238/

#define window_cartoon_width 139
#define window_cartoon_height 100
PROGMEM const static unsigned char window_cartoon_bits[] = {
   0xb5, 0xb6, 0xaa, 0x6d, 0x6b, 0x5b, 0x6b, 0xdb, 0xb6, 0xdd, 0xfd, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xf7, 0x05, 0xd6, 0x6a, 0xb7, 0xda, 0xde, 0xf6,
   0xda, 0xb6, 0xad, 0xb5, 0x57, 0xb5, 0x7f, 0x77, 0x57, 0x55, 0x5d, 0x07,
   0xad, 0xad, 0xd5, 0x56, 0x55, 0xab, 0xb7, 0x6a, 0x75, 0xdf, 0xfe, 0xff,
   0xfd, 0xfd, 0xfd, 0x7f, 0xb7, 0x05, 0x5a, 0xbb, 0xb6, 0xda, 0x76, 0x5d,
   0xd5, 0x5e, 0xd7, 0xf5, 0x76, 0xf7, 0xf7, 0xef, 0x6f, 0xeb, 0xb6, 0x05,
   0xb5, 0x6a, 0xed, 0x6d, 0xab, 0x6b, 0xbf, 0xf5, 0xba, 0xde, 0xdb, 0xdf,
   0xff, 0xbf, 0xdb, 0xfd, 0xef, 0x06, 0xab, 0xd6, 0x55, 0xdb, 0x6e, 0x5b,
   0xb5, 0xad, 0xeb, 0x7a, 0xff, 0xff, 0xdf, 0x7d, 0xc2, 0x5b, 0xdd, 0x05,
   0x76, 0xad, 0xae, 0xb5, 0xdb, 0xee, 0xda, 0xd6, 0xde, 0xd7, 0x7f, 0xff,
   0x7f, 0x85, 0xf4, 0xef, 0xbb, 0x03, 0xaa, 0xb5, 0x75, 0x7f, 0xbb, 0xbb,
   0xb7, 0xdd, 0xba, 0xfe, 0xed, 0xff, 0x55, 0x11, 0xa0, 0x7e, 0x6f, 0x07,
   0x55, 0x6d, 0xdf, 0xb5, 0xef, 0xde, 0xfd, 0xff, 0xef, 0xdb, 0xff, 0x05,
   0x02, 0x80, 0xec, 0xdb, 0xb5, 0x05, 0xb7, 0xd5, 0xb4, 0xb6, 0xda, 0x5a,
   0xab, 0xaa, 0x5a, 0xff, 0x2f, 0x55, 0x00, 0x12, 0xa0, 0xbf, 0xff, 0x05,
   0x6a, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0x10, 0x00,
   0x4a, 0x40, 0xec, 0xf6, 0x56, 0x07, 0x5d, 0x6b, 0x81, 0x00, 0x81, 0x40,
   0x00, 0x00, 0xa2, 0x28, 0x42, 0x08, 0x80, 0xae, 0xc8, 0xdf, 0xff, 0x05,
   0xd5, 0x5a, 0xbc, 0x6e, 0x36, 0x57, 0xbf, 0x7f, 0x5d, 0x82, 0x00, 0xa1,
   0x5e, 0x11, 0xe8, 0x7f, 0xad, 0x06, 0xb5, 0xf6, 0xdc, 0xda, 0x6d, 0xdd,
   0x6a, 0xd5, 0x7b, 0x00, 0x12, 0xaa, 0x40, 0x2a, 0xc8, 0xf6, 0xff, 0x07,
   0xab, 0x6d, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xd4, 0x52,
   0x95, 0x90, 0xe4, 0xff, 0x6d, 0x05, 0xb6, 0xea, 0x0c, 0x02, 0x80, 0x00,
   0x00, 0x00, 0xa0, 0xc8, 0x12, 0x12, 0x29, 0x25, 0xc8, 0xbf, 0xdf, 0x07,
   0x6d, 0x5b, 0x24, 0x48, 0x0a, 0x52, 0x2a, 0x49, 0x22, 0x26, 0x65, 0x41,
   0x42, 0x92, 0xe4, 0xf6, 0x7e, 0x05, 0xd5, 0xf6, 0x8c, 0x00, 0x20, 0x00,
   0x00, 0x00, 0x60, 0x04, 0x49, 0x12, 0x94, 0x24, 0xe8, 0xef, 0xed, 0x07,
   0x55, 0xad, 0x04, 0x24, 0x08, 0x21, 0x90, 0x44, 0x04, 0x51, 0x92, 0x48,
   0x49, 0x12, 0xe5, 0xff, 0xbf, 0x06, 0x5d, 0x6b, 0x94, 0x00, 0x01, 0x84,
   0x02, 0x88, 0x20, 0x42, 0x92, 0x12, 0x49, 0x2a, 0xc8, 0xff, 0xf6, 0x05,
   0xb5, 0xde, 0x04, 0x24, 0x10, 0x01, 0x10, 0x01, 0xa4, 0x82, 0x24, 0x41,
   0x12, 0x11, 0xe4, 0xef, 0xbf, 0x07, 0xd5, 0xb4, 0x2c, 0x00, 0x22, 0x24,
   0x20, 0x10, 0x20, 0x0a, 0x49, 0x12, 0x52, 0xaa, 0xe8, 0xff, 0xfe, 0x06,
   0xb5, 0x6d, 0x84, 0x48, 0x00, 0x80, 0x04, 0x42, 0x22, 0x42, 0x92, 0x48,
   0x84, 0x10, 0x6a, 0xff, 0xbb, 0x07, 0x57, 0xeb, 0x08, 0x01, 0x84, 0x08,
   0x40, 0x00, 0x60, 0x44, 0x92, 0x92, 0x94, 0x2a, 0xe0, 0xef, 0xff, 0x06,
   0xaa, 0xb6, 0x04, 0x48, 0x10, 0x42, 0x08, 0x92, 0x04, 0x82, 0x24, 0x41,
   0x52, 0x24, 0xea, 0xff, 0xfb, 0x05, 0x76, 0xb5, 0x4c, 0x00, 0x01, 0x00,
   0x01, 0x00, 0x60, 0x14, 0x49, 0x4a, 0x84, 0x54, 0xe8, 0xbf, 0xb7, 0x07,
   0xcd, 0x6e, 0x04, 0x09, 0x24, 0x12, 0x48, 0x22, 0x22, 0x41, 0x92, 0x10,
   0x29, 0x11, 0xea, 0xff, 0xff, 0x05, 0xba, 0xea, 0x14, 0x40, 0x40, 0x80,
   0x00, 0x40, 0x20, 0x86, 0x92, 0x42, 0x52, 0x2a, 0xe0, 0xff, 0xbf, 0x07,
   0xd5, 0x5e, 0x84, 0x08, 0x01, 0x12, 0x92, 0x04, 0x22, 0x22, 0x4a, 0x92,
   0xa4, 0x24, 0xea, 0x7f, 0xff, 0x05, 0xb6, 0xf2, 0x14, 0x10, 0x12, 0x00,
   0x00, 0x08, 0x60, 0x84, 0x48, 0x12, 0x89, 0x54, 0xe8, 0xff, 0xef, 0x07,
   0xd5, 0x6d, 0x84, 0x00, 0x40, 0x24, 0x22, 0x20, 0x09, 0xa2, 0x92, 0x20,
   0x52, 0x12, 0xe2, 0xf7, 0xbd, 0x03, 0xb6, 0xdd, 0x14, 0x44, 0x84, 0x40,
   0x04, 0x01, 0x60, 0x84, 0x24, 0x45, 0x8a, 0x54, 0xe8, 0xff, 0xff, 0x07,
   0x6d, 0x77, 0x84, 0x10, 0x00, 0x04, 0x20, 0x24, 0x21, 0x22, 0x95, 0x92,
   0x50, 0x29, 0xea, 0xff, 0xbf, 0x07, 0x55, 0xed, 0x0c, 0x81, 0x24, 0x80,
   0x40, 0x00, 0x44, 0x04, 0x51, 0x10, 0x15, 0x25, 0xe0, 0x7f, 0xff, 0x06,
   0xdb, 0x5a, 0x04, 0x20, 0x80, 0x24, 0x02, 0x22, 0x20, 0xa3, 0x8a, 0xa2,
   0xa8, 0x28, 0xed, 0xff, 0xf7, 0x07, 0xb6, 0xf5, 0x4c, 0x84, 0x08, 0x00,
   0x10, 0x84, 0x24, 0x04, 0x29, 0x85, 0x82, 0x2a, 0xe0, 0xff, 0xff, 0x06,
   0x55, 0x5b, 0x04, 0x01, 0x42, 0x44, 0x42, 0x00, 0x20, 0x52, 0x52, 0x12,
   0x35, 0x29, 0xec, 0xef, 0xdf, 0x07, 0xdb, 0xea, 0x14, 0x10, 0x80, 0x00,
   0x00, 0x24, 0x61, 0x42, 0x45, 0x22, 0x44, 0xa5, 0xe0, 0xff, 0xff, 0x06,
   0xb6, 0x77, 0x04, 0x41, 0x04, 0x44, 0x92, 0x00, 0x04, 0x82, 0x94, 0x48,
   0x29, 0x29, 0xec, 0x7f, 0xff, 0x07, 0x2a, 0xd5, 0x2c, 0x84, 0x20, 0x08,
   0x00, 0x20, 0x60, 0x2a, 0xa9, 0x12, 0x55, 0x2a, 0xe0, 0xff, 0xdf, 0x07,
   0xdb, 0x7e, 0x04, 0x00, 0x84, 0x40, 0x22, 0x85, 0x08, 0x42, 0x25, 0x41,
   0x48, 0x29, 0xed, 0xff, 0xff, 0x06, 0xb6, 0xd5, 0x88, 0x24, 0x00, 0x02,
   0x04, 0x00, 0x61, 0x84, 0x4a, 0x92, 0x52, 0x25, 0xe0, 0xff, 0xfd, 0x07,
   0x55, 0x75, 0x24, 0x80, 0x24, 0x08, 0x20, 0x04, 0x20, 0x52, 0xaa, 0x92,
   0x4a, 0x2a, 0xec, 0x7f, 0xff, 0x07, 0xb6, 0xed, 0x84, 0x08, 0x40, 0x20,
   0x81, 0x48, 0x44, 0x82, 0x92, 0x22, 0x54, 0xa9, 0xe0, 0xff, 0xdf, 0x06,
   0x6d, 0x5b, 0x0c, 0x42, 0x02, 0x01, 0x04, 0x00, 0x21, 0x52, 0x55, 0x92,
   0x55, 0x15, 0xec, 0xff, 0xff, 0x07, 0x55, 0xf5, 0x08, 0x00, 0x08, 0x48,
   0x10, 0x11, 0x44, 0x86, 0xda, 0x22, 0x25, 0x55, 0xc8, 0xff, 0xfd, 0x07,
   0x6d, 0x57, 0x26, 0x12, 0x22, 0x01, 0x04, 0x04, 0x30, 0x10, 0x00, 0x00,
   0x00, 0x00, 0xe9, 0xff, 0xbf, 0x05, 0x5b, 0xfd, 0x44, 0x40, 0x00, 0x90,
   0x40, 0x90, 0x40, 0x22, 0x11, 0x49, 0x44, 0x20, 0xe8, 0xdf, 0xff, 0x07,
   0x6a, 0x6b, 0x04, 0x02, 0x44, 0x02, 0x08, 0x00, 0x22, 0x42, 0x4a, 0x92,
   0x5a, 0x2f, 0xe2, 0xff, 0xf7, 0x07, 0xad, 0xda, 0x14, 0x90, 0x00, 0x10,
   0x41, 0x22, 0x40, 0xca, 0xda, 0x92, 0xaa, 0x28, 0xe8, 0xff, 0x7f, 0x07,
   0xb5, 0x75, 0x44, 0x02, 0x24, 0x42, 0x08, 0x08, 0x32, 0x22, 0x55, 0x21,
   0xa9, 0x36, 0xe5, 0xff, 0xfe, 0x07, 0x6b, 0xd7, 0x0c, 0x44, 0x40, 0x00,
   0x80, 0x40, 0x40, 0x44, 0x55, 0x45, 0xaa, 0x2a, 0xe8, 0xff, 0xff, 0x06,
   0xad, 0x7a, 0x84, 0x00, 0x01, 0x92, 0x24, 0x10, 0x22, 0xa2, 0xaa, 0x92,
   0xaa, 0x2a, 0xe4, 0xff, 0xef, 0x07, 0x6b, 0xeb, 0x14, 0x10, 0x12, 0x00,
   0x00, 0x02, 0x60, 0x84, 0xaa, 0x92, 0xaa, 0xaa, 0xe8, 0xff, 0xff, 0x07,
   0xae, 0x6d, 0x04, 0x01, 0x40, 0x22, 0x49, 0x20, 0x09, 0x53, 0x5b, 0x21,
   0x55, 0x35, 0xe4, 0xff, 0xff, 0x06, 0x6a, 0xdb, 0x2c, 0x48, 0x04, 0x00,
   0x00, 0x04, 0x20, 0x42, 0x55, 0x45, 0xaa, 0x2a, 0xe8, 0x7f, 0xff, 0x07,
   0x5d, 0x6d, 0x04, 0x01, 0x21, 0x22, 0x22, 0x21, 0x22, 0xa2, 0xaa, 0x92,
   0xaa, 0x36, 0xe5, 0xff, 0xf7, 0x07, 0xd5, 0xed, 0x08, 0x10, 0x40, 0x04,
   0x04, 0x40, 0x60, 0x84, 0xaa, 0x52, 0xaa, 0x2a, 0xe8, 0xff, 0x7f, 0x07,
   0x5b, 0xb5, 0x24, 0x01, 0x09, 0x20, 0x20, 0x02, 0x22, 0x52, 0x55, 0x81,
   0xaa, 0x3a, 0xe4, 0xff, 0xdf, 0x07, 0xb5, 0xee, 0x0c, 0x24, 0x00, 0x81,
   0x40, 0x10, 0x40, 0x82, 0xaa, 0x2a, 0x55, 0xa5, 0xe8, 0xff, 0xff, 0x07,
   0x6d, 0x5b, 0x44, 0x00, 0x11, 0x04, 0x02, 0x42, 0x22, 0x52, 0x55, 0x91,
   0x6a, 0x3b, 0xe4, 0x7f, 0x7f, 0x07, 0x55, 0xf5, 0x08, 0x11, 0x40, 0x20,
   0x10, 0x00, 0x44, 0x02, 0x55, 0x23, 0xaa, 0x2a, 0xe8, 0xff, 0xff, 0x07,
   0xdb, 0x6e, 0x04, 0x84, 0x04, 0x89, 0x44, 0x12, 0x30, 0x6a, 0x29, 0x91,
   0x54, 0x3b, 0xe5, 0xfb, 0xf7, 0x06, 0xd6, 0xea, 0x54, 0x00, 0x10, 0x00,
   0x00, 0x20, 0x41, 0x82, 0xaa, 0x22, 0xd5, 0x2a, 0xe8, 0xff, 0xff, 0x07,
   0xad, 0x7d, 0x04, 0x92, 0x80, 0x88, 0x48, 0x02, 0x20, 0xa2, 0x52, 0x91,
   0x54, 0x37, 0xe4, 0xff, 0xff, 0x07, 0x6b, 0xeb, 0x4c, 0x00, 0x12, 0x10,
   0x00, 0x84, 0x44, 0x24, 0x95, 0x12, 0x51, 0xb5, 0xe8, 0xbf, 0x7f, 0x07,
   0x5a, 0x6d, 0x04, 0x12, 0x80, 0x80, 0x04, 0x10, 0x30, 0x42, 0x55, 0xa1,
   0x54, 0x2d, 0xe4, 0xff, 0xf7, 0x07, 0x56, 0xeb, 0x0c, 0x80, 0x08, 0x04,
   0xa0, 0x00, 0x41, 0x8a, 0x52, 0x85, 0xa4, 0x35, 0xe8, 0xff, 0xff, 0x06,
   0xb5, 0x5e, 0x24, 0x22, 0x42, 0x90, 0x04, 0x12, 0x20, 0xa2, 0x24, 0x11,
   0x52, 0xad, 0xe4, 0xff, 0xff, 0x07, 0x6d, 0xf5, 0x44, 0x04, 0x00, 0x01,
   0x08, 0x80, 0x44, 0x84, 0xaa, 0x52, 0x52, 0x35, 0xe8, 0xff, 0xef, 0x07,
   0xd5, 0x5a, 0x04, 0x20, 0x24, 0x44, 0x20, 0x12, 0x30, 0x52, 0x25, 0x01,
   0xa9, 0x36, 0xea, 0xff, 0xfe, 0x07, 0xdb, 0xf6, 0x8c, 0x80, 0x00, 0x08,
   0x41, 0x00, 0x41, 0x02, 0xa9, 0x2a, 0x51, 0x2d, 0xe0, 0xff, 0xdf, 0x06,
   0x56, 0x6d, 0x04, 0x02, 0x24, 0x00, 0x04, 0x12, 0x20, 0x6a, 0x55, 0x91,
   0xd4, 0x3a, 0xed, 0xff, 0xff, 0x07, 0x55, 0xdb, 0x2c, 0x94, 0x00, 0x49,
   0x08, 0x40, 0x44, 0x02, 0x95, 0x92, 0xaa, 0x32, 0xe0, 0xee, 0xbb, 0x07,
   0xed, 0x6a, 0x04, 0x00, 0x24, 0x00, 0x20, 0x02, 0x31, 0x52, 0xa9, 0x42,
   0xaa, 0x2d, 0xec, 0x7f, 0xff, 0x05, 0x5b, 0xed, 0x24, 0x41, 0x00, 0x21,
   0x41, 0x10, 0x40, 0x44, 0x55, 0x92, 0x54, 0x6b, 0xc8, 0xff, 0xf7, 0x07,
   0xaa, 0x75, 0x04, 0x04, 0x49, 0x04, 0x04, 0x02, 0x21, 0x52, 0xa5, 0x42,
   0x6b, 0x1d, 0xe4, 0xfd, 0xbf, 0x07, 0xb6, 0xd6, 0x4c, 0x10, 0x00, 0x40,
   0x10, 0x20, 0x62, 0x46, 0x55, 0x15, 0xda, 0xb5, 0xe8, 0xdf, 0xfe, 0x06,
   0x55, 0x7b, 0x04, 0x02, 0x11, 0x09, 0x40, 0x02, 0x20, 0xaa, 0xaa, 0xd2,
   0xaa, 0x2e, 0xe4, 0xfb, 0xf7, 0x07, 0xdb, 0xe6, 0x4c, 0x20, 0x00, 0x00,
   0x05, 0x48, 0x44, 0x88, 0xaa, 0x52, 0xfb, 0x3a, 0xc8, 0xff, 0xdf, 0x06,
   0x56, 0x5d, 0x04, 0x02, 0x49, 0x24, 0x20, 0x02, 0x20, 0x20, 0x00, 0xa9,
   0x54, 0xaf, 0xe4, 0xdf, 0xff, 0x07, 0x6a, 0xf5, 0xdc, 0x5a, 0x95, 0x55,
   0xd5, 0xda, 0x7d, 0x01, 0x22, 0x00, 0xa5, 0x34, 0xe8, 0x7f, 0xfb, 0x06,
   0xad, 0x6a, 0x2c, 0x55, 0x55, 0xaa, 0x2a, 0x55, 0x55, 0x44, 0x08, 0x41,
   0x00, 0x88, 0x64, 0xff, 0xdf, 0x07, 0x6b, 0xdb, 0x20, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xad, 0x02, 0x08, 0x20, 0x11, 0xe8, 0x76, 0xff, 0x05,
   0xd6, 0x76, 0x00, 0x01, 0x24, 0x91, 0x24, 0x10, 0xa2, 0xfe, 0x7d, 0x23,
   0x05, 0x00, 0xe9, 0xff, 0x5d, 0x07, 0x5a, 0xd5, 0xbe, 0xfe, 0x55, 0xab,
   0xd5, 0xeb, 0x56, 0xff, 0xff, 0x56, 0x55, 0x22, 0xe0, 0xdf, 0xff, 0x07,
   0x6b, 0x6b, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x55, 0x15, 0x65, 0x7d, 0xdb, 0x06, 0xda, 0xda, 0xb6, 0x55, 0xfb, 0x6e,
   0x7f, 0x6f, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x6b, 0xe5, 0xf7, 0xff, 0x05,
   0xab, 0x6d, 0xdb, 0xf6, 0x57, 0xdb, 0xaa, 0xdd, 0xd5, 0xeb, 0xff, 0xff,
   0xff, 0xff, 0xf7, 0xbf, 0x5b, 0x07, 0x5a, 0xd5, 0xd6, 0x56, 0x6e, 0xbb,
   0x6f, 0xbb, 0xbe, 0xde, 0xfe, 0xff, 0xff, 0xff, 0xef, 0x7e, 0xff, 0x07,
   0x6b, 0x5b, 0xbb, 0xdd, 0xb5, 0x6d, 0xb5, 0xed, 0xd5, 0xfb, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xfb, 0x5b, 0x05, 0xd6, 0xd6, 0x6a, 0x55, 0xb7, 0xd5,
   0x6e, 0x5b, 0xbb, 0x56, 0xdb, 0xff, 0xff, 0xff, 0xbf, 0x6f, 0xff, 0x07,
   0xad, 0xba, 0xd5, 0xde, 0x6a, 0xaf, 0xb5, 0xad, 0xed, 0xfd, 0x7f, 0xef,
   0xff, 0x77, 0xf7, 0xff, 0xbb, 0x06, 0xb5, 0xab, 0xae, 0x55, 0xaf, 0xba,
   0xae, 0x6d, 0x57, 0xab, 0xed, 0xfd, 0xff, 0xff, 0xbf, 0x6d, 0xf7, 0x06,
   0xad, 0xf6, 0x5a, 0xbd, 0xb5, 0xed, 0x7a, 0xdb, 0xda, 0xfd, 0x7e, 0xdf,
   0xff, 0xff, 0xf6, 0xff, 0xdf, 0x03, 0x6b, 0xad, 0x6b, 0x65, 0x6d, 0xad,
   0xab, 0xb6, 0x76, 0xab, 0xeb, 0xbb, 0xfd, 0xed, 0xbf, 0x6d, 0x7d, 0x07,
   0x5a, 0x55, 0xad, 0x5d, 0xdb, 0x6d, 0xdb, 0xda, 0xad, 0xfd, 0xbe, 0xff,
   0xdf, 0xff, 0xf6, 0xff, 0xb7, 0x05, 0xd6, 0xf6, 0x6a, 0x75, 0x2b, 0xdb,
   0xb6, 0xab, 0x6d, 0xab, 0x75, 0xdb, 0xff, 0xef, 0xbf, 0x6e, 0xf7, 0x07,
   0xb5, 0xad, 0xad, 0xad, 0xed, 0xb6, 0x6d, 0xaf, 0xb6, 0x6d, 0xdf, 0x7f,
   0x7b, 0xfb, 0xf6, 0xfb, 0x5d, 0x05, 0x6d, 0xab, 0xb5, 0x6a, 0xab, 0x56,
   0x5b, 0xbd, 0xad, 0xed, 0xba, 0xf6, 0xff, 0xdf, 0xb7, 0xaf, 0xff, 0x07 };
