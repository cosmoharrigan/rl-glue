# Introduction #

RL-Glue agents, environments, and experiment programs, or _components_ can either be compiled together (if they are all written in C/C++ and will run on a single machine) or they can communicate over sockets if they are written in a mixture of languages or should be connected over the network.

Many RL-Glue scenarios are run over sockets on a single machine, so that the three components may be written in different languages.

A _codec_ is a small software library that knows how to translate the socket messages to a destination language.  The codec is a wrapper that allows the components to only implement  the base RL-Glue interface.  Codecs are currently written for C/C++/Java/Python.  Work is underway or scheduled to write codecs for LISP and Matlab.

If you'd like to help out by writing a codec for your favorite language, please post to the [RL-Glue Google Group](http://groups.google.com/group/rl-glue).