/* 
 * File:   KB.h
 * Author: mjloyola
 */

#include <vector>
#include <string>
#include "Fact.h"

#ifndef KB_H
#define KB_H

class KB {
private:
	// Fact count
	int numFacts;
public:	
	// Vector of Facts
        std::vector<Fact*> *allFacts;
	// Constructors/Destructors
	KB();
	virtual ~KB();
	// Add Facts to the KB
	Fact add(Fact *FactObj);
	// Remove Facts from KB
	void del(std::string FactName);
	// Search for Facts matching a string
	std::vector<Fact*> search(std::string FactName);
};

#endif /* KB_H */
