#include "word.h"

int copy_stack_to_stack(ch_stack* in_stack, ch_stack* out_stack)
{
    if (char_stack_count(in_stack) == 0)
    {
        return 0;
    }
    int index = char_stack_count(in_stack);
    while (index != 0)
    {
        char value = char_stack_get_deep(in_stack, --index);
        char_stack_push(out_stack, value);
    }
}

int push_stack_to_stack(ch_stack* in_stack, ch_stack* out_stack)
{
    if (char_stack_count(in_stack) == 0)
    {
        return 0;
    }
    while (char_stack_count(in_stack) != 0)
    {
        char value = char_stack_pull(in_stack);
        char_stack_push(out_stack, value);
    }
    
    return 1;
}

int pull_last_word_from_stack(ch_stack* stack, ch_stack* out_stack) 
{
    if (char_stack_count(stack) == 0)
    {
        return 0;
    }
    int terminator_count = 0;
        
    while (terminator_count != 2) {
        if (char_stack_count(stack) == 0) {
            break;
        }
        
        char temp_stack_char = char_stack_pull(stack);
            
        if (temp_stack_char == NULL
            || temp_stack_char == "\0" 
            || temp_stack_char == -40 
            || temp_stack_char == -44 
            || temp_stack_char == 24
            || temp_stack_char == -8
        ) {
            terminator_count++;
        } else {
            char_stack_push(out_stack, temp_stack_char);
        }
    }
    
    return 1;
}