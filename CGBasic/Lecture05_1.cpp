/// ================================
///  CG基礎第5回演習課題 
/// ================================

// @date    2014-10-28
// @author  Kazuma Ito

#include <stdlib.h>
#include <GL/glut.h>
#define KEY_ESC 27

/* 面の指定 */
int face[][4] = {
    { 0, 1, 2, 3 }, /* A-B-C-D */
    { 1, 5, 6, 2 }, /* B-F-G-C */
    { 5, 4, 7, 6 }, /* F-E-H-G */
    { 4, 0, 3, 7 }, /* E-A-B-H */
    { 4, 5, 1, 0 }, /* E-F-B-A */
    { 3, 2, 6, 7 }  /* D-C-G-H */
};

/* 色の指定 */
double col[][3] = {
    { 1.0, 0.0, 0.0 },  //　赤
    { 0.0, 1.0, 0.0 },  //　緑
    { 0.0, 0.0, 1.0 },  //　青
    { 1.0, 0.0, 1.0 },  //　マゼンタ
    { 1.0, 1.0, 0.0 },  //　黄
    { 0.0, 1.0, 1.0 }   //　シアン
};

double vertex[][3] = {
    { 0.0, 0.0, 0.0 }, /* A */
    { 1.0, 0.0, 0.0 }, /* B */
    { 1.0, 1.0, 0.0 }, /* C */
    { 0.0, 1.0, 0.0 }, /* D */
    { 0.0, 0.0, 1.0 }, /* E */
    { 1.0, 0.0, 1.0 }, /* F */
    { 1.0, 1.0, 1.0 }, /* G */
    { 0.0, 1.0, 1.0 }, /* H */
};

void myKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC)
        exit(0);
}

void display(){
    int i, j;

    // Zバッファの有効化
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslated(-0.5, -0.5, -5.0);
    glRotated(30.0, 1.0, 1.0, 0.0);

    glBegin(GL_QUADS);
    for (j = 0; j<6; j++){
        glColor3dv(col[j]);
        for (i = 0; i<4; i++){
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();

    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
    glFlush();
}

void myInit(char *progname){
    int width = 500, height = 500;
    double aspect = (double)width / (double)height;

    // Zバッファの有効化
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
