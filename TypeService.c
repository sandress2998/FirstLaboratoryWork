#include "Complex.h"
#include "TypeService.h"


/// Definitions (Implementation) of type functions

// INT

void sumInt(const void* a, const void* b, void* res) {
    *(int*)res = (*((const int*)a))+(*((const int*)b));
}

void multiplyInt(const void* a, const void* b, void* res) {
    *(int*)res = *((const int*) a) * *((const int*) b);
}

void getIntValue(void* a) {
    printf("Enter int value:\n");
    scanf("%d", (int*)a);
}
void printInt(void* a) {
    printf("%d", *(int*)a);
}


// FLOAT

void sumFloat(const void* a, const void* b, void* res) {
    *(float*)res = (*((const float*) a)) + *((const float*) b);
}

void multiplyFloat(const void* a, const void* b, void* res) {
    *(float*)res = *((const float*) a) * *((const float*) b);
}

void getFloatValue(void* a) {
    printf("Enter float value:\n");
    scanf("%f", (float*)a);
}

void printFloat(void* a) {
    printf("%.2f", *(float*)a);
}

// DOUBLE

void sumDouble(const void* a, const void* b, void* res) {
    *(double*)res = *((const double*) a) + *((const double*) b);
}

void multiplyDouble(const void* a, const void* b, void* res) {
    *(double*)res = *((const double*) a) * *((const double*) b);
}

void getDoubleValue(void* a) {
    printf("Enter double value:\n");
    scanf("%lf", (double*)a);
}

void printDouble(void* a) {
    printf("%.2f", *(double*)a);
}

// COMPLEX

void sumComplex(const void* a, const void* b, void* res) {
    ((Complex*)res) -> x = (((const Complex*) a) -> x) + (((const Complex*) b) -> x);
    ((Complex*)res) -> y = (((const Complex*) a) -> y) + (((const Complex*) b) -> y);
}

void multiplyComplex(const void* a, const void* b, void* res) {
    ((Complex*)res) -> x = (((const Complex*) a) -> x) * (((const Complex*) b) -> x) - (((const Complex*) a) -> y) * (((const Complex*) b) -> y);
    ((Complex*)res) -> y = (((const Complex*) a) -> x) * (((const Complex*) b) -> y) + (((const Complex*) a) -> y) * (((const Complex*) b) -> x);
}

void getComplexValue(void* a) {
    printf("Enter complex value:\n");
    scanf("%lf", &(((Complex*)a) -> x));
    scanf("%lf", &(((Complex*)a) -> y));
}

void printComplex(void* a) {
    printf("(%.2f; %.2f)", ((Complex*)a) -> x, ((Complex*)a) -> y);
}
