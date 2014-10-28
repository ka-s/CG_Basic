#include <stdlib.h>
#include <GL/glut.h>
#define KEY_ESC 27

/*x,y,zé≤Çï`Ç≠ä÷êî*/
void xyzAxes(){
    glBegin(GL_LINES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(1.0, 0.0, 0.0);

    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 1.0, 0.0);

    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 1.0);
    glEnd();
}

void myKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC)
        exit(0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslated(0.0, 0.0, -5.0);

    // âBñ èàóùÇÃó·ÇÃÇΩÇﬂÇ…ÉRÅ[ÉhÇí«â¡

    // îíÇÃãÖÇï`âÊ
    glColor3d(1.0, 1.0, 1.0);
    glutSolidSphere(1.0, 20, 20);

    // óŒÇÃî¬Çï`âÊ
    glRotated(-60.0, 0.0, 1.0, 0.0);
    glColor3d(0.0, 1.0, 0.0);
    glRectd(-1.0, -1.5, 1.0, 1.5);

    /* --- Ç±Ç±Ç‹Ç≈ --- */

    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
    glFlush();
}

void myInit(char *progname){
    int width = 500, height = 500;
    double aspect = (double)width / (double)height;

    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(progname);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 1.0, 20.0);

}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
