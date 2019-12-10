#pragma once
#include "RigidBody.hpp"
#include "Matrix4.hpp"

class Primitive
{
private:
    RigidBody* m_body;
    Matrix4* m_offset;

public:
    Primitive();
    Primitive(RigidBody* p_body, Matrix4* p_offset);
    Primitive(Primitive& p_primitive);
    ~Primitive(){};

    RigidBody* getBody() { return m_body; };
    Matrix4* getOffset() { return m_offset; };

	void setBody(RigidBody* p_body) { m_body = p_body; };
    void setOffset(Matrix4* p_offset) { m_offset = p_offset; };
};