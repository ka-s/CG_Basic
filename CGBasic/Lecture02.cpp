/// ----------------------------------------
///  CG基礎第2回課題
/// ----------------------------------------

// @date 2014-09-30
// @author Kazuma Ito

#include <stdio.h>
#include <GL/glut.h>

// ---------- 定数 ----------

// 画面サイズ
const int SIZE_X = 640;
const int SIZE_Y = 480;

// --------------------------


// 描画関数
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// 初期設定関数
void Init(){
    // 灰色
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
}

// メイン関数
int main(int argc, char *argv[]){
    // ■初期化
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("CGBasic Subject02");

    // ■メイン処理
    glutDisplayFunc(Display);
    Init();
    glutMainLoop();

    return 0;
}