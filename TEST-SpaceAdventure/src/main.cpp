//
//  main.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include <iostream>

#include "View/LifeCycle/LifeCycle.hpp"

int main(int argc, char* args[]) {
    
    LifeCycle LifeCycle;
    
    LifeCycle.Play();
    
    LifeCycle.QuitGame();

    return 0;
}
