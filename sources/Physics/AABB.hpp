#ifndef AABB_HPP
#define AABB_HPP

struct AABB {

    float minX;
    float minY;
    float minZ;

    float maxX;
    float maxY;
    float maxZ;

    float clipXCollide(const AABB& other, float x) const;
    float clipYCollide(const AABB& other, float y) const;
    float clipZCollide(const AABB& other, float z) const;

    void move(float x, float y, float z);
};

#endif
