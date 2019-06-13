///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* m_button4;
		wxButton* m_button5;
		wxStaticText* m_staticText19;
		wxSlider* m_slider1;
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textCtrl9;
		wxCheckBox* m_radioBtn3;
		wxStaticText* m_staticText21;
		wxChoice* m_choice2;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu11;
		wxButton* WxButton2;
		wxStaticText* m_staticText22;
		wxSlider* m_slider2;
		wxSlider* m_slider3;
		wxStaticText* m_staticText23;
		wxChoice* m_choice3;

		// Virtual event handlers, overide them in your derived class
		virtual void MainFormClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void WxPanel_Repaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void ChangeChartColor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangePointColor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeScale( wxScrollEvent& event ) { event.Skip(); }
		virtual void ChangePointSize( wxCommandEvent& event ) { event.Skip(); }
		virtual void AddError( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeRegresionType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenFormFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenFromKeyboard( wxCommandEvent& event ) { event.Skip(); }
		virtual void Save( wxCommandEvent& event ) { event.Skip(); }
		virtual void Copy(wxCommandEvent& event) { event.Skip(); }
		virtual void ChangedX(wxScrollEvent& event) { event.Skip(); }
		virtual void ChangedY(wxScrollEvent& event) { event.Skip(); }
		virtual void ChangePointStyle(wxCommandEvent& event) { event.Skip(); }



	public:
		wxPanel* WxPanel;

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Regresja liniowa"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

