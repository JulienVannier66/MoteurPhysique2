#include <Octree.hpp>

Octree::Octree(Rectangle p_region, std::list<RigidBody::BoundingSphere> p_objList)
{
    m_region = p_region;
    m_objects = p_objList;
}

Octree::Octree(Rectangle p_region)
{
    m_region = p_region;
    m_objects = std::list<RigidBody::BoundingSphere>();
}

Octree::Octree(Octree& p_octree)
{
    m_region = p_octree.m_region;
    m_objects = p_octree.m_objects;
    m_enfants = p_octree.m_enfants;
    m_activeNodes = p_octree.m_activeNodes;
	m_parent = p_octree.m_parent;
}

void Octree::BuildTree() 
{
    // si on arrive à une feuille on termine la fonction
    if (m_objects.size() <= 2) return;

    Vecteur3D dimensions = m_region.getMax() - m_region.getMin();
    Vecteur3D vecteur0 = Vecteur3D(0, 0, 0);

	//On vérifie si les dimensions du cube sont plus grandes que les dimensions minimum
    if (dimensions.getX() <= m_taille_min && dimensions.getY() <= m_taille_min &&
        dimensions.getZ() <= m_taille_min)
    { return; }

    Vecteur3D half = dimensions * 0.5f;
    Vecteur3D center = m_region.getMin() + half;

    // On crée les subdivisions de l'octree
    std::vector<Rectangle> octant;
    octant.push_back(Rectangle(m_region.getMin(), center));
    octant.push_back(
        Rectangle(Vecteur3D(center.getX(), m_region.getMin().getY(), m_region.getMin().getZ()),
                  Vecteur3D(m_region.getMax().getX(), center.getY(), center.getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(center.getX(), m_region.getMin().getY(), center.getZ()),
                  Vecteur3D(m_region.getMax().getX(), center.getY(), m_region.getMax().getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(m_region.getMin().getX(), m_region.getMin().getY(), center.getZ()),
                  Vecteur3D(center.getX(), center.getY(), m_region.getMax().getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(m_region.getMin().getX(), center.getY(), m_region.getMin().getZ()),
                  Vecteur3D(center.getX(), m_region.getMax().getY(), center.getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(center.getX(), center.getY(), m_region.getMin().getZ()),
                  Vecteur3D(m_region.getMax().getX(), m_region.getMax().getY(), center.getZ())));
    octant.push_back(Rectangle(center, m_region.getMax()));
    octant.push_back(
        Rectangle(Vecteur3D(m_region.getMin().getX(), center.getY(), center.getZ()),
                  Vecteur3D(center.getX(), m_region.getMax().getY(), m_region.getMax().getZ())));

    //Liste contenant les objets à ajouter
    std::vector<std::vector<RigidBody::BoundingSphere>> octList;

    for (RigidBody::BoundingSphere obj : m_objects)
    {
        if (obj.rayon != 0)
        {
            for (int i = 0; i < 8; i++)
            {
                Vecteur3D vec1 = octant.at(i).getCenter();
                Vecteur3D vec2 = obj.centre;

                float dist = ((vec2.getX() - vec1.getX()) * (vec2.getX() - vec1.getX()) +
                              (vec2.getY() - vec1.getY()) * (vec2.getY() - vec1.getY()) +
                              (vec2.getZ() - vec1.getZ()) * (vec2.getZ() - vec1.getZ()));
                // Si la sphere est dans le cube
                if (dist >= (octant.at(i).getDemiLongueur().getX() * sqrt(3) + obj.rayon))
                {
                    // On ajoute l'objet dans la liste
                    octList.at(i).push_back(obj);
                    break;
                }
            }
        }
    }

    //Création des enfants
    for (int i = 0; i < 8; i++)
    {
        if (octList.at(i).size() != 0)
        {
            std::list<RigidBody::BoundingSphere> newlist;
            for (RigidBody::BoundingSphere obj : octList.at(i)) { newlist.push_back(obj); }

            m_enfants.push_back(CreateNode(octant.at(i), newlist));
            m_activeNodes |= (1 << i);
            m_enfants.at(i).BuildTree();
        }
    }
}

Octree Octree::CreateNode(Rectangle region,
                          std::list<RigidBody::BoundingSphere> objList) 
{
    if (objList.size() == 0) return Octree();
    Octree ret = Octree(region, objList);
    ret.m_parent = this;
    return ret;
}

Octree Octree::CreateNode(Rectangle p_region, RigidBody::BoundingSphere p_item)
{
    std::list<RigidBody::BoundingSphere> objList;                                                
    objList.push_back(p_item);
    Octree ret = Octree(p_region, objList);
    ret.m_parent = this;
    return ret;
}



