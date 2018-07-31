/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rule.h
 * Author: Nicole
 *
 * Created on February 17, 2017, 11:25 AM
 */

#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <vector>

#ifndef RULE_H
#define RULE_H

class Rule {
    public:
        //name of the rule, rule/fact(1), rule/fact(2)
        std::string Name,Name1,Name2;
        
        //vectors that would hold the params of the their respective fact/rule
        std::vector<std::string> param;
        std::vector<std::string> param1;
        std::vector<std::string> param2;

        // operator symbol
        char op;	//A or O

	// Constructors/Destructor
        Rule(std::string n);
        Rule(const Rule& R);

        ~Rule();
    private:
    
};


#endif /* RULE_H */
