/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationResponse.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 10 de Outubro de 2018, 16:18
 */

#include "SimulationResponse.h"
#include "AnalysisOfVariance_if.h"

SimulationResponse::SimulationResponse(std::string type, std::string name, GetterMember getterMember) {
	_type = type;
	_name = name;
	_getterMemberFunction = getterMember;
}

std::string SimulationResponse::show() {
	return "name=" + this->_name + ", type=" + this->_type;
}

std::string SimulationResponse::name() const {
	return _name;
}

std::string SimulationResponse::type() const {
	return _type;
}

double SimulationResponse::value() {
	return this->_getterMemberFunction();
}