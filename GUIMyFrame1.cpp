#include "GUIMyFrame1.h"
#include"ChartClass.h"
#include"ConfigClass.h"
#include"DataWindow.h"
#include <wx/colordlg.h>
#include <wx/clipbrd.h>


GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	cfg = std::make_shared<ConfigClass>(this);
	chart = new ChartClass(cfg);

}

void GUIMyFrame1::MainFormClose( wxCloseEvent& event )
{
	Destroy();
}

void GUIMyFrame1::WxPanel_Repaint( wxUpdateUIEvent& event )
{
	Repaint();
}

void GUIMyFrame1::ChangeChartColor(wxCommandEvent& event)
{
	wxColourDialog ColorPicker(this);

	if (ColorPicker.ShowModal() == wxID_OK) 
	{
		chart->SetChartColor(ColorPicker.GetColourData().GetColour());
		Repaint();
	}
}

void GUIMyFrame1::ChangePointColor( wxCommandEvent& event )
{
	wxColourDialog ColorPicker(this);

	if (ColorPicker.ShowModal() == wxID_OK)
	{
		chart->SetPointColor(ColorPicker.GetColourData().GetColour());
		Repaint();
	}
}

void GUIMyFrame1::ChangeScale( wxScrollEvent& event )
{
	cfg->scale = m_slider1->GetValue() + 10;
	cfg->scale /= 100;
	Repaint();
}

void GUIMyFrame1::ChangePointSize( wxCommandEvent& event )
{
	m_textCtrl9->GetValue().ToDouble(chart->GetPointSizePointer());

}

void GUIMyFrame1::AddError( wxCommandEvent& event )
{
	cfg->RegresionError = m_radioBtn3->IsChecked();
	Repaint();
}

void GUIMyFrame1::ChangeRegresionType( wxCommandEvent& event )
{
	cfg->type = m_choice2->GetSelection();
}

void GUIMyFrame1::OpenFormFile( wxCommandEvent& event )
{
	wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("config files (*.txt)|*.txt"), wxFD_OPEN);

	if (WxOpenFileDialog.ShowModal() == wxID_OK) 
		chart->data.AddFromFile((const_cast<char*>((const char*)WxOpenFileDialog.GetPath().mb_str())));

	Repaint();

}

void GUIMyFrame1::OpenFromKeyboard( wxCommandEvent& event )
{
	wxFrame *dataFrame = new DataWindow(this);
	dataFrame->Show(true);
	Repaint();
}

void GUIMyFrame1::Save( wxCommandEvent& event )
{
	wxFileDialog saveFileDialog(this, "Choose a file", "", "", "JPG files (*.jpg)|*.jpg|PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;
	m_image = m_buffer.ConvertToImage();
	m_image.AddHandler(new wxJPEGHandler);
	m_image.AddHandler(new wxPNGHandler);
	m_image.SaveFile(saveFileDialog.GetPath());
}


GUIMyFrame1::~GUIMyFrame1()
{

}

void GUIMyFrame1::Repaint()
{
	wxClientDC __MyDC(WxPanel);
	m_buffer = wxBitmap(WxPanel->GetSize().x, WxPanel->GetSize().y);
	wxBufferedDC MyDC(&__MyDC, m_buffer);

	 int w, h;
	 WxPanel->GetSize(&w, &h);
	 chart->Draw(&MyDC, w, h);
}


void GUIMyFrame1::UpdateControls()
{

}

void GUIMyFrame1::Copy(wxCommandEvent &e)
{
	int w, h;
	wxClientDC MyDC(WxPanel);
	wxMemoryDC MyBitmapDC;
	WxPanel->GetClientSize(&w, &h);
	wxBitmap MyBitmap(w, h);
	MyBitmapDC.SelectObject(MyBitmap);
	MyBitmapDC.Blit(0, 0, w, h, &MyDC, 0, 0);

	if (wxTheClipboard->Open()) 
	{
		wxTheClipboard->SetData(new wxBitmapDataObject(MyBitmap));
		wxTheClipboard->Close();
	}
}

void GUIMyFrame1::ChangedX(wxScrollEvent& event) 
{
	cfg->Set_dX(m_slider2->GetValue());
	Repaint();
}
void GUIMyFrame1::ChangedY(wxScrollEvent& event)
{
	cfg->Set_dY(m_slider3->GetValue());
	Repaint();

}
void GUIMyFrame1::ChangePointStyle(wxCommandEvent& event) {
	cfg->PointStyle = m_choice3->GetSelection();
	Repaint();
}