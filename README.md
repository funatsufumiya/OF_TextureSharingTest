# OF TextureSharingTest

Texture Sharing example, using [ZMQ](https://github.com/funatsufumiya/ofxZmq) and [GVTextureSerializer](https://github.com/funatsufumiya/ofxGVTextureSerializer).

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
    bool atleast_one = false;
     while (subscriber.hasWaitingMessage()) {
        atleast_one = true;
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
