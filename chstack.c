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

#include <stdlib.h>
#include "chstack.h"

void char_stack_init(ch_stack* stack, size_t size)
{
    stack->size = size;
    stack->count = 0;
    stack->ptr = calloc(stack->size, sizeof(char));
}

void char_stack_done(ch_stack* stack)
{
    stack->size = 0;
    stack->count = 0;
    free(stack->ptr);
}

void char_stack_clean(ch_stack* stack)
{
    stack->count = 0;
}

int char_stack_count(ch_stack* stack)
{
    return stack->count;
}

void char_stack_push(ch_stack* stack, char value)
{
    if (stack->count >= stack->size) {
        return;
    }
    stack->ptr[stack->count++] = value;
}

char char_stack_pull(ch_stack* stack)
{
    if (stack->count == 0) {
        return -1;
    }
    return stack->ptr[--stack->count];
}

char char_stack_get_deep(ch_stack* stack, int index)
{
    if (stack->count == 0 || index < 0 || stack->count < index) {
        return -1;
    }
    return stack->ptr[index];
}

int char_stack_top(ch_stack* stack)
{
    if (stack->count == 0) {
        return -1;
    }
    return stack->ptr[stack->count];
}

int char_stack_is_empty(ch_stack* stack)
{
    return stack->count == 0;
}

int char_stack_is_full(ch_stack* stack)
{
    return stack->count >= stack->size;
}