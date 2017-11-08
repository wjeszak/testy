/*
 * state_machine.cpp
 *
 *  Created on: 8 lis 2017
 *      Author: Geotronics
 */

#include <iostream>
#include <stdio.h>
#include "table.h"

using namespace std;

void Execute_State_Machine(void)
{
    unsigned int current_state = 0;
    while (1)
    {
        char transition_letter;
        cout << "Current state: " << current_state << "\n";
        cout << "Enter transition letter: ";
        cin >> transition_letter;
        cin.ignore(1000, '\n'); /* Eat up the '\n' still in the input stream */
        Table_Entry const *  p_entry = table_begin();
        Table_Entry const * const  p_table_end =  table_end();
        bool state_found = false;
        while ((!state_found) && (p_entry != p_table_end))
        {
            if (p_entry->current_state_id == current_state)
            {
                if (p_entry->transition_letter == transition_letter)
                {
                    cout << "State found, transitioning"
                         << " from state " << current_state
                         << ", to state " << p_entry->next_state_id
                         << "\n";
                    current_state = p_entry->next_state_id;
                    // wywolanie funkcji
                    if(p_entry->fp == NULL)
                    	cout << "Pusty wskaznik!";
                    else
                    	p_entry->fp();
                    state_found = true;
                    break;
                }
             }
             ++p_entry;
         }
         if (!state_found)
         {
             cerr << "Transition letter not found, current state not changed.\n";
         }
    }
}
