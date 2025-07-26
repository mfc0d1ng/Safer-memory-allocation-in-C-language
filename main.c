#include <stdio.h>
#include <stdlib.h>
#include "include/new.h"

typedef struct point
{
    int x, y;
}point;

int main()
{
    int* integer = new(int);

    *integer = 10000; 

    printf("*integer = %i\n", *integer);

    delete(integer);

    
    const char** strings = new_block(const char*, 3);

    strings[0] = "Hello";
    strings[1] = "world";
    strings[2] = "2025";

    printf("strings: %s %s %s\n", strings[0], strings[1], strings[2]);

    delete(strings);
    

    point* points = new_block(point, 2);

    points[0] = (point){1, 1};
    points[1] = (point){2, 2};

    printf("points: {{%i, %i}, {%i, %i}}\n", points[0].x, points[0].y, points[1].x, points[1].y);

    delete(points);

    return EXIT_SUCCESS;
}
