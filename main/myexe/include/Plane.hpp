#pragma once
#include "Primitive.hpp"

class Plane : public Primitive
{
private:
    Vecteur3D m_normal = Vecteur3D();
    float m_offset = 0;

public:
    Plane() = default;
    Plane(Vecteur3D p_normal,float p_offset)
    {
        m_normal = p_normal;
        m_offset = p_offset;
    };
    Plane(Plane& p_plane) 
	{
        m_normal = p_plane.m_normal;
        m_offset = p_plane.m_offset;
	}
    ~Plane(){};

	Vecteur3D getNormal() { return m_normal; }
    float getOffset() { return m_offset; }

	void setNormal(Vecteur3D p_normal) { m_normal = p_normal; };
    void setOffset(float p_offset) { m_offset = p_offset; }
};