#include "./utils.h"

bmp_colors** set_line_width(bmp_colors **image, bmp_infoheader ih,
    int r, int g,
    int b, int line_width,
    int x, int y) {
    int dim = line_width / 2;

    for (int i = x - dim; i <= x + dim; i++) {
        for (int j = y - dim; j <= y + dim; j++) {
            if (i >= 0 && j >= 0 && i < ih.height && j < ih.width) {
                image[i][j].R = r;
                image[i][j].G = g;
                image[i][j].B = b;
            }
        }
    }
    return image;
}

void draw_line(bmp_colors **image, bmp_infoheader ih,
    int yA, int xA,
    int yB, int xB,
    int r, int g, int b,
    int line_width
    ) {
    int diffx = xB - xA;
    int diffy = yB - yA;
    int maxx = ZERO, maxy = ZERO;
    int xint = xA - xB;
    int yint = yA - yB;
    if (xA < xB)
        xint = xB - xA;
    if (yA < yB)
        yint = yB - yA;

    int panta = ZERO;
    if (xint > yint) {
        if (xA < xB) {
            for (int i = xA; i <= xB; i++) {
                panta = ((i - xA) * diffy + yA * diffx) / diffx;
                if (i >= 0 && panta >= 0 && i < ih.height && panta < ih.width) {
                    image[i][panta].R = r;
                    image[i][panta].G = g;
                    image[i][panta].B = b;
                }
                image = set_line_width(image, ih, r, g, b, line_width, i, panta);
            }
        } else {
            for (int i = xA; i >= xB; i--) {
                panta = ((i - xA) * diffy + yA * diffx) / diffx;
                if (i >= 0 && panta >= 0 && i < ih.height && panta < ih.width) {
                    image[i][panta].R = r;
                    image[i][panta].G = g;
                    image[i][panta].B = b;
                }
                image = set_line_width(image, ih, r, g, b, line_width, i, panta);
            }
        }
    } else {
        if (yA < yB) {
            for (int i = yA; i <= yB; i++) {
                panta = ((i - yA) * diffx + xA * diffy) / diffy;
                if (i >= 0 && panta >= 0 && i < ih.width && panta < ih.height) {
                    image[panta][i].R = r;
                    image[panta][i].G = g;
                    image[panta][i].B = b;
                }
                image = set_line_width(image, ih, r, g, b, line_width, panta, i);
            }
        } else {
            for (int i = yA; i >= yB; i--) {
                panta = ((i - yA) * diffx + xA * diffy) / diffy;
                if (i >= 0 && panta >= 0 && i < ih.width && panta < ih.height) {
                    image[panta][i].R = r;
                    image[panta][i].G = g;
                    image[panta][i].B = b;
                }
                image = set_line_width(image, ih, r, g, b, line_width, panta, i);
            }
        }
    }
}

void draw_rectangle(bmp_colors **image, bmp_infoheader ih,
    int yA, int xA,
    int width, int height,
    int r, int g, int b,
    int line_width
    ) {
    int x2 = xA + height;
    int y3 = yA + width;
    draw_line(image, ih, yA, xA, yA, x2, r, g, b, line_width);
    draw_line(image, ih, yA, xA, y3, xA, r, g, b, line_width);
    draw_line(image, ih, y3, x2, yA, x2, r, g, b, line_width);
    draw_line(image, ih, y3, xA, y3, x2, r, g, b, line_width);
}

void draw_triangle(bmp_colors **image, bmp_infoheader ih,
    int y1, int x1,
    int y2, int x2,
    int y3, int x3,
    int r, int g, int b,
    int line_width
    ) {
    draw_line(image, ih, y1, x1, y2, x2, r, g, b, line_width);
    draw_line(image, ih, y3, x3, y2, x2, r, g, b, line_width);
    draw_line(image, ih, y1, x1, y3, x3, r, g, b, line_width);
}
