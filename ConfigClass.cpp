#pragma warning(disable: 4996) // Visual Studio: warning C4996: 'XXX': This function or variable may be unsafe. <- wxcrt.h
#include <fstream>
#include "ConfigClass.h"

using namespace std;

ConfigClass::ConfigClass(GUIMyFrame1 *wnd)
{
 MainWindow=wnd;
 x_start=-1.0;
 x_stop=2.0;
 x0=-10.0;
 y0=-10.0;
 x1=10.0;
 y1=10.0;
 dX=0;
 dY=0;
 scale = 1;
 RegresionError = false;
 PointStyle = 0;
 type = 0;
}


istream& rd2EOL(istream& str)
{
 int ch;
 
 while( (ch=str.get()) != EOF && ch != '\n');
 return str;
}
