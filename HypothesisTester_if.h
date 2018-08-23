/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTester_if.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 19:04
 */

#ifndef HYPOTHESISTESTER_IF_H
#define HYPOTHESISTESTER_IF_H

#include <string>

class HypothesisTester_if {
public:

	enum H1Comparition {
		LESS_THAN = 1,
		EQUAL = 2,
		DIFFERENT = 3,
		GREATER_THAN = 4
	};
public:
	/* TODO: all "test" methods should return double p-value, not bool */
	virtual bool testAverageDifference(double confidencelevel, double avg, H1Comparition comp) = 0;
	virtual bool testProportionDifference(double confidencelevel, double prop, H1Comparition comp) = 0;
	virtual bool testVarianceDifference(double confidencelevel, double var, H1Comparition comp) = 0;
	virtual bool testAverageDifference(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) = 0;
	virtual bool testProportionDifference(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) = 0;
	virtual bool testVarianceDifference(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) = 0;
	virtual void setDataFilename(std::string dataFilename) = 0;
	virtual std::string getDataFilename() = 0;
};

#endif /* HYPOTHESISTESTER_IF_H */

