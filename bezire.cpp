#include <windows.h>

#include <GL/glut.h>

#include <stdlib.h>

#include <cmath>

int n=0;
int pts[4][2];

void init()
{
    glClearColor(0,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,640,0,480);
}

static void display(void)
{
    glFlush();
}

void bezier()
{

    for(float t = 0;t <= 1;t += 0.001)
    {
        float x = pts[0][0]*(pow(1-t,3)) + pts[1][0]*3*t*pow(1-t,2) + pts[2][0]*3*pow(t,2)*(1-t) + pts[3][0]*pow(t,3);
        float y = pts[0][1]*(pow(1-t,3)) + pts[1][1]*3*t*pow(1-t,2) + pts[2][1]*3*pow(t,2)*(1-t) + pts[3][1]*pow(t,3);

        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
    }
}

static void mouseHandler(int button, int state, int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        pts[n][0] = x;
        pts[n][1] = 480-y;
        n++;

        /*glBegin(GL_POINTS);
        glVertex2f(x,480-y);
        glEnd();*/

        if(n==4)
        {
            bezier();
            n=0;
        }
    }
    glFlush();
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseHandler);


    glutMainLoop();

    return EXIT_SUCCESS;
}

