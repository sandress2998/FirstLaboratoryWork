#include <stdio.h>
#include <stdlib.h>

#include "Test.h"
#include "VectorFunctions.h"

int main() {
    testIntFunctions();
    testFloatFunctions();
    testDoubleFunctions();
    testComplexFunctions();

    testDotProduct();
    testSumProduct();

    /* Пример для скалярного произведения
    Vector* vector1 = buildVector(3, &setVectorDoubleInfo);
    Vector* vector2 = buildVector(3, &setVectorDoubleInfo);
    void* p = malloc(sizeof(double));

    scalarVectors(vector1, vector2, p);

    printf("%.2f\n", *(double*)p);
    */
    return 0;
}



