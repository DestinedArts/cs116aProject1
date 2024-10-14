## About
Project 1 - 3D Mesh Viewer

Create an indexed Mesh class, read data from a Wavefront .obj file, and display the mesh in an OpenFrameworks interactive 3D Window. A simple panel interface using ofxGUI includes a toggle button to select whether or not face normals are displayed with a slider to adjust the normal.

**Code Editor**: Visual Studio<br>
**Library**: OpenGL (openFrameworks)

## Examples
* Search: https://www.stlfinder.com/3dmodels/?search=the+dragon+prince&free=0
* Ethari's Metal Lotus: https://www.thingiverse.com/thing:4049954
* Cube of Aaravos: https://www.thingiverse.com/thing:3119114
* Teapot/Teddy bear: https://groups.csail.mit.edu/graphics/classes/6.837/F03/models/

### Notes<br>
random notes taken during class

\<Vector\> important methods
* push.back()
* erase()
* size()  size - 1 = top of shape
* back()

**ofFile**: load/save files

**.obj files**: include in bin -> data<br>
ex: openFrameworks folder/apps/myApps/<projectname>/bin/data

reading in obj file: starts at index 1, not 0<br>
Check to make sure you are expecting the verts from the obj file to be "1 origin"; no index in 0 for vertices<br>
ie. in the obj file syntax the vert list starts with index 1, but in a c++ array, it starts with 0
