#include <windows.h> 
#include <Math.h> 
#include <GL/glut.h>  
#include<iostream>
#include <sstream>

using namespace std;
#define PI 3.14159265f

bool fullScreenMode = true;

///////////////////////////////Shoot condition Variables////////////
int score = 0;
std::stringstream  scorech;

int sh = 0;
bool shoot1 = false
	, shoot2 = false
	, shoot3 = false
	, shoot4 = false
	, shoot5 = false
	, shoot6 = false;

///////////////////////////////Meteors Variables/////////////////////

//float bx = 15, by = 15, br = ((float)rand()) / RAND_MAX * 7 - 1;
//float bx1 = -15, by1 = 15, br1 = ((float)rand()) / RAND_MAX * 7 - 1;
//float bx2 = 2, by2 = 15, br2 = ((float)rand()) / RAND_MAX * 7 - 1;

float bx = rand() % 30 + (-15)
, by = 15
//, br = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
, br = rand() % 3 + (2);

float bx1 = rand() % 30 + (-15)
, by1 = 15
//, br1 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
, br1 = rand() % 3 + (2);

float bx2 = rand() % 30 + (-15)
, by2 = 15
//, br2 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
, br2 = rand() % 3 + (2);

float bx3 = rand() % 30 + (-15)
, by3 = 15
//, br3 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
, br3 = rand() % 3 + (2);

///////////////////////////////Bullets Variables/////////////////////

float screenLeft, screenRight, screenBottom, screenTop;
float xPos = 0, yPos=-2;

float  x1ShPos = xPos, x2ShPos = xPos, x3ShPos = xPos,
       x4ShPos = xPos, x5ShPos = xPos, x6ShPos = xPos,
	   y1ShPos = -2, y2ShPos = -2, y3ShPos = -2,
	   y4ShPos = -2, y5ShPos = -2, y6ShPos = -2;

float x1BPos = xPos, y1BPos = -2,
	  x2BPos = xPos, y2BPos = -2,
	  x3BPos = xPos, y3BPos = -2,
	  x4BPos = xPos, y4BPos = -2,
	  x5BPos = xPos, y5BPos = -2,
	  x6BPos = xPos, y6BPos = -2;

/////////////////////////////////////////////////////////////////////

void renderBitmapString(float x, float y, void *font, string str)
{
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	glRasterPos2f(x, y);
	for (string::iterator c = (&str)->begin(); c != (&str)->end(); ++c)
	{
		glutBitmapCharacter(font, *c);
	}
}

void BackgroundColor() {	
	glClearColor(0, 0, 0, 0);
}

