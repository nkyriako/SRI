/*
 *parse the file to read 
 * write a KB and RB to txt file, adding in the formatting 
 * print a fact to the screen but formatted 
 */

/* 
 * File:   main.cpp
 * 
 *
 * Created on February 17, 2017, 11:23 AM
 */

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "KB.h"
#include "RB.h"
#include "Rule.h"
#include "Fact.h" 
#include "Query.h"


//method to strip whitespace and newlines from strings 
std::string removeSpace(std::string &S) {
    
    S.erase(std::remove_if(S.begin(), S.end(), 
            [](char c){
                return (c=='\r'||c=='\n'||c==' ');
            }), S.end() );
    return S;
}

//method to remove the first word of a string 
std::string removeFirst(std::string& S) {
    std::string::size_type x =0;
    x=S.find_first_not_of(" \t", x);
    x=S.find_first_of(" \t", x);
    S.erase(0, S.find_first_not_of(" \t", x));
    
    std::cout<<S;
    return S;
}


//calls the query class, passing a string argument
void INFERENCE(std::string obj, RB *rb, KB *kb) {
    //wrapper call query 
    //prints vector of results
	//check if second word
	removeSpace(obj);
	vector<Fact*> facts=inquire(obj, rb, kb);

	// Code for adding inferenced Facts/Rules disfunctional

	/*for(std::vector<Fact*>::iterator x=(kb->allFacts)->begin();
	 x!=(kb->allFacts)->end(); ++x) {
	 std::cout<<"FACT (";
	 std::cout<<(*x)->Name;		//x pointer?
	 for (auto P=((*x)->param).begin(); P!=((*x)->param).end(); ++P) {
	 std::cout <<*P;
	 if (P!=((*x)->param).end()-1) {
	 std::cout<<",";
	 }
	 }
	 std::cout<<")\n";
	 }
	/*for (int i = 0; i < facts.size(); i++)
	 {
	 std::cout << i <<"\n";
	 std::cout << facts.at(i)->Name << "(";
	 std::cout << facts.at(i)->param.at(0) << ",";
	 std::cout << facts.at(i)->param.at(1) << ")\n";
	 }

	if (removeSpace(namestr).length() != 0) {

		//if second word, rename all to that second word
		for (int i = 0; i < facts.size(); i++) {
			kb->add(
					new Fact(namestr, facts.at(i)->param.at(0),
							facts.at(i)->param.at(1)));
		}
	} else {*/

	for (int i = 0; i < facts.size(); i++)
	{
		std::cout << i <<"\n";
		std::cout << facts.at(i)->Name << "(";
		std::cout << facts.at(i)->param.at(0) << ",";
		std::cout << facts.at(i)->param.at(1) << ")\n";
	}
}

//deletes fact or rule
void DROP(std::string obj, KB *kb, RB *rb) {
    //search through KB and RB for name, then delete 
    //STRIP WHITESPACE
    removeSpace(obj);
    kb->del(obj);
    rb->delRule(obj);
}

//***********************************************************

