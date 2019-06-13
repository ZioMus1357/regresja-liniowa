#pragma once

#include<iostream>

/**********************************************************************************************//**
 * @class	Container
 *
 * @brief	A container.
 **************************************************************************************************/

class Container {
public:
		/**********************************************************************************************//**
	 * @fn	Container::Container();
	 *
	 * @brief	Constructor
	 **************************************************************************************************/
	Container();


	/**********************************************************************************************//**
	 * @fn	void Container::AddCords(double xCord, double yCord);
	 *
	 * @brief	Adds the cords to 'yCord'
	 *
	 * @param	xCord	The x cord.
	 * @param	yCord	The y cord.
	 **************************************************************************************************/

	void AddCords(double xCord, double yCord);

	/**********************************************************************************************//**
	 * @fn	void Container::AddFromFile(char* filename);
	 *
	 * @brief	Adds from file
	 *
	 * @param [in,out]	filename	If non-null, filename of the file.
	 **************************************************************************************************/

	void AddFromFile(char* filename);

	/**********************************************************************************************//**
	 * @fn	void Container::BladLiniowej();
	 *
	 * @brief	Blad liniowej
	 **************************************************************************************************/

	void BladLiniowej();

	/**********************************************************************************************//**
	 * @fn	void Container::RegresjaLiniowa();
	 *
	 * @brief	Regresja liniowa
	 **************************************************************************************************/

	void RegresjaLiniowa();

	/**********************************************************************************************//**
	 * @fn	void Container::RegresjaNieLiniowa();
	 *
	 * @brief	Regresja nieliniowa
	 **************************************************************************************************/

	void RegresjaNieLiniowa();

	/**********************************************************************************************//**
	 * @fn	Container::~Container();
	 *
	 * @brief	Destructor
	 **************************************************************************************************/

	~Container();

	/** @brief	The table with co-ordinates*/
	double * Table;
	
	/** @brief	An int to process with amount of points*/
	int n = 0;
	
	/** @brief	Paramert a of Linear Regression */
	double parA;
	
	/** @brief	Parametr b of Linear Regression */
	double parB;
	
	/** @brief	Linear Regression error*/
	double errLin;
	
	/** @brief	every single measurement error */
	double * eLin;

	/** @brief	The x minimum */
	double xMin;

	/** @brief	The x maximum */
	double xMax;

	/** @brief	The y minimum */
	double yMin;

	/** @brief	The y maximum */
	double yMax;

	/** @brief	Parametrers of Non-Linear Regression */
	double * NLpar;
};