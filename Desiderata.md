# Design Goals #

RL-Glue is an interface for connecting reinforcement learning agents, environments, and experiments.

The RL-Glue software project is an implementation of the RL-Glue interface that supports single-agent, discrete-time, lock-step reinforcement learning between agents, environments, and experiments (_components_) developed by different people, potentially in different languages, which can be run on different physical machines.

Our design and ongoing improvement to the RL-Glue software project is guided by two principles"

  * Require minimal buy-in
  * Provide maximum flexibility

## Require Minimal Buy-In ##
The RL-Glue interface should make you implement components the same way you'd want to implement them -- you should not have to contort your code in uncomfortable ways to implement traditional reinforcement learning.

This is a stronger statement than it might sound:

  * You should be able to use any programming language you want
    * Caveat : you may have to write a [Codec](Codec.md) so that RL-Glue components in other languages know how to talk to your agent.
  * You should be able to use any platform you want
  * You should be able to use any programming paradigm you want (functional, procedural, object oriented)

**Not done : Talk about function interface, network codecs, and the ability to wrap functions in objects if you want.**

## Provided Maximum Flexibility ##
The RL-Glue interface should let you do things that weren't expected by the RL-Glue team.