void ShipSpaceDraw() {
	//////////////////////////////SHIP////////////////////////////////////
	{
		/////////////////MainBody
		{
			//////Upper Triangle
			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);	glVertex2f(xPos, yPos - 5);
			glColor3f(1, 0, 0); glVertex2f(xPos - .25, yPos - 5.5);
			glColor3f(1, 0, 0); glVertex2f(xPos + .25, yPos - 5.5);
			glEnd();

			//////Right Canon
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1); glVertex2f(xPos + .35, yPos - 5.6);
			glColor3f(1, 1, 1); glVertex2f(xPos + .35, yPos - 6.2);
			glColor3f(1, 0, 0); glVertex2f(xPos + .45, yPos - 6.2);
			glColor3f(1, 0, 0); glVertex2f(xPos + .45, yPos - 5.6);
			glEnd();

			//////Left Canons
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1); glVertex2f(xPos - .35, yPos - 5.6);
			glColor3f(1, 1, 1); glVertex2f(xPos - .35, yPos - 6.2);
			glColor3f(1, 0, 0); glVertex2f(xPos - .45, yPos - 6.2);
			glColor3f(1, 0, 0); glVertex2f(xPos - .45, yPos - 5.6);
			glEnd();

			//////Main Body
			glBegin(GL_QUADS);
			glColor3f(1, 0, 0); glVertex2f(xPos + .25, yPos - 5.5); 
			glVertex2f(xPos - .25, yPos - 5.5); 
			glVertex2f(xPos - .25, yPos - 6.1); 
			glVertex2f(xPos + .25, yPos - 6.1);
			glEnd();

			//////Right Wing
			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0); glVertex2f(xPos + .25, yPos - 5.75);
			glColor3f(1, 1, 1); glVertex2f(xPos + .25, yPos - 6.3);
			glColor3f(1, 0, 0); glVertex2f(xPos + .75, yPos - 6.5);
			glEnd();

			//////Left Wing
			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);	glVertex2f(xPos - .25, yPos - 5.75); 
			glColor3f(1, 1, 1); glVertex2f(xPos - .25, yPos - 6.3); 
			glColor3f(1, 0, 0); glVertex2f(xPos - .75, yPos - 6.5);
			glEnd();

			//////Middle Triangle top
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .25, yPos - 6.1);
			glVertex2f(xPos - .25, yPos - 6.1); 
			glVertex2f(xPos, yPos - 5.8);
			glEnd();

			//////Middle Triangle bottom
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .25, yPos - 6.1);
			glVertex2f(xPos - .25, yPos - 6.1);
			glVertex2f(xPos, yPos - 6.5);
			glEnd();

			//////
			glBegin(GL_TRIANGLES);
			glColor3f(1, 1, 1); glVertex2f(xPos, yPos - 6.5); 
			glColor3f(1, 0, 0); glVertex2f(xPos + .25, yPos - 6.5); 
			glColor3f(1, 1, 1); glVertex2f(xPos + .25, yPos - 6.1);
			glEnd();

			//////
			glBegin(GL_TRIANGLES);
			glColor3f(1, 1, 1); glVertex2f(xPos, yPos - 6.5); 
			glColor3f(1, 0, 0); glVertex2f(xPos - .25, yPos - 6.5); 
			glColor3f(1, 1, 1); glVertex2f(xPos - .25, yPos - 6.1);
			glEnd();

			//////
			glBegin(GL_TRIANGLES);
			glColor3f(1, 1, 1); glVertex2f(xPos - .12, yPos - 6.5); glVertex2f(xPos, yPos - 6.75); glVertex2f(xPos + .12, yPos - 6.5);
			glEnd();
		}
		//////////Flames
		{
			float f12 = .8 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - .8)));
			float s12 = .49 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (.8 - .49)));
			float t12 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (.15 - 0)));

			float f1 = 1;
			float s1 = .69;
			float t1 = .15;

			//////left first flame
			glBegin(GL_TRIANGLES);
			glColor3f( f1, s1, t1);
			glVertex2f(xPos - .25, yPos - 6.5);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .5, yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .12, yPos - 6.5);
			glEnd();

			//////left second flame
			glBegin(GL_TRIANGLES);
			glColor3f(f1, s1, t1);
			glVertex2f(xPos - .25, yPos - 6.5);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .25, yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .12, yPos - 6.5);
			glEnd();

			//////left third flame
			glBegin(GL_TRIANGLES);
			glColor3f(f1, s1, t1);
			glVertex2f(xPos - .25, yPos - 6.5);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .1, yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .12, yPos - 6.5);
			glEnd();

			//////right first flame
			glBegin(GL_TRIANGLES);
			glColor3f(f1, s1, t1);
			glVertex2f(xPos + .25, yPos - 6.5);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .5, yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .12, yPos - 6.5);
			glEnd();

			//////right second flame
			glBegin(GL_TRIANGLES);
			glColor3f(f1, s1, t1);
			glVertex2f(xPos + .25, yPos - 6.5);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .25, yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .12, yPos - 6.5);
			glEnd();

			//////right third flame
			glBegin(GL_TRIANGLES);
			glColor3f(f1, s1, t1);
			glVertex2f(xPos + .25, yPos - 6.5);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .1, yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .12, yPos - 6.5);
			glEnd();

			//////middle flame
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);
			glVertex2f(xPos - .12, yPos - 6.7);
			glColor3f(f1, s1, t1);
			glVertex2f(xPos , yPos - 7.00);
			glColor3f(0, 0, 0);
			glVertex2f(xPos + .12, yPos - 6.7);
			glEnd();

		}
	}

	/////////////////////////////Background SPACE DOTS////////////////////////////////////
	{
		//glPointSize(1.0);
		//glColor3ub(0, 255, 0);
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int i = 1; i < 100000; i++)
		{
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			int x = rand() % -1024;
			int y = rand() % -860;

			if (i % 2 == 0)
				glVertex2i(x, y);
			else
				glVertex2i(-x, -y);
			if (i % 3 == 0)
				glVertex2i(-x, y);
			else
				glVertex2i(x, -y);
		}
	glEnd();
	}

	/////////////////////////////////////////////////////////////////////
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {

	int i;
	int triangleAmount = 15; //# of triangles used to draw circle
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  2*PI / triangleAmount)),
			y + (radius * sin(i * 2*PI / triangleAmount))
			);
	}
	glEnd();
}

/*
void BulletDraw()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); glVertex2f(x1ShPos, y1ShPos - 5); glVertex2f(x1ShPos - .25, y1ShPos - 5.5); glVertex2f(x1ShPos + .25, y1ShPos - 5.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); glVertex2f(x2ShPos, y2ShPos - 5); glVertex2f(x2ShPos - .25, y2ShPos - 5.5); glVertex2f(x2ShPos + .25, y2ShPos - 5.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); glVertex2f(x3ShPos, y3ShPos - 5); glVertex2f(x3ShPos - .25, y3ShPos - 5.5); glVertex2f(x3ShPos + .25, y3ShPos - 5.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); glVertex2f(x4ShPos, y4ShPos - 5); glVertex2f(x4ShPos - .25, y4ShPos - 5.5); glVertex2f(x4ShPos + .25, y4ShPos - 5.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); glVertex2f(x5ShPos, y5ShPos - 5); glVertex2f(x5ShPos - .25, y5ShPos - 5.5); glVertex2f(x5ShPos + .25, y5ShPos - 5.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); glVertex2f(x6ShPos, y6ShPos - 5); glVertex2f(x6ShPos - .25, y6ShPos - 5.5); glVertex2f(x6ShPos + .25, y6ShPos - 5.5);
	glEnd();
}
*/

