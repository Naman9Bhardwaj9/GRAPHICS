#include "GL/freeglut.h"
#include "GL/gl.h"
float _angle = 0.0f;
void drawShape()
{
    glClearColor(0.3, 0.4, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(_angle, 0.0, 0.0, 1.0); //constant value for self rotation
    glColor3f(1.0, 0.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(-0.5, 0.5, 0);
    glEnd();
    glFlush();
}

void update()
{
    _angle += 10;
    if (_angle > 360)
        _angle = 0;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 800);
    glutInitPosition(100, 100);
    glutCreateWindow("Self-Rotating Polygon");
    glutDisplayFunc(drawShape);
    glutTimerFunc(120, update, 0);
    glutMainLoop();

    return 0;
}