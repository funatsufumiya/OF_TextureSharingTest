# OF TextureSharingTest

Realtime Texture Sharing example, using [ZMQ](https://github.com/funatsufumiya/ofxZmq) and [GVTextureSerializer](https://github.com/funatsufumiya/ofxGVTextureSerializer). Transferring bytes size is 1/40 (max) smaller than normal RGBA8 texture transport.

(this code is receiver (ZMQ_SUB). tested with [godot_TextureSharingTest](https://github.com/funatsufumiya/godot_TextureSharingTest))

## Dependencies

- oF 0.11 - 0.12
- ofxZmq: https://github.com/funatsufumiya/ofxZmq
- ofxGVTextureSerializer: https://github.com/funatsufumiya/ofxGVTextureSerializer

## Code (Receiver)

```cpp
ofxGVTextureSerializer serializer;
ofTexture tex;
ofxZmqSubscriber subscriber;

void ofApp::setup(){
    ofLogToConsole();
    ofSetFrameRate(60);
    
    subscriber.connect("tcp://localhost:5555");
}

void ofApp::update(){
     while (subscriber.hasWaitingMessage()) {
        ofBuffer buffer;
        subscriber.getNextMessage(buffer);

        if (buffer.size() > 0) {
            try {
                tex = serializer.deserialize(buffer);
            } catch (std::exception& e) {
                ofLogError() << e.what();
            }
        }
     }
}

void ofApp::draw(){
    if (tex.isAllocated()) {
        tex.draw(0, 0);
    }
}
```

## Code (Sender)

```cpp
ofxGVTextureSerializer serializer;
ofFbo fbo;
ofxZmqPublisher publisher;

void ofApp::setup(){
    ofLogToConsole();
    ofSetFrameRate(60);
    
    fbo.allocate(512, 512, GL_RGBA); // must be GL_RGBA
    publisher.bind("tcp://*:5555");
}

void ofApp::update(){
    fbo.begin();
    ofClear(0);
    ofSetColor(255);
    
    // draw rotating triangle
    ofPushMatrix();
    ofTranslate(fbo.getWidth() / 2, fbo.getHeight() / 2);
    ofRotateDeg(ofGetElapsedTimef() * 30);
    ofDrawTriangle(0, -100, 87, 100, -87, 100);
    ofPopMatrix();

    fbo.end();
    
    ofBuffer buffer = serializer.serializeTexture(fbo.getTexture());
    publisher.send(buffer);
}
