/*
 * CCalc.h
 *
 *  Created on: 2 de dez de 2016
 *      Author: sirineo
 */

#ifndef CCALC_H_
#define CCALC_H_

class CCalc {
private:
	int n_;
	double i_;
	double pv_;
public:
	CCalc();
	CCalc(const int n, const double i, const double pv);
	virtual ~CCalc();
	double GetI() const;
	void SetI(double i);
	int GetN() const;
	void SetN(int n);
	double GetPv() const;
	void SetPv(double pv);
	double CalcPmt() const;
};

#endif /* CCALC_H_ */