void BulletDrawV2()
{
	{
		//////Right Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x1BPos + .35, y1BPos - 5.6);
		glVertex2f(x1BPos + .35, y1BPos - 5.9);
		glVertex2f(x1BPos + .45, y1BPos - 5.9);
		glVertex2f(x1BPos + .45, y1BPos - 5.6);
		glEnd();

		//////Left Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x1BPos - .35, y1BPos - 5.6);
		glVertex2f(x1BPos - .35, y1BPos - 5.9);
		glVertex2f(x1BPos - .45, y1BPos - 5.9);
		glVertex2f(x1BPos - .45, y1BPos - 5.6);
		glEnd();
	}
	{
		//////Right Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x2BPos + .35, y2BPos - 5.6);
		glVertex2f(x2BPos + .35, y2BPos - 5.9);
		glVertex2f(x2BPos + .45, y2BPos - 5.9);
		glVertex2f(x2BPos + .45, y2BPos - 5.6);
		glEnd();

		//////Left Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x2BPos - .35, y2BPos - 5.6);
		glVertex2f(x2BPos - .35, y2BPos - 5.9);
		glVertex2f(x2BPos - .45, y2BPos - 5.9);
		glVertex2f(x2BPos - .45, y2BPos - 5.6);
		glEnd();
	}
	{
		//////Right Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x3BPos + .35, y3BPos - 5.6);
		glVertex2f(x3BPos + .35, y3BPos - 5.9);
		glVertex2f(x3BPos + .45, y3BPos - 5.9);
		glVertex2f(x3BPos + .45, y3BPos - 5.6);
		glEnd();

		//////Left Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x3BPos - .35, y3BPos - 5.6);
		glVertex2f(x3BPos - .35, y3BPos - 5.9);
		glVertex2f(x3BPos - .45, y3BPos - 5.9);
		glVertex2f(x3BPos - .45, y3BPos - 5.6);
		glEnd();
	}
	{
		//////Right Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x4BPos + .35, y4BPos - 5.6);
		glVertex2f(x4BPos + .35, y4BPos - 5.9);
		glVertex2f(x4BPos + .45, y4BPos - 5.9);
		glVertex2f(x4BPos + .45, y4BPos - 5.6);
		glEnd();

		//////Left Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x4BPos - .35, y4BPos - 5.6);
		glVertex2f(x4BPos - .35, y4BPos - 5.9);
		glVertex2f(x4BPos - .45, y4BPos - 5.9);
		glVertex2f(x4BPos - .45, y4BPos - 5.6);
		glEnd();
	}
	{
		//////Right Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x5BPos + .35, y5BPos - 5.6);
		glVertex2f(x5BPos + .35, y5BPos - 5.9);
		glVertex2f(x5BPos + .45, y5BPos - 5.9);
		glVertex2f(x5BPos + .45, y5BPos - 5.6);
		glEnd();

		//////Left Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x5BPos - .35, y5BPos - 5.6);
		glVertex2f(x5BPos - .35, y5BPos - 5.9);
		glVertex2f(x5BPos - .45, y5BPos - 5.9);
		glVertex2f(x5BPos - .45, y5BPos - 5.6);
		glEnd();
	}
	{
		//////Right Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x6BPos + .35, y6BPos - 5.6);
		glVertex2f(x6BPos + .35, y6BPos - 5.9);
		glVertex2f(x6BPos + .45, y6BPos - 5.9);
		glVertex2f(x6BPos + .45, y6BPos - 5.6);
		glEnd();

		//////Left Canon
		glBegin(GL_QUADS);
		glColor3f(.8, .8, 0);
		glVertex2f(x6BPos - .35, y6BPos - 5.6);
		glVertex2f(x6BPos - .35, y6BPos - 5.9);
		glVertex2f(x6BPos - .45, y6BPos - 5.9);
		glVertex2f(x6BPos - .45, y6BPos - 5.6);
		glEnd();
	}
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	/*if (score >= 5) 
		BulletDraw();*/	

	BulletDrawV2();
	
	ShipSpaceDraw();

	drawFilledCircle(bx, by, br);
	drawFilledCircle(bx1, by1, br1);
	drawFilledCircle(bx2, by2, br2);
	drawFilledCircle(bx3, by3, br3);

	std::string numberAsString = std::to_string(score);
	renderBitmapString(-17, 9, GLUT_BITMAP_TIMES_ROMAN_24, "Score = ");
	renderBitmapString(-15, 9, GLUT_BITMAP_TIMES_ROMAN_24, numberAsString);

	glutSwapBuffers();
}