//Dumps the contents of KB and RB to an SRI file 
void DUMP(std::string filename, KB *kb, RB *rb) {
    std::cout << "Dumping to " << filename << std::endl;
    //STRIP WHITESPACE
    removeSpace(filename);
    
    //create and open file with name filename
    std::ofstream file;
    file.open(filename);
    
    
    //for each member of rb.allRules, dump the rule
    for(std::map<std::string, Rule*>::iterator x=(rb->allRules)->begin();
            x!=(rb->allRules)->end(); ++x ) {
 
        //if we implement the vector in each rule,
        //dump first section of rule 
        //for x in kb, 
            //dump rulename and associated vector 
        file<<"RULE ";
        file<<(x->first);
        file<<"(";
        for (std::vector<std::string>::iterator P=((x->second)->param).begin();
                 P!=((x->second)->param).end(); ++P) {
                    file <<*P;
                 if (P!=((x->second)->param).end()-1) {
                   file <<",";
                 }
         }
        file<<"):- ";
	if ((x->second)->op == 'O') {
		file <<"OR ";
	} else {
		file <<"AND ";
	}


        file<<(x->second)->Name1<<"(";
         //dump second rule name and associated vector
         for (std::vector<std::string>::iterator P=((x->second)->param1).begin();
                 P!=((x->second)->param1).end(); ++P) {
                file<<*P;
                if (P!=((x->second)->param1).end()-1) {
                   file <<",";
                } 
         }
        //dump third rule name and associated vector
        file<<") "<<(x->second)->Name2<<"(";
         for (std::vector<std::string>::iterator P=((x->second)->param2).begin();
                P!=((x->second)->param2).end(); ++P) {
                    file<<*P;
                if (P!=((x->second)->param2).end()-1) {
                   file <<",";
                } 
         }
        file<<")\n";
    }
    

    //for each member of kb.array, dump the fact
    for(std::vector<Fact*>::iterator x=(kb->allFacts)->begin(); 
            x!=(kb->allFacts)->end(); ++x) {
        file<<"FACT ";
	file<<(*x)->Name;		//x pointer?
	file<<"(";
        for (auto P=((*x)->param).begin(); P!=((*x)->param).end(); ++P) {
            file <<*P;
            if (P!=((*x)->param).end()-1) {
                file<<",";
            }
        }
		file<<")\n";
    }
    //close the file
    file.close();
}


//loads the KB and RB with contents of given SRI file 
void LOAD(std::string filename, KB *kb, RB* rb) {
    removeSpace(filename);
    if (filename == "") {
	std::cout<<"No filename Specified. \n";
        throw(false);
    }
    std::cout << "Loading from" << filename << std::endl;
    
    std::string line = ""; //string to read lines from input 
    std::ifstream readFile(filename); //opens the input file 
    std::string word =""; //fact or rule prefix
    std::size_t SECOND; //index of word after the prefix
    
    //line by line add rules/facts to the RB/KB
    while(std::getline(readFile, line)) {
        std::stringstream iss(line); //load into string stream
    
        //if fact, add to KB
        //if rule, add to RB
        if (iss>>word) {
            SECOND = line.find(word);
            if (word=="RULE") {
                //not sure if this works
                rb->add( new Rule(removeFirst(line))); //New?
            } else if (word == "FACT") {
                kb->add(new Fact(removeFirst(line)));
            }
        }
        
    }
    
    
}



int main(int argc, char** argv) {
    
    KB *kb = new KB();
    RB *rb = new RB();
    
    std::string line;
    std::string word;
    
    std::cout  << "Enter commands, followed by input" << std::endl;
    std::cout << "Enter 'EXIT' to exit the program" <<std::endl;
    bool takingInput = true;
    
    while(takingInput) {
       std::getline(std::cin, line);
        std::istringstream iss(line);
        
        //Look at the first word 
        if(iss >> word){
           
            
            //pass substring of 'line' without the beginning word
   
            if (word=="RULE"){
                    //new rule
                    rb->add(new Rule(removeFirst(line))); //new
            } else if (word=="FACT"){
                    // new fact 
                    kb->add(new Fact(removeFirst(line))); //new
            } else if (word=="INFERENCE"){
                    //make a query
                    INFERENCE(removeFirst(line), rb, kb);
            } else if (word=="DROP") {
                    //drop fact or rule 
                    DROP(removeFirst(line), kb, rb);
            } else if (word == "LOAD") {
                    LOAD(removeFirst(line), kb, rb);
            } else if(word == "DUMP") {
                    DUMP(removeFirst(line), kb, rb);
            } else if (word =="EXIT") {
                takingInput=false;
            } else {
             std::cout <<"Not a valid command." 
             <<"Valid commands are LOAD, DROP, INFERENCE, FACT, RULE, DUMP ";
            }
            //else the argument is invalid 
        } else {
            std::cout <<"Not a valid command." 
             <<"Valid commands are LOAD, DROP, INFERENCE, FACT, RULE, DUMP " ;
        }
        std::cout << "\n";
    }
    
    
    std::cout << "Exiting Program..." << std::endl;
	delete rb;
	delete kb;
    return 0;
}

