#pragma once
#include "Primitive.hpp"

Primitive::Primitive()
{
    m_body = new RigidBody();
    m_offset = Matrix4();
    m_demiLongueur = Vecteur3D(0, 0, 0);
}

Primitive::Primitive(RigidBody* p_body, Matrix4 p_offset)
{
    m_body = p_body;
    m_offset = p_offset;
    m_demiLongueur = Vecteur3D(0, 0, 0);
}

Primitive::Primitive(Primitive& p_primitive) 
{ 
	m_body = p_primitive.m_body;
    m_offset = p_primitive.m_offset;
    m_demiLongueur = p_primitive.m_demiLongueur;
}