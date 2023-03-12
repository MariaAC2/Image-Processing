# Image-Processing

#### Chirnogeanu Maria-Andreea, Grupa 315CB

In header-ul bmp_header.h a fost adaugata o structura cele 3 culori ale pixelilor (respectiv rosu - R, green - G, blue -B).
In header-ul utils.h am inserat bibliotecile folosite pt toate functiile, respectiv apelarea functiilor in main.

#### main.c
In functia main.c stochez fiecare sir de caractere intr-un array de string-uri.
Array-ul de string-uri este comparat cu un string sau un set de string-uri ce reprezinta denumirea comenzii intalnite in input si, daca se verifica, se apeleaza functia corespunzatoare comenzii.

#### Task1.c
In task1, se efectueaza urmatoarele comenzi:
 * **edit** - functie care citeste fisierul bmp din input, initializeaza matricea si o formeaza
 * **save** - functie care salveaza matricea in fisierul bmp din output
 * **quit** - functie care dezaloca memoria pt matrice si pt array-ul de string-uri

#### Task2.c
In task2, se efectueaza functia **insert**, in care se apeleaza 2 imagini din input si sunt "unite" in functie de 2 parametri dati.

#### Task3.c
In task3, se efectueaza urmatoarele comenzi:
 * **set_line_width** - functie care seteaza grosimea si culoarea liniei pe care urmeaza sa o traseze
 * **draw_line** - functie care traseaza linia, in functie de grosimea si de culorile alese
 * **draw_rectangle** - functie care creeaza un dretunghi cu ajutorul functiei draw_line
 * **draw_triangle** - functie care creeaza un triunghi cu ajutorul functiei draw_line

#### Task4.c
In task4, se efectueaza functia **fill**, care umple spatiile in functie de coordonatele date.
