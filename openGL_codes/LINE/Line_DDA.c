#include<GL/glut.h>
#include<GL/gl.h>

float x1,x2,y1,y2;
void init()
{
	glClearColor(1.0,0.0,0.0,0.0);	//Blue background
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,700,0,700);
}

void display()
{
   int a;
   float temp1,temp2,m,c;
   temp1 = y2-y1;
   temp2 = x2-x1;
   m = temp1/temp2;	        //slope
   c = y1 - x1*m;		//intercept
if(m<=1)
   {
      a = 1;			//case counter
      glColor3f(0,1,0);
      glBegin(GL_POINTS);
      glVertex2d(x1,y1);
glEnd();
      while(x1<x2)
	{
	   x1 = x1 + 1;
	   y1 = (m*x1) + c;
	   y1 = (int)(y1+0.5); 	//Round Off Method!!!
	   glBegin(GL_POINTS);
	   glVertex2d(x1,y1);
glEnd();

	 }
    }

else
    {
      a = 1;            	//case counter
      glColor3f(0,1,0);		
      glBegin(GL_POINTS);
      glVertex2d(x1,y1);
glEnd();
	while(y1<y2)
	 {
	   y1 = y1 + 1;
	   x1 = (y1-c)/m;
	   x1 = (int)(x1 + 0.5); 	//Round off Method!!
	   glBegin(GL_POINTS);
	   glVertex2d(x1,y1);
glEnd();

	 }
     }
glFlush();
}


int main(int argc,char **argv)
{
	// DDA
	
	int a; 			//case counter
 	
	printf("Simple DDA method\n");
	printf("Enter first point co-ordinates\n");
	printf("x1: ");
	scanf("%f",&x1);
	printf("y1: ");
	scanf("%f",&y1);
	printf("Enter second point co-ordinates\n");
	printf("x2: ");
	scanf("%f",&x2);
	printf("y2: ");
	scanf("%f",&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(700,700);
glutCreateWindow("DDA");
init();
glutDisplayFunc(display);
glutMainLoop();
}
