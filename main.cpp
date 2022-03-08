#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Lib(pict).h" //  библиотека
float pos_x = 0.69, pos_y = -5.99, Scc = 0;
// блок объ€влений функций
void renderScene(void);
bool isVictory = false;
bool isDeaf = false;
bool isGetApple[3] = { false,false,false};
bool isOpenDoor[3] = { false, false, false };
bool isVictory1 = false;
// блок реализации функций

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
	glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функци€ должна быть первой в renderScene
       glPushMatrix();
    drawTera(); // прогружаем первый слой сцены
 
    drawExcit();//прогружаем точку выхода
    if (!isVictory)
    drawCat(pos_x, pos_y ,0);// прогуружаем персонажа
    
    
    if (isGetApple[0])
        drawApple( .7, .9);
    if (isGetApple[1])
        drawApple(.8, .9);
    if (isGetApple[2])
        drawApple(.9, .9);
    if (!isOpenDoor[1])
        drawDoor(0, 0);
    if (!isOpenDoor[0])
        drawDoor(-.5, 0);
    if (!isOpenDoor[2])
        drawDoor(.5, 0);
    if (isVictory)
        drawViktory();
    glutSwapBuffers(); // эта функци€ должна быть последний в renderScene
}

void processKeys(unsigned char key, int x, int y) {

    if (key == 113)
        exit(0); // close app закрываетс€ на Q
    if (key == 100) {
        pos_x = pos_x + 0.1;//вправо на D

    }
    if (key == 97) {
        pos_x = pos_x - 0.1;//влево на A

    }

    if (key == 119) {
        pos_y = pos_y + 0.1;//вверх на W

    }
    if (key == 115) {
        pos_y = pos_y - 0.1;//вниз на S

    }
    if (Scc ==3)
        isVictory = true, 
        isGetApple[0] = { true },
        isGetApple[1] = { true },
        isGetApple[2] = { true };
   
    if (Scc == -1)
        Scc = 0;

   if (Scc==1)
       isGetApple[0] = { true };
   if (Scc == 2)
       isGetApple[0] = { true }, isGetApple[1] = { true };
 
    if ((pos_x >= -1.31) && (pos_x <= 1.29) && (pos_y >= -1.29) && (pos_y <= 3.3))
        Scc+=1,pos_x = 0.69, pos_y = -5.99;
    if (((pos_x >= 1.99) && (pos_x <= 4.5) && (pos_y >= -1.29) && (pos_y <= 3.3))
     || ((pos_x >= -4.55) && (pos_x <=-1.99) && (pos_y >= -1.29) && (pos_y <= 3.3)))
        Scc = 0, pos_x = 0.69, pos_y = -5.99,
        isGetApple[0] = { false },
        isGetApple[1] = { false },
        isGetApple[2] = { false };;
       
    glutPostRedisplay(); // отрисовка
}
