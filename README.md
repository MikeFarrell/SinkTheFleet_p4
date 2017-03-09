# SinkTheFleet_p4


If were just ignoring all the work i did that made the program work in my branch let me know what i can do at this point - JW


I'm gonna check through everything a few times..  I think there's some missing
operator [] overload() still, I'm confused what those are supposed to do, if 
anyone wants to do those. Let me know if you come across any bugs -jr

Anything else that needs to be worked on? My build seems to be running fine. If not I will work on test plan, sample output, etc.

Should be working now -MF

Hey Mike, so I put up my new CPlayer.cpp file with the validLocation(), but I made a new branch or pull request thing
because I didn't have the hitShip() and other stuff you just put in.  Can 
you update it so it has both of our changes? -jr

Hey so I got isValidLocation() done, and did some work on setShips().  I 
might have to make some changes to save() and getgrid() though. -jr

Working on hithship - mf

I put up some saved grid files for testing, smallGrid1 and 2, and largeGrid1 and 2. 
The load/save part works now.  Added some stuff to the sinkTheFleet constructor.
I moved the 'select grid size' to the very beginning of game because the sinkTheFleet
constructor needs it. 

There's still some problem with setShips() and validLocation(), you can overwrite a 
position right now.. Then it's supposed to confirm the location with user for each ship. 

DETAILS ARE IN THE "WORKING ON COMMENTS" COMMIT 
