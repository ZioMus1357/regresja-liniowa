#include"DataWindow.h"
#include"Container.h"
#include"ChartClass.h"

class ChartClass;
class Container;

DataWindow::DataWindow(GUIMyFrame1* parent) :wxFrame(parent, wxID_ANY, "Dodaj punkt:") {
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);
	OpisOkna = new wxStaticText(this, wxID_ANY, _("Podaj wspó³¿êdne x i y:"), wxPoint(10,0), wxDefaultSize, 0);
	bSizer1->Add(OpisOkna, 0, wxALL, 5);
	WpiszX = new wxTextCtrl(this, wxID_ANY, _("0.0"), wxPoint(10, 30), wxDefaultSize, 0);
	bSizer1->Add(WpiszX, 0, wxALL, 5);
	WpiszY = new wxTextCtrl(this, wxID_ANY, _("0.0"), wxPoint(160,30), wxDefaultSize, 0);
	bSizer1->Add(WpiszY, 0, wxALL, 5);
	Dodaj = new wxButton(this, wxID_ANY, _("Dodaj punkt"), wxPoint(10,70), wxDefaultSize, 0);
	bSizer1->Add(Dodaj, 0, wxALL, 5);
	Dodaj->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DataWindow::AddData), NULL, this);
	ojciec = parent;
}

void DataWindow::AddData(wxCommandEvent& event){
	double valueX ,valueY;
	WpiszX->GetValue().ToDouble(&valueX);
	WpiszY->GetValue().ToDouble(&valueY);
	ojciec->chart->data.AddCords(valueX,valueY);
}