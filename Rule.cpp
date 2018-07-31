/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rule.cpp
 * Author: Nicole
 * 
 * Created on February 17, 2017, 11:25 AM
 */

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <vector>
#include <iostream>
#include "Rule.h"

// Standard constructor with string parsing
Rule::Rule(std::string n) {
	Name = n.substr(0, n.find("("));
	std::string namestr = n.substr(0, n.find(")") + 1);
	n = n.substr(n.find(")") + 1, n.size() - n.find(")") + 1);

	//counts the number of the commas/parmas
	int count = 1;
	for (int i = 0; i < namestr.length(); i++) {
		std::string temp = namestr.substr(i, 1);
		if (temp.find(",") == 0) {
			count++;
		}
	}

	//parse the chuck from the main string
	for (int i = 0; i < count; i++) {
		if (i == 0) {
			param.push_back(
					namestr.substr(namestr.find("(") + 1,
							namestr.find(",") - namestr.find("(") - 1));
			namestr = namestr.substr(namestr.find(","),
					namestr.length() - namestr.find(","));
		} else if (i == count - 1) {
			param.push_back(
					namestr.substr(namestr.find(",") + 1,
							namestr.find(")") - namestr.find(",") - 1));
		} else {
			param.push_back(namestr.substr(1, namestr.find(",", 2) - 1));
			namestr = namestr.substr(namestr.find(",", 2),
					namestr.length() - namestr.find(",", 2));
		}

	}

	//check for operation
	std::string operation = n.substr(n.find(" ") + 1,
			n.find(" ", 3) - n.find(" ") - 1);
	if (operation.compare("AND") == 0) {
		op = 'A';
	} else {
		op = 'O';
	}
	n = n.substr(n.find(" ", 3) + 1, n.size() - n.find(" ", 3));

	//getting Rule/Fact(1)
	Name1 = n.substr(0, n.find("("));
	std::string namestr1 = n.substr(0, n.find(")") + 1);
	n = n.substr(n.find(")") + 1, n.size() - n.find(")") + 1);

	count = 1;
	for (int i = 0; i < namestr1.length(); i++) {
		std::string temp = namestr1.substr(i, 1);
		if (temp.find(",") == 0) {
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		if (i == 0) {
			param1.push_back(
					namestr1.substr(namestr1.find("(") + 1,
							namestr1.find(",") - namestr1.find("(") - 1));
			namestr1 = namestr1.substr(namestr1.find(","),
					namestr1.length() - namestr1.find(","));
		} else if (i == count - 1) {
			param1.push_back(
					namestr1.substr(namestr1.find(",") + 1,
							namestr1.find(")") - namestr1.find(",") - 1));
		} else {
			param1.push_back(namestr1.substr(1, namestr1.find(",", 2) - 1));
			namestr1 = namestr1.substr(namestr1.find(",", 2),
					namestr1.length() - namestr1.find(",", 2));
		}

	}

	//getting Rule/Fact(2)
	Name2 = n.substr(1, n.find("(")-1);
	std::string namestr2 = n.substr(0, n.find(")") + 1);
	n = n.substr(n.find(")") + 1, n.size() - n.find(")") + 1);

	count = 1;
	for (int i = 0; i < namestr2.length(); i++) {
		std::string temp = namestr2.substr(i, 1);
		if (temp.find(",") == 0) {
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		if (i == 0) {
			param2.push_back(
					namestr2.substr(namestr2.find("(") + 1,
							namestr2.find(",") - namestr2.find("(") - 1));
			namestr2 = namestr2.substr(namestr2.find(","),
					namestr2.length() - namestr2.find(","));
		} else if (i == count - 1) {
			param2.push_back(
					namestr2.substr(namestr2.find(",") + 1,
							namestr2.find(")") - namestr2.find(",") - 1));
		} else {
			param2.push_back(namestr2.substr(1, namestr2.find(",", 2) - 1));
			namestr2 = namestr2.substr(namestr2.find(",", 2),
					namestr2.length() - namestr2.find(",", 2));
		}

	}

}
Rule::Rule(const Rule &R ){
    
}

Rule::~Rule() {

}

