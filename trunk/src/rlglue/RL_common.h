/* 
* Copyright (C) 2007, Adam White

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

* 
*  $Revision$
*  $Date$
*  $Author$
*  $HeadURL$
* 
*/


#ifndef RLcommon_h
#define RLcommon_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#define __RL_CHECK_STRUCT(X)  if(__rlglue_check_abstract_type(X)!=0){printf("Struct failed validity check at file %s line %d\n",__FILE__,__LINE__);exit(__rlglue_check_abstract_type(X));}


typedef double reward_t;
typedef int terminal_t;
typedef char* message_t;
typedef char* task_specification_t;

/* Strings are not guaranteed to be null terminated I think */
typedef struct
{
	unsigned int numInts;
	unsigned int numDoubles;
	unsigned int numChars;
	int* intArray;
	double* doubleArray;
	char* charArray;
} rl_abstract_type_t;

typedef rl_abstract_type_t observation_t;
typedef rl_abstract_type_t action_t;
typedef rl_abstract_type_t random_seed_key_t;
typedef rl_abstract_type_t state_key_t;

typedef struct{
  observation_t o;
  action_t a;
} observation_action_t;

typedef struct
{
  reward_t r;
  observation_t o;
  terminal_t terminal;
} reward_observation_t;

typedef struct {
  reward_t r;
  observation_t o;
  action_t a;
  terminal_t terminal;
} reward_observation_action_terminal_t;

void __rlglue_print_abstract_type(const rl_abstract_type_t *theStruct);
int __rlglue_check_abstract_type(const rl_abstract_type_t *theStruct);
char * __rlglue_get_svn_version();

#ifdef __cplusplus
}
#endif

#endif