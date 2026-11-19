#pragma once      
#include <iostream>
#include <string>
#include <vector>

class FormElement {
protected:
	std::string name;
public:
	FormElement(std::string _name) :name(_name) { ; }

	void setName(std::string name);
	std::string getName();

	virtual std::string getElement() = 0;
};

 
class InputP : public  FormElement  {
public:
	InputP(std::string _name) :FormElement(_name) { ; }

	std::string getElement();

};
 

class SelectP : public  FormElement {

public:
	SelectP(std::string _name) :FormElement(_name) { ; }

	std::string getElement();
};

class FormP {
private:
	std::pmr::vector<FormElement *> formElements;
	unsigned int no_of_formElements;
	unsigned int max_formElements;

public:
	FormP(unsigned int max_formElements);
	unsigned int addFormElement(FormElement *formElement);

	void getInputsHtml();

	FormElement & operator [] (int);

	void operator+ (FormElement *);

	~FormP() {  }
};
