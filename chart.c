#include <gl/freeglut.h>
#include <stdio.h>

// inputs for the chart
char xlabel[20];
char ylabel[20];
int sampleCount;

struct BarData {
	char label[20];
	int value;
};

struct BarData dataArr[20];

void setInputs() {
	printf("Please enter data for the chart:\n");

	printf("Label for x-axis:\n");
	scanf_s("%s", xlabel, 20);

	printf("Label for y-axis:\n");
	scanf_s("%s", ylabel, 20);

	printf("Number of samples:\n");
	scanf_s("%d", &sampleCount);

	printf("Enter data for each sample:\n");
	for (int i = 0; i < sampleCount; i++) {
		printf("Label:\n");
		scanf_s("%s", dataArr[i].label, 20);
		printf("Value:\n");
		scanf_s("%d", &dataArr[i].value);
	}

	// print array of data
	for (int i = 0; i < sampleCount; i++) {
		printf("\n%s %d\n", dataArr[i].label, dataArr[i].value);
	}

}

void drawAxis() {
	glColor3ub(100, 100, 100);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-12, -12);
	glVertex2f(-12, 12);
	glVertex2f(-12, -12);
	glVertex2f(12, -12);
	glEnd();
}

void drawDashes() {
	int start = -11;
	int value = 1;
	char scale[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};

	for (int i = 0; i < 10; i++) {
		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(-12, start);
		glVertex2f(-12.5, start);
		glEnd();

		glRasterPos2f(-13, start);

		if (i == 9)
		{
			glRasterPos2f(-13.5, start);

			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		}
		else {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scale[i]);
		}
		

		start += 1;
	}
}


void chartDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	int width = 2;
	int xPos = -10;

	drawAxis();
	drawDashes();

	for (int i = 0; i < sampleCount; i++) {
		glColor3f(0.3922, 0.5843, 0.9294);
		glBegin(GL_QUADS);
		glVertex2f(xPos, -12);
		glVertex2f(xPos + width, -12);
		glVertex2f(xPos + width, dataArr[i].value - 12);
		glVertex2f(xPos, dataArr[i].value - 12);
		glEnd();

		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(xPos, -13);
		int j = 0;
		while (dataArr[i].label[j] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dataArr[i].label[j]);
			j++;
		}


		xPos += 3.0;
	}


	// bitmap text for the labels
	glColor3f(0.0f, 0.0f, 0.0f);

	// xlabel position
	glRasterPos2f(10, -13);
	int i = 0;
	while (xlabel[i] != '\0') {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, xlabel[i]);
		i++;
	}



	// ylabel position
	glRasterPos2f(-13, 13);

	i = 0;
	while (xlabel[i] != '\0') {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ylabel[i]);
		i++;
	}


	glutSwapBuffers();
	printf("\nexist display function\n");
}