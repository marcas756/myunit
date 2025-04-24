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
