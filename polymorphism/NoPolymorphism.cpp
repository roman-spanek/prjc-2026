#include "NoPolymophism.h"

void Input::setName(std::string name){
	this->name = name;
}
std::string Input::getName() const{
	return name;
}

std::string Input::getElement() {
	return "<input type=\"text\" name=\"" + this->name + "\" value=\"\">";
}

void Select::setName(std::string name) {
	this->name = name;
}
std::string Select::getName() {
	return name;
}

std::string Select::getElement() {
	return "<select name=\"" + this->name + "\"> \n"+ 
		'\t' + '\t' + "<option> </option> \n" +
		'\t' + "</select>";
}


Form::Form(int max_inputs, int max_selects) {
	this->max_inputs = max_inputs;
	this->max_selects = max_selects;

	no_of_inputs = 0;
	no_of_selects = 0;

	inputs = new Input *[max_inputs];
	selects = new Select *[max_selects];

	for (int i = 0; i < max_inputs; i++) {
		inputs[i] = NULL;
	}

	for (int i = 0; i < max_selects; i++) {
		selects[i] = NULL;
	}

}
unsigned int Form::addInput(Input *input) {
	if (no_of_inputs >= max_inputs) return 0;
	no_of_inputs++;
	int i = 0;

	while (inputs[i] != NULL) i++;

	inputs[i] = input;

	return i + 1;
}

unsigned int Form::addSelect(Select *select) {
	if (no_of_selects >= max_selects) return 0;
	no_of_selects++;
	int i = 0;

	while (selects[i] != NULL) i++;

	selects[i] = select;

	return i + 1;
}


void Form::getInputsHtml() {

	std::cout << "<form>" << std::endl;
	if (no_of_inputs > 0) {
		for (int i = 0; i < max_inputs; i++) {
			if (inputs[i] != NULL) {
				std::cout << '\t' + inputs[i]->getElement() << std::endl;
			}
		}
	}

	if (no_of_selects > 0) {
		for (int i = 0; i < max_selects; i++) {
			if (selects[i] != NULL) {
				std::cout << '\t' +  selects[i]->getElement() << std::endl;
			}
		}
	}
	std::cout << "</form>" << std::endl;
}