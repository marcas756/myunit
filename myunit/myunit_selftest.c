/*****************************************************************************
 *                                                                           *
 *  MyUnit – A lightweight unit testing framework for embedded C projects    *
 *                                                                           *
 *  Forked from uCUnit (C) 2007–2008 Sven Stefan Krauss                      *
 *                  https://www.ucunit.org                                   *
 *                                                                           *
 *  (C) 2025 Marco Bacchi                                                    *
 *      marco@bacchi.at                                                      *
 *                                                                           *
 *  File        : myunit.h                                                   *
 *  Description : Macros for unit testing                                    *
 *  Author      : Marco Bacchi                                               *
 *                                                                           *
 *****************************************************************************/

/*
 * This file is part of MyUnit, a fork of uCUnit.
 *
 * It is licensed under the Common Public License Version 1.0 (CPL-1.0),
 * as published by IBM Corporation and approved by the Open Source Initiative.
 *
 * MyUnit incorporates substantial modifications and extensions to the original
 * uCUnit codebase. The original work is:
 *   (C) 2007–2008 Sven Stefan Krauss, https://www.ucunit.org
 *
 * This file is distributed under the CPL in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the CPL for details.
 *
 * A copy of the license should have been provided with this distribution,
 * or can be found online at:
 *     http://www.opensource.org/licenses/cpl1.0.txt
 */
#include "myunit.h"


MYUNIT_TESTCASE(test_assert)
{
    // Test case description: This test case demonstrates a passing and a failing example of assertions.
    // The assertions will check simple conditions for equality and inequality.

    // Passing Assertion:
    // Test that 1 + 1 equals 2. This is expected to pass.
    MYUNIT_ASSERT("Check if 1 + 1 equals 2", (1 + 1 == 2));

    // Failing Assertion:
    // Test that 1 + 1 equals 3. This is expected to fail.
    MYUNIT_ASSERT("Check if 1 + 1 equals 3", (1 + 1 == 3));
}


MYUNIT_TESTCASE(test_assert_val_equal)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_EQUAL.
    // It compares two variables for equality.

    int a = 5;
    int b = 5;
    int c = 10;

    // Passing Assertion:
    // Test that variable 'a' is equal to variable 'b'. This is expected to pass as both are 5.
    MYUNIT_ASSERT_EQUAL(a, b);

    // Failing Assertion:
    // Test that variable 'a' is equal to variable 'c'. This is expected to fail as a is 5 and c is 10.
    MYUNIT_ASSERT_EQUAL(a, c);
}

MYUNIT_TESTCASE(test_assert_val_different)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_DIFFER.
    // It compares two variables to check if they are different.

    int x = 3;
    int y = 4;
    int z = 3;

    // Passing Assertion:
    // Test that variable 'x' is different from variable 'y'. This is expected to pass as x is 3 and y is 4.
    MYUNIT_ASSERT_DIFFER(x, y);

    // Failing Assertion:
    // Test that variable 'x' is different from variable 'z'. This is expected to fail as both x and z are 3.
    MYUNIT_ASSERT_DIFFER(x, z);
}

MYUNIT_TESTCASE(test_assert_mem_equal)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_MEM_EQUAL.
    // It compares two memory blocks for equality.

    int buffer1[5] = {1, 2, 3, 4, 5};
    int buffer2[5] = {1, 2, 3, 4, 5};
    int buffer3[5] = {5, 4, 3, 2, 1};

    // Passing Assertion:
    // Test that 'buffer1' is equal to 'buffer2'. This is expected to pass since both buffers have the same values.
    MYUNIT_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

    // Failing Assertion:
    // Test that 'buffer1' is equal to 'buffer3'. This is expected to fail since the buffers have different values.
    MYUNIT_ASSERT_MEM_EQUAL(buffer1, buffer3, sizeof(buffer1));
}




MYUNIT_TESTCASE(test_assert_mem_different)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_MEM_DIFFERENT.
    // It compares two memory blocks to check if they are different.

    int buffer1[5] = {1, 2, 3, 4, 5};
    int buffer2[5] = {1, 2, 3, 4, 5};
    int buffer3[5] = {5, 4, 3, 2, 1};

    // Passing Assertion:
    // Test that 'buffer1' is different from 'buffer3'. This is expected to pass as both buffers have different values.
    MYUNIT_ASSERT_MEM_DIFFERENT(buffer1, buffer3, sizeof(buffer1));

    // Failing Assertion:
    // Test that 'buffer1' is different from 'buffer2'. This is expected to fail as both buffers have the same values.
    MYUNIT_ASSERT_MEM_DIFFERENT(buffer1, buffer2, sizeof(buffer1));
}