void reshape(int width, int height) {
	if (height == 0) height = 1;
	float ratio = (float)width / height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height) {
		screenLeft = -10 * ratio;
		screenRight = 10 * ratio;
		screenBottom = -10;
		screenTop = 10;
	}
	else {
		screenLeft = -10;
		screenRight = 10;
		screenBottom = -10 * ratio;
		screenTop = 10 / ratio;
	}
	gluOrtho2D(screenLeft, screenRight,
		screenBottom, screenTop);
	/*ballXMin = screenLeft + ballRadius;
	ballXMax = screenRight - ballRadius;
	ballYMin = screenBottom + ballRadius;
	ballYMax = screenTop - ballRadius;*/
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;

	case 'a':
		if (xPos > screenLeft + 1) {
			xPos -= 0.5f;
			//glutPostRedisplay();
			/*if (yShPos == 0)
				xShPos -= .5f;*/
		}
		else
			xPos = xPos;
		break;

	case 'd':
		if (xPos < screenRight - 1) {
			xPos += 0.5f;
			/*if (yShPos == 0)
				xShPos += .5f;*/
		}
		else
			xPos = xPos;
		break;

	case 32:
		sh++;
		cout << sh << endl;
		if (sh == 7)
			sh = 1;
		switch (sh)
		{
		case 1:
			shoot1 = 1;
			break;
		case 2:
			shoot2 = 1;
			break;
		case 3:
			shoot3 = 1;
			break;
		case 4:
			shoot4 = 1;
			break;
		case 5:
			shoot5 = 1;
			break;
		case 6:
			shoot6 = 1;
			break;
		default:
			break;
		}
		break;
	}
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (xPos < screenRight - 1)
			xPos += 0.5f;
		else
			xPos = xPos;
		break;

	case GLUT_KEY_LEFT:
		if (xPos > screenLeft + 1)
			xPos -= 0.5f;
		else
			xPos = xPos;
		break;

	case GLUT_KEY_F1:
		fullScreenMode = !fullScreenMode;
		if (fullScreenMode) {
			glutFullScreen();
		}
		else {
			glutReshapeWindow(GetSystemMetrics(SM_CXSCREEN) / 2,
				GetSystemMetrics(SM_CYSCREEN) / 2);
			glutPositionWindow(GetSystemMetrics(SM_CXSCREEN) / 4,
				GetSystemMetrics(SM_CYSCREEN) / 4);
		}
		break;
	}
}

