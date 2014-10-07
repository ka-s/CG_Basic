/// ----------------------------------------
///  CG基礎第3回追加課題
/// ----------------------------------------

// @date 2014-10-07
// @author Kazuma Ito

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// ---------- 定数 ----------

// 画面サイズ
const int SIZE_X = 640;
const int SIZE_Y = 480;
// 画面出現座標
const int SPAWN_X = 70;
const int SPAWN_Y = 100;

// ESCキー
#define KEY_ESC 27

// ---------- 関数プロト宣言 ----------

void Display();
void Init(char *progname);
void MyKeyboard(unsigned char key, int x, int y);
void DrawCircle(double x, double y, double r, int accuracy);

// --------------------

// 描画関数
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // オレンジ色の三角形8個の円
    glColor3d(1.0, 0.5, 0.0);
    DrawCircle(-0.5, 0.0, 0.25, 8);

    // 紫色の三角形16個の円
    glColor3d(1.0, 0.0, 1.0);
    DrawCircle(0.5, 0.0, 0.3, 16);

    glFlush();
}

// 初期設定関数
void Init(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitWindowPosition(SPAWN_X, SPAWN_Y);
    glutCreateWindow(progname);
    // 背景を灰色
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutKeyboardFunc(MyKeyboard);
}

// キー関数
void MyKeyboard(unsigned char key, int x, int y){
    if (key == KEY_ESC){
        exit(0);
    }
}

// --------------------
//  円を描画する関数
//  x, y        : 中心座標
//  r           : 円の半径
//  accuracy    : 円の精度・ポリゴン数
// --------------------
void DrawCircle(double x, double y, double r, int accuracy){
    glBegin(GL_TRIANGLES);

    double degree = 360 / (double)accuracy;

    for (int i = 0; i < accuracy; ++i){
        glVertex2d(x, y);
        glVertex2d(
            cos(degree * i * 3.14 / 180) * r + x,
            sin(degree * i * 3.14 / 180) * r + y);
        glVertex2d(
            cos(degree * (i + 1) * 3.14 / 180) * r + x,
            sin(degree * (i + 1) * 3.14 / 180) * r + y);
    }

    glEnd();
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