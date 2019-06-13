#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
    cfg= std::move(c);
	data.AddCords(5.1, 3.6);
	data.AddCords(2.4, 2.2);
	data.AddCords(-2.0, -8.9);

}

void ChartClass::Set_Range()
{
	 double xmin=-12,xmax=12,ymin=-12,ymax=12;

	 y_min=ymin;
	 y_max=ymax;
	 x_min=xmin;
	 x_max=xmax;
}
void ChartClass::Draw(wxDC *dc, int w, int h)
{
	width = w - 20;
	height = h - 20;
	dc->SetBackground(wxBrush(wxColor(255, 255, 255)));
	dc->Clear();

	dc->SetPen(wxPen(wxColor(0, 0, 0)));
	dc->SetBrush(wxBrush(chartColor));
	dc->DrawRectangle(10, 10, w - 20, h - 20);

	dc->SetPen(wxPen(wxColor(255, 255, 255)));
	dc->SetClippingRegion(10, 10, w - 20, h - 20);

	dc->SetPen(wxPen(pointColor));
	dc->SetBrush(wxBrush(pointColor));
	DrawPoints(dc);

	dc->SetPen(wxPen(wxColor(0, 0, 0)));
	SetTransform();
	DrawAxies(dc);
	if (cfg->type == 0)
	{
		DrawLine(dc);
		DrawInfo(dc);
	}
	else
		DrawPolynomial(dc);

}
wxPoint ChartClass::point2d(Matrix t, double x1, double y1)
{
	Vector vector;
	vector.Set(x1, y1);
	vector = t * vector;
	x1 = vector.GetX();
	y1 = vector.GetY();
	return wxPoint(x1, y1);
}

double ChartClass::Get_Y_min()
{
    Set_Range();
    return y_min;
}

double ChartClass::Get_Y_max()
{
    Set_Range();
    return y_max;
}

void ChartClass::SetTransform() 
{
	Matrix transform; // skalowanie
	transform.data[0][0] = cfg->scale *  width / (cfg->Get_x1() - cfg->Get_x0());
	transform.data[1][1] = cfg->scale * height / (cfg->Get_y1() - cfg->Get_y0()) *(-1);
	transform.data[0][2] = 10- transform.data[0][0] * cfg->Get_x0();
	transform.data[1][2] = 10- transform.data[1][1] * cfg->Get_y1();
	Matrix transform2; // translacja
	transform2.data[0][0] = transform2.data[1][1] = 1;
	transform2.data[0][2] = cfg->Get_dX();
	transform2.data[1][2] = cfg->Get_dY();

	tr =  transform;
	infotr = transform2;
}

void ChartClass::DrawAxies(wxDC *dc) 
{
	double *x1=new double, *x2 = new double, *y1 = new double, *y2 = new double;
	Set_Range();

	//XAxis
	*x1 = x_min; *x2 = x_max; *y1 = 0; *y2 = 0;
	dc->DrawLine(point2d(tr, *x1, *y1), point2d(tr, *x2 * 2 * (1 / cfg->scale), *y2 * 2 * (1 / cfg->scale)));

	//YAxis
	*x1 = 0; *x2 = 0; *y1 = y_min; *y2 = y_max;
	dc->DrawLine(point2d(tr, *x1, *y1 * 2 * (1 / cfg->scale)), point2d(tr, *x2, *y2 * 2 * (1 / cfg->scale)));



	delete x1;
	delete x2;
	delete y1;
	delete y2;
}

void ChartClass::DrawPoints(wxDC *dc) 
{
	for (int i = 0; i < data.n; ++i) 
	{	
		if(cfg->PointStyle)
			dc->DrawRectangle(point2d(tr, data.Table[2 * i], data.Table[2 * i + 1]) + wxPoint(-pointSize * cfg->scale, -pointSize * cfg->scale), wxSize(2*pointSize * cfg->scale,2*pointSize * cfg->scale));
		else
			dc->DrawCircle(point2d(tr, data.Table[2 * i], data.Table[2 * i + 1]), pointSize * cfg->scale);
		dc->DrawText(wxString::Format("%.2lf", data.Table[2 * i]), point2d(tr, data.Table[2 * i], data.Table[2 * i + 1]));
		dc->DrawText(wxString::Format("%.2lf", data.Table[2 * i+1]), point2d(tr, data.Table[2 * i] + 1, data.Table[2 * i+1]));
	}
}
void ChartClass::DrawLine(wxDC *dc) 
{
	data.RegresjaLiniowa();
	data.BladLiniowej();
	dc->DrawLine(point2d(tr, x_min * 1000* cfg->scale, data.parA*x_min * 1000* cfg->scale + data.parB), point2d(tr, x_max * 1000*cfg->scale, data.parA*x_max* 1000*cfg->scale + data.parB));
	for (int i = 0; i < data.n; ++i) {
		if (cfg->RegresionError == true)
			dc->DrawLine(point2d(tr, data.Table[2 * i], data.eLin[i]), point2d(tr, data.Table[2 * i], 0));
	}
}
void ChartClass::DrawInfo(wxDC *dc) {
	double x1 = 10, y1 = 10;
	Vector vector;
	vector.Set(x1, y1);
	vector = infotr * vector;
	x1 = vector.GetX();
	y1 = vector.GetY();
	double w = 160;
	double h = 70;
	if (x1 > 494) {
		x1 = 494;
	}
	if (y1 > 461) {
		y1 = 461;
	}
	dc->SetBrush(wxBrush(wxColor(255,255,255)));
	dc->DrawRectangle(x1,y1, w,h);
	dc->SetPen(wxPen(wxColor(0, 0, 0)));
	dc->DrawRectangle(x1, y1, w,h);
	dc->DrawText(wxString::Format("Wspó³czynniki regresji:\na= %.2lf  b= %.2lf\nB³¹d regresji=%.2lf",data.parA,data.parB,data.errLin) ,wxPoint(x1 + 5,y1+5));
}

void ChartClass::DrawPolynomial(wxDC *dc)
{
	double x_1 = x_min, x_2, y_1, y_2;
	while (x_1 <= x_max)
	{
		x_2 = x_1 + 0.1;
		y_1 = y_2 = 0;
		for (int i = 0; i < data.n; ++i)
		{
			y_1 += data.NLpar[i] * pow(x_1, i);
			y_2 += data.NLpar[i] * pow(x_2, i);
		}
		dc->DrawLine(point2d(tr, x_1, y_1), point2d(tr, x_2, y_2));
		x_1 = x_2;
	}
}
