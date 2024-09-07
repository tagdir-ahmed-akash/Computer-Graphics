
/*****************************************************************************
        FILE : submit.c (311170030 2023-2024 Assignment 1)
        NOTE : you have to implement functions in this file
*****************************************************************************/
/*****************************************************************************
        Student Information
        Student ID:2021521460115
        Student Name:MD AKASH HOSSAIN
*****************************************************************************/

#include <GL/freeglut.h>
#include <math.h>

float shapeAngles[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
float shapeScales[5] = { 1.0, 1.0, 1.0, 1.0, 1.0 };
float shapeTranslationsX[5] = { -0.6, -0.3, 0.0, 0.3, 0.6 }; // X positions for each shape
float shapeTranslationsY[5] = { 0.3, 0.3, 0.3, 0.3, 0.3 };    // Y positions for each shape

void drawShape(int index) {
    glPushMatrix();
    glTranslatef(shapeTranslationsX[index], shapeTranslationsY[index], 0.0);
    glRotatef(shapeAngles[index], 0.0, 0.0, 1.0);
    glScalef(shapeScales[index], shapeScales[index], 1.0);

    if (index == 0) {
        // Triangle
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.1, 0.0);
        glVertex2f(0.1, 0.0);
        glVertex2f(0.0, 0.2);
        glEnd();
    }
    else if (index == 1) {
        // Square
        glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.1, -0.1);
        glVertex2f(0.1, -0.1);
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.1, 0.1);
        glEnd();
    }
    else if (index == 2) {
        // Circle
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0, 0.0, 1.0);
        for (int i = 0; i < 360; i += 10) {
            float angle = i * 3.14159265 / 180.0;
            float x = 0.1 * cos(angle);
            float y = 0.1 * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
    else if (index == 3) {
        // Pentagon
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
        for (int i = 0; i < 5; i++) {
            float angle = i * 2 * 3.14159265 / 5;
            float x = 0.1 * cos(angle);
            float y = 0.1 * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
    else if (index == 4) {
        // Line
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 1.0);
        glVertex2f(-0.1, 0.0);
        glVertex2f(0.1, 0.0);
        glEnd();
    }

    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < 5; i++) {
        drawShape(i);
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        shapeAngles[0] += 5.0;
        break;
    case '2':
        shapeScales[0] *= 1.1;
        break;
    case '3':
        shapeTranslationsX[0] += 0.05;
        break;
    case '4':
        shapeTranslationsY[0] += 0.05;
        break;
    case '5':
        shapeAngles[1] += 5.0;
        break;
    case '6':
        shapeScales[1] *= 1.1;
        break;
    case '7':
        shapeTranslationsX[1] += 0.05;
        break;
    case '8':
        shapeTranslationsY[1] += 0.05;
        break;
    case '9':
        shapeAngles[2] += 5.0;
        break;
    case '0':
        shapeScales[2] *= 1.1;
        break;
    case 'q':
        shapeTranslationsX[2] += 0.05;
        break;
    case 'w':
        shapeTranslationsY[2] += 0.05;
        break;
    case 'e':
        shapeAngles[3] += 5.0;
        break;
    case 'r':
        shapeScales[3] *= 1.1;
        break;
    case 't':
        shapeTranslationsX[3] += 0.05;
        break;
    case 'y':
        shapeTranslationsY[3] += 0.05;
        break;
    case 'u':
        shapeAngles[4] += 5.0;
        break;
    case 'i':
        shapeScales[4] *= 1.1;
        break;
    case 'o':
        shapeTranslationsX[4] += 0.05;
        break;
    case 'p':
        shapeTranslationsY[4] += 0.05;
        break;
    }

    glutPostRedisplay();
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height) {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Shapes");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
