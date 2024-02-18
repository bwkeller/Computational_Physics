#include <math.h>
#include "length.hpp"
#include "vector.hpp"

float length(vector r) {
    return sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
}
