#include "./utils.h"

void fill(bmp_colors **matrix, bmp_infoheader *ih, int y, int x,
    int r, int g, int b, bmp_colors *original
    ) {
    if (y >= 0 && y < ih->height && x >= 0 && x < ih->width) {
        matrix[y][x].R = r;
        matrix[y][x].G = g;
        matrix[y][x].B = b;

        if (x < ih->width - 1) {
            bmp_colors s = matrix[y][x + 1];
            if (s.R == original->R && s.G == original->G && s.B == original->B) {
                fill(matrix, ih, y, x + 1, r, g, b, original);
            }
        }
        if (y < ih->height - 1) {
            bmp_colors s = matrix[y + 1][x];
            if (s.R == original->R && s.G == original->G && s.B == original->B) {
                fill(matrix, ih, y + 1, x, r, g, b, original);
            }
        }
        if (x >= 1) {
            bmp_colors s = matrix[y][x - 1];
            if (s.R == original->R && s.G == original->G && s.B == original->B) {
                fill(matrix, ih, y, x - 1, r, g, b, original);
            }
        }
        if (y >= 1) {
            bmp_colors s = matrix[y - 1][x];
            if (s.R == original->R && s.G == original->G && s.B == original->B) {
                fill(matrix, ih, y - 1, x, r, g, b, original);
            }
        }
    }
}
