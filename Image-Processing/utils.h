#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "./bmp_header.h"
#define MAX_FILE_NAME 100
#define MAX_LINE 1000
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7

bmp_colors** edit(bmp_fileheader *fh, bmp_infoheader *ih, char *file_name);
void insert(bmp_colors **image1, bmp_infoheader ih1, char *f2, int y, int x);
bmp_colors** set_line_width(bmp_colors **image, bmp_infoheader ih,
    int r, int g,
    int b, int line_width,
    int x, int y);
void draw_line(bmp_colors **image, bmp_infoheader ih,
    int yA, int xA,
    int yB, int xB,
    int r, int g, int b,
    int line_width);
void draw_rectangle(bmp_colors **image, bmp_infoheader ih,
    int yA, int xA,
    int width, int height,
    int r, int g, int b,
    int line_width);
void draw_triangle(bmp_colors **image, bmp_infoheader ih,
    int y1, int x1,
    int y2, int x2,
    int y3, int x3,
    int r, int g, int b,
    int line_width);
void fill(bmp_colors **matrix, bmp_infoheader *ih, int y, int x,
    int r, int g, int b, bmp_colors *original);
void save(bmp_colors **matrix, bmp_fileheader *fh,
    bmp_infoheader *ih, char *file_name);
void quit(bmp_colors **matrix, bmp_infoheader infoheader, char **v);


