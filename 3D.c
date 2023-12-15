#include <gl/freeglut.h>
#include <stdio.h>

void display3D() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 1.0, 5.0,   // Eye position
		0.0, 0.0, 0.0,   // Look-at position
		0.0, 1.0, 0.0);  // Up vector


	// Z
	glPushMatrix();
	glTranslatef(-2.0, 0.0, -1.5);

	glBegin(GL_QUADS);

	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glColor3f(1.0f, 0.0f, 0.0f);
	
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, -0.5);

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0);

	glEnd();

	glPopMatrix();


	// L
	glPushMatrix();
	glTranslatef(-0.75, 0.0, -1.5);

	glBegin(GL_QUADS);

	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glColor3f(0.0f, 1.0f, 0.0f);

	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.0, -0.5, 0);
	glVertex3f(0.0, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glEnd();
	glPopMatrix();

	//V
	glPushMatrix();
	glTranslatef(-0.25, 0.0, -1.5);

	glBegin(GL_QUADS);

	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(0.0, -0.5, 0);
	glVertex3f(0.0, -0.5, -0.5);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(0.0, -0.5, -0.5);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, -0.5);

	glEnd();
	glPopMatrix();

	// N
	glPushMatrix();
	glTranslatef(-.75, 1.25, -1.5);

	glBegin(GL_QUADS);

	glColor3f(201.0f / 255.0f, 131.0f / 255.0, 120.0f / 255.0f);

	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.0);

	glColor3f(201.0f / 255.0f, 131.0f / 255.0, 120.0f / 255.0f);


	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.0, 0.5, -0.5);
	glVertex3f(0.0, -0.5, -0.5);
	glVertex3f(0.0, -0.5, 0.0);

	glColor3f(241.0f / 255.0f, 168.0f / 255.0, 157.0f / 255.0f);


	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.0, -0.5, -0.5);

	glEnd();
	glPopMatrix();

	// M
	glPushMatrix();
	glTranslatef(-2.0, 1.25, -1.5);

	glBegin(GL_QUADS);

	glColor3f(241.0f / 255.0f, 168.0f / 255.0, 157.0f / 255.0f);

	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.0);

	glColor3f(201.0f / 255.0f, 131.0f / 255.0, 120.0f / 255.0f);

	glVertex3f(-0.5, 0.5, -.5);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -0.5);

	glColor3f(241.0f / 255.0f, 168.0f / 255.0, 157.0f / 255.0f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.0, 0.0, -0.5);

	glColor3f(201.0f / 255.0f, 131.0f / 255.0, 120.0f / 255.0f);

	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);


	glEnd();
	glPopMatrix();

	glutSwapBuffers();
	printf("exist display function\n");
}