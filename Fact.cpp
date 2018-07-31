/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Fact.cpp
 * Author: Nicole
 * 
 * Created on February 17, 2017, 11:53 AM
 */

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <vector>

#include <iostream>
#include "Fact.h"

// Fact constuctor for special cases
Fact::Fact(std::string n,std::string n1, std::string n2){
	Name = n;
	param.at(0) = n1;
	param.at(1) = n2;
}

// Standard fact constructor with string parsing
Fact::Fact(std::string n){
	Name = n.substr(0,n.find("("));
	//counts the number of params
	int count=1;
	for(unsigned int i = 0; i <n.length();i++)
	{
		std::string temp = n.substr(i,1);
		if(temp.find(",")==0)
		{
			count++;
		}
	}

	//Parse from the string n to a vector of params
	for(int i = 0; i < count ;i++)
	{
		if(i==0)
		{
			param.push_back(n.substr(n.find("(")+1, n.find(",")- n.find("(")-1));
			n = n.substr(n.find(","),n.length() - n.find(","));
		}
		else if(i == count -1)
		{
			param.push_back(n.substr(n.find(",")+1, n.find(")")- n.find(",")-1));
		}
		else
		{
			param.push_back(n.substr(1,n.find(",",2)-1));
			n = n.substr(n.find(",",2),n.length() - n.find(",",2));
		}

	}

}

// Fact destructor
Fact::~Fact(){
	    for(std::vector<std::string>::iterator itr = param.begin(); itr != param.end(); ++itr)
    {
	//delete *(itr);
	param.erase(itr);
	}
	param.clear();
	
}







