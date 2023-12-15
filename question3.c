#include <gl/freeglut.h>
#include <stdio.h>


void thirdDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glRotatef(180, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2i(0, 2);
	glVertex2i(2, 2);
	glVertex2i(0, 0);
	glEnd();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			exit(0);
		break;
	}
}

void thirdKeyboard(unsigned char key, int x, int y) {}