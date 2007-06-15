#include <stdio.h>
#include <stdlib.h>
#include "ZeroAgent.h"

Action theAction;
Observation theObservation;

void agent_print(const char* header, RL_abstract_type* data) {
  int i = 0;
  fprintf(stderr, "%s", header);
  fprintf(stderr, "%d %d\n", data->numInts, data->numDoubles);

  for (i = 0; i < data->numInts; ++i)
    fprintf(stderr, "%d ", data->intArray[i]);
  fprintf(stderr, "\n");

  for (i = 0; i < data->numDoubles; ++i)
    fprintf(stderr, "%f ", data->doubleArray[i]);
  fprintf(stderr, "\n");
}

void agent_init(Task_specification task_spec) {
  theAction.numInts  = 1;
  theAction.intArray = (int*)malloc(sizeof(int) * theAction.numInts);

  theAction.numDoubles  = 0;
  theAction.doubleArray = 0;
}

Action agent_start(Observation o) {
  theObservation = o;
  theAction.intArray[0] = rand();

  agent_print("agent_start observation ", &theObservation);
  agent_print("agent_start action ", &theAction);

  return theAction;
}

Action agent_step(Reward r, Observation o) {
  theObservation = o;
  theAction.intArray[0] = rand();

  agent_print("agent_step observation ", &theObservation);
  agent_print("agent_step action ", &theAction);

  return theAction;
}

void agent_end(Reward r) {
}

void agent_cleanup() {
}

void agent_freeze() {
}

char* agent_message(const char* inMessage) {
  return NULL;
}
