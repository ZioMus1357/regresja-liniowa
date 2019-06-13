#pragma once
#include"GUIMyFrame1.h"

/**********************************************************************************************//**
 * @class	DataWindow
 *
 * @brief	Form for viewing the data.
 **************************************************************************************************/

class DataWindow : public wxFrame {
private:

public:
	/** @brief	The opis okna */
	wxStaticText* OpisOkna;
	/** @brief	The wpiszXx coordinate text field coresponding to X value of point*/
	wxTextCtrl* WpiszX;
	/** @brief	The wpiszy coordinate text field coresponding to Y value of point*/
	wxTextCtrl* WpiszY;
	/** @brief	Button corresponding to adding an Point of co-ordinates value inserted into text field WpiszX and WPiszY*/
	wxButton* Dodaj;

	/**********************************************************************************************//**
	 * @fn	DataWindow::DataWindow(GUIMyFrame1* parent);
	 *
	 * @brief	Constructor
	 *
	 * @param [in,out]	parent	If non-null, the parent.
	 **************************************************************************************************/

	DataWindow(GUIMyFrame1* parent);
	/** @brief	The parent object */
	GUIMyFrame1* ojciec;


	/**********************************************************************************************//**
	 * @fn	void DataWindow::AddData(wxCommandEvent& event);
	 *
	 * @brief	Adds a data
	 *
	 * @param [in,out]	event	The event.
	 **************************************************************************************************/

	void AddData(wxCommandEvent& event);


};