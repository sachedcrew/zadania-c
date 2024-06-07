#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

void modifyPoint(Point *p) {
    p->x += 10;
    p->y += 5;
}

typedef struct {
    Point top_left;
    Point bottom_right;
} Rectangle;

void calculateRectangle(Rectangle *r, float *area, float *perimeter) {
    float length = r->bottom_right.x - r->top_left.x;
    float width = r->bottom_right.y - r->top_left.y;
    *area = length * width;
    *perimeter = 2 * (length + width);
}

int main() {
    Point p = {2.0, 3.0};
    printf("Przed modyfikacją: x = %.2f, y = %.2f\n", p.x, p.y);
    modifyPoint(&p);
    printf("Po modyfikacji: x = %.2f, y = %.2f\n", p.x, p.y);

    Rectangle rect = {{0.0, 0.0}, {4.0, 3.0}};
    float area, perimeter;
    calculateRectangle(&rect, &area, &perimeter);
    printf("Pole prostokąta: %.2f, Obwód prostokąta: %.2f\n", area, perimeter);

    return 0;
}
