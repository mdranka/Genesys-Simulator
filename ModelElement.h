/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelElement.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 19:40
 */

#ifndef MODELELEMENT_H
#define MODELELEMENT_H

#include <string>
#include <list>
#include "Util.h"

/*!
 * This class is the basis for any element of the model (such as Queue, Resource, Variable, etc.) and also for any component of the model. 
 * It has the infrastructure to read and write on file and to verify symbols.
 */
class ModelElement {
public:
    ModelElement(std::string elementTypename);
    ModelElement(const ModelElement& orig);
    virtual ~ModelElement();
public:
    virtual std::string show();
public: // static
    static void LoadInstance(std::list<std::string> words); // TODO: return ModelComponent* ?
    static std::list<std::string>* SaveInstance(ModelElement* element);
    static bool Check(ModelElement* element, std::string* errorMessage);

public: // get & set
    Util::identitifcation getId() const;
    void setName(std::string _name);
    std::string getName() const;
    std::string getTypename() const;

protected: // must be overriden by derived classes
    virtual void _loadInstance(std::list<std::string> words) = 0;
    virtual std::list<std::string>* _saveInstance();
    //virtual std::list<std::string>* _saveInstance(std::string type);
    virtual bool _check(std::string* errorMessage) = 0;

protected:
    Util::identitifcation _id;
    std::string _name;
    std::string _typename;
};

#endif /* MODELELEMENT_H */
