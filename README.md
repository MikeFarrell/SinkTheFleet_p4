
# SinkTheFleet_p4

If you guys want, try the version in the branch I made, using the Player1.shp and Player2.shp files. I will be working on that version. -JW

Hey ya, that saveGrid and getGrid() we had earlier was working fine. 
I'm reverting back to last working version.  -jr

i still have the working version that i have been updating with your changes. Do you guys want to meet up in the lab before class today? I'm good to head over there now with all the files if you want -JW

Is it working for anyone?  Revert back?  Everything was working ok before.. 

well now it's not working. I'm getting hundreds of errors.-jr

i made several changes to Play() in the csinkthefleet.cpp. I will check the changes you committed. -JW

if you want i can start moving your recent changes to my branch and then we can merge it. I have options for excluded ships, verification of ship location, handling for ships out of bounds when reading from file, etc. -JW

hmm, I didn't see the other branch I thought it was all on the main page there.  It's working though
if you get all the updated files.  We're still missing the option for user to verify the location for each ship..
-jr

no. Idk if you guys want to use it but i made a better getGrid, saveGrid, and setShips function and updated play(), plus added a bunch of commenting in jconwhit-game-working branch. I downloaded the master branch and its not working for me. Either that or i bugged it out -JW

I think it's all there, it's working on my end..   I just added a copy constructor and
assignment operator= to CPlayer.cpp and CPlayer.h.  They're not being used
anywhere right now.. -jr

is it showing up properly? I tried to merge the two together and it should be showing up in Cplayer - mf

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
