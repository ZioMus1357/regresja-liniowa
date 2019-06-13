///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,400 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	WxPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	WxPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer1->Add( WxPanel, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_button4 = new wxButton( this, wxID_ANY, _("Kolor T³a"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_button4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button5 = new wxButton( this, wxID_ANY, _("Kolor Punkt\u00F3w"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_button5, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Skala wykresu:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer2->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider1 = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( m_slider1, 0, wxALL|wxEXPAND, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Wielko\u015B\u0107 punkt\u00F3w:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer2->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, _("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_textCtrl9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText23 = new wxStaticText(this, wxID_ANY, _("Styl Punkt\u00F3w:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText23->Wrap(-1);
	bSizer2->Add(m_staticText23, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxString m_choice3Choices[] = { _("Okr\u0105g"), _("Kwadrat")};
	int m_choice3NChoices = sizeof(m_choice3Choices) / sizeof(wxString);
	m_choice3 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3NChoices, m_choice3Choices, 0);
	m_choice3->SetSelection(0);
	bSizer2->Add(m_choice3, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_radioBtn3 = new wxCheckBox( this, wxID_ANY, _("S\u0142upki B\u0142\u0119d\u00F3w:"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_radioBtn3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Typ Regresji:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer2->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choice2Choices[] = { _("Liniowa"), _("Nielioniwa")};
	int m_choice2NChoices = sizeof( m_choice2Choices ) / sizeof( wxString );
	m_choice2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2NChoices, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	bSizer2->Add( m_choice2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );


	m_staticText22 = new wxStaticText(this, wxID_ANY, _("Pozycja ramki:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText22->Wrap(-1);
	bSizer2->Add(m_staticText22, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_slider2 = new wxSlider(this, wxID_ANY, 0, 0, 600, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer2->Add(m_slider2, 0, wxALL | wxEXPAND, 5);

	m_slider3 = new wxSlider(this, wxID_ANY, 0, 0, 600, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer2->Add(m_slider3, 0, wxALL | wxEXPAND, 5);



	bSizer1->Add( bSizer2, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	m_menu11 = new wxMenu();
	wxMenuItem* m_menu11Item = new wxMenuItem( m_menu1, wxID_ANY, _("Wczytaj Dane"), wxEmptyString, wxITEM_NORMAL, m_menu11 );
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu11, wxID_ANY, wxString( _("Z Pliku") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu11->Append( m_menuItem3 );

	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu11, wxID_ANY, wxString( _("Z Klawiatury") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu11->Append( m_menuItem4 );

	m_menu1->Append( m_menu11Item );

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Zapisz do pliku") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem5 );

	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem(m_menu1, wxID_ANY, wxString(_("Kopiuj")), wxEmptyString, wxITEM_NORMAL);
	m_menu1->Append(m_menuItem6);

	m_menubar1->Append( m_menu1, _("Menu") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	WxPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::ChangeChartColor ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::ChangePointColor ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_textCtrl9->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::ChangePointSize ), NULL, this );
	m_radioBtn3->Connect(wxEVT_CHECKBOX, wxCommandEventHandler( MyFrame1::AddError ), NULL, this );
	m_choice2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::ChangeRegresionType ), NULL, this );
	m_menu11->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::OpenFormFile ), this, m_menuItem3->GetId());
	m_menu11->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::OpenFromKeyboard ), this, m_menuItem4->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::Save ), this, m_menuItem5->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::Copy), this, m_menuItem6->GetId());
	m_slider2->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);
	m_slider2->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::ChangedX), NULL, this);

	m_slider3->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);
	m_slider3->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::ChangedY), NULL, this);

	m_choice3->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame1::ChangePointStyle), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	WxPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::ChangeChartColor ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::ChangePointColor ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::ChangeScale ), NULL, this );
	m_textCtrl9->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::ChangePointSize ), NULL, this );
	m_radioBtn3->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::AddError ), NULL, this );
	m_choice2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::ChangeRegresionType ), NULL, this );

}
