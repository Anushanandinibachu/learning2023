#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

double calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
}

int main() {
    struct Box myBox = { 5.0, 3.0, 4.0 };
    struct Box* boxPtr = &myBox;

    // Accessing members using (*) asterisk and (.) dot operator
    double volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    double surfaceArea = 2 * ((*boxPtr).length * (*boxPtr).width + (*boxPtr).length * (*boxPtr).height + (*boxPtr).width * (*boxPtr).height);
    printf("Volume (using (*) and .): %.2f\n", volume);
    printf("Surface Area (using (*) and .): %.2f\n", surfaceArea);

    // Accessing members using (->) arrow operator (both pointer and dot representation)
    volume = boxPtr->length * boxPtr->width * boxPtr->height;
    surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
    printf("Volume (using ->): %.2f\n", volume);
    printf("Surface Area (using ->): %.2f\n", surfaceArea);

    return 0;
}