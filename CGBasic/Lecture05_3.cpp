/// ================================
///  CGŠî‘b‘æ5‰ñ’Ç‰Á‰Û‘è‚Ì’Ç‰Á
/// ================================

// @date    2014-10-28
// @author  Kazuma Ito

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define KEY_ESC 27
const double Pi = 3.14;

void Circle2D(double radius, int x, int y){
    for (int i = 0; i <= 360; ++i){
        double th2 = (double)i + 10;
        double i_rad = (double)i / 180.0 * Pi;
        double th2_rad = th2 / 180.0 * Pi;

        double x1 = radius * cos(i_rad);
        double y1 = radius * sin(i_rad);
        double x2 = radius * cos(th2_rad);
        double y2 = radius * sin(th2_rad);

        glBegin(GL_LINES);
        glVertex2f(x1 + x, y1 + y);
        glVertex2f(x2 + x, y2 + y);
        glEnd();
    }
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

    // ÂF‚Ì—Ö
    glPushMatrix();
    glTranslated(-1.0, 0.0, -5.0);
    glColor3d(0.0, 0.0, 1.0);
    Circle2D(0.5, 0, 0);
    glPopMatrix();

    // ‰©F‚Ì—Ö
    glPushMatrix();
    glTranslated(-0.5, -0.5, -5.0);
    glColor3d(1.0, 1.0, 0.0);
    Circle2D(0.5, 0, 0);
    glPopMatrix();

    // •F‚Ì—Ö
    glPushMatrix();
    glTranslated(0.0, 0.0, -5.0);
    glColor3d(0.0, 0.0, 0.0);
    Circle2D(0.5, 0, 0);
    glPopMatrix();

    // —ÎF‚Ì—Ö
    glPushMatrix();
    glTranslated(0.5, -0.5, -5.0);
    glColor3d(0.0, 1.0, 0.0);
    Circle2D(0.5, 0, 0);
    glPopMatrix();

    // ÔF‚Ì—Ö
    glPushMatrix();
    glTranslated(1.0, 0.0, -5.0);
    glColor3d(1.0, 0.0, 0.0);
    Circle2D(0.5, 0, 0);
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
    // ”wŒi‚ð”’‚ÉÝ’è
    glClearColor(1.0, 1.0, 1.0, 1.0);
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
