

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
    
}

// Function to calculate the area of a triangle in 3D 
double area(const Triangle* t) {
}

int main() {
    Point pts [3]; //Array of 3 points
    // double x, y, z;
    for (int i = 1; i <= 3; i++)
    {
        printf("Point %i (x y z): ");
        scanf("%lf %lf %lf", &pts[i].x, &pts[i].y, &pts[i].z);
    }
    Triangle t = {pts[1], pts[2], pts[3]};

    // Print the results
    printf("Perimeter: %.6f\n", perimeter(&t));
    printf("Area: %.6f\n", area(&t));

    return 0;
}
