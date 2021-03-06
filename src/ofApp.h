#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include  "ofxAssimpModelLoader.h"
#include "Octree.h"
#include <glm/gtx/intersect.hpp>


//** Particle system and gravity start **//
#include "Particle.h"
#include "ParticleEmitter.h"

#include "Lander.h" 
//** Particle system and gravity end **//


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void checkCollisions(); 

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent2(ofDragInfo dragInfo);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawAxis(ofVec3f);
		void initLightingAndMaterials();
		void savePicture();
		void toggleWireframeMode();
		void togglePointsDisplay();
		void toggleSelectTerrain();
		void setCameraTarget();
		bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);
		bool raySelectWithOctree(ofVec3f &pointRet);
		glm::vec3 getMousePointOnPlane(glm::vec3 p , glm::vec3 n);
		//void loadVbo(ParticleEmitter e);
		void loadVbo(); 
		void loadVbo2();
		void devMode(); 
		void fuelDraw(); 
		void landerMovement(ofVec3f m);

		//for fuel 
		float startTime; // store when we start time timer
		float endTime; // when do want to stop the timer
		float activeStart = 0; // calculates current time when user applies fuel/thrusters
		float activeEnd = 0; // holds the value of the timer the last time it was set 
		float timer = 0; //for calculations with fuel 
		bool timerStarted = false; 
		
		bool  bTimerReached; // used as a trigger when we hit the timer

		ofEasyCam cam; // this is the main camera
		ofCamera cam1, cam2; // these are the other camera views
		ofCamera* theCam;

		//ofxAssimpModelLoader mars, lander;
		ofxAssimpModelLoader lunar, model; 
		Lander lander; 

		ofLight light;
		Box boundingBox, landerBounds; 
		Box testBox;
		vector<Box> colBoxList;
		bool bLanderSelected = false;
		Octree octree;
		TreeNode selectedNode; 
		glm::vec3 mouseDownPos, mouseLastPos;
		bool bInDrag = false;


		//** Particle system and gravity start **//
			ParticleEmitter landerParticle;

			GravityForce grav;
			ImpulseForce impulse;  // test for collisions;
		//** Particle system and gravity end **//

		// explosion
		ParticleEmitter emitter;

		bool bHide;
			ofxIntSlider numLevels;	// octree levels
			ofxFloatSlider gravity;	// strength of the gravity
			ofxFloatSlider damping;	// resistance force?
			ofxFloatSlider radius;	// radius of the particles
			ofxVec3Slider velocity;	// velocity of the particles TODO: change this to be the velocity of the ship? (no, change the thrust instead bc cant directly change velocity)
			ofxFloatSlider lifespan;	// lifespan of the particles
			ofxFloatSlider rate;	// particle spawn rate
			ofxFloatSlider restitution;	// bounceback
			ofxIntSlider thrustStr; // strength of the thrust, aka speed?

			ofxFloatSlider camDistance; // this is the distance of the current camera view
			ofxPanel gui;
		

		bool bAltKeyDown;
		bool bCtrlKeyDown;
		bool bWireframe;
		bool bDisplayPoints;
		bool bPointSelected;
		
		bool pointSelected = false;
		bool bDisplayLeafNodes = false;
		bool bDisplayOctree = false;
		bool bDisplayBBoxes = false;
		
		bool bLanderLoaded;
		bool bTerrainSelected;
	
		ofVec3f selectedPoint;
		ofVec3f intersectPoint;

		vector<Box> bboxList;

		const float selectionRange = 4.0;

		ParticleSystem* sys;


		//ofLight keyLight, fillLight, rimLight, light;
		ofPlanePrimitive plane;
		ofMaterial planeMaterial;


		bool bModelLoaded = false;
		bool bPlaneLoaded = false;
		bool bWireFrame = false;
		
		//ofxPanel gui;
		
		ofxToggle keyEnabled, fillEnabled, rimEnabled;

		ofxVec3Slider keyPosition, keyDiffuse, keySpecular;

		ofxVec3Slider fillPosition, fillDiffuse, fillSpecular;

		ofxVec3Slider rimPosition, rimDiffuse, rimSpecular;

		ofxFloatSlider planeShiningess;

		// textures
		//
		ofTexture  particleTex;

		// shaders
		//
		ofVbo vbo, vbo2; // vbo for booster, vbo2 for explosion
		ofShader shader;

		ofSoundPlayer   boosterSound;
		ofSoundPlayer   explosionSound;

		ofImage background;

};
