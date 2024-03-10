#include <math.h>
#include "header.hpp"

float length(struct vector r) {
    return sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
}
