#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//set camera parameter
	cam.setDistance(10.0);
	cam.setNearClip(.1);
	cam.setTarget(glm::vec3(0, 0, 0));
	ofNoFill();


	gui.setup(); // most of the time you don't need a name
	gui.add(normalToggle.setup("draw normal", false, 100.0, 50.0));
	gui.add(normalLength.setup("normal length", 0.5, 0.0, 1.0));


	//m.loadMesh();
	loadFile(OBJFNAME);
	m.calcNormal();
	m.printStats();
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::loadFile(const char* fname)
{
	ofFile file;

	file.open(ofToDataPath(fname), ofFile::ReadWrite, false);
	ofBuffer buff = file.readToBuffer();

	for (auto line : buff.getLines())
	{
		istringstream lineSS(line);
		string lineType;
		lineSS >> lineType;

		if (lineType == "v")	// if vertex
		{
			float x, y, z, w = 1;
			lineSS >> x >> y >> z >> w;
			m.verts.push_back(glm::vec3(x, y, z)); // ignoring w for now
		}
		else if (lineType == "vt")	// else if texture
		{
			// ignore for now
			// float u, v, w;
			// lineSS >> u >> v >> w;
		}
		else if (lineType == "vn")	// else if normal
		{
			// float i, j, k;
			// lineSS >> i >> j >> k;
		}
		else if (lineType == "f")	// else if face
		{
			vector <int> vInd;	// vertex indices
			vector <int> vtInd;	// texture indices
			vector <int> vnInd;	// normal indices

			string refStr;
			while (lineSS >> refStr)
			{
				istringstream ref(refStr);	// turn string into an input string stream
				string vStr, vtStr, vnStr;
				getline(ref, vStr, '/');
				getline(ref, vtStr, '/');
				getline(ref, vnStr, '/');
				int v  = atoi(vStr.c_str())  - 1;	// read vertex index, convert from 1 base indexing to 0
				int vt = atoi(vtStr.c_str()) - 1;	// read texture index, convert from 1 base indexing to 0
				int vn = atoi(vnStr.c_str()) - 1;	// read normal index, convert from 1 base indexing to 0

				vInd.push_back(v);				// store vertex index
				vtInd.push_back(vt);			// store texture index
				vnInd.push_back(vn);			// store normal index
			}
			// only keep first three vertices for now
			// TODO: for polygons larger than triangles, triangulate
			// check at least 3 vertices
			if (vInd.size() < 3)
			{
				cout << "error face has " << vInd.size() << " < 3 vertices" << endl;
				exit();
			}
			m.tInd.push_back(glm::ivec3(vInd[0], vInd[1], vInd[2]));
		}
		else if (lineType == "l")	// else if line
		{
			// ignore for now
		}
		else if (lineType == "" || lineType == "#")	// else if empty line or comment
		{
			// ignore
		}
		else cout << "unknown line type: " << lineType << endl;
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	// draw each triangle
	for (int i = 0; i < m.tInd.size(); i++)
		// triangle indicis are 1 indexing so subtract to convert to 0 indexing
		ofDrawTriangle(m.verts[m.tInd[i][0]], m.verts[m.tInd[i][1]], m.verts[m.tInd[i][2]]);

	// get toggle value for drawing the normal
	if ((bool)normalToggle)
	{
		float length = normalLength;
		for (int i = 0; i < m.tInd.size(); i++)
			ofDrawLine(m.tCentroid[i], m.tCentroid[i] + length * m.tNormal[i]);
	}
	

	cam.end();

	if (!bHide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
