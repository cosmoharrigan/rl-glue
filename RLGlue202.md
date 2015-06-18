# RL-Glue 2.0.2 #
  * The reward may have been getting corrupted in the 2.0.1 release.
  * The Agent and Environment message have been fixed since 2.0.1.  You can use this functionality to pass messages from the experiment program to the agents and environments at runtime.  We've got some interesting things planned for it, so stay tuned!
  * You are allowed to call agent\_message and env\_message before RL\_init
  * Faster and cleaner Java Networking Code
  * Cleaned up memory leaks
  * Compiles cleanly with g++ again

**If you have any problems with RL-Glue, please feel free to post them to the Issues list so we can look into them.**

The 2.0.x release required a fairly major rewrite of large portions of RL-Glue.  We're actively maintaining and testing the glue, and we appreciate any bugs you can point us to.

**If you have suggestions for RL-Glue, please feel free to post them to the Wiki**


