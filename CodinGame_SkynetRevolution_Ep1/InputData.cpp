//
//  InputData.cpp
//  CodinGame_SkynetRevolution_Ep1
//
//  Created by Woody on 07/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include "InputData.hpp"

InputData::InputData(int nods, int links, int exits) {
    InputData::numberOfNods = nods;
    InputData::numberOfLinks = links;
    InputData::numberOfExits = exits;
}

void InputData::AddExit(const int exit) {
    InputData::exits.push_back(exit);
}

void InputData::AddLink(const vector<int> link) {
    InputData::links.push_back(link);
}

int InputData::NumberOfNods() const{
    return InputData::numberOfNods;
}

int InputData::NumberOfExits() const{
    return InputData::numberOfExits;
}

int InputData::NumberOfLinks() const{
    return InputData::numberOfLinks;
}

vector<int> InputData::GetExits() const {
    return InputData::exits;
}

vector<vector<int> > InputData::GetLinkAtIndex() const {
    return InputData::links;
}
