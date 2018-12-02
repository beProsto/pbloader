//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_VECTOR_HPP
#define PBLOADER_VECTOR_HPP

template<typename T>
class Vector2 {
public:
    Vector2() { }
    Vector2(const Vector2& vec) { x = vec->x; y = vec->y; }

    Vector2 operator +(const Vector2& v) { return Vector2(x + v.x, y + v.y); }
    Vector2 operator -(const Vector2& v) { return Vector2(x - v.x, y - v.y); }
    Vector2 operator *(const Vector2& v) { return Vector2(x * v.x, y * v.y); }
    Vector2 operator /(const Vector2& v) { return Vector2(x / v.x, y / v.y); }

    Vector2& operator =(const Vector2& v) { x = v.x; y = v.y; return *this; }

    bool operator <(const Vector2& v) {
        if(x < v.x && y < v.y)
            return true;
        else
            return false;
    }
    bool operator >(const Vector2& v) {
        if(x > v.x && y > v.y)
            return true;
        else
            return false;
    }

    Vector2& operator +=(const Vector2& v) { x += v.x; y += v.y; return *this; }
    Vector2& operator -=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
    Vector2& operator *=(const Vector2& v) { x *= v.x; y *= v.y; return *this; }
    Vector2& operator /=(const Vector2& v) { x /= v.x; y /= v.y; return *this; }

    bool operator ==(const Vector2& v) {
        if(x == v.x && y == v.y)
            return true;
        else
            return false;
    }
    bool operator !=(const Vector2& v) {
        if(x != v.x && y != v.y)
            return true;
        else
            return false;
    }
    bool operator <=(const Vector2& v) {
        if(x <= v.x && y <= v.y)
            return true;
        else
            return false;
    }
    bool operator >=(const Vector2& v) {
        if(x >= v.x && y >= v.y)
            return true;
        else
            return false;
    }
private:
    T x;
    T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

#endif //PBLOADER_VECTOR_HPP
