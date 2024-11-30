#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray{
    public:
    ray() {}
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    //first const makes readonly
    const point3& origin() const {return orig;}
    const vec3& direction() const {return dir;}

    point3 at(double t) const {
        return orig + dir * t;
    }

    private:
        point3 orig;
        vec3 dir;
};

#endif