/// ----------------------------------------
///  CG��b��2��ۑ�
/// ----------------------------------------

// @date 2014-09-30
// @author Kazuma Ito

#include <stdio.h>
#include <GL/glut.h>

// ---------- �萔 ----------

// ��ʃT�C�Y
const int SIZE_X = 640;
const int SIZE_Y = 480;

// --------------------------


// �`��֐�
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// �����ݒ�֐�
void Init(){
    // �D�F
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
}

// ���C���֐�
int main(int argc, char *argv[]){
    // ��������
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(SIZE_X, SIZE_Y);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("CGBasic Subject02");

    // �����C������
    glutDisplayFunc(Display);
    Init();
    glutMainLoop();

    return 0;
}