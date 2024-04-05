#include <stdio.h>
#include <stdlib.h>

#include "Test.h"
/* for following example
#include "VectorFunctions.h"
#include "TypeService.h"
*/

int main() {

    testIntFunctions();
    testFloatFunctions();
    testDoubleFunctions();
    testComplexFunctions();

    testDotProduct();
    testSumProduct();

    // The example for dot product
    /*
    Vector* vector1 = buildVector(3, &intOperationsService);
    Vector* vector2 = buildVector(3, &intOperationsService);
    void* p = malloc(sizeof(int));

    scalarVectors(vector1, vector2, p);

    printf("%d\n", *(int*)p);
    */
    return 0;
}
