#include <math.h>
#include "length.hpp"
#include "vector.hpp"

namespace newton {
    float length(vector r) {
        return sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
    }
}

namespace einstein{
    float length(vector r) {
        return sqrt(r.x*r.x + r.y*r.y + r.z*r.z - (c*r.t)*(c*r.t));
    }
}
