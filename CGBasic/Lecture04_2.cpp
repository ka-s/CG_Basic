/// ================================
///  CGξbζ4ρΗΑΫθ 
/// ================================

#include <stdio.h>
#include <GL/glut.h>
#define KEY_ESC 27

// -------- Φvg^CvιΎ --------
void myKeyboard(unsigned char key, int x, int y);
void display();
void myInit(char *progname);
int main(int argc, char *argv[]);
// --------------------------------------

// L[όΝΦAΦ
void myKeyboard(unsigned char key, int x, int y) {
    // ESCπ·ΖIΉ
    if (key == KEY_ESC){
        exit(0);
    }
}

// `ζΦ
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ‘ΤFΜOp`π`ζ
    glColor3d(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex3d(0.0, 0.5, 0.0);
        glVertex3d(-0.5, -0.5, 0.0);
        glVertex3d(0.5, -0.5, 0.0);
    glEnd();

    // ‘τ½Ο·
    glTranslated(0.1, 0.2, 0.3);
    glRotated(30, 0.0, 0.0, 1.0);
    glScaled(0.5, 0.6, 0.7);

    // ‘ψF(?)Μάp`π`ζ
    glBegin(GL_POLYGON);
        glColor3d(1.0, 0.0, 0.0);
        glVertex3d(0.0, 0.8, -3.0);

        glColor3d(0.5, 0.5, 0.0);
        glVertex3d(-0.8, 0.5, -3.0);

        glColor3d(0.0, 1.0, 0.0);
        glVertex3d(-0.5, -0.5, -3.0);

        glColor3d(0.0, 0.5, 0.5);
        glVertex3d(0.5, -0.5, -3.0);

        glColor3d(0.0, 0.0, 1.0);
        glVertex3d(0.8, 0.5, -3.0);
    glEnd();

    // ‘τ½Ο·
    glTranslated(0.0, 0.0, 0.0);
    glRotated(0, 0.0, 0.0, 0.0);
    glScaled(1.0, 1.0, 1.0);

    // ‘ΞFΜOp`π`ζ
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex3d(0.0, 0.5, 8.0);
        glVertex3d(-0.5, -0.5, 8.0);
        glVertex3d(0.5, -0.5, 8.0);
    glEnd();

    glFlush();
}

// ϊ»Φ
void myInit(char *progname) {
    int width = 500, height = 500;
    double aspect = (double)width / (double)height;

    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(progname);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // ½se
    glOrtho(-1.0, 1.0 ,-1.0 , 1.0, 0.1, 7.0);
}

// -------- CΦ --------
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
// ----------------------------