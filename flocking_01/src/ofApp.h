#pragma once

#include "ofMain.h"
#include "CBoid.h"
#include "CBox.h"
#include "CFlock.h"



// Forward declarations.
class CBox;
class CFlock;

class ofApp : public ofBaseApp{
private:
    CBox *box;
    CFlock *Flocks[MAX_FLOCKS];
    
    ofQuaternion wrld_rot;
    
    int mouseDownX, mouseDownY;
    bool inMouseDrag;
    
public:
    CFlock *FlockAtIndex(int i)
    {
        if (i < 0 || i >= MAX_FLOCKS)
            return NULL;
        
        return Flocks[i];
    }
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    ofImage backgroundImage;
};
