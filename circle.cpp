#include <windows.h>

#include <GL/glut.h>

#include <stdlib.h>

#include <iostream>

#include <cmath>

using namespace std;

void init()
{
    glClearColor(0,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,640,0,480);
}

void draw_pixel(int x, int y)
{
    //glPointSize(14.0);

    //glColor3d(0,1,1);

    glBegin(GL_POINTS);

    glVertex2f(x,y);

    glEnd();
}

void midpointalgo(int x0,int y0,int x1, int y1, int r)
{
    int p = 1 - r;

    int x = 0;
    int y = r;

    int xc,yc;

    while(x <= y)
    {

        if(p < 0)
        {
            x = x + 1;
            p = p + (2*x) + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + (2*x)-(2*y) + 1;
        }

        xc = x0;
        yc = y0;

        glColor3d(1,0,0);
        draw_pixel(x+xc, y+yc);

        glColor3d(0,1,0);
        draw_pixel(y+xc, x+yc);

        glColor3d(0,1,1);
        draw_pixel(y+xc, -x+yc);

        glColor3d(1,0,1);
        draw_pixel(x+xc, -y+yc);

        glColor3d(1,1,0);
        draw_pixel(-x+xc, -y+yc);

        glColor3d(1,1,1);
        draw_pixel(-y+xc, -x+yc);

        glColor3d(1,0.5,0.3);
        draw_pixel(-y+xc, x+yc);

        glColor3d(0.5,0.9,0.9);
        draw_pixel(-x+xc, y+yc);
    }
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

int cnt=0;
int xp[50],yp[50];

static void mouseHandling(int button, int state, int x ,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

    xp[cnt] = x;
    yp[cnt] = 480 - y;

    cnt++;

    if(cnt == 2)
    {
        cnt = 0;
        int radius = sqrt(pow((xp[1]-xp[0]),2)+pow((yp[1]-yp[0]),2));
        midpointalgo(xp[0],yp[0],xp[1],yp[1],radius);
    }

    glFlush();

    }
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
    glutMouseFunc(mouseHandling);

    glClearColor(0,0,0,0);
    glCullFace(GL_BACK);

    glutMainLoop();

    return EXIT_SUCCESS;
}
