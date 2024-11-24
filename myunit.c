/*! \copyright

   https://opensource.org/license/mit/

   Copyright 2013-2023 Marco Bacchi <marco@bacchi.at>

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without
   restriction, including without limitation the rights to use,
   copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following
   conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
   OTHER DEALINGS IN THE SOFTWARE.
*/

/*!
    \file myunit.c
    \brief A lightweight unit testing framework for embedded systems.
    \details
*/

#include "myunit.h"

char *myunit_testsuite_name;                 /*!< Name of the current test suite */
char *myunit_testcase_name;                  /*!< Name of the current test case */
int myunit_testsuite_assert_fail_count;      /*!< Failed assertions in the test suite. */
int myunit_testsuite_assert_success_count;   /*!< Successful assertions in the test suite. */
int myunit_testcase_assert_success_count;    /*!< Successful assertions in the current test case. Reset after each test case. */
int myunit_testcase_assert_fail_count;       /*!< Failed assertions in the current test case. Reset after each test case.*/
int myunit_testcase_success_count;           /*!< Successfully completed test cases in the test suite. */
int myunit_testcase_fail_count;              /*!< Failed test cases in the test suite. */

void (*myunit_action)(void) = NULL;

MYUNIT_CHECKPOINTS(MYUNIT_CHECKPOINT_SIZE);

void myunit_exec_testcase(void(*testcase)(void), char* name)
{
       myunit_testcase_assert_fail_count  = 0;
       myunit_testcase_assert_success_count  = 0;
       myunit_testcase_name = name;
       MYUNIT_PRINTF("%s %s %s\n",myunit_testcase_begin_tag,myunit_testsuite_name,name);
       testcase();
       MYUNIT_PRINTF("%s %s %s %d %d\n",myunit_testcase_end_tag,myunit_testsuite_name,name,myunit_testcase_assert_fail_count,myunit_testcase_assert_success_count);
       myunit_testsuite_assert_fail_count+=myunit_testcase_assert_fail_count;
       myunit_testsuite_assert_success_count+=myunit_testcase_assert_success_count;
       (myunit_testcase_assert_fail_count)?(myunit_testcase_fail_count++):(myunit_testcase_success_count++);
}
