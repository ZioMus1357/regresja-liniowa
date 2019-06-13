#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"
#include"vecmat.h"
#include"Container.h"
class Matrix;

/**********************************************************************************************//**
 * @class	ChartClass
 *
 * @brief	A chart class.
 **************************************************************************************************/

class ChartClass
{
    private:
        /** @brief	The configuration */
        std::shared_ptr<ConfigClass> cfg;
		
		/** @brief	The width of screen */
		int	width;
		
		/** @brief	The height of screen */
		int height;  
		
		/** @brief	The minimum of x variable */
		double x_min;
		
		/** @brief	The maximum of x variable */
		double x_max; 
		
		/** @brief	The minimum of function value */
		double y_min;
		
		/** @brief	The maximum function value */
		double y_max;

		/** @brief	The tr TODO */
		Matrix tr;

		/** @brief	The infotr */
		Matrix infotr;
		/** @brief	The chart's color */
		wxColor chartColor = wxColor(255,255,255);

		/** @brief	The point's color */
		wxColor pointColor = wxColor(125, 125, 0);

		/** @brief	Size of the point */
		double pointSize = 1;

        /**********************************************************************************************//**
         * @fn	wxPoint ChartClass::point2d(Matrix t,double x1,double y1);
         *
         * @brief	Point 2D
         *
         * @param	t 	A Matrix to process.
         * @param	x1	The first x value.
         * @param	y1	The first y value.
         *
         * @returns	A wxPoint.
         **************************************************************************************************/

        wxPoint point2d(Matrix t,double x1,double y1);

		/**********************************************************************************************//**
		 * @fn	void ChartClass::DrawAxies(wxDC *dc);
		 *
		 * @brief	Draw axies
		 *
		 * @param [in,out]	dc	If non-null, the device-context.
		 **************************************************************************************************/

		void DrawAxies(wxDC *dc);

		/**********************************************************************************************//**
		 * @fn	void ChartClass::DrawPoints(wxDC *dc);
		 *
		 * @brief	Draw points
		 *
		 * @param [in,out]	dc	If non-null, the device-context.
		 **************************************************************************************************/

		void DrawPoints(wxDC *dc);

		/**********************************************************************************************//**
		 * @fn	void ChartClass::DrawLine(wxDC * dc);
		 *
		 * @brief	Draw line
		 *
		 * @param [in,out]	dc	If non-null, the device-context.
		 **************************************************************************************************/

		void DrawLine(wxDC * dc);

		/**********************************************************************************************//**
		 * @fn	void ChartClass::DrawInfo(wxDC *dc);
		 *
		 * @brief	Draw information
		 *
		 * @param [in,out]	dc	If non-null, the device-context.
		 **************************************************************************************************/

		void DrawInfo(wxDC *dc);
       
    public:
		/** @brief	The data */
		Container data;

        /**********************************************************************************************//**
         * @fn	ChartClass::ChartClass(std::shared_ptr<ConfigClass> c);
         *
         * @brief	Constructor
         *
         * @param	c	A std::shared_ptr&lt;ConfigClass&gt; to process.
         **************************************************************************************************/

        ChartClass(std::shared_ptr<ConfigClass> c);

        /**********************************************************************************************//**
         * @fn	void ChartClass::Set_Range();
         *
         * @brief	Sets the range x_min,y_min,x_max,y_max
         **************************************************************************************************/

        void Set_Range();   

        /**********************************************************************************************//**
         * @fn	double ChartClass::Get_Y_min();
         *
         * @brief	Get y coordinate minimum
         *
         * @returns	The calculated y coordinate minimum.
         **************************************************************************************************/

        double Get_Y_min();

        /**********************************************************************************************//**
         * @fn	double ChartClass::Get_Y_max();
         *
         * @brief	Get y coordinate maximum
         *
         * @returns	The calculated y coordinate maximum.
         **************************************************************************************************/

        double Get_Y_max();

        /**********************************************************************************************//**
         * @fn	void ChartClass::Draw(wxDC *dc, int w, int h);
         *
         * @brief	Draws chart
         *
         * @param [in,out]	dc	If non-null, the device-context.
         * @param 		  	w 	The width.
         * @param 		  	h 	The height.
         **************************************************************************************************/

        void Draw(wxDC *dc, int w, int h);

		/**********************************************************************************************//**
		 * @fn	void ChartClass::SetTransform();
		 *
		 * @brief	Sets the transform matrix
		 **************************************************************************************************/

		void SetTransform();

		/**********************************************************************************************//**
		 * @fn	void ChartClass::SetChartColor(wxColor color)
		 *
		 * @brief	Sets chart color
		 *
		 * @param	color	The color.
		 **************************************************************************************************/

		void SetChartColor(wxColor color) { chartColor = color; }

		/**********************************************************************************************//**
		 * @fn	void ChartClass::SetPointColor(wxColor color)
		 *
		 * @brief	Sets point color
		 *
		 * @param	color	The color.
		 **************************************************************************************************/

		void SetPointColor(wxColor color) { pointColor = color; }

		/**********************************************************************************************//**
		 * @fn	double * ChartClass::GetPointSizePointer()
		 *
		 * @brief	Gets point size pointer
		 *
		 * @returns	The point size pointer.
		 **************************************************************************************************/

		double * GetPointSizePointer() { return &pointSize; }
		void DrawPolynomial(wxDC*);
 
};

#endif
