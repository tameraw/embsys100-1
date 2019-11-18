#include<assert.h>
#include"stack.h"
#include<stdio.h>

int main()
{
    int stack_values[] = {1, 2, 3};
    int *p_values = &stack_values[0];
    int actual_value;
    int actual;
    int expected;
    int expected_value;
    // Ctor test
    stack_ctor();
    // Push test
    expected = 0;
    actual = stack_push(*p_values);
    assert(actual == expected);
    // Size is 1 test
    expected = 1;
    actual = stack_size();
    assert(actual == expected);
    // not empty and not full
    assert(!stack_empty());
    assert(!stack_full());
    // Pop test
    actual_value = -1;  // invalidate before test
    expected = 0;
    expected_value = *p_values;
    actual = stack_pop(&actual_value);
    assert(actual == expected);
    assert(actual_value == expected_value);
    assert(stack_empty());
    // Push push test
    expected = 0;
    ++p_values;
    actual = stack_push(*p_values);
    assert(actual == expected);
    ++p_values;
    actual = stack_push(*p_values);
    assert(actual == expected);
    // is full test
    assert(stack_full());
    // pop
    actual_value = -1;  // invalidate before test
    expected = 0;
    expected_value = *p_values;
    actual = stack_pop(&actual_value);
    assert(actual == expected);
    assert(actual_value == expected_value);
    assert(!stack_empty());
    // pop
    --p_values;  // account for previous pop
    actual_value = -1;  // invalidate before test
    expected = 0;
    expected_value = *p_values;
    actual = stack_pop(&actual_value);
    assert(actual == expected);
    assert(actual_value == expected_value);
    // empty
    assert(stack_empty());
    assert(!stack_full());
    return 0;
}
