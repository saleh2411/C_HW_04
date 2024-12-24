

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

    double x, y, z;
    for (int i = 1; i <= 3; i++)
    {
        printf("Point %i (x y z): ");
        scanf("%lf %lf %lf", &x, &y, &z);
    }
    

    // Print the results
    printf("Perimeter: %.6f\n", perimeter);
    printf("Area: %.6f\n", area);

    return 0;
}
