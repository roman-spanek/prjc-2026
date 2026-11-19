#pragma once
#include <iostream>
#include <string>

class Input {
private:
	std::string name;
	
public:
	Input(const std::string _name) :name(_name) { ; }
	void setName(std::string name) ;
	std::string getName() const;

	std::string getElement();
};


class Select {
private:
	std::string name;

public:
	Select(std::string _name) :name(_name) { ; }
	void setName(std::string name);
	std::string getName();

	std::string getElement();
};

class Form {
private:
	Input **inputs;
	Select **selects;
	unsigned int no_of_inputs; 
	unsigned int no_of_selects;
	unsigned int max_inputs;
	unsigned int max_selects;

public:
	Form(int max_inputs, int max_selects);
	unsigned int addInput(Input *input);
	unsigned int addSelect(Select *select);

	void getInputsHtml();

	~Form() { delete inputs; delete selects; }
};


