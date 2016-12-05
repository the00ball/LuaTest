/*
 * CCalc.cpp
 *
 *  Created on: 2 de dez de 2016
 *      Author: sirineo
 */

#include "CCalc.h"
#include <math.h>

CCalc::CCalc() : CCalc(0,0,0)
{
}

CCalc::CCalc(const int n, const double i, const double pv) : n_(n), i_(i), pv_(pv)
{
}

double CCalc::GetI() const
{
	return i_;
}

void CCalc::SetI(double i)
{
	i_ = i;
}

int CCalc::GetN() const
{
	return n_;
}

void CCalc::SetN(int n)
{
	n_ = n;
}

double CCalc::GetPv() const
{
	return pv_;
}

void CCalc::SetPv(double pv)
{
	pv_ = pv;
}

CCalc::~CCalc() {
}

double CCalc::CalcPmt() const
{
	return this->pv_* this->i_/(1-(1/pow(1+this->i_,this->n_)));
}
