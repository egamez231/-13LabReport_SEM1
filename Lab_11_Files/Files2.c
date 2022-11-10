#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Main body
int main()
{
   int i,iCount=0;
   float axisX[4],axisY[4],iDis[4];
   char Var[4] = {'A','B','C','D'};

   FILE *fcor;
   FILE *fdis;

   if ((fcor = fopen("flight.dat","r"))== NULL)
   {
       printf("Error Opening File");
       exit (-1);
   }

   // Reading Data
   while (!feof(fcor))
   {
        for (i=0;i<4;i++)
        {
            fscanf (fcor,"%f %f",&axisX[i],&axisY[i]);
        }

   }
   fclose (fcor);

   if ((fdis = fopen("flightdis.dat","w"))== NULL)
   {
       printf("Error Opening File");
       exit (-1);
   }


   // Calculation Function
   for (i=0;i<4;i++)
   {
       iDis[i] = sqrt ((pow(axisX[i],2))+ (pow (axisY[i],2)));

       if (iDis[i] > 20.00)
       {
           iCount++;
       }
   }
   printf ("Incoming Aircraft(s): %d\n",iCount);

   // Distance Output display
   fprintf(fdis,"Aircraft     Distance from Control Center\n");

   do
   {
        for (i=0;i<4;i++)
        {
            fprintf(fdis,"%c\t\t\t%.2f\n",Var[i],iDis[i]);
        }

   }
   while (feof(fdis));


    fclose (fdis);



return (0);
}