MYUNIT_TESTCASE(test_assert_32bit)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_32_BIT.
    // It checks if the given value fits within a 32-bit unsigned integer range.

    uint64_t value1 = 0xFFFFFFFF;      // 32-bit maximum value (should pass)
    uint64_t value2 = 0x1FFFFFFFF;     // Exceeds 32-bit range (should fail)

    // Passing Assertion:
    // Test that 'value1' fits within the 32-bit unsigned integer range. This is expected to pass.
    MYUNIT_ASSERT_32BIT(value1);

    // Failing Assertion:
    // Test that 'value2' fits within the 32-bit unsigned integer range. This is expected to fail.
    MYUNIT_ASSERT_32BIT(value2);
}



MYUNIT_TESTCASE(test_assert_16bit)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_16BIT.
    // It checks if the given value fits within a 16-bit unsigned integer range.

    uint32_t value1 = 0xFFFF;      // 16-bit maximum value (should pass)
    uint32_t value2 = 0x1FFFF;     // Exceeds 16-bit range (should fail)

    // Passing Assertion:
    // Test that 'value1' fits within the 16-bit unsigned integer range. This is expected to pass.
    MYUNIT_ASSERT_16BIT(value1);

    // Failing Assertion:
    // Test that 'value2' fits within the 16-bit unsigned integer range. This is expected to fail.
    MYUNIT_ASSERT_16BIT(value2);
}




MYUNIT_TESTCASE(test_assert_8bit)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_8BIT.
    // It checks if the given value fits within an 8-bit unsigned integer range.

    uint16_t value1 = 0xFF;      // 8-bit maximum value (should pass)
    uint16_t value2 = 0x1FF;     // Exceeds 8-bit range (should fail)

    // Passing Assertion:
    // Test that 'value1' fits within the 8-bit unsigned integer range. This is expected to pass.
    MYUNIT_ASSERT_8BIT(value1);

    // Failing Assertion:
    // Test that 'value2' fits within the 8-bit unsigned integer range. This is expected to fail.
    MYUNIT_ASSERT_8BIT(value2);
}




MYUNIT_TESTCASE(test_assert_bit_clr)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_BIT_CLR.
    // It checks whether a specific bit in the middle of a given value is cleared.

    uint32_t value1 = 0xFFFFFBFF;   // All bits set except bit 10 (bit 10 is cleared)
    uint32_t value2 = 0xFFFFFFFF;   // All bits set (no bit is cleared)
    uint32_t bit_to_check = 10;     // We are checking bit 10

    // Passing Assertion:
    // Test that bit 10 is cleared in 'value1'. This is expected to pass since bit 10 is cleared.
    MYUNIT_ASSERT_BIT_CLR(value1, bit_to_check);

    // Failing Assertion:
    // Test that bit 10 is cleared in 'value2'. This is expected to fail since all bits are set.
    MYUNIT_ASSERT_BIT_CLR(value2, bit_to_check);
}


MYUNIT_TESTCASE(test_assert_bit_set)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_BIT_SET.
    // It checks whether a specific bit in the middle of a given value is set.

    uint32_t value1 = 0xFFFFFBFF;   // Bit 10 is set
    uint32_t value2 = 0xFFFFF7FF;   // Bit 10 is cleared
    uint32_t bit_to_check = 11;     // We are checking bit 11

    // Passing Assertion:
    // Test that bit 11 is set in 'value1'. This is expected to pass since bit 11 is set.
    MYUNIT_ASSERT_BIT_SET(value1, bit_to_check);

    // Failing Assertion:
    // Test that bit 11 is set in 'value2'. This is expected to fail since bit 11 is cleared.
    MYUNIT_ASSERT_BIT_SET(value2, bit_to_check);
}



