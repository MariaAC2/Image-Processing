#include "./utils.h"

bmp_colors** edit(bmp_fileheader *fh, bmp_infoheader *ih, char *file_name) {
    FILE *fin = NULL;
    fin = fopen(file_name, "rb");

    fread(&fh->fileMarker1, 1, 1, fin);
    fread(&fh->fileMarker2, 1, 1, fin);
    fread(&fh->bfSize, 4, 1, fin);
    fread(&fh->unused1, 2, 1, fin);
    fread(&fh->unused2, 2, 1, fin);
    fread(&fh->imageDataOffset, 4, 1, fin);

    fread(&ih->biSize, 4, 1, fin);
    fread(&ih->width, 4, 1, fin);
    fread(&ih->height, 4, 1, fin);
    fread(&ih->planes, 2, 1, fin);
    fread(&ih->bitPix, 2, 1, fin);
    fread(&ih->biCompression, 4, 1, fin);
    fread(&ih->biSizeImage, 4, 1, fin);
    fread(&ih->biXPelsPerMeter, 4, 1, fin);
    fread(&ih->biYPelsPerMeter, 4, 1, fin);
    fread(&ih->biClrUsed, 4, 1, fin);
    fread(&ih->biClrImportant, 4, 1, fin);

    bmp_colors s;
    int padding = ih->width % 4;

    bmp_colors **matrix = NULL;
    matrix = (bmp_colors **)malloc(ih->height * sizeof(bmp_colors *));
    for (int i = 0; i < ih->height; i++) {
        matrix[i] = malloc(ih->width * sizeof(bmp_colors));
    }

    for (int i = 0; i < ih->height; i++) {
        for (int j = 0; j < ih->width; j++) {
            fread(&s.B, 1, 1, fin);
            fread(&s.G, 1, 1, fin);
            fread(&s.R, 1, 1, fin);
            matrix[i][j] = s;
        }
        fseek(fin, padding, SEEK_CUR);
    }

    fclose(fin);
    return matrix;
}

void save(bmp_colors **matrix, bmp_fileheader *fh, bmp_infoheader *ih, char *file_name) {
    FILE *fout = NULL;
    fout = fopen(file_name, "wb");

    fwrite(&fh->fileMarker1, 1, 1, fout);
    fwrite(&fh->fileMarker2, 1, 1, fout);
    fwrite(&fh->bfSize, 4, 1, fout);
    fwrite(&fh->unused1, 2, 1, fout);
    fwrite(&fh->unused2, 2, 1, fout);
    fwrite(&fh->imageDataOffset, 4, 1, fout);

    fwrite(&ih->biSize, 4, 1, fout);
    fwrite(&ih->width, 4, 1, fout);
    fwrite(&ih->height, 4, 1, fout);
    fwrite(&ih->planes, 2, 1, fout);
    fwrite(&ih->bitPix, 2, 1, fout);
    fwrite(&ih->biCompression, 4, 1, fout);
    fwrite(&ih->biSizeImage, 4, 1, fout);
    fwrite(&ih->biXPelsPerMeter, 4, 1, fout);
    fwrite(&ih->biYPelsPerMeter, 4, 1, fout);
    fwrite(&ih->biClrUsed, 4, 1, fout);
    fwrite(&ih->biClrImportant, 4, 1, fout);

    int padding = ih->width % 4;
    unsigned char empty = 0;
    bmp_colors s;
    for (int i = 0; i < ih->height; i++) {
        for (int j = 0; j < ih->width; j++) {
            s = matrix[i][j];
            fwrite(&s.B, 1, 1, fout);
            fwrite(&s.G, 1, 1, fout);
            fwrite(&s.R, 1, 1, fout);
        }
        for (int j = 0; j < padding; j++) {
            fwrite(&empty, 1, 1, fout);
        }
    }

    fclose(fout);
}

void quit(bmp_colors **matrix, bmp_infoheader infoheader, char **v) {
    for (int i = 0; i < infoheader.height; i++) {
        free(matrix[i]);
    }

    for (int i = 0; i < MAX_FILE_NAME; i++) {
        free(v[i]);
    }

    free(v);
    free(matrix);
}

