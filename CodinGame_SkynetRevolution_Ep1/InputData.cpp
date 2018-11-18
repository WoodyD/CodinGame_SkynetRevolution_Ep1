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

string InputData::CheckAndRemoveLink(const int & virusPos, const bool usingAStar){
    int linkIndex = 0;
    if(usingAStar)
        linkIndex = GetLinkIndexToRemoveByShortestWay(virusPos);
    else
        linkIndex = GetLinkIndexToRemove(virusPos);
    
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

int InputData::GetLinkIndexToRemove(const int & virusCoord) {
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

int InputData::GetLinkIndexToRemoveByShortestWay(const int & virusCoord) {
    vector<vector<int>> allUncheckedLinks(InputData::links);
    vector<vector<int>> allPossibleWays;
    vector<int> indexesToRemove;
    vector<int> linkToRemove;
    int index = -1;
    
    
    for(vector<int> link : InputData::links){
        index++;
        for(int & exit : InputData::exits){
            if((link[0] == exit && link[1] == virusCoord) || (link[0] == virusCoord && link[1] == exit)) {
                return index;
            }
            
            if((link[0] == exit|| link[1] == exit)) {
                indexesToRemove.push_back(index);
                allPossibleWays.push_back(link);
            }
        }
    }
    
    for (int i = (int)(indexesToRemove.size() - 1); i >= 0; i--){
        vector<vector<int>>::iterator it = allUncheckedLinks.begin();
        advance(it, indexesToRemove[i]);
        allUncheckedLinks.erase(it);
    }
    
    while(linkToRemove.empty() || !allUncheckedLinks.empty()){
        for(vector<int> & link : allPossibleWays){
            for(int curPoint : link){
                if(curPoint == virusCoord){
                    linkToRemove = link;
                    break;
                }
            }
            
            //indexesToRemove.clear();
            //index = -1;
            
            for(vector<int> linkToCheck : allUncheckedLinks){
                //index++;
                for(int curPoint : link){
                    if(linkToCheck[0] == curPoint || linkToCheck[1] == curPoint){
                        link.push_back(linkToCheck[0]);
                        link.push_back(linkToCheck[1]);
                        //indexesToRemove.push_back(index);
                        break;
                    }
                }
//                if(!indexesToRemove.empty())
//                    break;
            }
            
//            for (int i = (int)(indexesToRemove.size() - 1); i >= 0; i--){
//                vector<vector<int>>::iterator it = allUncheckedLinks.begin();
//                advance(it, indexesToRemove[i]);
//                allUncheckedLinks.erase(it);
//            }
        }
    }
    
    index = -1;
    for(vector<int> link : links){
        index++;
        if((link[0] == linkToRemove[0] && link[1] == linkToRemove[1])
           || (link[0] == linkToRemove[1] && link[1] == linkToRemove[0]))
            return index;
    }

    //if returned index -1 -> doesnt work proper
    return index;
}


