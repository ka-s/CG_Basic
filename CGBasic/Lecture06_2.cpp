/// ================================
///  CGîbć6ńKŰč 
/// ================================

// @date    2014-11-04
// @author  Kazuma Ito

#include <stdlib.h>
#include <GL/glut.h>
#define KEY_ESC 27

void myKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC)
        exit(0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ĄÔĚşĚŞ
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(2.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // ĄÔĚăĚŞ
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glTranslated(0.0, 0.5, 0.0);
    glScaled(1.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // ĄÔĚ^C
    //   ăÖ
    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(0.5, -0.5, 0.4);
    glScaled(0.08, 0.08, 0.08);
    glutSolidTorus(1.0, 4.0, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(0.5, -0.5, -0.4);
    glScaled(0.08, 0.08, 0.08);
    glutSolidTorus(1.0, 4.0, 32, 32);
    glPopMatrix();

    //   OÖ
    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(-0.5, -0.5, 0.4);
    glScaled(0.08, 0.08, 0.08);
    glutSolidTorus(1.0, 4.0, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(-0.5, -0.5, -0.4);
    glScaled(0.08, 0.08, 0.08);
    glutSolidTorus(1.0, 4.0, 32, 32);
    glPopMatrix();

    glDisable(GL_DEPTH_TEST);
    glFlush();
}

void myInit(char *progname){
    int width = 500, height = 500;
    double aspect = (double)width / (double)height;

    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(progname);
    // wiđÉÝč
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 1.0, 20.0);
    // JĚÝč
    gluLookAt(
        2.0, 1.0, 4.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
