#pragma once

typedef struct {
    void (*sum)(const void* a, const void* b, void* res);
    void (*multiply)(const void* a, const void* b, void* res);
    void (*getValue) (void* value);
    void (*print) (void* value);
    int elementSize;
} FieldInfo;

