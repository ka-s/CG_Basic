/// ================================
///  CG��b��4�񉉏K�ۑ�
/// ================================

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
    // �`�悷����W
    double a = 0.25, z1 = -2.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ���ԐF�̎l�p�`��`��
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3d(-a, -a, z1);
        glVertex3d(a, -a, z1);
        glVertex3d(a, a, z1);
        glVertex3d(-a, a, z1);
    glEnd();

    // ���􉽕ϊ�
    glTranslated(0.2, 0.1, 0.2);
    glRotated(30, 0.0, 0.0, 1.0);
    glScaled(2.0, 0.5, 1.0);

    // ���F�̎l�p�`��`��
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3d(-a, -a, z1);
        glVertex3d(a, -a, z1);
        glVertex3d(a, a, z1);
        glVertex3d(-a, a, z1);
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
    gluPerspective(60.0, aspect, 0.1, 7.0);
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