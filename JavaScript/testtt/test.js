var cX;
var cY;
var spdX = 0;
var spdY = 0;
var on = false;

function setup() {
    createCanvas(windowWidth, windowHeight);
}
//create circle
function draw() {
    background(0);
    noStroke();
    fill(255);
    cX = width / 2;
    cY = height / 2;
    circle(cX, cY, 100);

    //boundry
    if (cX >= width) {
        spdX = random(-1, -5);
    }
    if (cX <= width) {
        spdX = random(1, 5);
    }
    if (cY >= height) {
        spdY = random(-1, -5);
    }
    if (cY <= height) {
        spdY = random(1, 5);
        } 
    cX += spdX;
    cY += spdY;
}
//click to restar
function mousePressed() {
    on = !on;
    if (on) {
        spdX = random(2,5);
        spdY = random(2,5);
    } else {
        spdX = 0;
        spdY = 0;
    }
}