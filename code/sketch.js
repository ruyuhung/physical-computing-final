
var data; //contain the reading input
var reading =0;
var currentM; // for condition

// four identical circles for hologram
  var circle1 = { x: 1000/4, y: 1000/2 };
  var circle2 = { x: 1000/2, y: 1000/4 };
  var circle3 = { x: 1000*3/4, y: 1000/2 };
  var circle4 = { x: 1000/2, y: 1000*3/4 };



function setup() {
  createCanvas (1000,1000);
  background(0);
  frameRate(20);
  var url = 'https://api.particle.io/v1/devices/320039001751353432393433/soundValue?access_token=394d3c6278fbfca17465503aeaeea4c05fc2eb1f';
  data = loadJSON(url, parseData);
  currentM = millis();




}

function callAPI()
{
  var url ='https:/api.particle.io/v1/devices/320039001751353432393433/soundValue?access_token=394d3c6278fbfca17465503aeaeea4c05fc2eb1f';
  data = loadJSON(url, parseData);
}

function mousePressed()
{
  clear();


}
function draw() {
    //This is for testing the drawing works
    // var diameter = random(30,80)*frameCount*0.01;
    // var r = random(150, 200);
    // var b = random(100, 190)*frameCount*0.01;
    //
    // noStroke();
    // fill(r, 0, b);
    // ellipse(circle1.x, circle1.y, diameter+10, diameter+10);
    // ellipse(circle2.x, circle2.y, diameter+10, diameter+10);
    // ellipse(circle3.x, circle3.y, diameter+10, diameter+10);
    // ellipse(circle4.x, circle4.y, diameter+10, diameter+10);
    //
    //
    // noStroke();
    // fill(r-30, 0, b+20);
    // ellipse(circle1.x, circle1.y, diameter, diameter);
    // ellipse(circle2.x, circle2.y, diameter, diameter);
    // ellipse(circle3.x, circle3.y, diameter, diameter);
    // ellipse(circle4.x, circle4.y, diameter, diameter);






  //This is the real drawing for data input
  if ((millis()-currentM)>1000)
  {
  callAPI();
  text(reading, 20,20);
  fill(200,200,200);
  ellipse(circle1.x, circle1.y, radius, radius);
  ellipse(circle2.x, circle2.y, radius, radius);
  ellipse(circle3.x, circle3.y, radius, radius);
  ellipse(circle4.x, circle4.y, radius, radius);

  }

}


function parseData(data)
{
  reading = data.result; // the statement after data has to be the names in JSON!!!
  radius = map(reading, 0, 500, 1, 500); // map the audio envolope input to the size of 1/4*canvas
}
