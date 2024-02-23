#include <iostream>
#include <math.h>

using namespace std;

class threevec_ {
    public: 
        float x;
        float y;
        float z;
        threevec_(float xin, float yin, float zin);
};

threevec_::threevec_(float xin, float yin, float zin) {
    x = xin;
    y = yin;
    z = zin;
}

std::ostream& operator<<(std::ostream& os, const threevec_& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

threevec_ operator+(const threevec_& a, const threevec_& b) {
    return threevec_(a.x+b.x, a.y+b.y, a.z+b.y);
}

int main() {
    threevec_ vec_(1.0, 1.0, 1.0);
    cout << "vec =" << endl;
    cout << vec_ << endl;
    threevec_ res_ = vec_ + vec_;
    cout << "vec + vec =" << endl;
    cout << res_ << endl;
    return 0;
}
