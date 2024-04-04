#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Test.h"
#include "FieldInfo.h"
#include "TypeService.h"
#include "VectorFunctions.h"
#include "Complex.h"
#include "Vector.h"

/// test FieldInfo functions

void testSumInt() {
    int firstValue = -10;
    int secondValue = 8;
    int expectedResult = firstValue + secondValue;

    int* firstValuePtr = &firstValue;
    int* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(int));

    sumInt((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(*(int*)result == expectedResult);
    //printf("The function \"sumFloat\" passed the test\n");
    free(result);
}

void testMultiplyInt() {
    int firstValue = -10;
    int secondValue = 8;
    int expectedResult = firstValue * secondValue;

    int* firstValuePtr = &firstValue;
    int* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(int));

    multiplyInt((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(*(int*)result == expectedResult);
    //printf("The function \"multiplyInt\" passed the test\n");
    free(result);
}

void testIntFunctions() {
    testSumInt();
    testMultiplyInt();
    //printf("\"Int\" functions passed the test\n");
}

void testSumFloat() {
    float firstValue = -10.0;
    float secondValue = 8.1;
    float expectedResult = firstValue + secondValue;

    float* firstValuePtr = &firstValue;
    float* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(float));

    sumFloat((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(*(float*)result == expectedResult);
    //printf("The function \"sumFloat\" passed the test\n");
    free(result);
}

void testMultiplyFloat() {
    float firstValue = -10;
    float secondValue = 8;
    float expectedResult = firstValue * secondValue;

    float* firstValuePtr = &firstValue;
    float* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(float));

    multiplyFloat((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(*(float*)result == expectedResult);
    //printf("The function \"multiplyFloat\" passed the test\n");
    free(result);
}

void testFloatFunctions() {
    testSumFloat();
    testMultiplyFloat();
    //printf("\"Float\" functions passed the test\n");
}

void testSumDouble() {
    double firstValue = -10.0;
    double secondValue = 8.1;
    double expectedResult = firstValue + secondValue;

    double* firstValuePtr = &firstValue;
    double* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(double));

    sumDouble((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(*(double*)result == expectedResult);
    //printf("The function \"sumDouble\" passed the test\n");
    free(result);
}

void testMultiplyDouble() {
    double firstValue = -10;
    double secondValue = 8;
    double expectedResult = firstValue * secondValue;

    double* firstValuePtr = &firstValue;
    double* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(double));

    multiplyDouble((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(*(double*)result == expectedResult);
    //printf("The function \"multiplyDouble\" passed the test\n");
    free(result);
}

void testDoubleFunctions() {
    testSumDouble();
    testMultiplyDouble();
    //printf("\"Double\" functions passed the test\n");
}

void testSumComplex() {
    Complex firstValue = {-10.9, 198,2};
    Complex secondValue = {-10.9, 198,2};
    Complex expectedResult = {firstValue.x + secondValue.x, firstValue.y + secondValue.y};

    Complex* firstValuePtr = &firstValue;
    Complex* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(Complex));

    sumComplex((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(((Complex*)result) -> x == expectedResult.x && ((Complex*)result) -> y == expectedResult.y);
    //printf("The function \"sumComplex\" passed the test\n");
    free(result);
}

void testMultiplyComplex() {
    Complex firstValue = {-10.9, 198,2};
    Complex secondValue = {-10.9, 198,2};
    Complex expectedResult = {firstValue.x * secondValue.x - firstValue.y * secondValue.y,
                              firstValue.x * secondValue.y + firstValue.y * secondValue.x};

    Complex* firstValuePtr = &firstValue;
    Complex* secondValuePtr = &secondValue;
    void* result = malloc(sizeof(Complex));

    multiplyComplex((const void*) firstValuePtr, (const void*) secondValuePtr, result);
    assert(((Complex*)result) -> x == expectedResult.x && ((Complex*)result) -> y == expectedResult.y);
    //printf("The function \"multiplyComplex\" passed the test\n");
    free(result);
}

void testComplexFunctions() {
    testSumComplex();
    testMultiplyComplex();
    //printf("\"Complex\" functions passed the test\n");
}

/// Bellow is block of code to test Vector functions

static const char* X1 = "x1";
static const char* X2 = "x2";
static const char* X3 = "x3";
static const char* Y1 = "y1";
static const char* Y2 = "y2";
static const char* Y3 = "y3";
static const char* PLUS = "+";
static const char* CROSS = "*";

static const char* dotProductExpected = ":+,+,*,x1,y1,*,x2,y2,*,x3,y3";
static const char* sumProductExpected[3] = { ":+,x1,y1", ":+,x2,y2", ":+,x3,y3" };

static const int SIZE = 3;

typedef struct Node* NodePtr;

/// fake type just like int, float, Complex еtc
struct Node {
    char* lexem;
    NodePtr leftNode;
    NodePtr rightNode;
};


/// Functions to support Node
// {{
int getNodeSize() {
    return sizeof(struct Node);
}

NodePtr newNode(void) {
	return (NodePtr) safemalloc(getNodeSize());
}

NodePtr newNodeCopy(const NodePtr src) {
	NodePtr result = newNode();
	assert(result != NULL);
	copyValue(src, result, getNodeSize());
	return result;
}

void operation(const char* lexem, const void* leftNode, const void* rightNode, void* result) {
    ((NodePtr)result) -> lexem = lexem;
    ((NodePtr)((NodePtr)result))-> leftNode = newNodeCopy((NodePtr)leftNode);
    ((NodePtr)((NodePtr)result))-> rightNode = newNodeCopy((NodePtr)rightNode);
}
// }}

/// Fake typeService
// {{
void sumNodeFake(const void* leftNode, const void* rightNode, void* result) {
    operation(PLUS, leftNode, rightNode, result);
}

void multiplyNodeFake(const void* leftNode, const void* rightNode, void* result) {
    operation(CROSS, leftNode, rightNode, result);
}

void getNodeValueFake(void* node) {
    // is empty now // we don't use it
}

void printNodeFake(void* node) {
    // is empty // we don't use it
}


static const FieldInfo fakeOperationsService = { &sumNodeFake, &multiplyNodeFake, &getNodeValueFake, &printNodeFake, sizeof(struct Node) };

FieldInfo* setFakeOperationsService() { return &fakeOperationsService; };

void setVectorFakeInfo(Vector* vector) {
    if (vector == NULL) emptyError();

    vector -> fieldInfo = setFakeOperationsService();

    //printf("It's the test. Vector is going to be created with random values automatically. Size: %d\n", vector -> size);
    initializeVector(vector);
}
// }}

void printToBuff(char **buff, const char separator, int *remainingSize, NodePtr node) {
    assert(node);
    assert(node -> lexem);

    int stepLength = 1 + strlen(node -> lexem);
	assert((*remainingSize) > 1 + stepLength);
    **buff = separator;
    strcpy((*buff) + 1, node -> lexem);
    *buff += stepLength;
    *remainingSize -= stepLength;

    if (node -> leftNode != NULL) {
        printToBuff(buff, ',', remainingSize, (NodePtr)(node -> leftNode));
    }
    if (node -> rightNode != NULL) {
        printToBuff(buff, ',', remainingSize, (NodePtr)(node -> rightNode));
    }
}


/// test scalarVectors
void testDotProduct(void) {
    NodePtr nodeForInit = (NodePtr) safemalloc(getNodeSize());
    nodeForInit -> leftNode = NULL;
    nodeForInit -> rightNode = NULL;
    nodeForInit -> lexem = X1;

    Vector* firstVector = buildVector(SIZE, &setVectorFakeInfo);

    // we don't use getValue in fieldInfo so we should initialize vector manually
    setElementValue(firstVector, 1, (void*) nodeForInit);
    nodeForInit -> lexem = X2;
    setElementValue(firstVector, 2, (void*) nodeForInit);
    nodeForInit -> lexem = X3;
    setElementValue(firstVector, 3, (void*) nodeForInit);

    Vector* secondVector = buildVector(SIZE, &setVectorFakeInfo);

    nodeForInit -> lexem = Y1;
    setElementValue(secondVector, 1, (void*) nodeForInit);
    nodeForInit -> lexem = Y2;
    setElementValue(secondVector, 2, (void*) nodeForInit);
    nodeForInit -> lexem = Y3;
    setElementValue(secondVector, 3, (void*) nodeForInit);

    free(nodeForInit);

    void* dotProduct = safemalloc(getNodeSize());
    scalarVectors(firstVector, secondVector, dotProduct);

    char buff[1000];
    char* bufferStart = buff;
    int remainingSize = sizeof(buff);
    printToBuff(&bufferStart, ':', &remainingSize, (NodePtr)dotProduct);
    assert(strcmp(buff, dotProductExpected) == 0);

    free(dotProduct);
    //printf("Test for scalarVectors passed.\n");
}

/// Test sumVectors
void testSumProduct(void) {
    NodePtr nodeForInit = (NodePtr) safemalloc(getNodeSize());
    nodeForInit -> leftNode = NULL;
    nodeForInit -> rightNode = NULL;
    nodeForInit -> lexem = X1;

    Vector* firstVector = buildVector(SIZE, &setVectorFakeInfo); // we use fake vector???

    setElementValue(firstVector, 1, (void*) nodeForInit);
    nodeForInit -> lexem = X2;
    setElementValue(firstVector, 2, (void*) nodeForInit);
    nodeForInit -> lexem = X3;
    setElementValue(firstVector, 3, (void*) nodeForInit);

    Vector* secondVector = buildVector(SIZE, &setVectorFakeInfo);

    nodeForInit -> lexem = Y1;
    setElementValue(secondVector, 1, (void*) nodeForInit);
    nodeForInit -> lexem = Y2;
    setElementValue(secondVector, 2, (void*) nodeForInit);
    nodeForInit -> lexem = Y3;
    setElementValue(secondVector, 3, (void*) nodeForInit);

    free(nodeForInit);

    Vector* sumProduct = buildVector(SIZE, &setVectorFakeInfo);
    sumVectors(firstVector, secondVector, sumProduct);

    char buff[3][10];
    char* bufferStart;
    int remainingSize;
    for (int i = 1; i <= SIZE; i++) {
        remainingSize = sizeof(buff[0]);
        bufferStart = buff[i - 1];
        printToBuff(&bufferStart, ':', &remainingSize, (NodePtr)getElementPtr(sumProduct, i));
        assert(strcmp(buff[i - 1], sumProductExpected[i - 1]) == 0);
    }
    free(sumProduct);
    //printf("Test for sumVectors passed.\n");
}


