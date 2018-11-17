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

void InputData::AddLink(const int n1, const int n2) {
    vector<int> link;
    link.push_back(n1);
    link.push_back(n2);
    InputData::links.push_back(link);
}

string InputData::CheckAndRemoveLink(const int virusPos){
    int linkIndex = GetLinkIndexToRemove(virusPos);
    
    // ? Check this. There must be a better way to do this.
    string removedLink = "";
    removedLink += to_string(InputData::links[linkIndex][0]);
    removedLink += " ";
    removedLink += to_string(InputData::links[linkIndex][1]);
    
    vector<vector<int>>::iterator it = InputData::links.begin();
    advance(it, linkIndex);
    InputData::links.erase(it);
    
    return removedLink;
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

vector< vector<int> > InputData::GetLinks() const {
    return InputData::links;
}

int InputData::GetLinkIndexToRemove(const int virusCoord) {
    int index = -1;
    
    for(vector<int> & link : InputData::links){
        index++;
        for(int & exit : InputData::exits){
            if((link[0] == exit && link[1] == virusCoord) || (link[0] == virusCoord && link[1] == exit)) {
                return index;
            }
        }
    }
    
    return index;
}

