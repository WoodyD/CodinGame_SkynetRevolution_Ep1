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
    vector<vector<int>> allPossibleVirusWays;
    vector<int> indexesToRemove;
    
    for(vector<int> link : InputData::links){
        for(int & exit : InputData::exits){
            if((link[0] == exit && link[1] == virusCoord) || (link[0] == virusCoord && link[1] == exit)) {
                return GetIndexByLink(link, links);
            }
        }
        
        if(link[0] == virusCoord) {
            indexesToRemove.push_back(GetIndexByLink(link, links));
            allPossibleVirusWays.push_back(link);
        } else if(link[1] == virusCoord) {
            indexesToRemove.push_back(GetIndexByLink(link, links));
            swap(link[0], link[1]);
            allPossibleVirusWays.push_back(link);
        }
    }
    
    RemoveElementsByIndex(allUncheckedLinks, indexesToRemove);
    
    while(!allUncheckedLinks.empty()){
        indexesToRemove.clear();
        vector<vector<int>> newWays;
        
        for(vector<int> & virusLink : allPossibleVirusWays){
            for(int curVirusPoint : virusLink){
                for(int exit : exits){
                    if(curVirusPoint == exit){
                        return GetIndexByLink(virusLink, links);
                    }
                }
            }
            
            int virusLastPosition = virusLink.back();
            
            for(vector<int> linkToCheck : allUncheckedLinks){
                if(linkToCheck[0] == virusLastPosition){
                    newWays.push_back(linkToCheck);
                    int curIndex = GetIndexByLink(linkToCheck, allUncheckedLinks);
                    if (find(indexesToRemove.begin(), indexesToRemove.end(), curIndex) == indexesToRemove.end())
                        indexesToRemove.push_back(curIndex);
                    
                } else if(linkToCheck[1] == virusLastPosition){
                    swap(linkToCheck[0], linkToCheck[1]);
                    newWays.push_back(linkToCheck);
                    int curIndex = GetIndexByLink(linkToCheck, allUncheckedLinks);
                    if (find(indexesToRemove.begin(), indexesToRemove.end(), curIndex) == indexesToRemove.end())
                        indexesToRemove.push_back(curIndex);
                    
                }
            }
        }
        allPossibleVirusWays.clear();
        allPossibleVirusWays = newWays;
        RemoveElementsByIndex(allUncheckedLinks, indexesToRemove);
        
    }
    
    return -1;
}

int InputData::GetIndexByLink(const vector<int> & linkToCheck, const vector<vector<int>> & vectorToCheck){
    int index = -1;
    
    for(const vector<int> & link : vectorToCheck){
        index++;
        if((link[0] == linkToCheck[0] && link[1] == linkToCheck[1])
           || (link[0] == linkToCheck[1] && link[1] == linkToCheck[0]))
            return index;
    }
    
    return index;
}

void InputData::RemoveElementsByIndex(vector<vector<int> > &removeFrom, vector<int> &indexes) {
    sort(indexes.begin(), indexes.end());
    for (int i = (int)(indexes.size() - 1); i >= 0; i--){
        vector<vector<int>>::iterator it = removeFrom.begin();
        advance(it, indexes[i]);
        removeFrom.erase(it);
    }
}

