//  main.cpp
//  CodinGame_SkynetRevolution_Ep1
//
//  Created by Woody on 07/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//
//  Test cases for episode 1: https://www.codingame.com/ide/puzzle/skynet-revolution-episode-1
//  Test cases for episode 2: https://www.codingame.com/ide/puzzle/skynet-revolution-episode-2

#include <iostream>
#include <string>
#include <vector>

#include "InputData.hpp"

using namespace std;

int main()
{
    int N;// cerr << "N - the total number of nodes in the level, including the gateways" << endl;
    int L;// cerr << "L - the number of links" << endl;
    int E;// cerr << "E - the number of exit gateways" << endl;
    cerr << "Enter N L E: " << endl;
    //cin >> N >> L >> E; cin.ignore();
    N = 8; L = 13; E = 2;
    InputData data(N, L, E);

    data.AddLink(6, 2); data.AddLink(7, 3);
    data.AddLink(6, 3); data.AddLink(5, 3);
    data.AddLink(3, 4); data.AddLink(7, 1);
    data.AddLink(2, 0); data.AddLink(0, 1);
    data.AddLink(0, 3); data.AddLink(1, 3);
    data.AddLink(2, 3); data.AddLink(7, 4);
    data.AddLink(6, 5);

    data.AddExit(4);
    data.AddExit(5);
    
//    cerr << "N1 and N2 defines a link between these nodes. " << endl;
//    for (int i = 0; i < L; i++) {
//        int N1; cerr << "Enter N1 N2: " << endl;
//        int N2;
//        cin >> N1 >> N2; cin.ignore();
//        data.AddLink(N1, N2);
//    }
//    data.AddLink(0, 1);
//    data.AddLink(0, 2);
//    data.AddLink(1, 3);
//    data.AddLink(2, 3);
//
//    for (int i = 0; i < E; i++) {
//        int EI; cerr << "Enter the index of a gateway node: " << endl;
//        cin >> EI; cin.ignore();
//        data.AddExit(EI);
//    }
    
    // game loop
    while (1) {
        int SI; cerr << "The index of the node on which the Skynet agent is positioned this turn :" << endl;
        cin >> SI; cin.ignore();
        string link = "";
        
        //Scynet Revolution Episode1 solution:
        //link = data.CheckAndRemoveLink(SI);

        //Scynet Revolution Episode2 solution:
        link = data.CheckAndRemoveLink(SI, true);
        
        cout << link << endl;
    }
}

