//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_VECTOR_HPP
#define PBLOADER_VECTOR_HPP

template<typename T>
class Vector2 {
public:
    T x;
    T y;

    Vector2() { }
    Vector2(const T& a) {x = a, y = a;}
    Vector2(const T& x, const T& y) {this->x = x; this->y = y;}
    Vector2(const Vector2& other) { x = other.x; y = other.y; }


    Vector2 operator +(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
    Vector2 operator -(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
    Vector2 operator *(const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
    Vector2 operator /(const Vector2& v) const { return Vector2(x / v.x, y / v.y); }


    Vector2& operator =(const Vector2& v) { x = v.x; y = v.y; return *this; }

    Vector2& operator +=(const Vector2& v) { x += v.x; y += v.y; return *this; }
    Vector2& operator -=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
    Vector2& operator *=(const Vector2& v) { x *= v.x; y *= v.y; return *this; }
    Vector2& operator /=(const Vector2& v) { x /= v.x; y /= v.y; return *this; }
        
    bool operator ==(const Vector2& v) const {
        if(x == v.x && y == v.y)
            return true;
        else
            return false;
    }
    bool operator !=(const Vector2& v) const {
        if(x != v.x && y != v.y)
            return true;
        else
            return false;
    }


    bool operator <(const Vector2& v) const{
        if(x < v.x && y < v.y)
            return true;
        else
            return false;
    }
    bool operator >(const Vector2& v) const {
        if(x > v.x && y > v.y)
            return true;
        else
            return false;
    }


    bool operator <=(const Vector2& v) const {
        if(x <= v.x && y <= v.y)
            return true;
        else
            return false;
    }
    bool operator >=(const Vector2& v) const {
        if(x >= v.x && y >= v.y)
            return true;
        else
            return false;
    }
    
    // i'm writing this with githubs' editor, so there can be some problems xd
    template <typename X>
    Vector2 operator +(const X& v) const { return Vector2(x + v, y + v); }
    template <typename X>
    Vector2 operator -(const X& v) const { return Vector2(x - v, y - v); }
    template <typename X>
    Vector2 operator *(const X& v) const { return Vector2(x * v, y * v); }
    template <typename X>
    Vector2 operator /(const X& v) const { return Vector2(x / v, y / v); }

    template <typename X>
    Vector2& operator =(const X& v) { x = v; y = v; return *this; }

    template <typename X>
    Vector2& operator +=(const X& v) { x += v; y += v; return *this; }
    template <typename X>
    Vector2& operator -=(const X& v) { x -= v; y -= v; return *this; }
    template <typename X>
    Vector2& operator *=(const X& v) { x *= v; y *= v; return *this; }
    template <typename X>
    Vector2& operator /=(const X& v) { x /= v; y /= v; return *this; }
    
    template <typename X>
    bool operator ==(const X& v) const {
        if(x == v && y == v)
            return true;
        else
            return false;
    }
    template <typename X>
    bool operator !=(const X& v) const {
        if(x != v && y != v)
            return true;
        else
            return false;
    }

    template <typename X>
    bool operator <(const X& v) const{
        if(x < v && y < v)
            return true;
        else
            return false;
    }
    template <typename X>
    bool operator >(const X& v) const {
        if(x > v && y > v)
            return true;
        else
            return false;
    }

    template <typename X>
    bool operator <=(const X& v) const {
        if(x <= v && y <= v)
            return true;
        else
            return false;
    }
    template <typename X>
    bool operator >=(const X& v) const {
        if(x >= v && y >= v)
            return true;
        else
            return false;
    }
};

typedef Vector2<unsigned char> Vector2byte;
typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2ui;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;


#endif //PBLOADER_VECTOR_HPP
