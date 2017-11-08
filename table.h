/*
 * table.h
 *
 *  Created on: 8 lis 2017
 *      Author: Geotronics
 */

#ifndef TABLE_H_
#define TABLE_H_

struct Table_Entry
{
    unsigned int  current_state_id;
    unsigned char transition_letter;
    unsigned int  next_state_id;
    void (*fp)();
};

Table_Entry const* table_begin(void);
Table_Entry const* table_end(void);

#endif /* TABLE_H_ */
