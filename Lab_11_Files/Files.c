#include <stdio.h>
#include <stdlib.h>


//Struct
typedef struct iCoordinate
{
    float axisX;
    float axisY;
}iCoordinate;

// Main body
int main()
{
   int i;

   FILE *fcor;
   iCoordinate CoXY [4];

   if ((fcor = fopen("flight.dat","w"))== NULL)
   {
       printf("Error Opening File");
       exit (-1);
   }

   for (i=0;i<4;i++)
   {
       printf ("Input X[%d] :",i);
       scanf ("%f",&CoXY[i].axisX);
       fprintf(fcor,"%.1f\t",CoXY[i].axisX);
       printf ("Input Y[%d] :",i);
       scanf ("%f",&CoXY[i].axisY);
       fprintf(fcor,"%.1f\n",CoXY[i].axisY);
   }
    fclose (fcor);

return (0);
}
