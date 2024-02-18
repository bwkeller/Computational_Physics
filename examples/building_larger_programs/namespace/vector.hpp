#ifndef VECTOR_H
#define VECTOR_H
namespace newton {
    typedef struct {
        float x;
        float y;
        float z;
    } vector;
}

namespace einstein {
    const float c = 1; // Use "natural" units (c=1)
    typedef struct {
        float x;
        float y;
        float z;
        float t;
    } vector;
}
#endif
