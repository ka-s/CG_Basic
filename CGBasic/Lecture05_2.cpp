/// ================================
///  CG基礎第5回追加課題 
/// ================================

// @date    2014-10-28
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

    // 青色の球
    glPushMatrix();
    glTranslated(-1.0, 0.0, -5.0);
    glColor3d(0.0, 0.0, 1.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // 黄色の球
    glPushMatrix();
    glTranslated(-0.5, -0.5, -5.3);
    glColor3d(1.0, 1.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // 黒色の球
    glPushMatrix();
    glTranslated(0.0, 0.0, -5.6);
    glColor3d(0.0, 0.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // 緑色の球
    glPushMatrix();
    glTranslated(0.5, -0.5, -5.9);
    glColor3d(0.0, 1.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // 赤色の球
    glPushMatrix();
    glTranslated(1.0, 0.0, -6.2);
    glColor3d(1.0, 0.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
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
    // 背景を白に設定
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
