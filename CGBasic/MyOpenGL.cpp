#include <iostream>
#include <GL/glut.h>

const int SIZE_X = 640;
const int SIZE_Y = 480;

struct Camera
{
    GLdouble EyeX = 0.0;
    GLdouble EyeY = 0.0;
    GLdouble EyeZ = 0.0;
    GLdouble TarX = 0.0;
    GLdouble TarY = 0.0;
    GLdouble TarZ = 0.0;
};

Camera camera;

int count = 0;

void Init();
void Display();
void Reshape(int w, int h);
void Timer(int v);

void Init(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Display(){
    // 計算
    camera.EyeX = sin(3.14 * 2 / 360 * count) * 10;
    camera.EyeY = sin(3.14 * 2 / 180 * count) * 10;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Zバッファ有効化
    glEnable(GL_DEPTH_TEST);

    // カメラ設定
    glLoadIdentity();
    gluLookAt(
        camera.EyeX, camera.EyeY, 5.0,
        camera.TarX, camera.TarY, camera.TarZ,
        0.0, 1.0, 0.0);

    // 光源の設定
    float Light0Pos[] = { 1, 1, 1, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, Light0Pos);

    // 球のマテリアル
    GLfloat gold_amb[] = { 0.24725, 0.1995, 0.0745, 1.0 };
    GLfloat gold_diff[] = { 0.75164, 0.60648, 0.22648, 1.0 };
    GLfloat gold_spe[] = { 0.628281, 0.555802, 0.366065, 1.0 };
    GLfloat gold_shin[] = { 51.2 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gold_amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gold_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gold_spe);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, gold_shin);

    // 球描画
    glutSolidSphere(0.5, 60, 60); // 通常
    //glutWireSphere(0.5, 10, 10); // ワイヤーフレーム

    glFlush();

    // フレームカウント
    count++;
}

void Reshape(int w, int h){
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int v){
    glutPostRedisplay();
    glutTimerFunc(v, Timer, 15);
}

// -------------------- メイン関数 --------------------
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("My OpenGL");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0, Timer, 17);
    Init();
    glutMainLoop();

    return 0;
}