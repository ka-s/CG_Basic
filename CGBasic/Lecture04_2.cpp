/// ================================
///  CG��b��4��ǉ��ۑ� 
/// ================================

// git test 3rd.

#include <stdio.h>
#include <GL/glut.h>
#define KEY_ESC 27

// -------- �֐��v���g�^�C�v�錾 --------
void myKeyboard(unsigned char key, int x, int y);
void display();
void myInit(char *progname);
int main(int argc, char *argv[]);
// --------------------------------------

// �L�[���͊֘A�֐�
void myKeyboard(unsigned char key, int x, int y) {
    // ESC�������ƏI��
    if (key == KEY_ESC){
        exit(0);
    }
}

// �`��֐�
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ���ԐF�̎O�p�`��`��
    glColor3d(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex3d(0.0, 0.5, 0.0);
        glVertex3d(-0.5, -0.5, 0.0);
        glVertex3d(0.5, -0.5, 0.0);
    glEnd();

    // ���􉽕ϊ�
    glTranslated(0.1, 0.2, 0.3);
    glRotated(30, 0.0, 0.0, 1.0);
    glScaled(0.5, 0.6, 0.7);

    // �����F(?)�̌܊p�`��`��
    glBegin(GL_POLYGON);
        glColor3d(1.0, 0.0, 0.0);
        glVertex3d(0.0, 0.8, -3.0);

        glColor3d(0.5, 0.5, 0.0);
        glVertex3d(-0.8, 0.5, -3.0);

        glColor3d(0.0, 1.0, 0.0);
        glVertex3d(-0.5, -0.5, -3.0);

        glColor3d(0.0, 0.5, 0.5);
        glVertex3d(0.5, -0.5, -3.0);

        glColor3d(0.0, 0.0, 1.0);
        glVertex3d(0.8, 0.5, -3.0);
    glEnd();

    // ���􉽕ϊ�
    glTranslated(0.0, 0.0, 0.0);
    glRotated(0, 0.0, 0.0, 0.0);
    glScaled(1.0, 1.0, 1.0);

    // ���ΐF�̎O�p�`��`��
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex3d(0.0, 0.5, 8.0);
        glVertex3d(-0.5, -0.5, 8.0);
        glVertex3d(0.5, -0.5, 8.0);
    glEnd();

    glFlush();
}

// ���������֐�
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
    // ���s���e
    glOrtho(-1.0, 1.0 ,-1.0 , 1.0, 0.1, 7.0);
}

// -------- ���C���֐� --------
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
// ----------------------------