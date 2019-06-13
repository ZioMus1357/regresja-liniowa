#include "Container.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include<vector>

using namespace std;

Container::Container() {
	Table = new double[1];
	eLin = new double[1];
	NLpar = new double[1];
}

void Container::RegresjaLiniowa() {
	double sumX = 0, sumY = 0, srX, srY, tmp1 = 0, tmp2 = 0;
	for (int i = 0; i < n; ++i) {
		sumX += Table[2 * i];
		sumY += Table[2 * i + 1];
	}
	srX = sumX / n;
	srY = sumY / n;
	for (int i = 0; i < n; ++i) {
		tmp1 += (Table[2 * i] - srX) * (Table[2 * i + 1] - srY);
		tmp2 += (Table[2 * i] - srX) * (Table[2 * i] - srX);
	}
	parA = tmp1 / tmp2;
	parB = srY - parA * srX;
}

void Container::BladLiniowej() {
	delete[] eLin;
	eLin = new double[n];
	double sumE = 0;
	for (int i = 0; i < n; ++i) {
		eLin[i] = Table[2 * i + 1] - (parB * Table[2 * i] + parA);
		sumE += eLin[i] * eLin[i];
	}
	errLin = sqrt(sumE / (n - 2.));
}

void Container::RegresjaNieLiniowa() {
	int i, j, k, dn;
	dn = n - 1;
	delete[] NLpar;
	NLpar = new double[dn + 1];

	vector<double> X(2 * dn + 1);
	for (i = 0; i < 2 * dn + 1; ++i) {
		X[i] = 0;
		for (j = 0; j < n; ++j) {
			X[i] = X[i] + pow(Table[2 * j], i);
		}
	}

	vector<vector<double>> B(dn + 1,vector<double>(dn + 2));
	for (i = 0; i <= dn; ++i) {
		for (j = 0; j <= dn; ++j) {
			B[i][j] = X[i + j];
		}
	}

	vector<double> Y(dn + 1);
	for (i = 0; i < dn + 1; ++i) {
		Y[i] = 0;
		for (j = 0; j < n; ++j) {
			Y[i] = Y[i] + pow(Table[2 * j], i) * Table[2 * j + 1];
		}
	}

	for (i = 0; i <= dn; ++i) {
		B[i][dn + 1] = Y[i];
	}

	dn = dn + 1;

	for (i = 0; i < dn; ++i) {
		for (k = i + 1; k < dn; ++k) {
			if (B[i][i] < B[k][i]) {
				for (j = 0; j <= dn; ++j) {
					double temp = B[i][j];
					B[i][j] = B[k][j];
					B[k][j] = temp;
				}
			}
		}
	}
	for (i = 0; i < dn - 1; ++i) {
		for (k = i + 1; k < dn; ++k) {
			double t = B[k][i] / B[i][i];
			for (j = 0; j <= dn; ++j) {
				B[k][j] = B[k][j] - t * B[i][j];
			}
		}
	}
	for (i = dn - 1; i >= 0; --i) {
		NLpar[i] = B[i][n];
		for (j = 0; j < dn; j++) {
			if (j != i) {
				NLpar[i] = NLpar[i] - B[i][j] * NLpar[j];
			}
		}
		NLpar[i] = NLpar[i] / B[i][i];
	}
}

void Container::AddCords(double xCord, double yCord) {
	if (n == 0) {
		n++;
		delete[] Table;
		Table = new double[2 * n];
		Table[0] = xCord;
		Table[1] = yCord;
		xMin = xMax = xCord;
		yMin = yMax = yCord;
	}
	else {
		n++;
		double *newTab = new double[2 * n];
		for (int i = 0; i < 2 * (n - 1); ++i) {
			newTab[i] = Table[i];
		}
		newTab[2 * n - 2] = xCord;
		newTab[2 * n - 1] = yCord;
		if (xCord > xMax) xMax = xCord;
		if (xCord < xMin) xMin = xCord;
		if (yCord > yMax) yMax = yCord;
		if (yCord < yMin) yMin = yCord;
		delete[] Table;
		Table = newTab;
	}
	RegresjaLiniowa();
	BladLiniowej();
	RegresjaNieLiniowa();
}

void Container::AddFromFile(char* filename) {
	double x, y;
	ifstream file;
	file.open(filename, ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			file >> x >> y;
			this->AddCords(x, y);
		}
		file.close();
	}
}

Container::~Container() {
	delete[] Table;
	delete[] NLpar;
	delete[] eLin;
}