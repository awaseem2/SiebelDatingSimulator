# Week of April 14th

This week I worked on drawing the tiles both in terms of the graphics and with drawing them on the screen. I also created a main character
and added the ability to move it from tile to tile with arrow keys.

I've been struggling a lot with making certain tiles not able to be walked through. I will make sure to finish that soon.

# Week of April 21st

Certain border and wall tiles are no longer able to be walked through. 

The file paths of images are no longer hard coded and are now read in from an xml file. This change allows for more rooms to be added in the future without any hassle. I decided to use pugi for reading the xml file since it seemed really simple to use and is fairly popular which makes debugging easier.

I created an npc class which reads in phrases from the xml file, and I created "collision detection" between the npc and player.  When
the player collides with an npc, it prints one of the npc's images on the screen. This goes away when the player moves away.

I also changed how the character walks a little. I added enums of the "direction" the player is facing which makes the code easier to read.
and it makes sense to change the player's direction in update rather than doing everything in the draw method.

A huge problem I've been dealing with is how slow the player moves. I believe this is a consequence of drawing the map (which is drawing
14 x 15 tiles) every frame using a for loop. I'm not sure if this is fixable, but I'm gonna look into if it's possible to only draw
the map once since that's stagnant and only in the background.

# Week of April 28th

This week I worked on finalizing my game by making sure all of my big goals were fulfilled first and foremost. I fixed the lag
issue of last week by drawing an ofImage of the map instead of drawing each tile individually, since having an image and just keeping
the tiles for reference of the player's next tile had the same effect without the time wasted with a for loop called for every frame,
as was done previously.

I also added a second room and the ability to move back and forth between the two rooms. This wasn't too much of a hastle, I just had to
make sure my xml file and how I parsed it worked for different rooms.

I then added a greeting message that is displayed when the player is near an npc. This was then followed by "options" drawn under the
greeting for the user to click on. This affects the player's 'charisma' and 'romance' levels which are displayed constantly 
at the bottom of the screen. A problem I encountered while working on this was preventing the user from "cheating" and going back to the npc to get maximum stat points. In order to solve this, I had to add a method to player that keeps track of the rooms that have already been visited, and then only draw the options to the screen if it is a new room.

Sadly, I didn't get to finish everything I had envisioned. I wanted to add a third room and have some sort of "ending". I also wanted to
add items so that you can give them to npcs and it would affect your charisma/romance levels accordingly. If I had more time,
I'm sure these things wouldn't have been too hard to add due to my fairly flexible code. I think what I've finished thus far is a
good basis since anything additional wouldn't change the code drastically in any way.
