/*
 * RB.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Jeremy
 */

#include "RB.h"

// RB Constructor
RB::RB(){
    allRules = new std::map<string, Rule*>();
    numRules = 0;
}

// Adds a rule to the RB !!! -> Duplicate rule handling TBD
void RB::add(Rule *ruleObj){
    string ruleName = ruleObj->Name;
    std::cout << "Adding Rule: " << ruleName << "\n";
    allRules->insert({ruleName, ruleObj});
    numRules++;
}

// Removes a rule from the RB !!! -> Validity checking TBD
void RB::delRule(string ruleName){
    allRules->erase(ruleName);
    numRules--;
}

// Search the RB for a Rule and return it
// !!! Using map::at throws a logic_error exception if the Rule is not in KB
Rule* RB::search(string ruleName){
    std::map<string, Rule*>::iterator it = allRules->find(ruleName);
    if( it != allRules->end() )
        return it->second;
    else{ return NULL;//return new Rule("NULL","NULL","NULL",'N');
	}
    //return allRules->at(ruleName);  //// Prototype 
}

// RB Destructor
RB::~RB(){
    for(std::map<std::string, Rule*>::iterator itr = allRules->begin(); itr != allRules->end(); ++itr)
    {
        delete itr->second;
        //allRules->erase(itr);
    }
    allRules->clear();
    delete allRules;
}

