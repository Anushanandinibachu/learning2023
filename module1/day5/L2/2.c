#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double calculateDistance(struct Point p1, struct Point p2) {
    double distance;
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

int main() {
    struct Point point1, point2;

    printf("Enter coordinates for Point 1:\n");
    printf("x: ");
    scanf("%lf", &point1.x);
    printf("y: ");
    scanf("%lf", &point1.y);

    printf("\nEnter coordinates for Point 2:\n");
    printf("x: ");
    scanf("%lf", &point2.x);
    printf("y: ");
    scanf("%lf", &point2.y);

    double distance = calculateDistance(point1, point2);

    printf("\nThe distance between the two points is: %.2lf\n", distance);

    return 0;
}