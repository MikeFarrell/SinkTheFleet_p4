# SinkTheFleet_p4

Im working on play() still. Its taking a while because everything is different. Ill keep updating when i make major progress

Anyone started on play()? Wondering what to work on next... -JR

Everything should now be up to date. I apologize for the number of commits, I was changing a lot of things in a lot of files to make the program work correctly. 

As a reminder according to the things I was fixing with some of the classes and functions, if you are passing a parameter reference, do not make it const. For example, "const CShip & ship" will not allow you to use the ship reference. If you need to change the parameter, use a reference like "CShip & ship", otherwise use "const CShip ship" without the &.
