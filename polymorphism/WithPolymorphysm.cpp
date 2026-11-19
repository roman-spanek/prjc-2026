#include "WithPolymorphysm.h"

void FormElement::setName(std::string name) {
	this->name = name;
}
std::string FormElement::getName() {
	return name;
}

std::string InputP::getElement() {
	return "<input type=\"text\" name=\"" + this->name + "\" value=\"\">";
}

std::string SelectP::getElement() {
	return "<select name=\"" + this->name + "\"> \n" +
		'\t' + '\t' + "<option> </option> \n" +
		'\t' + "</select>";
}


FormP::FormP(unsigned int max_formElements) {
	this->max_formElements = max_formElements;
	no_of_formElements = 0;

}
unsigned int FormP::addFormElement(FormElement *formElement) {
	if (no_of_formElements >= max_formElements) return 0;
	no_of_formElements++;
	this->formElements.push_back(formElement);
	return no_of_formElements;

}



void FormP::getInputsHtml() {

	std::cout << "<form>" << std::endl;
	for (FormElement * value : this->formElements) {
		std::cout << '\t' + value->getElement() << std::endl;
	}

	std::cout << "</form>" << std::endl;
}



FormElement & FormP::operator [] (int index) {
	if (index > no_of_formElements ) return *formElements[0];

	if (index < 0 ) return *formElements[0];

	return *formElements[index];
}

void FormP::operator+ (FormElement * formElement) {
	addFormElement(formElement);
}