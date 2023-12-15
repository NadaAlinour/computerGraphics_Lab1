#include <gl/freeglut.h>
#include <stdio.h>

// get from user input
struct Edges {
	char a;
	char b;
};

struct Vertices {
	char character;
	float x;
	float y;
};

struct Vertices vertices[5];
struct Edges edges[7]; // should be max 7 anyway

void setGraphInputs() {
	// a b c d e
	int startChar = 97;
	int xshift = 0;
	for (int i = 0; i < 2; i++) {
		vertices[i].character = startChar++;
		vertices[i].x = -9.25 + xshift;
		vertices[i].y = -1.25;
		xshift += 7;
	}

	startChar = 99;
	xshift = 0;
	for (int i = 2; i < 5; i++) {
		vertices[i].character = startChar++;
		vertices[i].x = -9.25 + xshift;
		vertices[i].y = 7.75;
		xshift += 7;
	}

	printf("Please enter data for the graph edges\n");
	for (int i = 0; i < 7; i++) {
		printf("Edge %d:\n", i + 1);

		printf("first vertex:\n");
		scanf_s(" %c", &edges[i].a, 1);

		printf("\n");

		printf("second vertex:\n");
		scanf_s(" %c", &edges[i].b, 1);
		printf("\n");

	}

	for (int i = 0; i < 7; i++) {
		printf("Edge %d\n", i + 1);
		printf("first vertex: %c   second vertex: %c\n", edges[i].a, edges[i].b);
	}
	
}

void drawVertices() {
	glColor3ub(100, 100, 100);

	int xshift = 0;
	int i = 0;
	while (i < 2) {
		// make circle later
		glBegin(GL_LINE_LOOP);
		glVertex2f(-10 + xshift, -2);
		glVertex2f(-8 + xshift, -2);
		glVertex2f(-8 + xshift, 0);
		glVertex2f(-10 + xshift, 0);
		glEnd();
		glRasterPos2f(vertices[i].x, vertices[i].y);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, vertices[i].character);
		xshift += 7;
		i++;
	}

	xshift = 0;
	i = 2;
	while (i < 5) {
		// make circle later
		glBegin(GL_LINE_LOOP);
		glVertex2f(-10 + xshift, 7);
		glVertex2f(-8 + xshift, 7);
		glVertex2f(-8 + xshift, 9);
		glVertex2f(-10 + xshift, 9);
		glEnd();
		glRasterPos2f(vertices[i].x, vertices[i].y);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, vertices[i].character);
		xshift += 7;
		i++;
	}
	
}

void drawEdges() {
	float xshift = 1.25;

	for (int i = 0; i < 5; i++) {
		glBegin(GL_LINES);
		if (edges[i].a == 'a')
			glVertex2f(vertices[0].x + xshift, vertices[0].y);
		else if (edges[i].a == 'b')
			glVertex2f(vertices[1].x + xshift, vertices[1].y);
		else if (edges[i].a == 'c')
			glVertex2f(vertices[2].x + xshift, vertices[2].y);
		else if (edges[i].a == 'd')
			glVertex2f(vertices[3].x + xshift, vertices[3].y);
		else if (edges[i].a == 'e')
			glVertex2f(vertices[4].x + xshift, vertices[4].y);

		if (edges[i].b == 'a')
			glVertex2f(vertices[0].x - xshift + 0.45, vertices[0].y);
		else if (edges[i].b == 'b')
			glVertex2f(vertices[1].x - xshift + 0.45, vertices[1].y);
		else if (edges[i].b == 'c')
			glVertex2f(vertices[2].x - xshift + 0.45, vertices[2].y);
		else if (edges[i].b == 'd')
			glVertex2f(vertices[3].x - xshift + 0.45, vertices[3].y);
		else if (edges[i].b == 'e')
			glVertex2f(vertices[4].x - xshift + 0.45, vertices[4].y);


		glEnd();
	}
}
 
void graphDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	drawVertices();
	drawEdges();
	

	glutSwapBuffers();
	printf("\nexist display function\n");
}