/// ----------------------------------------
///  CG基礎第3回課題
/// ----------------------------------------

// @date 2014-10-07
// @author Kazuma Ito

#include <stdio.h>
#include <GL/glut.h>

// ---------- 定数 ----------

// 画面サイズ
const int SIZE_X = 700;
const int SIZE_Y = 500;
// 画面出現座標
const int SPAWN_X = 70;
const int SPAWN_Y = 100;

// ESCキー
#define KEY_ESC 27

// ---------- 関数プロト宣言 ----------

void Display();
void Init(char *progname);
void MyKeyboard(unsigned char key, int x, int y);

// --------------------

// 描画関数
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // 赤い三角形
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(-0.9, 0.9);
        glVertex2d(0.0, 0.0);
        glVertex2d(0.9, 0.9);
    glEnd();

    // 緑の三角形
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(-0.9, -0.9);
        glVertex2d(0.0, 0.0);
        glVertex2d(0.9, -0.9);
    glEnd();

    glFlush();
}

// 初期設定関数
void Init(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitWindowPosition(SPAWN_X, SPAWN_Y);
    glutCreateWindow(progname);
    // 背景を灰色
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutKeyboardFunc(MyKeyboard);
}

// キー関数
void MyKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC){
        exit(0);
    }
}

// メイン関数
int main(int argc, char *argv[]){
    // ■初期化
    glutInit(&argc, argv);
    Init("CGBasic Subject02");

    // ■メイン処理
    glutDisplayFunc(Display);
    glutMainLoop();

    return 0;
}