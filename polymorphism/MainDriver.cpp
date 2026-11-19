#include <iostream>

//#include "NoPolymophism.h"
#include "WithPolymorphysm.h"


int main() {
/* NO POLY */
	/*
	Form f1(5, 5);
	f1.addInput(new Input("name"));
	f1.addInput(new Input("surename"));
	f1.addInput(new Input("middlename"));

	f1.addSelect(new Select("age"));
	f1.addSelect(new Select("department"));

	f1.getInputsHtml();
	*/

	//POLY
	FormP f1(10);
	f1.addFormElement(new InputP("name"));
	f1.addFormElement(new InputP("surename"));
	f1.addFormElement(new InputP("middlename"));

	f1.addFormElement(new SelectP("age"));
	f1.addFormElement(new SelectP("department"));

	f1.getInputsHtml();

	f1 + new InputP("name 2");

	std::cout <<f1[1].getName() << std::endl;

	f1.getInputsHtml();


}