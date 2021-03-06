//
//  Vector4.hpp
//  Game Framework
//
//  Created by numata on Jan 10, 2011.
//  Copyright (c) 2011-2016 Satoshi Numata. All rights reserved.
//

#ifndef __VECTOR4_HPP__
#define __VECTOR4_HPP__


#include "GMObject.hpp"

class Matrix4x4;
class Vector2;
class Vector3;
class Quaternion;


/*!
    @class  Vector4
    @group  Math
    @unity-compatible   true
 */
struct Vector4 : public GMObject
{
public:
    /*!
        @const  one
        @unity-compatible   true
     */
    static const Vector4&    one;

    /*!
        @const  zero
        @unity-compatible   true
     */
    static const Vector4&    zero;
    
public:
#pragma mark - Static 関数
    /*!
        @task   Static 関数
     */
    
    /*!
        @method     Distance
        @unity-compatible   true
        2つのベクトル間の距離を返します。
     */
    static float    Distance(const Vector2& a, const Vector2& b);

    /*!
        @method     Dot
        @unity-compatible   true
        2つのベクトルの内積を返します。
     */
    static float    Dot(const Vector4& lhs, const Vector4& rhs);

    /*!
        @method     EaseIn
     */
    static Vector4  EaseIn(const Vector4& vec1, const Vector4& vec2, float amount);

    /*!
        @method     EaseInOut
     */
    static Vector4  EaseInOut(const Vector4& vec1, const Vector4& vec2, float amount);

    /*!
        @method     EaseOut
     */
    static Vector4  EaseOut(const Vector4& vec1, const Vector4& vec2, float amount);

    /*!
        @method     Lerp
        @unity-compatible   true
        ベクトル a と b の間で t の値による線形補間を計算します。
        パラメーター t は [0, 1] の範囲で制限されます。
     */
    static Vector4  Lerp(const Vector4& vec1, const Vector4& vec2, float amount);

    /*!
        @method     LerpUnclamped
        @unity-compatible   true
        ベクトル a と b の間で t の値による線形補間を計算します。
        パラメーター t は [0, 1] の範囲で制限されます。
     */
    static Vector4  LerpUnclamped(const Vector4& vec1, const Vector4& vec2, float amount);

    /*!
        @method     Max
        @unity-compatible   true
        2つのベクトルの各成分の最大の要素からなるベクトルを返します。
     */
    static Vector4  Max(const Vector4& vec1, const Vector4& vec2);

    /*!
        @method     Min
        @unity-compatible   true
        2つのベクトルの各成分の最小の要素からなるベクトルを返します。
     */
    static Vector4  Min(const Vector4& vec1, const Vector4& vec2);

    /*!
        @method     MoveTowards
        @unity-compatible   true
        現在の位置 current から target に向けて移動します。
     */
    static Vector4 MoveTowards(const Vector4& current, const Vector4& target, float maxDistanceDelta);

    /*!
        @method     Project
        @unity-compatible   true
        ベクトル b の上にベクトル a を投影したベクトルを返します。
     */
    static Vector4  Project(const Vector4& a, const Vector4& b);

    /*!
        @method     Scale
        @unity-compatible   true
        2つのベクトルの各成分を乗算します。
     */
    static Vector4  Scale(const Vector4& a, const Vector4& b);

    static Vector4  SmoothStep(const Vector4& a, const Vector4& b, float t);

public:
#pragma mark - Public 変数
    /*!
        @var    x
        @unity-compatible   true
     */
    float x;
    
    /*!
        @var    y
        @unity-compatible   true
     */
    float y;
    
    /*!
        @var    z
        @unity-compatible   true
     */
    float z;
    
    /*!
        @var    w
        @unity-compatible   true
     */
    float w;
    
public:
#pragma mark - コンストラクタ
    /*!
        @task   コンストラクタ
     */
    
