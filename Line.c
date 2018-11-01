/* A-Nony-Mus
31 Jan. 2012
Page 104, project 10
This program takes two pairs of coordinates input by the user, and outputs the slope, midpoint, the slope of the perpendicular bisector, and the equation of the line
3 Feb. 2012
edited to take input from a file and output to a file
29 Feb. 2012
edit while loop from counting to endfile*/

#include <stdio.h>


int main(void)
{

double x0, x1, xavg, //the variables for the two input x coordinates and their average
	y0, y1, yavg, yint, perp_yint, //the variables for the two input y coordinates, their average, and the y intercept
	slope, perp_slope; //the variables for the slope and the perpendicular bisectors slope
FILE *inp, //input file
	*outp; //output file
int end, //variable compared to EOF
    status; //variable for a place to assign what has been read, this is never displayed

//print some warnings for formatting
printf("the x coordinates cannot equal each other,\nand the y coordinates cannot equal each other,\notherwise you will get bizzarre results\n");
printf("Please format your inputs as (5.0, 3.0) (6.0, 20)");

inp = fopen("program_input.txt", "r"); //open the input file
outp = fopen("F:program_output.txt", "w"); //open the output file

end = fscanf(inp, "%d", &status); //read the input file to make sure there is something there

while(end != EOF) //continue until end of file
{
fscanf(inp, "(%lf, %lf) (%lf, %lf)\n", &x0, &y0, &x1, &y1); //read from the input file
fprintf(outp, "you entered (%4.2f, %4.2f) (%4.2f, %4.2f),\n", x0, y0, x1, y1); //print to the output file

xavg = (x0 + x1) / 2; //calculation to determine the average of the input x coordinates
yavg = (y0 + y1) / 2; //calculation to determine the average of the input y coordinates
slope = (y1 - y0) / (x1 - x0); //calculation to determine the slope of the line
perp_slope = -1 * ((x1 - x0) / (y1 - y0)); //calculation to determine the slope of the perpendicular bisector
yint = y0 - (slope * x0); //calculation to determine the y intercept
perp_yint = yavg - (perp_slope * xavg); //calculation to determine the equation of the perpendicular bisector

//display the midpoint coordinates, the slope, the slope of the perpendicular bisector, and the equation of the line
fprintf(outp, " your midpoint is (%4.2f, %4.2f)\n your slope is %4.2f\n the slope of the perpendicular bisector is %4.2f\n the equation of the line is y=%4.2fx+%4.2f\n the equation of the perpendicular bisector is y=%4.2fx+%4.2f\n\n", xavg, yavg, slope, perp_slope, slope, yint, perp_slope, perp_yint);

end = fscanf(inp, "%d", &status); //check to see if it has reached the end of the file

}

fclose(inp); //close the input file
fclose(outp); //close the output file

return(0);
}
