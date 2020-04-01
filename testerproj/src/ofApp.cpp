#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    kinect.init();
    kinect.open();
    
    colorImg.allocate(kinect.getWidth(), kinect.getHeight());
    grayImg.allocate(kinect.getWidth(), kinect.getHeight());
    background.allocate(kinect.getWidth(), kinect.getHeight());
    
    bLearnBackground = true;
    threshold = 80;
    
    snapCounter = 0;
    bSnapShot = false;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    

    
    bool bNewFrame = false;
    
    kinect.update();
    bNewFrame = kinect.isFrameNew();
    
    
    if (kinect.isFrameNew()) {
        colorImg.setFromPixels(kinect.getPixels());
        grayImg = colorImg;
        if (bLearnBackground == true){
            background = grayImg;
            bLearnBackground = false;
        }
        
        grayDiff.absDiff(background, grayImg);
        
        contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, false);
     
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //colorImg.draw(0,0);
    //grayImg.draw(0,0);
    //background.draw(0,0);
    grayDiff.draw(0,0);
    
    ofFill();
    ofSetHexColor(0x333333);
    ofDrawRectangle(360, 540, 320, 240);
    ofSetHexColor(0xffffff);
    
    contourFinder.draw();
    
  
    ofSetColor(255,0,0);
    
    
    
    
    
//    if (bSnapShot == true){
//        img.grabScreen(, <#int y#>, <#int w#>, <#int h#>)
//    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bLearnBackground = true;
            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
