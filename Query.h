/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Query.h
 * Author: Nicole
 *
 * Created on February 26, 2017, 7:47 PM
 */

#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include <map>
#include "KB.h"
#include "RB.h"
#include "Rule.h"
#include "Fact.h"

std::vector<Fact*> inquire(std::string n, RB* rb, KB* kb);
std::vector<Fact*> infer(Rule *rule, RB *rb, KB *kb, std::string param1,std::string param2);
std::vector<Fact*> filter(std::vector<Fact*> unfilterfacts, std::string param1,std::string param2);
std::vector<Fact*> merge(std::vector<Fact*> facts,std::vector<Fact*>facts1);

#endif /* QUERY_H */
