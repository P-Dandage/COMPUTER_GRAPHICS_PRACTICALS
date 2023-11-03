#include <GL/glut.h>


void Init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
}


void drawHome() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);

    glVertex2i(200, 100);
    glVertex2i(600, 100);
    glVertex2i(600, 500);
    glVertex2i(200, 500);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(200, 500);
    glVertex2i(600, 500);
    glVertex2i(400, 700);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(350, 100);
    glVertex2i(450, 100);
    glVertex2i(450, 400);
    glVertex2i(350, 400);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Home Shape");
    Init();
    glutDisplayFunc(drawHome);
    glutMainLoop();

    return 0;
}
