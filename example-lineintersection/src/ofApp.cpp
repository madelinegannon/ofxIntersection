#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
    for(int i=0;i<1000;i++){
        lines[i].set(ofPoint(ofRandomWidth()-ofGetWidth()/2, ofRandomHeight()-ofGetHeight()/2, ofRandom(-500,500)),ofPoint(ofRandomWidth()-ofGetWidth()/2, ofRandomHeight()-ofGetHeight()/2, ofRandom(-500,500)));
        
    }
   /*
    cam.setupPerspective();
    cam.setVFlip(false);
    ofEnableAlphaBlending();
    */
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    
    ofPoint mouse(ofGetMouseX(), ofGetMouseY(),-1);
    ofPoint mouseworld=cam.screenToWorld(mouse);
    ofPoint mouseworld2=cam.screenToWorld(ofPoint(mouse.x, mouse.y, 1));
    ofVec3f mousedir=mouseworld2-mouseworld;
    mousedir.normalize();
    ofPoint mousefinal=mouseworld+mousedir.scale(600);
    
    cam.begin();
    
    
    ofSetColor(255, 0, 0,100);
    Plane p1;
    p1.set(ofPoint(0,0,0), ofVec3f(1,0,1));
    p1.draw();
    ofSetColor(ofColor::white,100);
    Triangle tri;
    tri.set(ofPoint(-50,-50,-50), ofPoint(100,0,0), ofPoint(-20,100,40));
    tri.draw();
    
    IntersectionData idata=is.PlaneTriangleIntersection(p1, tri);
    
    
    /*
    Line l1,l2;
    l1.set(ofPoint(-500,-500,0), ofPoint(500,500,0));
    l2.set(ofPoint(-500,500,300),mousefinal);
    l1.draw();
    l2.draw();
    
    idata=is.LineLineIntersection(l1, l2);
    ofDrawSphere(idata.pos, 3);
    ofLine(idata.pos, idata.pos+idata.dir);
    ofDrawSphere(idata.pos+idata.dir,3);
    
    ofSetColor(255, 255,255);
    for(int i=0;i<1000;i++){
        lines[i].draw();
        idata=is.PointLineDistance(mousefinal, lines[i]);
        if(idata.isIntersection){
            ofDrawSphere(idata.pos, 3);
            ofPushStyle();
            ofSetColor(ofColor::red);
            ofLine(idata.pos, mousefinal);
            ofPopStyle();
        };
    }
     */
    
   cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='f'){
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}