void timer(int v) {
	/*if (score == 5)
		shoot1 = shoot2 = shoot3 = shoot4 = shoot5 = shoot6 = 0;*/
	
	////////////////////////Meteor////////////////////////////////////////
	{
	bx -= .15;
	by -= .2;
	if (bx < screenLeft || by < screenBottom) {
		bx = rand() % 30 + (-15);
		by = 15;
		//br = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		 br = rand() % 3 + (2);
	}
	if (((x1BPos + .35 - bx)*(x1BPos + .35 - bx) + (y1BPos - 5.7 - 5 - by)*(y1BPos - 5.7 - 5 - by)) <= br*br ||
		((x2BPos + .35 - bx)*(x2BPos + .35 - bx) + (y2BPos - 5.7 - 5 - by)*(y2BPos - 5.7 - 5 - by)) <= br*br ||
		((x3BPos + .35 - bx)*(x3BPos + .35 - bx) + (y3BPos - 5.7 - 5 - by)*(y3BPos - 5.7 - 5 - by)) <= br*br ||
		((x4BPos + .35 - bx)*(x4BPos + .35 - bx) + (y4BPos - 5.7 - 5 - by)*(y4BPos - 5.7 - 5 - by)) <= br*br ||
		((x5BPos + .35 - bx)*(x5BPos + .35 - bx) + (y5BPos - 5.7 - 5 - by)*(y5BPos - 5.7 - 5 - by)) <= br*br ||
		((x6BPos + .35 - bx)*(x6BPos + .35 - bx) + (y6BPos - 5.7 - 5 - by)*(y6BPos - 5.7 - 5 - by)) <= br*br ||

		((x1BPos - .35 - bx)*(x1BPos - .35 - bx) + (y1BPos - 5.7 - 5 - by)*(y1BPos - 5.7 - 5 - by)) <= br*br ||
		((x2BPos - .35 - bx)*(x2BPos - .35 - bx) + (y2BPos - 5.7 - 5 - by)*(y2BPos - 5.7 - 5 - by)) <= br*br ||
		((x3BPos - .35 - bx)*(x3BPos - .35 - bx) + (y3BPos - 5.7 - 5 - by)*(y3BPos - 5.7 - 5 - by)) <= br*br ||
		((x4BPos - .35 - bx)*(x4BPos - .35 - bx) + (y4BPos - 5.7 - 5 - by)*(y4BPos - 5.7 - 5 - by)) <= br*br ||
		((x5BPos - .35 - bx)*(x5BPos - .35 - bx) + (y5BPos - 5.7 - 5 - by)*(y5BPos - 5.7 - 5 - by)) <= br*br ||
		((x6BPos - .35 - bx)*(x6BPos - .35 - bx) + (y6BPos - 5.7 - 5 - by)*(y6BPos - 5.7 - 5 - by)) <= br*br)
	{
		bx = rand() % 30 + (-15);
		by = 15;
		//br = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		 br = rand() % 3 + (2);
		score++;
		
	}
	/////////////////////////.
	bx1 += .15;
	by1 -= .2;
	if (bx1 > screenRight || by1 < screenBottom) {
		bx1 = rand() % 30 + (-15);
		by1 = 15;
		//br1 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		 br1 = rand() % 3 + (2);
	}
	if (((x1BPos + .35 - bx1)*(x1BPos + .35 - bx1) + (y1BPos - 5.7 - 5 - by1)*(y1BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x2BPos + .35 - bx1)*(x2BPos + .35 - bx1) + (y2BPos - 5.7 - 5 - by1)*(y2BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x3BPos + .35 - bx1)*(x3BPos + .35 - bx1) + (y3BPos - 5.7 - 5 - by1)*(y3BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x4BPos + .35 - bx1)*(x4BPos + .35 - bx1) + (y4BPos - 5.7 - 5 - by1)*(y4BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x5BPos + .35 - bx1)*(x5BPos + .35 - bx1) + (y5BPos - 5.7 - 5 - by1)*(y5BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x6BPos + .35 - bx1)*(x6BPos + .35 - bx1) + (y6BPos - 5.7 - 5 - by1)*(y6BPos - 5.7 - 5 - by1)) <= br1*br1 ||

		((x1BPos - .35 - bx1)*(x1BPos - .35 - bx1) + (y1BPos - 5.7 - 5 - by1)*(y1BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x2BPos - .35 - bx1)*(x2BPos - .35 - bx1) + (y2BPos - 5.7 - 5 - by1)*(y2BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x3BPos - .35 - bx1)*(x3BPos - .35 - bx1) + (y3BPos - 5.7 - 5 - by1)*(y3BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x4BPos - .35 - bx1)*(x4BPos - .35 - bx1) + (y4BPos - 5.7 - 5 - by1)*(y4BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x5BPos - .35 - bx1)*(x5BPos - .35 - bx1) + (y5BPos - 5.7 - 5 - by1)*(y5BPos - 5.7 - 5 - by1)) <= br1*br1 ||
		((x6BPos - .35 - bx1)*(x6BPos - .35 - bx1) + (y6BPos - 5.7 - 5 - by1)*(y6BPos - 5.7 - 5 - by1)) <= br1*br1)
	{
		bx1 = rand() % 30 + (-15);
		by1 = 15;
		//br1 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		 br1 = rand() % 3 + (2);
		score++;
	}
	////////////////////////////.
	//bx2 += .15;
	by2 -= .2;
	if (bx2 > screenRight || by2 < screenBottom) {
		bx2 = rand() % 30 + (-15);
		by2 = 15;
		//br2 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		 br2 = rand() % 3 + (2);
	}
	if (((x1BPos + .35 - bx2)*(x1BPos + .35 - bx2) + (y1BPos - 5.7 - 5 - by2)*(y1BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x2BPos + .35 - bx2)*(x2BPos + .35 - bx2) + (y2BPos - 5.7 - 5 - by2)*(y2BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x3BPos + .35 - bx2)*(x3BPos + .35 - bx2) + (y3BPos - 5.7 - 5 - by2)*(y3BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x4BPos + .35 - bx2)*(x4BPos + .35 - bx2) + (y4BPos - 5.7 - 5 - by2)*(y4BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x5BPos + .35 - bx2)*(x5BPos + .35 - bx2) + (y5BPos - 5.7 - 5 - by2)*(y5BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x6BPos + .35 - bx2)*(x6BPos + .35 - bx2) + (y6BPos - 5.7 - 5 - by2)*(y6BPos - 5.7 - 5 - by2)) <= br2*br2 ||

		((x1BPos - .35 - bx2)*(x1BPos - .35 - bx2) + (y1BPos - 5.7 - 5 - by2)*(y1BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x2BPos - .35 - bx2)*(x2BPos - .35 - bx2) + (y2BPos - 5.7 - 5 - by2)*(y2BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x3BPos - .35 - bx2)*(x3BPos - .35 - bx2) + (y3BPos - 5.7 - 5 - by2)*(y3BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x4BPos - .35 - bx2)*(x4BPos - .35 - bx2) + (y4BPos - 5.7 - 5 - by2)*(y4BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x5BPos - .35 - bx2)*(x5BPos - .35 - bx2) + (y5BPos - 5.7 - 5 - by2)*(y5BPos - 5.7 - 5 - by2)) <= br2*br2 ||
		((x6BPos - .35 - bx2)*(x6BPos - .35 - bx2) + (y6BPos - 5.7 - 5 - by2)*(y6BPos - 5.7 - 5 - by2)) <= br2*br2)
	{
		bx2 = rand() % 30 + (-15);
		by2 = 15;
		//br2 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		 br2 = rand() % 3 + (2);
		score++;
	}
	////////////////////////////.
	//bx3 += .15;
	by3 -= .2;
	if (bx3 > screenRight || by3 < screenBottom) {
		bx3 = rand() % 30 + (-15);
		by3 = 15;
		//br3 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		br3 = rand() % 3 + (2);
	}
	if (((x1BPos + .35 - bx3)*(x1BPos + .35 - bx3) + (y1BPos - 5.7 - 5 - by3)*(y1BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x2BPos + .35 - bx3)*(x2BPos + .35 - bx3) + (y2BPos - 5.7 - 5 - by3)*(y2BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x3BPos + .35 - bx3)*(x3BPos + .35 - bx3) + (y3BPos - 5.7 - 5 - by3)*(y3BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x4BPos + .35 - bx3)*(x4BPos + .35 - bx3) + (y4BPos - 5.7 - 5 - by3)*(y4BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x5BPos + .35 - bx3)*(x5BPos + .35 - bx3) + (y5BPos - 5.7 - 5 - by3)*(y5BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x6BPos + .35 - bx3)*(x6BPos + .35 - bx3) + (y6BPos - 5.7 - 5 - by3)*(y6BPos - 5.7 - 5 - by3)) <= br3*br3 ||
	
		((x1BPos - .35 - bx3)*(x1BPos - .35 - bx3) + (y1BPos - 5.7 - 5 - by3)*(y1BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x2BPos - .35 - bx3)*(x2BPos - .35 - bx3) + (y2BPos - 5.7 - 5 - by3)*(y2BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x3BPos - .35 - bx3)*(x3BPos - .35 - bx3) + (y3BPos - 5.7 - 5 - by3)*(y3BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x4BPos - .35 - bx3)*(x4BPos - .35 - bx3) + (y4BPos - 5.7 - 5 - by3)*(y4BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x5BPos - .35 - bx3)*(x5BPos - .35 - bx3) + (y5BPos - 5.7 - 5 - by3)*(y5BPos - 5.7 - 5 - by3)) <= br3*br3 ||
		((x6BPos - .35 - bx3)*(x6BPos - .35 - bx3) + (y6BPos - 5.7 - 5 - by3)*(y6BPos - 5.7 - 5 - by3)) <= br3*br3)
	{
		bx3 = rand() % 30 + (-15);
		by3 = 15;
		//br3 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
		br3 = rand() % 3 + (2);
		score++;
	}
	}
	//////////////////////////////Shooting Bullets///////////////////////
	//if (score >= 5)
	{/*
		if (shoot1 == 1)
		{
			if (y1ShPos < screenTop + 6)
				y1ShPos += .9;

			if (y1ShPos >= screenTop + 6)
			{
				y1ShPos = -2;
				x1ShPos = xPos;
				shoot1 = 0;
			}
		}
		else if (shoot1 != 1)
			x1ShPos = xPos;
		//////////
		if (shoot2 == 1)
		{
			if (y2ShPos < screenTop + 6)
				y2ShPos += .9;

			if (y2ShPos >= screenTop + 6)
			{
				y2ShPos = -2;
				x2ShPos = xPos;
				shoot2 = 0;
			}
		}
		else if (shoot2 != 1)
			x2ShPos = xPos;
		///////
		if (shoot3 == 1)
		{
			if (y3ShPos < screenTop + 6)
				y3ShPos += .9;

			if (y3ShPos >= screenTop + 6)
			{
				y3ShPos = -2;
				x3ShPos = xPos;
				shoot3 = 0;
			}
		}
		else if (shoot3 != 1)
			x3ShPos = xPos;
		/////////
		if (shoot4 == 1)
		{
			if (y4ShPos < screenTop + 6)
				y4ShPos += .9;

			if (y4ShPos >= screenTop + 6)
			{
				y4ShPos = -2;
				x4ShPos = xPos;
				shoot4 = 0;
			}
		}
		else if (shoot4 != 1)
			x4ShPos = xPos;
		/////////
		if (shoot5 == 1)
		{
			if (y5ShPos < screenTop + 6)
				y5ShPos += .9;

			if (y5ShPos >= screenTop + 6)
			{
				y5ShPos = -2;
				x5ShPos = xPos;
				shoot5 = 0;
			}
		}
		else if (shoot5 != 1)
			x5ShPos = xPos;
		///////
		if (shoot6 == 1)
		{
			if (y6ShPos < screenTop + 6)
				y6ShPos += .9;

			if (y6ShPos >= screenTop + 6)
			{
				y6ShPos = -2;
				x6ShPos = xPos;
				shoot6 = 0;
			}
		}
		else if (shoot6 != 1)
			x6ShPos = xPos;
		*/	
	}
	///////////////////////////GameOver Condtion/////////////////////////
	{
		if (((xPos - bx)*(xPos - bx) + (yPos - 5 - by)*(yPos - 5 - by)) <= br*br ||
			((xPos - bx1)*(xPos - bx1) + (yPos - 5 - by1)*(yPos - 5 - by1)) <= br1*br1 ||
			((xPos - bx2)*(xPos - bx2) + (yPos - 5 - by2)*(yPos - 5 - by2)) <= br2*br2)
		{

			if (MessageBoxA(NULL, "GameOver!!, Retry ??", "GameOver", MB_YESNO) == IDYES)
			{
				xPos = 0;
				score = 0;
				bx = 15;
				by = 15;
				br = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
				bx1 = -15;
				by1 = 15;
				br1 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
				by2 = 15;
				br2 = ((7 - 2) + 1) * (rand() / (RAND_MAX + 1.0));
			}
			else
			{
				exit(0);
			}

			


		}
		/*if (((x1ShPos - bx)*(x1ShPos - bx) + (y1ShPos - 5 - by)*(y1ShPos - 5 - by)) <= br*br 
			&& ((xPos - bx)*(xPos - bx) + (yPos - 5 - by)*(yPos - 5 - by)) <= br*br ||
			((x2ShPos - bx)*(x2ShPos - bx) + (y2ShPos - 5 - by)*(y2ShPos - 5 - by)) <= br*br 
			&& ((xPos - bx)*(xPos - bx) + (yPos - 5 - by)*(yPos - 5 - by)) <= br*br ||
			((x3ShPos - bx)*(x3ShPos - bx) + (y3ShPos - 5 - by)*(y3ShPos - 5 - by)) <= br*br 
			&& ((xPos - bx)*(xPos - bx) + (yPos - 5 - by)*(yPos - 5 - by)) <= br*br ||
			((x4ShPos - bx)*(x4ShPos - bx) + (y4ShPos - 5 - by)*(y4ShPos - 5 - by)) <= br*br 
			&& ((xPos - bx)*(xPos - bx) + (yPos - 5 - by)*(yPos - 5 - by)) <= br*br  ||
			((x5ShPos - bx)*(x5ShPos - bx) + (y5ShPos - 5 - by)*(y5ShPos - 5 - by)) <= br*br 
			&& ((xPos - bx)*(xPos - bx) + (yPos - 5 - by)*(yPos - 5 - by)) <= br*br  ||
			((x6ShPos - bx)*(x6ShPos - bx) + (y6ShPos - 5 - by)*(y6ShPos - 5 - by)) <= br*br)
		{
			MessageBox(NULL, "GameOver!!", "GameOver", MB_OK | MB_ICONEXCLAMATION);
			exit(0);
		}
		if (((x1ShPos - bx1)*(x1ShPos - bx1) + (y1ShPos - 5 - by1)*(y1ShPos - 5 - by1)) <= br1*br1 
			&& ((xPos - bx1)*(xPos - bx1) + (yPos - 5 - by1)*(yPos - 5 - by1)) <= br1*br1 ||
			((x2ShPos - bx1)*(x2ShPos - bx1) + (y2ShPos - 5 - by1)*(y2ShPos - 5 - by1)) <= br1*br1 
			&& ((xPos - bx1)*(xPos - bx1) + (yPos - 5 - by1)*(yPos - 5 - by1)) <= br1*br1 ||
			((x3ShPos - bx1)*(x3ShPos - bx1) + (y3ShPos - 5 - by1)*(y3ShPos - 5 - by1)) <= br1*br1 
			&& ((xPos - bx1)*(xPos - bx1) + (yPos - 5 - by1)*(yPos - 5 - by1)) <= br1*br1 ||
			((x4ShPos - bx1)*(x4ShPos - bx1) + (y4ShPos - 5 - by1)*(y4ShPos - 5 - by1)) <= br1*br1 
			&& ((xPos - bx1)*(xPos - bx1) + (yPos - 5 - by1)*(yPos - 5 - by1)) <= br1*br1 ||
			((x5ShPos - bx1)*(x5ShPos - bx1) + (y5ShPos - 5 - by1)*(y5ShPos - 5 - by1)) <= br1*br1 
			&& ((xPos - bx1)*(xPos - bx1) + (yPos - 5 - by1)*(yPos - 5 - by1)) <= br1*br1 ||
			((x6ShPos - bx1)*(x6ShPos - bx1) + (y6ShPos - 5 - by1)*(y6ShPos - 5 - by1)) <= br1*br1)
		{
			MessageBox(NULL, "GameOver!!", "GameOver", MB_OK | MB_ICONEXCLAMATION);
			exit(0);
		}
		if (((x1ShPos - bx2)*(x1ShPos - bx2) + (y1ShPos - 5 - by2)*(y1ShPos - 5 - by2)) <= br2*br2 
			&& ((xPos - bx2)*(xPos - bx2) + (yPos - 5 - by2)*(yPos - 5 - by2)) <= br2*br2 ||
			((x2ShPos - bx2)*(x2ShPos - bx2) + (y2ShPos - 5 - by2)*(y2ShPos - 5 - by2)) <= br2*br2 
			&& ((xPos - bx2)*(xPos - bx2) + (yPos - 5 - by2)*(yPos - 5 - by2)) <= br2*br2 ||
			((x3ShPos - bx2)*(x3ShPos - bx2) + (y3ShPos - 5 - by2)*(y3ShPos - 5 - by2)) <= br2*br2 
			&& ((xPos - bx2)*(xPos - bx2) + (yPos - 5 - by2)*(yPos - 5 - by2)) <= br2*br2 ||
			((x4ShPos - bx2)*(x4ShPos - bx2) + (y4ShPos - 5 - by2)*(y4ShPos - 5 - by2)) <= br2*br2 
			&& ((xPos - bx2)*(xPos - bx2) + (yPos - 5 - by2)*(yPos - 5 - by2)) <= br2*br2 ||
			((x5ShPos - bx2)*(x5ShPos - bx2) + (y5ShPos - 5 - by2)*(y5ShPos - 5 - by2)) <= br2*br2 
			&& ((xPos - bx2)*(xPos - bx2) + (yPos - 5 - by2)*(yPos - 5 - by2)) <= br2*br2 ||
			((x6ShPos - bx2)*(x6ShPos - bx2) + (y6ShPos - 5 - by2)*(y6ShPos - 5 - by2)) <= br2*br2)
		{
			MessageBox(NULL, "GameOver!!", "GameOver", MB_OK | MB_ICONEXCLAMATION);
			exit(0);
		}*/
	}
	//////////////////////////////Shooting Bullets V2///////////////////////
	{
		if (shoot1 == 1)
		{
			if (y1BPos < screenTop + 6)
				y1BPos += .9;

			if (y1BPos >= screenTop + 6)
			{
				y1BPos = -2;
				x1BPos = xPos;
				shoot1 = 0;
			}
		}
		else if (shoot1 != 1)
			x1BPos = xPos;
		////////////////////////////////
		if (shoot2 == 1)
		{
			if (y2BPos < screenTop + 6)
				y2BPos += .9;

			if (y2BPos >= screenTop + 6)
			{
				y2BPos = -2;
				x2BPos = xPos;
				shoot2 = 0;
			}
		}
		else if (shoot2 != 1)
			x2BPos = xPos;
		////////////////////////////////
		if (shoot3 == 1)
		{
			if (y3BPos < screenTop + 6)
				y3BPos += .9;

			if (y3BPos >= screenTop + 6)
			{
				y3BPos = -2;
				x3BPos = xPos;
				shoot3 = 0;
			}
		}
		else if (shoot3 != 1)
			x3BPos = xPos;
		////////////////////////////////
		if (shoot4 == 1)
		{
			if (y4BPos < screenTop + 6)
				y4BPos += .9;

			if (y4BPos >= screenTop + 6)
			{
				y4BPos = -2;
				x4BPos = xPos;
				shoot4 = 0;
			}
		}
		else if (shoot4 != 1)
			x4BPos = xPos;
		////////////////////////////////
		if (shoot5 == 1)
		{
			if (y5BPos < screenTop + 6)
				y5BPos += .9;

			if (y5BPos >= screenTop + 6)
			{
				y5BPos = -2;
				x5BPos = xPos;
				shoot5 = 0;
			}
		}
		else if (shoot5 != 1)
			x5BPos = xPos;
		////////////////////////////////
		if (shoot6 == 1)
		{
			if (y6BPos < screenTop + 6)
				y6BPos += .9;

			if (y6BPos >= screenTop + 6)
			{
				y6BPos = -2;
				x6BPos = xPos;
				shoot6 = 0;
			}
		}
		else if (shoot6 != 1)
			x6BPos = xPos;

	}
	/////////////////////////////////////////////////////////////////////
	
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("SpaceShip");
	glutFullScreen();
	BackgroundColor();
	glutTimerFunc(0, timer, 0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}
