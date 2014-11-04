/// ================================
///  CG基礎第6回演習課題 
/// ================================

// @date    2014-11-04
// @author  Kazuma Ito

#include <stdlib.h>
#include <GL/glut.h>
#define KEY_ESC 27

// 点の配列
double vertex[][3] = {
    { 0.0, 0.0, 0.0 },
    { 1.0, -1.0, 1.0 },
    { 1.0, -1.0, -1.0 },
    { -1.0, -1.0, -1.0 },
    { -1.0, -1.0, 1.0 },
};

// 線分のベクトル
int edge[][2] = {
    { 0, 1 },
    { 0, 2 },
    { 0, 3 },
    { 0, 4 },
    { 1, 2 },
    { 2, 3 },
    { 3, 4 },
    { 4, 1 },
};

void myKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC)
        exit(0);
}

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

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // 軸の描画
    xyzAxes();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 頂点と線分からのピラミッド
    glPushMatrix();
    //   色は白
    glColor3d(1.0, 1.0, 1.0);
    //   Y方向に平行移動
    glTranslated(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; ++i){
        glVertex3dv(vertex[edge[i][0]]);
        glVertex3dv(vertex[edge[i][1]]);
    }
    glEnd();
    glPopMatrix();

    // 黄色の中身が詰まった円錐
    glPushMatrix();
    //   色は黄色
    glColor3d(1.0, 1.0, 0.0);
    //   X方向に平行移動
    glTranslated(2.0, 0.0, 0.0);
    //   コーンのとんがりが上になるように回転
    glRotated(-90, 1.0, 0.0, 0.0);
    glutSolidCone(1.0, 2.0, 16.0, 16.0);
    glPopMatrix();

    // 円錐の上に紫の中身が詰まったドーナツをかぶる
    glPushMatrix();
    //   色は紫
    glColor3d(0.63, 0.13, 0.94);
    //   コーンに被るように平行移動
    glTranslated(2.0, 1.5, 0.0);
    //   被れるように回転
    glRotated(90, 1.0, 0.0, 0.0);
    //   縮小する
    glScaled(0.3, 0.3, 0.3);
    glutSolidTorus(1.0, 4.0, 16.0, 16.0);
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
    // 背景を黒に設定
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 1.0, 20.0);
    // カメラの設定
    gluLookAt(
        2.0, 4.0, 4.0,
        1.5, 0.0, 0.0, 
        0.0, 1.0, 0.0);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
