#include "../../../external/freeglut-3.2.0/include/GL/freeglut_std.h"
#include <Box.hpp>
#include <CollisionData.hpp>
#include <GravityGenerator.hpp>
#include <Primitive.hpp>
#include <RigidBody.hpp>
#include <Plane.hpp>
#include <iostream>
#include <typeinfo>

void inputKeyBoard(unsigned char key, int x, int y);
void renderScene(void);

    Box r1;
	Plane p1;
    GravityGenerator g;

float startFrame = 0;
float endFrame = 0;
float deltaFrame = 0.016f;
float i = 0;
int nbFrames = 0;
float lastTime = 0;

void inputKeyBoard(unsigned char key, int x, int y) { std::cout << "t" << std::endl; }
// Calculate FPS
void calculFrame(int& nbFrames, float& lastTime)
{
    double currentTime = glutGet(GLUT_ELAPSED_TIME);
    nbFrames++;
    if (currentTime - lastTime >= 1000)
    {
        // cout and reset timer
     /*   std::cout << "FPS : " << nbFrames << std::endl;*/
        nbFrames = 0;
        lastTime += 1000;
    }
}

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    if (h == 0) { h = 1; }

    float ratio = w * 1.0f / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);
    // Reset Matrix
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    // Set the correct perspective.
    gluPerspective(45, ratio, 1, 100);
    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
    calculFrame(nbFrames, lastTime);
    startFrame = glutGet(GLUT_ELAPSED_TIME); // Get start time to calculate deltaFrame for a frame

    glEnable(GL_DEPTH_TEST); // Enables Depth Testing

    // r1.addForce(Vecteur3D(0.00, -0.4, 0));
    /*
        std::cout << "delta : " << deltaFrame << std::endl;
        std::cout << "start : " << startFrame << std::endl;
        std::cout << "end : " << endFrame << std::endl;*/
    r1.getBody()->integrate(deltaFrame);
    g.updateForce(*(r1.getBody()), deltaFrame);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(r1.getBody()->getPosition().getX(), r1.getBody()->getPosition().getY(),
                 r1.getBody()->getPosition().getZ());
    // std::cout << "x : " << r1.getPosition().getX() << std::endl;
    // std::cout << "y : " << r1.getPosition().getY() << std::endl;
    // glRotated(0.2 * i, r1.getRotation().getX(), r1.getRotation().getY(),
    // r1.getRotation().getZ());

    Matrix4 l_finalMatrix = r1.getBody()->getTransformMatrice();
    float l_CubeSize = 5;

    Vecteur3D cubePoints[8];
    float x = r1.getDemiLongueur().getX();
    float y = r1.getDemiLongueur().getY();
    float z = r1.getDemiLongueur().getZ();
    cubePoints[0] = l_finalMatrix * Vecteur3D(-x, -y, z);
    cubePoints[1] = l_finalMatrix * Vecteur3D(-x, y, z);
    cubePoints[2] = l_finalMatrix * Vecteur3D(x, y, z);
    cubePoints[3] = l_finalMatrix * Vecteur3D(x, -y, z);

    cubePoints[4] = l_finalMatrix * Vecteur3D(-x, -y, -z);
    cubePoints[5] = l_finalMatrix * Vecteur3D(-x, y, -z);
    cubePoints[6] = l_finalMatrix * Vecteur3D(x, y, -z);
    cubePoints[7] = l_finalMatrix * Vecteur3D(x, -y, -z);

	/*std::cout << "cubePoints[0] : " << cubePoints[0] << std::endl;
	std::cout << "cubePoints[1] : " << cubePoints[1] << std::endl;
	std::cout << "cubePoints[2] : " << cubePoints[2] << std::endl;
	std::cout << "cubePoints[3] : " << cubePoints[3] << std::endl;
	std::cout << "cubePoints[4] : " << cubePoints[4] << std::endl;
	std::cout << "cubePoints[5] : " << cubePoints[5] << std::endl;
	std::cout << "cubePoints[6] : " << cubePoints[6] << std::endl;
	std::cout << "cubePoints[7] : " << cubePoints[7] << std::endl;*/

    glBegin(GL_QUADS);
    // face 1 devant
    glColor3b(60, 0, 0);
    glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());
    glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
    glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());
    glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());

    // face 2 derriere
    glColor3b(0, 60, 0);
    glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());
    glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());
    glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());
    glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());

    // face 3 droite
    glColor3b(60, 60, 0);
    glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());
    glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());
    glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());
    glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());

    // face 4 gauche
    glColor3b(60, 60, 60);
    glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());
    glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
    glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());
    glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());

    // face 5 haut
    glColor3b(0, 0, 60);
    glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
    glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());
    glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());
    glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());

    // face 6 bas
    glColor3b(60, 0, 60);
    glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());
    glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());
    glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());
    glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());
    glEnd();

	glBegin(GL_QUADS);
    glColor3b(60, 60, 60);
        glVertex3f(p1.getOffset(), 10, -10);
		glVertex3f(p1.getOffset(), -10, -10);
		glVertex3f(p1.getOffset() +10, -10, 10);
		glVertex3f(p1.getOffset() + 10, 10, 10);
    glEnd();

    glPopMatrix();
    glFlush();

    glutPostRedisplay();
    glutSwapBuffers();

    i = glutGet(GLUT_ELAPSED_TIME);

    endFrame = glutGet(GLUT_ELAPSED_TIME); // Get end time for deltaFrame
    deltaFrame = (endFrame - startFrame) / 1000;
}

int main(int argc, char** argv)
{
    r1.getBody()->setPosition(Vecteur3D(-100, -10, -50));
    r1.getBody()->setRotation(Vecteur3D(0, 0, 1));
    //r1.addForce(Vecteur3D(70, 30, 0));
    r1.setDemiLongueur(5, 5, 5);

	p1.setOffset(100);
    p1.setNormal(Vecteur3D(1, 0, 0));

    CollisionData col;
    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(-60, 100);
    glutInitWindowSize(1500, 400);
    glutCreateWindow("Moteur physique Particule");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(inputKeyBoard);

    // enter GLUT event processing loop
    glutMainLoop();

    return 1;
}



//bool pointInCube(Vecteur3D point, Primitive prim)
//{
//    bool temp;
//    float xmin, xmax, ymin, ymax, zmin, zmax;
//    for (int i = 0; i < 8; i++) {
//        if (Box* prim = dynamic_cast<Box*>(prim))
//        {
//            // old was safely casted to NewType
//            prim->getDemiLongueur();
//        }
//    }
//    temp = point.getX <
//} //// test Vertex-Face, on regarde  si un sommet de prim1 est dans prim2
  // bool vertex_Face = false;
  // for (int i = 0; i < 8; i++) { vertex_Face = vertex_Face || prim1. }