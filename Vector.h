#pragma once

#include "FieldInfo.h"

// �������� Vector � ��������� ����, �.�. ��� ����������� ������������ � ���� .c ������ - TestVectorFunctions.c, VectorFunctions.c

typedef struct Vector {

    int size;

    FieldInfo* fieldInfo; // ��������� �� ������, �������������� ������� �����.

    void* pointer; // ��������� �� ������ ������� �������

} Vector;
