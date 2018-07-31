/*
 * RB.h
 *
 *  Created on: Feb 23, 2017
 *      Author: Jeremy
 */

#include <map>
#include <memory>
#include <iostream>
#include <string>
#include "Rule.h"

#ifndef RB_H_
#define RB_H_

using namespace std;

class RB{
    private:

        //number of rule stored in KB
        int numRules;
    public:
	// RB constructor
        RB();
        //RB(const RB& R);

        //map storing rules
        map<string, Rule*> *allRules;
	// Add Rules to RB
        void add(Rule *ruleObj);
	// Remove Rules from RB
        void delRule(string ruleName);
	// Find Rules matching a string
        Rule* search(string ruleName);

        virtual ~RB();
};

#endif /* RB_H_ */
