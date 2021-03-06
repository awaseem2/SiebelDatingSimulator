# Project Proposal

The project I want to do is an rpg version of the Adventure game project we worked on months ago. 
I would like to use the same json and general movements/actions that were in the original game. I want the 
game to essentially be a visual version of everything that was in the text based version of Adventure, along with
arrow keys for movement to make it feel more like a game. For instance, there would be different 
"rooms" to travel to and monsters to battle in each of the rooms.
I would also improve on the original game by implementing new functionality such as a character select at the beginning that
effects the stats of your character, and having more rooms that aren't just filler rooms with nothing in them. The reason 
I want to do this for my final is because Adventure was my favorite MP we've done in class and I'd like to experience 
making a non-console based game from scratch. 

There are many ways I plan on implementing OpenFrameworks into my project. Though I won't know everything I need until I'm actually
coding the game, for now I know that I'm gonna use ofTimer to have some sort of a timer in the game, ofImage to implement
sprites for the characters, and I could give some of the more complicated graphics methods from the graphics portion of OF a try
like ofShader and ofPixels, since I plan on using pixel art for my graphics.

I've also found the library [Allegro](http://liballeg.org/) to use which is a library that focuses on video games. I plan on using this
library's full screen mode to make for a better user experience and to handle mouse input more accurately since OF clicks depend on
where the position clicked is in reference to other  objects. I would also use [Rapid Json](http://rapidjson.org/) to read
my JSon file since it seems to have good performance and would allow me to reuse my old JSon instead of integrating the story
into my actual code. It also has functions such as "pretty" which fixes indentations to make adding to my previous json
more convenient.

I don't have a ton of experience with making games really, but I believe the fact that I'm using an old class project has given me 
the advantage of having an idea of the overall code already. The last snake project and the extra credit additions I implemented
also introduced me a lot to OF and its many possibilities involving mouse clicks and basic graphics such as shapes. While not being
directly related to CS, I also have experience with making pixel art which should help with the art aspect of the game 
since it's not something new to me. I'm excited to learn a lot in this experience and I'm happy to go back to my favorite project
I've worked on this semester.