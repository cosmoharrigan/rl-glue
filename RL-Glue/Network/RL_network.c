#include <stdio.h>
#include <Network/RL_netlib.h> 

extern void rlSetAgentConnection(int);
extern void rlSetEnvironmentConnection(int);
extern void rlSetExperimentConnection(int);
extern int rlIsAgentConnected();
extern int rlIsEnvironmentConnected();
extern int rlIsExperimentConnected();

/* 
   rlConnectSystems is responsible for ensuring that the Glue has an agent, environment and experiment
   program before the Glue attempts to run an experiment.

   If the experiment and the Glue are compiled together RL_init calls rlConnectSystems.
   If the Glue is separate, it has its own main() that calls rlConnectSystems.   
   If all components are written in C, we can link to RL_direct.o instead of using this implementation.
*/

int rlConnectSystems() {
  int isAgentConnected       = rlIsAgentConnected();
  int isEnvironmentConnected = rlIsEnvironmentConnected(); 
  int isExperimentConnected  = rlIsExperimentConnected();
  int theClientType = 0;
  int theClient = 0;
  int theServer = 0;

  rlSocket theExperimentConnection = 0;

  if (!isAgentConnected || !isEnvironmentConnected || !isExperimentConnected) {
    theServer = rlOpen(kDefaultPort);
    rlListen(theServer, kDefaultPort);
  }

  while(!isAgentConnected || !isEnvironmentConnected || !isExperimentConnected) {
    theClient = rlAcceptConnection(theServer);
    rlRecvData(theClient, &theClientType, sizeof(int));

    switch(theClientType) {
    case kAgentConnection:
      rlSetAgentConnection(theClient);
      isAgentConnected = 1;
      break;

    case kEnvironmentConnection:
      rlSetEnvironmentConnection(theClient);
      isEnvironmentConnected = 1;
      break;

    case kExperimentConnection:
      rlSetExperimentConnection(theClient);
      isExperimentConnected = 1;
      theExperimentConnection = theClient;
      break;

    default:
      fprintf(stderr, "RL_network.c: Unknown Connection Type!\n");
      break;
    };
  }

  rlClose(theServer);

  return theExperimentConnection;
}
