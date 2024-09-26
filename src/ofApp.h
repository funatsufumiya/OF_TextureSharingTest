#pragma once

#include "ofMain.h"

#include "libsharedmemory.hpp"
#include "ofxGVTextureSerializer.h"

class ofApp : public ofBaseApp{

	public:
		std::shared_ptr<lsm::SharedMemoryReadStream> sm_reader;
		std::shared_ptr<lsm::SharedMemoryWriteStream> sm_writer;

		ofxGVTextureSerializer serializer;
		ofTexture tex;

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
		
};
