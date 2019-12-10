#pragma once
#include "RigidBody.hpp"
#include "Matrix4.hpp"

class Primitive
{
private:
    RigidBody* m_body ;
    Matrix4* m_offset;
    RigidBody::BoundingSphere m_boundingSphere;

public:
    Primitive();
    Primitive(RigidBody* p_body, Matrix4* p_offset);
    Primitive(Primitive& p_primitive);
    ~Primitive(){};

    RigidBody* getBody() { return m_body; };
    Matrix4* getOffset() { return m_offset; };
    RigidBody::BoundingSphere getBoundingSphere() { return m_boundingSphere; }


	void setBody(RigidBody* p_body) { m_body = p_body; }
    void setOffset(Matrix4* p_offset) { m_offset = p_offset; }
        void setBoundingSphere(Vecteur3D p_centre, float p_rayon)
        {
            m_boundingSphere.centre = p_centre;
            m_boundingSphere.rayon = p_rayon;
        }
};