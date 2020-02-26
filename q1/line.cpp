#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void display();
void init();
void reshape(int,int);
void timer(int);
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Line");
    display();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}
int sx=-50,sy=-50,ex=50,ey=50;
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //draw
    int dx = ex - sx;
    int dy = abs(ey - sy);
    int d = 2 * dy - dx;
    int Est = 2 * dy;
    int NorEst = 2 * (dy - dx);
    int x = sx;
    int y = sy;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    while (x < ex)
    {
        if (d <= 0)
            d += Est;
        else
        {
            d += NorEst;
            y += 1;
        }
        x += 1;
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

     glutSwapBuffers();
}

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
    glMatrixMode(GL_MODELVIEW);
}