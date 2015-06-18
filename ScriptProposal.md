# Introduction #
Our design of our rl-glue so far has been slightly contradictory. We'd like it to be very easy to use for a non-programmer, but at the same time we don't want to impose any structure that could make it simpler to use. I propose that we do add some structure and create some scripts to help make rl-glue incredibly easy to set up and use.


# Details #

Here is how I imagine rl-glue could be used:

The user has rl-glue installed somewhere on their system... like /usr/local (doesn't really matter exactly where). One thing installed with rl-glue is a script called rl-glue (in /usr/local/bin/rl-glue maybe). This script is the starting point for using rl-glue:

```
# rl-glue myproject
```

This will create a directory called myproject which contains the following folders:

```
myproject/
-agents/
-environments/
-experiments/
-utilities/
-script/
```

This last folder is the real important one.. the rest doesn't necessarily have to be structured exactly like that.

So, the user now has the structure for an rl-glue project. The script could even create an xcode project if given the appropriate option.

The next thing the user would probably want to do is create an agent:

```
# cd myproject
# script/generate agent java sarsaAgent
A agents/sarsaAgent.java
A agents/RL-agent.java
A agents/makefile
```

So, this script creates skeleton code for an agent (java in this case). Also, I'm showing it creating an extra file called RL-agent.java that contains main (but that's a separate issue, this is just to show how this structure could help solve such issues).

The script also generate a simple, well-documented makefile that will properly build the agent.

So, the process is the same for environments and experiments... Then to build everything and run it, something like this:

```
# script/build
Building RL-glue... done
Building RL-agent... done
Building RL_environment... done
Build complete. To run:
./RL-glue
./RL-agent
./RL-environment
```


Ok, so lets say that the user needs tile code for their agent. Maybe the tiles code is located at http://rlai.cs.ualberta.ca/svn/tiles. Then:

```
script/plugin install http://rlai.cs.ualberta.ca/svn/tiles
A utilities/tiles.cpp
A utilities/tiles.h
Tiles plugin installed. To use in your agent, include tiles.h:
#include "utilities/tiles.h"
...
```


This is just a rough sketch of what we could do. The idea would be to make all of these scripts give really clear instructions about what to do next after they are done. Also, the code of these scripts should be written in something very readable like ruby or python and be VERY well documented, so that if a user wanted to they could adapt them.
