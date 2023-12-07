#include <gl/freeglut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846;

float move = 10.0;
float spin = 0.0; // for car wheels
int direction = 1;

void keyboard2(unsigned char key, int x, int y) {

	printf("key pressed: %d\n", key);

	glutPostRedisplay();
}

void drawAxes() {
	glColor3ub(100, 100, 100);
	glBegin(GL_LINES);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	/*glVertex2f(0, -15);
	glVertex2f(0, 15);*/
	glEnd();
}


void carDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glPushMatrix();
	drawAxes();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(move, 0, 0);
	glTranslatef(1.0, 1.0, 0.0);
	glRotatef(spin, 0, 0, 1.0);
	glTranslatef(-1.0, -1.0, 0.0);



	// wheels
	// need fixing but for now so i can see if they rotate or naur

	glBegin(GL_LINE_LOOP);
	glVertex2f(1.0, 1.0); // center of the circle

	for (int i = 0; i < 20; i++) {
		float angle = 3.14159265358979323846 * 2.0 * (float)i / (float)20;
		float x = 1.0 + 1.0 * cos(angle);
		float y = 1.0 + 1.0 * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(move, 0, 0);
	glTranslatef(7.0, 1.0, 0.0);
	glRotatef(spin, 0, 0, 1.0);
	glTranslatef(-7.0, -1.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex2f(7.0, 1.0); // center of the circle

	for (int i = 0; i < 20; i++) {
		float angle = 3.14159265358979323846 * 2.0 * (float)i / (float)20;
		float x = 7.0 + 1.0 * cos(angle);
		float y = 1.0 + 1.0 * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(move, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1, 0.5);
	glVertex2f(-1, 1.5);
	glVertex2f(9, 1.5);
	glVertex2f(9, 0.5);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, 4);
	glVertex2f(2.5, 4);
	glVertex2f(2.5, 6);
	glVertex2f(8.5, 6);
	glVertex2f(8.5, 0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(3, 4);
	glVertex2f(3, 5.5);
	glVertex2f(5, 5.5);
	glVertex2f(5, 4);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(5.5, 4);
	glVertex2f(5.5, 5.5);
	glVertex2f(7.5, 5.5);
	glVertex2f(7.5, 4);
	glEnd();
	glPopMatrix();

	// glFlush();
	glutSwapBuffers();
	printf("exist display function\n");
}

void carUpdate() {

	if (direction == 1) {
		// translation
		move -= 0.1 * direction;
		// rotation for wheels
		spin += 4 * direction;
		if (spin > 360.0)
			spin -= 360.0;
		printf("FORWARD %f\n", move);
	}

	if (direction == -1) {
		// translation
		move -= 0.1 * direction;
		// rotation for wheels
		spin += 2 * direction;
		if (spin > 360.0)
			spin -= 360.0;

		printf("BACKWARD %f\n", move);
	}
		
	// switch directions (forwards/backwards)

	if (move <= -15.0 || move > 10.0) {
		direction *= -1;
	}

	
	glutPostRedisplay();
	glutTimerFunc(20, carUpdate, 0);

}


