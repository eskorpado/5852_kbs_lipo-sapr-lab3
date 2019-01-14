/*
This file is part of Reverse Notation Calc.

    Reverse Notation Calc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef _chstack_h
#define _chstack_h

#include <stddef.h>

typedef struct {
    char *ptr;
    size_t size;
    size_t count;
} ch_stack;

void char_stack_init(ch_stack* stack, size_t size);
void char_stack_done(ch_stack* stack);

void char_stack_push(ch_stack* stack, char value);
char char_stack_pull(ch_stack* stack);

void char_stack_clean(ch_stack* stack);
int char_stack_count(ch_stack* stack);

char char_stack_get_deep(ch_stack* stack, int index);

int char_stack_top(ch_stack* stack);
int char_stack_is_empty(ch_stack* stack);
int char_stack_is_full(ch_stack* stack);

#endif