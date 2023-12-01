#include <gl/freeglut.h>
#include <stdio.h>
#define FPS 10
float move = 10.0;
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
	glVertex2f(0, -15);
	glVertex2f(0, 15);
	glEnd();
}

void displayCallback() {

}

void carDisplay() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glPushMatrix();
	drawAxes();
	glPopMatrix();

	//glRotatef(30, 0, 0, 1); // rotate around z-axis

	glPushMatrix();
	glTranslatef(move, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(2, 0.0);
	glVertex2f(2, 2);
	glVertex2f(0.0, 2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(6.0, 0.0);
	glVertex2f(6, 2.0);
	glVertex2f(8, 2);
	glVertex2f(8, 0);
	glEnd();

	glBegin(GL_POLYGON);
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
		move -= 0.1 * direction;
		printf("FORWARD %f\n", move);
		printf("what the fuck");
	}

	if (direction == -1) {
		move -= 0.1 * direction;
		printf("BACKWARD %f\n", move);
		printf("move backwards");
	}
		

	if (move <= -15.0 || move > 10.0) {
		direction *= -1;
	}



	
	
	glutPostRedisplay();
	glutTimerFunc(20, carUpdate, 0);
	/*spin += 2.0;
	if (spin > 360)
		spin = spin - 360.0;
	glutPostRedisplay();
	glutTimerFunc(16, carUpdate, 0);*/
}


