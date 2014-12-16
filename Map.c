/*Brandeis Map Program*/
/*NAME AND DATE GOES HERE.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/***************************************************************************************/
/*Global parameters.                                                                   */
/***************************************************************************************/

/*Path to the map folder (that is prepended to all file names).*/
char PATH[100] = ""; 

/*File names*/
#define FileVertices    "MapDataVertices.txt" /*Map vertex data.*/
#define FileEdges       "MapDataEdges.txt"    /*Map edge data.*/
#define FilePath        "Route.txt"           /*Computed route points - feet.*/
#define FilePathCropped "RouteCropped.txt"    /*Computed route points - cropped pixels.*/

/*Limits*/
#define MaxString 100       /*Maximum length of any input string.*/
#define MaxLabel 5          /*Maximum length of a location label (includes ending \0).*/
#define MaxVertex 175       /*Maximum number of vertices.*/
#define MaxEdge   600       /*Maximum number of edges.*/
#define UndefinedIndex -1   /*All array insides start at 0; -1 is like a nil pointer.*/
#define InfiniteCost  10000 /*Cost of an edge that does not exist.*/


/***************************************************************************************/
/*MAP DATA                                                                             */
/***************************************************************************************/

/*Vertex data.*/
int  nV=0;                        /*Number of vertices.*/
int  Vindex[MaxVertex];           /*Vertex index.*/
char Vlabel[MaxVertex][MaxLabel]; /*Vertex label - each at most 3 chars plus the \0.*/
int  VX[MaxVertex];               /*Vertex X-coord. in feet from upper left corner.*/
int  VY[MaxVertex];               /*Vertex Y-coord. in feet from upper left corner.*/
char *Vname[MaxVertex];           /*Vertex name - pointer to an allocated string.*/

/*Edge data.*/
int  nE=0;              /*Number of edges.*/
int  Eindex[MaxEdge];   /*Edge index.*/
int  Estart[MaxEdge];   /*Edge start (a vertex number).*/
int  Eend[MaxEdge];     /*Edge end (a vertex number).*/
int  Elength[MaxEdge];  /*Edge length in feet.*/
int  Eangle[MaxEdge];   /*Edge angle in degrees clockwise from north.*/
char Edir[MaxEdge][6];  /*Edge direction - one of North, NE, East, ..., NW*/
char Ecode[MaxEdge];    /*Edge code - f/F, u/U, d/D, s/t (steps up/down), b (bridge)*/
char *Ename[MaxEdge];   /*Edge name - pointer to an allocated string.*/

/*User input for current request.*/
int Begin, Finish; /*Vertex indices of begin and finish locations.*/
int BoardFlag;     /*1 if have skateboard*/
int TimeFlag;      /*1 to minimize time instead of distance*/


/***************************************************************************************/
/*FUNCTION Time(i) TO RETURN THE NUMBER OF SECONDS TO TRAVERSE AN EDGE i               */
/***************************************************************************************/
#include "MapTime.h" /*To be used by Dijkstra's algorithm.*/


/***************************************************************************************/
/*INPUT / OUTPUT FUNCTIONS                                                             */
/***************************************************************************************/
#include "MapInputData.h" /*Used by GetVertices, GetEdges (called by main).*/
#include "MapInputUser.h" /*Used by GetRequest (called by main).*/
#include "MapOutput.h"    /*PrintLeg function to be used by Dijkstra's algorithm.*/


/***************************************************************************************/
/*GRAPH ADJACENCY LIST DATA STRUCTURE                                                  */
/***************************************************************************************/



/***************************************************************************************/
/*HEAP DATA STRUCTURE                                                                  */
/***************************************************************************************/



/***************************************************************************************/
/*Dijkstra's Single-Source Shortest Path Algorithm                                     */
/***************************************************************************************/

/*Do Dijkstra algorithm, reverse back edges, print path with PrintLeg.*/
void Dijkstra() {
}


/***************************************************************************************/
/*START OF PROGRAM                                                                     */
/***************************************************************************************/
int main() {
GetVertices();
GetEdges();
while (GetRequest()) {RouteOpen(); Dijkstra(); RouteClose();}
return(0);
}
