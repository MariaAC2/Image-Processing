#include "./utils.h"

int main() {
    char *fin_name = "";
    FILE *finput = NULL;

    char *fout_name = "";
    FILE *foutput = NULL;

    bmp_fileheader fh;
    bmp_infoheader ih;
    bmp_colors **matrix = NULL;

    char **v = malloc(MAX_LINE * sizeof(char *));
    for (int i = 0; i < MAX_LINE; i++) {
        v[i] = malloc(MAX_FILE_NAME * sizeof(char));
    }
    int number_words = 0;

    char buffer[MAX_LINE];
    char *ptr = NULL;
    while (fgets(buffer, MAX_LINE, stdin)) {
        ptr = strtok(buffer, " \n");
        while (ptr != NULL) {
            snprintf(v[number_words++], MAX_LINE, "%s", ptr);
            ptr = strtok(NULL, " \n");
        }
    }
    int red = 0, green = 0, blue = 0;
    int x = 1;
    bmp_colors *original = malloc(sizeof(bmp_colors));

    for (int i = 0; i < number_words; i++) {
        if (strcmp(v[i], "edit") == 0) {
            matrix = edit(&fh, &ih, v[i + 1]);
        } else if (strcmp(v[i], "insert") == 0) {
            int iy = atoi(v[i + 2]);
            int ix = atoi(v[i + 3]);
            insert(matrix, ih, v[i + 1], ix, iy);
        }
        if (strcmp(v[i], "set") == 0) {
            if (strcmp(v[i + 1], "draw_color") == 0) {
                red = atoi(v[i + 2]);
                green = atoi(v[i + 3]);
                blue = atoi(v[i + 4]);
            } else if (strcmp(v[i + 1], "line_width") == 0) {
                x = atoi(v[i + 2]);
            }
        } else if (strcmp(v[i], "draw") == 0) {
            if (strcmp(v[i + 1], "line") == 0) {
                int y1 = atoi(v[i + 2]);
                int x1 = atoi(v[i + 3]);
                int y2 = atoi(v[i + 4]);
                int x2 = atoi(v[i + FIVE]);
                draw_line(matrix, ih, y1, x1, y2, x2, red, green, blue, x);
            } else if (strcmp(v[i + 1], "rectangle") == 0) {
                int y1 = atoi(v[i + 2]);
                int x1 = atoi(v[i + 3]);
                int width = atoi(v[i + 4]);
                int height = atoi(v[i + FIVE]);
                draw_rectangle(matrix, ih, y1, x1, width, height, red, green, blue, x);
            } else if (strcmp(v[i + 1], "triangle") == 0) {
                int y1 = atoi(v[i + 2]);
                int x1 = atoi(v[i + 3]);
                int y2 = atoi(v[i + 4]);
                int x2 = atoi(v[i + FIVE]);
                int y3 = atoi(v[i + SIX]);
                int x3 = atoi(v[i + SEVEN]);
                draw_triangle(matrix, ih, y1, x1, y2, x2, y3, x3, red, green, blue, x);
            }
        }
        if (strcmp(v[i], "fill") == 0) {
            int y = atoi(v[i + 1]);
            int x = atoi(v[i + 2]);
            if (original != NULL && x >= 0 && x < ih.height && y >= 0 && y < ih.width) {
                original->R = matrix[x][y].R;
                original->G = matrix[x][y].G;
                original->B = matrix[x][y].B;
                fill(matrix, &ih, x, y, red, green, blue, original);
            }
        } else if (strcmp(v[i], "save") == 0) {
            save(matrix, &fh, &ih, v[i + 1]);
        } else if (strcmp(v[i], "quit") == 0) {
            quit(matrix, ih, v);
        }
    }
    return 0;
}
