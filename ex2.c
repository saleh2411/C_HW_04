

#include <stdio.h>
#include <math.h>

// Structure Definitions
typedef struct point {
    double x, y, z;
} Point;

typedef struct triangle {
    Point p, q, r;
} Triangle;


// Function to calculate the perimeter of a triangle in 3 D
double perimeter(const Triangle* t) {
    double d1 = sqrt(pow(t->p.x - t->q.x, 2) + pow(t->p.y - t->q.y, 2) + pow(t->p.z - t->q.z, 2));
    double d2 = sqrt(pow(t->q.x - t->r.x, 2) + pow(t->q.y - t->r.y, 2) + pow(t->q.z - t->r.z, 2));
    double d3 = sqrt(pow(t->r.x - t->p.x, 2) + pow(t->r.y - t->p.y, 2) + pow(t->r.z - t->p.z, 2));
    return d1 + d2 + d3;
}
    


// Function to calculate the area of a triangle in 3D 
double area(const Triangle* t) {
}

int main() {
    Point pts [3]; //Array of 3 points
    // double x, y, z;
    for (int i = 1; i <= 3; i++)
    {
        printf("Point %d (x y z): ", i);
        scanf("%lf %lf %lf", &pts[i].x, &pts[i].y, &pts[i].z);
    }
    Triangle t = {pts[1], pts[2], pts[3]};

    // Print the results
    printf("Perimeter: %.6f\n", perimeter(&t));
    printf("Area: %.6f\n", area(&t));

    return 0;
}