    /*!
        @method     Vector4
        @unity-compatible   false
     */
    Vector4();
    
    /*!
        @method     Vector4
        @unity-compatible   true
     */
    Vector4(float x, float y, float z, float w);
    
    /*!
        @method     Vector4
        @unity-compatible   false
     */
    Vector4(const Vector2& vec, float z, float w);
    
    /*!
        @method     Vector4
        @unity-compatible   false
     */
    Vector4(const Vector3& vec, float w);
    
    /*!
        @method     Vector4
        @unity-compatible   false
     */
    Vector4(const Vector4& vec);
    
public:
#pragma mark - Public 関数
    /*!
        @method     Public 関数
     */
    
    /*!
        @method     Magnitude
        @unity-compatible   true
     */
    float       Magnitude() const;
    
    /*!
        @method     SqrMagnitude
        @unity-compatible   true
     */
    float       SqrMagnitude() const;
    
    /*!
        @method     Normalized
        @unity-compatible   true
     */
    Vector4     Normalized() const;
    
    /*!
        @method     Normalize
        @unity-compatible   true
     */
    void        Normalize();
    
    /*!
        @method     Set
        @unity-compatible   true
        既存の Vector4 に x、y、z、w の成分を設定します。
     */
    void        Set(float x, float y, float z, float w);

    /*!
        @method     ToString
        @unity-compatible   true
        ベクトルの各要素を見やすくフォーマットした文字列を返します。
     */
    std::string ToString() const override;

    /*!
        @method     ToString
        @unity-compatible   true
        各要素に対して適用される書式を指定して、ベクトルの各要素を見やすくフォーマットした文字列を返します。
     */
    std::string ToString(const std::string& format) const;

    /*!
        @method     c_str
        ベクトルの各要素を見やすくフォーマットしたC言語文字列を返します。
     */
    const char* c_str() const override;

    /*!
        @method     c_str
        各要素に対して適用される書式を指定して、ベクトルの各要素を見やすくフォーマットしたC言語文字列を返します。
     */
    const char* c_str(const std::string& format) const;

public:
#pragma mark - 演算子のオーバーロード
    /*!
        @task   演算子のオーバーロード
     */
    
    /*!
        @method     operator=
     */
    Vector4&  operator=(const Vector4& vec);
    
    
    /*!
        @method     operator-
     */
    Vector4   operator-() const;
    
    /*!
        @method     operator+
     */
    Vector4   operator+(const Vector4& vec) const;
    
    /*!
        @method     operator-
     */
    Vector4   operator-(const Vector4& vec) const;
    
    /*!
        @method     operator*
     */
    Vector4   operator*(const Vector4& vec) const;
    
    /*!
        @method     operator/
     */
    Vector4   operator/(const Vector4& vec) const;
    
    /*!
        @method     operator*
     */
    Vector4   operator*(float value) const;
    
    /*!
        @method     operator/
     */
    Vector4   operator/(float value) const;


    friend Vector4 operator*(float value, const Vector4& vec);

    
    /*!
        @method     operator+=
     */
    Vector4&  operator+=(const Vector4& vec);
    
    /*!
        @method     operator-=
     */
    Vector4&  operator-=(const Vector4& vec);
    
    /*!
        @method     operator*=
     */
    Vector4&  operator*=(const Vector4& vec);
    
    /*!
        @method     operator/=
     */
    Vector4&  operator/=(const Vector4& vec);
    
    /*!
        @method     operator*=
     */
    Vector4&  operator*=(float value);
    
    /*!
        @method     operator/=
     */
    Vector4&  operator/=(float value);
    
    
    /*!
        @method     operator==
     */
    bool        operator==(const Vector4& vec) const;
    
    /*!
        @method     operator!=
     */
    bool        operator!=(const Vector4& vec) const;

    /*!
        @method     operator[]
     */
    float&      operator[](int index);

};


#endif  //#ifndef __VECTOR4_HPP__


