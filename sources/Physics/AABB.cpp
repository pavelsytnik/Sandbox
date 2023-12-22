#include "AABB.hpp"

// Possible through-block movement when we have bigger values of move distance. It's necessary to check

float AABB::clipXCollide(const AABB& other, float x) const {

    if (this->minY >= other.maxY || this->maxY <= other.minY ||
        this->minZ >= other.maxZ || this->maxZ <= other.minZ)
    {
        return x;
    }

    if (x > 0.f && this->maxX < other.minX &&
        this->maxX + x - other.minX > 0)
    {
        return x - (this->maxX + x - other.minX);
    }
    if (x < 0.f && this->minX > other.maxX
             && other.maxX - (this->minX + x) > 0)
    {
        return x + (other.maxX - (this->minX + x));
    }

    return x;
}

float AABB::clipYCollide(const AABB& other, float y) const {

    if (this->minX >= other.maxX || this->maxX <= other.minX ||
        this->minZ >= other.maxZ || this->maxZ <= other.minZ)
    {
        return y;
    }

    if (y > 0.f && this->maxY < other.minY &&
        this->maxY + y - other.minY > 0)
    {
        return y - (this->maxY + y - other.minY);
    }
    if (y < 0.f && this->minY > other.maxY
        && other.maxY - (this->minY + y) > 0)
    {
        return y + (other.maxY - (this->minY + y));
    }

    return y;
}

float AABB::clipZCollide(const AABB& other, float z) const {

    if (this->minX >= other.maxX || this->maxX <= other.minX ||
        this->minY >= other.maxY || this->maxY <= other.minY)
    {
        return z;
    }

    if (z > 0.f && this->maxZ < other.minZ &&
        this->maxZ + z - other.minZ > 0)
    {
        return z - (this->maxZ + z - other.minZ);
    }
    if (z < 0.f && this->minZ > other.maxZ
        && other.maxZ - (this->minZ + z) > 0)
    {
        return z + (other.maxZ - (this->minZ + z));
    }

    return z;
}

void AABB::move(float x, float y, float z) {
    minX += x;
    minY += y;
    minZ += z;
    maxX += x;
    maxY += y;
    maxZ += z;
}
