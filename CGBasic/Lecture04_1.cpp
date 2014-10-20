/// ================================
///  CG基礎第4回演習課題
/// ================================

#include <stdio.h>
#include <GL/glut.h>
#define KEY_ESC 27

// -------- 関数プロトタイプ宣言 --------
void myKeyboard(unsigned char key, int x, int y);
void display();
void myInit(char *progname);
int main(int argc, char *argv[]);
// --------------------------------------

// キー入力関連関数
void myKeyboard(unsigned char key, int x, int y) {
    // ESCを押すと終了
    if (key == KEY_ESC){
        exit(0);
    }
}

// 描画関数
void display() {
    // 描画する座標
    double a = 0.25, z1 = -2.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ■赤色の四角形を描画
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3d(-a, -a, z1);
        glVertex3d(a, -a, z1);
        glVertex3d(a, a, z1);
        glVertex3d(-a, a, z1);
    glEnd();

    // ■幾何変換
    glTranslated(0.2, 0.1, 0.2);
    glRotated(30, 0.0, 0.0, 1.0);
    glScaled(2.0, 0.5, 1.0);

    // ■青色の四角形を描画
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3d(-a, -a, z1);
        glVertex3d(a, -a, z1);
        glVertex3d(a, a, z1);
        glVertex3d(-a, a, z1);
    glEnd();

    glFlush();
}

// 初期化等関数
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
    gluPerspective(60.0, aspect, 0.1, 7.0);
}

// -------- メイン関数 --------
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
// ----------------------------