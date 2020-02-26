#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <iostream>

/** \brief
 *
 * \return void
 *
 */
void display();
void init();
void reshape(int, int);
void timer(int);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(1024, 1024);


    glutCreateWindow("Circle");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}
float x = -10, flag = 1;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw
    float r = 100;
    float x = 0, y = r;
    float p = 1 - r;
    glBegin(GL_POINTS);

    while (x != y)
    {
        //x++;
        if (p < 0)
        {
            //std::cout << "hello" << std::endl;
            p += 2 * (x + 1) + 1;
        }
        else
        {
            //std::cout << "hello from second" << std::endl;
            y--;
            p += 2 * (x + 1) + 1 - 2 * (y - 1);
        }
        //std::cout << x << "\t" << y <<std::endl;
        glVertex2i(x, y);
        glVertex2i(-x, y);
        glVertex2i(x, -y);
        glVertex2i(-x, -y);
        glVertex2i(y, x);
        glVertex2i(-y, x);
        glVertex2i(y, -x);
        glVertex2i(-y, -x);
        if (x == y)
            break;
        x++;
    }

    glEnd();

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
    glMatrixMode(GL_MODELVIEW);
}