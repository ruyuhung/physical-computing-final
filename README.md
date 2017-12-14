<p align="center">
Final Project - Physical Computing and the Internet of Things
 </p>

#### *Name: Ruby Hung*
#### *Date: 12.12.2017*

<p align="center">
<h1>
Project: Multifaceted SoundScape - A study on infinity mirror
</h1>
</p>

![alt](https://github.com/ruyuhung/physical-computing-final/blob/master/Pics/MultifacetedLogo.jpg)

## Introduction:
In this project, I explore the affordance of [Sparkfun Sound Detector](https://www.sparkfun.com/products/12642) and its embodiment onto an "[Infinity Mirror](https://en.wikipedia.org/wiki/Infinity_mirror),"  hologram, and servo motor. To explore multiple ways of converting the analog audio input to various facets of output, I choose different objects from the LED strips to a generative holography by JavaScript and the kinetic energy of a servo motor. The reason that I select infinity mirror as the stage not only because of its dramatic and aesthetic visual representation but also the looping concept which resonates with the programming world and the potential which technology evolves,  transforms and reinvents itself. My project is positioned between the subjects of computing, visual programming, computer-based (or handmade)  artifacts, and the imagination of future space. The primary practice would be to process documenting and critical making analysis.

## Concept Description:
In the following section, I divide my project into smaller topics with diagrams which could be better understood through individual discussion.

### Soundscape:
The soundscape is the environmental audio that could be perceived by humans. It is not confined to only one specific type of sound source but also others, such as natural and human-generated audio. The term was first used in 1969 by Michael Southworth in his article 'The Sonic Environment of Cities.' [(2)](http://dx.doi.org/10.1177/001391656900100104), And it gradually becomes a general terminology in the realm of an audio and immersive environment. The soundscape is adopted here to denote the relationships between our audio environment and the effects generated by sound.

### Infinity Mirror:
Infinity mirror is my primary display in this project. The main structure of infinity mirror is in the following diagram.  It consists of two layers of mirrors. In the front is a piece of 'two-way mirror' and at the back is the standard mirror. If we place anything in between, we will see two mirrors interact with each other, and the two-way mirror allows the audience to look through it. In general, it is a phenomenon of endless reflection between two pieces of mirrors. (1)
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/InfinityMirror.PNG)

### Holography
The choice of holography is the imagination of future space. As several sci-fi movies have shown, in the future, the urban landscape would be concrete buildings with the intangible but visible hologram, for instance, in 'Blade Runner 2049,' future cities are depicted as giant holographic figures could interact with humans.
Holography means the process of making hologram which empowers the audience to see the three-dimensional images without putting any other devices on themselves. It is a phenomenon first introduced by a Hungarian-born physicist, Dennis Gabor, in 1948. To construct a hologram, it has to be at least two layers of optical fields. An interference for diffracting the light and the reconstruction of images constitute a holographic image. For more detailed optical physics description please [click here](https://www.britannica.com/technology/holography#toc3271).
Here, I construct a simplified version of a holography made by four pieces of the acrylic sheet, and the content will be sound generated graph by p5*JS.
![alt](https://github.com/ruyuhung/physical-computing-final/blob/master/Pics/P5Page1.jpg)

### Inspiration and Critical Making:
I am fascinated by the potentials which technology empowers us and the shift of paradigm from traditional craftsmanship to technology users(or consumers). Also, the contrast between precise analog reading data to an illusion of infinity mirror is intriguing. The holographic image is my imagination of future space. And through the material engagement practice, I learn the particular characteristic of each object. As the "Critical Making" indicated and emphasized, the difference between maker movement and critical making lies in its process.

## Technical Practice:

### Physical Form
It will be a cube  of 7" * 7" * 7" with three sides of mirrors. The front mirror will be the infinity mirror. In additions, a servo motor placed in the middle would respond to the sound as well. Next to the stage, by putting a hologram (made by acrylics) that shows the visualization of the sound. The size is determined by the printer bed of Ultimaker2 which co-lab has, and it is 8" * 8" * 8"

### Input and output
The following diagram shows the input and output devices in this project. (1)
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/InputOutput.png)

### Wiring diagram
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/Sound_breadboard.jpg)

### Material, Hardware, and Software Used
	• Electronic Components:
		○ Particle RedBoard
		○ Sound detector
		○ LED strip (WS2812)
		○ Servo motor ()
		○ Screen Display for hologram (iPad)
	• Enclosure Components:
		○ 3D printed frame
	• Infinity Mirror Material:
		○ 12 * 12 inch acrylic mirror
		○ 12 * 12 two way mirror sheet
		○ 12 * 12 acrylic board (1/8")
	• Software and Hardware:
		○ Fusion 360
		○ Adobe Illustrator
		○ P5*Js
		○ Particle IDE
		○ Fusion Laser Cutter
		○ Ultimaker 2 (3D printer)

### Sound Detector Test (click to watch the link)
[![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/SoundDetector_Test.jpg)](https://youtu.be/0kD-XAbrdFI)

### Prototype of the Prototype (click to watch the link)
Before using the LED strip (WS2812), I soldered the individual led together and build a simple stand from the rest of my material. See how the led reacts to sound detector in the following video.
[![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/InfinityMirror_Test.jpg)](https://youtu.be/By63XaNeQ3g)

### Particle.io
##### My entire code in particle [soundscape_Rainbow.ino](https://github.com/ruyuhung/physical-computing-final/blob/master/code/soundscape_Rainbow.ino)

#### particle variable
I use Particle Cloud to send the audio data to the JavaScript. Firstly, sending the integer through `Particle.variable`.
```C++
#define PIN_ANALOG_IN A0

Particle.variable("soundValue", &val, INT);

int readSound()
{
    val = analogRead(PIN_ANALOG_IN);
    return val;
}
```

### P5*JS programming
#### [My entire p5*JS code](https://github.com/ruyuhung/physical-computing-final/blob/master/code/sketch.js)
#### [My LoadSound HTML Webpage](http://people.duke.edu/~jh518/Sound/soundTest.html) [Live Demo Webpage](http://people.duke.edu/~jh518/Sound/sound.html)
(When it is not reading the sound input, this is another similar webpage constructing by random value. This is the html reading the sound value and producing circle graph accordingly.)

In P5*JS libraries, I use loadJSON function to call the data from the particle cloud. And I create another function called `function parseData` to store the analog reading value.
```JavaScript
var url ='https:/api.particle.io/v1/devices/320039001751353432393433/soundValue?access_token=394d3c6278fbfca17465503aeaeea4c05fc2eb1f';
data = loadJSON(url, parseData);
```
And generate four identical circles for the hologram and also set the ellipse diameter as the reading data from the sound detector.
```JavaScript
function parseData(data)
{
  reading = data.result;
}
```

### Laser Cutting:
For precise cutting of mirrors and acrylics, I use the "Epilog Fusion M2 Laser" Cutter to cut 7 * 7 inch mirror and acrylic hologram designed by Adobe Illustrator.
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/LaserCutting_pic.jpg)
#### Cutting Completed
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/Hologram.JPG)
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/LaserCutting_01.JPG)

### 3D Design
For the frames of infinity mirror, I used Autodesk Fusion 360 and print them out by 'ultimaker2' provided by Co-Lab at Duke.
#### 3D model rendering
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/illusionMirrorStand_SideA.png)
![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/IllusionMirrorStand_Fusion360.png)

## Result:
The following video demo is the result of my project with some brief introduction.
<!-- [![alt](https://github.com/ruyuhung/MultifacetedSoundScape/blob/master/Pics/SoundDetector_Test.jpg)](https://youtu.be/0kD-XAbrdFI) -->



## Conclusion:

### Evaluation:
In this project, the primary purpose is to combine all the tools we've learned in class. It is a good combination of tools, from basic redboard controls to particle variables and loadJSON, from  soldering, laser cutting, to 3D modeling. For the general concept of my project, it is easy for the audience to perceive, for example, the audio input and various outputs. Aesthetically, the printed model, I used dark blue spray paint to make the background consistent with a darker color. The neopixel strips and the led stands could stand out of the context.  In the limited time scope, the consistent visual of my project is one of the pros.
On the other hand, the direct sound output might need more varieties instead of blinking the LED or. The originality part might have room for improvement; however,  as a prototype, this two positions helped me understand the basic structure of this art representation. Personally, it could be a high start point for future creativity.

### Reflection:
During the process, the shift of making process is the first thing that occurs to me. Before, it is hard to imagine the possibility of making the frames of mirrors and even putting a responding light into it without a well-equipped carpenter house and maybe some designing background. The difference between regular tutorials on 'How to make an illusion mirror?' and my approach is distinct. Firstly, in most of the previous cases, the frames are made out of wood, and the entire process is primarily in a cutting logic. On the contrast, with the help of 3D printers, the overall experience is "Building," the digital technology which allowed me to transform the cutting process from real life into the computer-aided modeling (CAD) software. Often, you will need a lot of carpenter tools, such as a hand saw, claw hammer, chisel, nail gun, wood bench, and sawhorse.  
Another crucial question appears along the way as well. Am I a critical maker or just a technology consumer? Not a seasoned 3d modeler nor a trained designer, but the basic understanding of solid modeling workflow allows me to taste the fruit of really designing something.

In the future,  I am interested in applying rasberryPi and API to my project. Also, I hope to explore more of the neopixel control and do more research on the light control and reaction. For now, the blinking effect seems to be predictable. In additions, it would be great to learn more about the potential of generative javascript graph.



## Reference:
1. Hand drawing diagram by Ruby Hung, software used: [Fifty Three](https://www.fiftythree.com/)
2. Southworth, M. (1969). The sonic environment of cities. Environment and Behavior, 1(1), 49-70.
http://dx.doi.org/10.1177/001391656900100104
3. Garnet Hertz, Critical Making - Conversations, http://www.conceptlab.com/criticalmaking/
4. https://www.particle.io/
5. https://www.sparkfun.com/
6. https://p5js.org/reference/
7. https://cloud.3dprinteros.com/