MYUNIT_TESTCASE(test_checkpoint_passed)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_CHECKPOINT_PASSED.
    // It checks whether a specific checkpoint has been passed (bit set) using the MYUNIT_ASSERT_CHECKPOINT_PASSED macro.

    // Set up checkpoint system
    MYUNIT_CHECKPOINS_INIT();    // Initialize all checkpoints to 0
    uint32_t checkpoint_bit = 5; // We are checking checkpoint 5

    // Set checkpoint 5
    MYUNIT_CHECKPOINT_SET(checkpoint_bit);

    // Passing Assertion:
    // Test that checkpoint 5 has been passed (bit is set). This is expected to pass.
    MYUNIT_ASSERT_CHECKPOINT_PASSED(checkpoint_bit);

    // Failing Assertion:
    // Test that checkpoint 6 has been passed (bit is not set). This is expected to fail.
    MYUNIT_ASSERT_CHECKPOINT_PASSED(6);
}

MYUNIT_TESTCASE(test_checkpoint_missed)
{
    // Test case description: This test case demonstrates a passing and a failing example using MYUNIT_ASSERT_CHECKPOINT_MISSED.
    // It checks whether a specific checkpoint has been missed (bit not set) using the MYUNIT_ASSERT_CHECKPOINT_MISSED macro.

    // Set up checkpoint system
    MYUNIT_CHECKPOINS_INIT();    // Initialize all checkpoints to 0
    uint32_t checkpoint_bit = 5; // We are checking checkpoint 5

    // Set checkpoint 5
    MYUNIT_CHECKPOINT_SET(checkpoint_bit);

    // Passing Assertion:
    // Test that checkpoint 6 has been missed (bit is not set). This is expected to pass.
    MYUNIT_ASSERT_CHECKPOINT_MISSED(6);

    // Failing Assertion:
    // Test that checkpoint 5 has been missed (bit is set). This is expected to fail.
    MYUNIT_ASSERT_CHECKPOINT_MISSED(checkpoint_bit);
}


static int custom_action_executed = 0; // Global check variable

void custom_action(void) {
    MYUNIT_PRINTF("Custom Action Invoked\n");
    custom_action_executed = 1; // Set the check variable when action is executed
}


MYUNIT_TESTCASE(set_action_success) {
    custom_action_executed = 0; // Reset the check variable
    MYUNIT_SET_ACTION(custom_action); // Set the custom action
    MYUNIT_ASSERT("Trigger custom action", 0); // Trigger a failure to invoke the custom action
    MYUNIT_ASSERT_EQUAL(custom_action_executed, 1); // Verify that the action was executed
}

MYUNIT_TESTCASE(reset_action) {
    custom_action_executed = 0; // Reset the check variable
    MYUNIT_SET_ACTION(NULL); // Reset the action to NULL
    MYUNIT_ASSERT("No action should execute", 1); // Ensure no failure happens
    MYUNIT_ASSERT("Trigger custom action", 0); // Trigger a failure to invoke the custom action
    MYUNIT_ASSERT_EQUAL(custom_action_executed, 0); // Verify that the action was not executed
}



void myunit_testsuite_setup()
{

}

void myunit_testsuite_teardown()
{

}

MYUNIT_TESTSUITE(selftest)
{
    MYUNIT_TESTSUITE_BEGIN();

    MYUNIT_EXEC_TESTCASE(test_assert);
    MYUNIT_EXEC_TESTCASE(test_assert_val_equal);
    MYUNIT_EXEC_TESTCASE(test_assert_val_different);

    MYUNIT_EXEC_TESTCASE(test_assert_mem_equal);
    MYUNIT_EXEC_TESTCASE(test_assert_mem_different);

    MYUNIT_EXEC_TESTCASE(test_assert_32bit);
    MYUNIT_EXEC_TESTCASE(test_assert_16bit);
    MYUNIT_EXEC_TESTCASE(test_assert_8bit);

    MYUNIT_EXEC_TESTCASE(test_assert_bit_clr);
    MYUNIT_EXEC_TESTCASE(test_assert_bit_set);

    MYUNIT_EXEC_TESTCASE(test_checkpoint_passed);
    MYUNIT_EXEC_TESTCASE(test_checkpoint_missed);

    MYUNIT_EXEC_TESTCASE(set_action_success);
    MYUNIT_EXEC_TESTCASE(reset_action);

    MYUNIT_TESTSUITE_END();
}
