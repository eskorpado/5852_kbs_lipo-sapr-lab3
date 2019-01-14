#ifndef word_h
#define word_h

#include "mystack.h"
#include "chstack.h"

int copy_stack_to_stack(ch_stack* in_stack, ch_stack* out_stack);
int push_stack_to_stack(ch_stack* in_stack, ch_stack* out_stack);
int pull_last_word_from_stack(ch_stack* stack, ch_stack* out_stack);

#endif