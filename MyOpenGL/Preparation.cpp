/// ----------------------------------------
///  CG基礎第4回予習
/// ----------------------------------------

#include <stdio.h>
#include <GL/glut.h>

// ---------- 定数 ----------

// 画面サイズ
const int SIZE_X = 640;
const int SIZE_Y = 480;
// 画面出現座標
const int SPAWN_X = 100;
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

    glPushMatrix();
    // 平行移動
    glTranslatef(0.0f, 0.0f, -3.0f);

    // ポリゴン描画
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.0f, 0.5);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.5f, -0.5f);
    glEnd();

    glPopMatrix();

    glFlush();
}

// 初期設定関数
void Init(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitWindowPosition(SPAWN_X, SPAWN_Y);
    glutCreateWindow(progname);

    // 背景色
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutKeyboardFunc(MyKeyboard);

    // カメラ
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, SIZE_X/SIZE_Y, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
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