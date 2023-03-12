#include "./utils.h"

void insert(bmp_colors **image1, bmp_infoheader ih1, char *f2, int y, int x) {
    bmp_fileheader fh2;
    bmp_infoheader ih2;
    bmp_colors **image2 = NULL;
    image2 = edit(&fh2, &ih2, f2);
    int xf = ZERO, yf = ZERO;

    if (x + ih2.width > ih1.width) {
        xf = ih1.width;
    } else {
        xf = x + ih2.width;
    }

    if (y + ih2.height > ih1.height) {
        yf = ih1.height;
    } else {
        yf = y + ih2.height;
    }

    int x1 = ZERO, y1 = ZERO;

    for (int i = y; i < yf; i++) {
        for (int j = x; j < xf; j++) {
            image1[i][j].B = image2[y1][x1].B;
            image1[i][j].G = image2[y1][x1].G;
            image1[i][j].R = image2[y1][x1].R;
            x1++;
        }
        y1++;
        x1 = ZERO;
    }
}
