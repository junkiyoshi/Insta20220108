#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(2);
	ofEnableDepthTest();
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofRotateY(15 * sin(ofGetFrameNum() * 0.05));
	ofRotateX(15 * cos(ofGetFrameNum() * 0.05));

	int span = 60;

	for(int i = 0; i < 5; i++){

		if (i < 3) {

			ofRotateY(90);
		}
		else if (i < 4) {

			ofRotateX(90);
		}
		else if (i < 5) {

			ofRotateX(180);
		}

		for (int x = span * -5; x < span * 5; x += span) {

			for (int y = span * -5; y < span * 5; y += span) {

				ofColor color;
				color.setHsb(12, 255, 255);

				ofSetColor(color, 64);
				ofFill();

				int r = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0035), 0, 1, 0, 4);

				auto location = glm::vec3(x, y, span * 4);

				if (r == 1) {

					location += glm::vec3(span, 0, 0);
				}
				else if (r == 2) {

					location += glm::vec3(span, span, 0);
				}
				else if (r == 3) {

					location += glm::vec3(0, span, 0);
				}

				int deg_start = r * 90;
				ofBeginShape();
				ofVertex(location + glm::vec3(span * cos(deg_start * DEG_TO_RAD), span  * sin(deg_start * DEG_TO_RAD), span));
				for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

					auto radius = span * 0.5;
					ofVertex(location + glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), span));
				}
				ofVertex(location + glm::vec3(span  * cos((deg_start + 90) * DEG_TO_RAD), span  * sin((deg_start + 90) * DEG_TO_RAD), span));
				ofEndShape();

				r = (r + 2) % 4;

				location = glm::vec3(x, y, span * 4);
				if (r == 1) {

					location += glm::vec3(span, 0, 0);
				}
				else if (r == 2) {

					location += glm::vec3(span, span, 0);
				}
				else if (r == 3) {

					location += glm::vec3(0, span, 0);
				}

				deg_start = r * 90;
				ofBeginShape();
				ofVertex(location + glm::vec3(span * cos(deg_start * DEG_TO_RAD), span  * sin(deg_start * DEG_TO_RAD), span));
				for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

					auto radius = span * 0.5;
					ofVertex(location + glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), span));
				}
				ofVertex(location + glm::vec3(span  * cos((deg_start + 90) * DEG_TO_RAD), span  * sin((deg_start + 90) * DEG_TO_RAD), span));
				ofEndShape();

				//

				ofSetColor(color);
				ofNoFill();

				r = (r + 2) % 4;

				location = glm::vec3(x, y, span * 4);

				if (r == 1) {

					location += glm::vec3(span, 0, 0);
				}
				else if (r == 2) {

					location += glm::vec3(span, span, 0);
				}
				else if (r == 3) {

					location += glm::vec3(0, span, 0);
				}

				deg_start = r * 90;
				ofBeginShape();
				ofVertex(location + glm::vec3(span * cos(deg_start * DEG_TO_RAD), span  * sin(deg_start * DEG_TO_RAD), span));
				for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

					auto radius = span * 0.5;
					ofVertex(location + glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), span));
				}
				ofVertex(location + glm::vec3(span  * cos((deg_start + 90) * DEG_TO_RAD), span  * sin((deg_start + 90) * DEG_TO_RAD), span));
				ofEndShape();

				r = (r + 2) % 4;

				location = glm::vec3(x, y, span * 4);
				if (r == 1) {

					location += glm::vec3(span, 0, 0);
				}
				else if (r == 2) {

					location += glm::vec3(span, span, 0);
				}
				else if (r == 3) {

					location += glm::vec3(0, span, 0);
				}

				deg_start = r * 90;
				ofBeginShape();
				ofVertex(location + glm::vec3(span * cos(deg_start * DEG_TO_RAD), span  * sin(deg_start * DEG_TO_RAD), span));
				for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

					auto radius = span * 0.5;
					ofVertex(location + glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), span));
				}
				ofVertex(location + glm::vec3(span  * cos((deg_start + 90) * DEG_TO_RAD), span  * sin((deg_start + 90) * DEG_TO_RAD), span));
				ofEndShape();

				ofSetColor(color);
				ofNoFill();
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}