#include<iostream>
#include<GL/glut.h>
using namespace std;

void Init()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(0, 1, 0);
    gluOrtho2D(0, 640, 0, 480);
    glClear(GL_COLOR_BUFFER_BIT);
}


int sign(float a) {


    if (a == 0) {
        return 0;
    }
    if (a > 0) {

        return 1;
    }
    return -1;

}
void B_Line(int x_1, int y_1, int x_2, int y_2) {

    float dy, dx, m, P;
    dy = y_2 - y_1;
    dx = x_2 - x_1;

    m = dy / dx;

    P = 2 * dy - dx;

    int x = x_1, y = y_1;
    if (m < 1) {
        int cnt = 1;
        for (int i = 0; i <= dx;i++) {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            if (P < 0) {

                x = x + 1;
                y = y;
                P = P + 2 * dy;
            }
            else {

                x = x + 1;
                y = y + 1;
                P = P + 2 * dy - 2 * dx;

            }
        }
    }
    else {
        int cnt = 1;
        for (int i = 0;i <= dy;i++) {

            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();

            if (P < 0) {

                x = x;
                y = y + 1;
                P = P + 2 * dx;
            }
            else {

                x = x + 1;
                y = y + 1;
                P = P + 2 * dx - 2 * dy;
            }
        }
    }
    glFlush();
}


void display()
{
    B_Line(320, 0, 320, 640);
    glFlush();
}

void mymouse(int b, int s, int x, int y)
{
    static int x_s, y_s, x_e, y_e, pt = 0;
    if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
    {
        if (pt == 0)
        {
            x_s = x;
            y_s = 480 - y;
            pt++;

            glBegin(GL_POINTS);
            glVertex2i(x_s, y_s);
            glEnd();
        }
        else
        {
            x_e = x;
            y_e = 480 - y;
            glBegin(GL_POINTS);
            glVertex2i(x_e, y_e);
            glEnd();

            B_Line(x_s, y_s, x_e, y_e);


        }


    }
    else if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
    {
        pt = 0;
    }
    glFlush();
}





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("BA-Line");
    Init();
    glutDisplayFunc(display);
    glutMouseFunc(mymouse);

    glutMainLoop();
    return 0;

}
