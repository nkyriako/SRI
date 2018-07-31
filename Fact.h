/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fact.h
 * Author: Nicole
 *
 * Created on February 17, 2017, 11:53 AM
 */

#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <vector>

#ifndef FACT_H
#define FACT_H

class Fact{
public:
	// name of the rule
	std::string Name;
	// vector that holds the parameters of the fact
	std::vector<std::string> param;
	// constructors/destructor
	Fact(std::string n);
	Fact(std::string n,std::string n1, std::string n2);
	~Fact();

private:
};

#endif /* FACT_H */
