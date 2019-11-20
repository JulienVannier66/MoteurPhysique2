#include "../../../external/freeglut-3.2.0/include/GL/freeglut_std.h"
#include <GravityGenerator.hpp>
#include <RigidBody.hpp>
#include <iostream>
#include <vector>

void inputKeyBoard(unsigned char key, int x, int y);
void renderScene(void);
void t1();
void t2();

RigidBody r1;
RigidBody r2;

float startFrame = 0;
float endFrame = 0;
float deltaFrame = 0;
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
        std::cout << "FPS : " << nbFrames << std::endl;
        nbFrames = 0;
        lastTime += 1000;
    }
}

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    if (h == 0) { h = 1; }

    float ratio = w * 1.0 / h;

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
    
	t1();
	t2();
    
	i = glutGet(GLUT_ELAPSED_TIME);

    endFrame = glutGet(GLUT_ELAPSED_TIME); // Get end time for deltaFrame
    deltaFrame = endFrame - startFrame;
}

int main(int argc, char** argv)
{
    r1.setPosition(Vecteur3D(-60, -10, -50));
    r1.setRotation(Vecteur3D(0, 0, 0));
    r1.addForce(Vecteur3D(0.5, 0, 0));
    r1.setMasse(20.0f);

	r2.setPosition(Vecteur3D(60, -10, -50));
    r2.setRotation(Vecteur3D(0, 0, 0));
    r2.addForce(Vecteur3D(-0.5, 0, 0));
    r2.setMasse(10.0f);

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 320);
    glutCreateWindow("Moteur physique Particule");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(inputKeyBoard);

    // enter GLUT event processing loop
    glutMainLoop();

    return 1;
}

void t1() {
    if (r1.getPosition().getX() > r2.getPosition().getX()) 
	{ 
		r1.addForce(Vecteur3D(-0.1, 0, 0));
		r1.setRotation(Vecteur3D(0, 0, 1));

		r2.addForce(Vecteur3D(0.1, 0, 0));
        r2.setRotation(Vecteur3D(0, 0, -1));
	}

    r1.integrate(deltaFrame);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(r1.getPosition().getX(), r1.getPosition().getY(), r1.getPosition().getZ());
    std::cout << "x : " << r1.getPosition().getX() << std::endl;
    std::cout << "y : " << r1.getPosition().getY() << std::endl;
    glRotated(0.2 * i, r1.getRotation().getX(), r1.getRotation().getY(), r1.getRotation().getZ());
    glColor3f(1.0, 1.0, 0);

    glBegin(GL_QUADS);
    glVertex3f(-2, -2, 0.0);
    glVertex3f(-2, 2, 0.0);
    glVertex3f(2, 2, 0.0);
    glVertex3f(2, -2, 0.0);
    glEnd();

    glPopMatrix();
    glFlush();

    glutPostRedisplay();
    glutSwapBuffers();
}

void t2()
{
    r2.integrate(deltaFrame);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(r2.getPosition().getX(), r2.getPosition().getY(), r2.getPosition().getZ());
    std::cout << "x : " << r2.getPosition().getX() << std::endl;
    std::cout << "y : " << r2.getPosition().getY() << std::endl;
    glRotated(0.2 * i, r2.getRotation().getX(), r2.getRotation().getY(), r2.getRotation().getZ());
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    glVertex3f(-2, -2, 0.0);
    glVertex3f(-2, 2, 0.0);
    glVertex3f(2, 2, 0.0);
    glVertex3f(2, -2, 0.0);
    glEnd();

    glPopMatrix();
    glFlush();

    glutPostRedisplay();
    glutSwapBuffers();
}