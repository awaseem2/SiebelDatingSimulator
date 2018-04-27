# Week of April 14th

This week I worked on drawing the tiles both in terms of the graphics and with drawing them on the screen. I also created a main character
and added the ability to move it from tile to tile with arrow keys.

I've been struggling a lot with making certain tiles not able to be walked through. I will make sure to finish that soon.

# Week 21st

Certain border and wall tiles are no longer able to be walked through. The file paths of images are no longer hard coded and are now
read in from an xml file. This change allows for more rooms to be added in the future without and hassle. I decided to use pugi for reading the xml file since it seemed really simple to use and is fairly popular which makes debugging easier.

I created an npc class which reads in phrases from the xml file, and I created "collision detection" between the npc and player. 

I also changed how the character walks a little. I added enums of the "direction" the player is facing which makes the code easier to read.
and it makes sense to change the player's direction in update rather than doing everything in the draw method.

A huge problem I've been dealing with is how slow the player moves. I believe this is a consequence of drawing the map (which is drawing
14 x 15 tiles) every frame using a for loop. I'm not sure if this is fixable, but I'm gonna look into if it's possible to only draw
the map once since that's stagnant and only in the background.
