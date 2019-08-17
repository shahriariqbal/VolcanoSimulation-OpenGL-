#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1416
static float	tx	=  1.0;
static float	ty	=  0.0;

float tx1 = 0;
float ty1 = 30;
bool day = true;
float sx=0,sy=0;
int l=1;

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    //glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
    glOrtho(-80.0, 80.0, -80.0, 80.0, -80.0, 80.0);
}
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = rx * cosf(theta);//calculate the x component
        float y = ry * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void circle(float radius_x, float radius_y)
{
    int i=0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 200; i++)
    {
        angle = 2 * PI * i / 200;
        glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
    }

    glEnd();
}

void circle2(GLdouble rad)
{
    int i = 0;
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
    int i=0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 200;
        glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
    }

    glEnd();
}






void field()
{
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.23,0.70,0.44);
    glVertex2f(-80,0);
    glVertex2f(80,0);
    glColor3f(0.2,0.8,0.2);
    glVertex2f(80,-80);
    glVertex2f(-80,-80);
    glPopMatrix();
    glEnd();


    //mountain
    glBegin(GL_POLYGON);
    glColor3f (0.365, 0.294,0.278);
    glVertex3f(-10,20,0);
    glVertex3f(-20,8,0);
    glVertex3f(-50,-20,0);
    glVertex3f(50,-20,0);
    glVertex3f(20,8,0);
    glVertex3f(10,20,0);

    glEnd();
glLineWidth(l);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(4,20);
    glVertex2f(12,36);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(12,36);
    glVertex2f(28,4);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-4,20);
    glVertex2f(-12,36);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-12,36);
    glVertex2f(-28,4);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(6,20);
    glVertex2f(12,28);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(12,28);
    glVertex2f(18,14);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-6,20);
    glVertex2f(-12,28);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-12,28);
    glVertex2f(-18,14);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(0,20);
    glVertex2f(6,54);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(2,20);
    glVertex2f(10,40);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f (1, 0.271, 0);
    glVertex3f(-8,20,0);
    glVertex3f(-16,2,0);
    glVertex3f(-28,-10,0);
    glVertex3f(-29,-10,0);
    glVertex3f(-17,2,0);
    glVertex3f(-9,20,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (1, 0.271, 0);
    glVertex3f(-4,20,0);
    glVertex3f(-8,0,0);
    glVertex3f(-14,-8,0);
    glVertex3f(-22,-14,0);
    glVertex3f(-23,-15,0);
    glVertex3f(-13,-8,0);
    glVertex3f(-9,0,0);
    glVertex3f(-3,-20,0);
    glVertex3f(-3,20,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (1, 0.271, 0);
    glVertex3f(8,20,0);
    glVertex3f(16,2,0);
    glVertex3f(28,-10,0);
    glVertex3f(29,-10,0);
    glVertex3f(18,2,0);
    glVertex3f(9,20,0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (1, 0.271, 0);
    glVertex3f(2,20,0);
    glVertex3f(6,0,0);
    glVertex3f(8,-4,0);
    glVertex3f(4,20,0);


    glEnd();


}


void sky()
{
    glPushMatrix();

    glBegin(GL_QUADS);
    //glColor3f(0.52,0.8,1);
    if(day)
        glColor3f(0,0.749,1);
    else
        glColor3f(0.098,0.098,0.439);
    glVertex2f(-80,80);
    glVertex2f(80,80);
    glColor3f(1,1,1);
    glVertex2f(80,-80);
    glVertex2f(-80,-80);
    glPopMatrix();
    glEnd();


    glPushMatrix();                             //sun
//    glTranslatef(ss,0.0,0.0);
    glTranslatef(-20.0,40.0,0.0);
   // glScalef(1.0,1.5,0.0);
    if(day)
        glColor3f(1.0,1.0,0.0);
    else
        glColor3f(1,1,1);
    circle(10-sx,10-sy);
    glPopMatrix();
}

float p=-100.0, p2=-90;
void moving_cloud(void)
{
    float cy=50, cx=0;
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p2,cy,0);
    circle(10,10);
    glTranslatef(cx,cy,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p2+28,cy+4,0);
    circle(10,10);
    glTranslatef(cx+28,cy+4,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p2+12,cy+10,0);
    circle(14,10);
    glTranslatef(cx+12,cy+10,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p2+17,cy-5,0);
    circle(13,10);
    glTranslatef(cx+17,cy-5,0);
    glPopMatrix();
}

void moving_cloud2(void)
{
    float cy=40, cx=0;
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p
                 +5,cy,0);
    circle(7,7);
    glTranslatef(cx+5,cy,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p+4+10,cy+2,0);
    circle(7,7);
    glTranslatef(cx+4+10,cy+2,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p+2+10,cy+3,0);
    circle(7,7);
    glTranslatef(cx+2+10,cy+3,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(cx+p+1+10,cy-2,0);
    circle(7,7);
    glTranslatef(cx+1+10,cy-2,0);
    glPopMatrix();
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    sky();

    if(p<=90.0)
        p=p+0.03;
    else
        p=-100;
    if(p2<=90.0)
        p2=p2+0.04;
    else
        p2=-100;

    glutPostRedisplay();

    glPushMatrix();
    moving_cloud();
    moving_cloud2();
    glPopMatrix();

    field();




    glFlush();
}

AnimationLava(){


l=12;

}

AnimationLava2()
{
   l=1;
}

void  my_keyboard(unsigned char key, int x, int y)
{

   switch(key)
    {
    case 'd':
        day=true;
        sx=0;
        sy=0;
        break;

    case 'n':
        day=false;
        sx=5;
        sy=5;
        //night();
        //keyDisplayAnimationNight();
        break;
    case 'r':
        //spinDisplay();
       break;

    case 'a':

        AnimationLava();
      break;

      case 's':

        AnimationLava2();
      break;

    default:
        break;
    }
}

int main()
{

    //PlaySound("sweet_bells_2013.wav", NULL, SND_LOOP| SND_ASYNC);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 900);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Volcanic Eruption");
    init();
    glutDisplayFunc(display);
    //glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    //glutMouseFunc(my_mouse);
    glutMainLoop();

    return 0;
}
