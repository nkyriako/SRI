/* 
 * File:   KB.cpp
 * Author: mjloyola
 */

#include "KB.h"
#include "Fact.h"
#include <string>
#include <iostream>
#include <vector>

//default constructor
KB::KB() {
	allFacts = new std::vector<Fact*>(); //establish vector to hold facts
	numFacts = 0; //establish variable to keep track of the number of facts
}

//destructor
KB::~KB() {
	//vector memory should be freed when it goes out of scope
    for(std::vector<Fact*>::iterator itr = allFacts->begin(); itr != allFacts->end(); ++itr)
    {
		
        delete (*itr);
        //allFacts->erase(itr);
    } 
    allFacts->clear();
    delete allFacts; 
}

//add facts to the vector list
Fact KB::add(Fact *FactObj) {
   
    
	allFacts->push_back(FactObj); //insert fact at the end of the vector list
	numFacts++; //increment fact count
	return *FactObj;
}

//remove facts from the vector list
void KB::del(std::string FactName) {
   
	//auto element;
	for(std::vector<Fact*>::iterator i=allFacts->begin(); i!=allFacts->end();) { //loop through vector and search for fact
		if((*i)->Name==(FactName)) { //dot equals substituted 
                    i=allFacts->erase(i);		
		} else {
			++i;
		}
	}
        /* Implementation TBD
	if(element == NULL) { //if fact wasn't found, throw error then terminate
		std::cout << "Error in KB::delete(): Fact not found" << std::endl;
		exit(0);
	}
         * 
         * */

}

//search the vector list for a specific fact and return ALL facts found
std::vector<Fact*>  KB::search(std::string FactName) {
	std::vector<Fact*> elements;
	for(std::vector<Fact*>::iterator x=allFacts->begin();
                 x!=allFacts->end(); ++x) { //loop through vector and search for fact
            
		if(FactName==(*x)->Name ) {//if fact name matches query search,
                 //add a copy of i to the vector 
                    elements.push_back(*x);
		}
	}
	if(elements.size()==0) { //if fact wasn't found, throw error then terminate
		std::cout << "Error in KB::search(): Fact not found" << std::endl;
	//	exit(0);
	}
	return elements;
}


