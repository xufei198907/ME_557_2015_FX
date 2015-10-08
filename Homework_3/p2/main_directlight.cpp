//
//  main_spotlight.cpp
//  HCI 557 Spotlight example
//
//  Adam Kohl, Fei Xu
//

// stl include
#include <iostream>
#include <string>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>


// glfw includes
#include <GLFW/glfw3.h>


// include local files
#include "controls.h"
#include "HCI557Common.h"
#include "CoordSystem.h"
#include "GLSphereHlgtDiff.h"
#include "GLSphereDiff.h"
#include "GLSphereSmooth.h"
#include "GLSphereSharp.h"



using namespace std;


// The handle to the window object
GLFWwindow*         window;

// Define some of the global variables we're using for this sample
GLuint program;

/* A trackball to move and rotate the camera view */
extern Trackball trackball;


int main(int argc, const char * argv[])
{
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Init glfw, create a window, and init glew
    
    // Init the GLFW Window
    window = initWindow();
    
    
    // Init the glew api
    initGlew();
    
    

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Create some models
    
    // coordinate system
//    CoordSystem* cs = new CoordSystem(70.0);
    
    GLSphereHlgtDiff* sphere1 = new GLSphereHlgtDiff(0.0, 0.0, 0.0, 10.0, 200, 200);
    
    GLSphereDiff* sphere2 = new GLSphereDiff(25.0, 0.0, 0.0, 10.0, 200, 200);
    
    GLSphereSharp* sphere3 = new GLSphereSharp(50.0, 0.0, 0.0, 10.0, 200, 200);
    
    GLSphereSmooth* sphere4 = new GLSphereSmooth(75.0, 0.0, 0.0, 10.0, 200, 200);
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Main render loop
    
    // Set up our green background color
    static const GLfloat clear_color[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    // This sets the camera to a new location
    // the first parameter is the eye position, the second the center location, and the third the up vector. 
    SetViewAsLookAt(glm::vec3(37.5f, 0.0f, 75.0f), glm::vec3(37.5f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    // Enable depth test
    // ignore this line, it allows us to keep the distance value after we proejct each object to a 2d canvas.
    glEnable(GL_DEPTH_TEST);
    
    //sphere->enableNormalVectorRenderer();
    
    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {
        
        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR , 0, clear_color);
        glClearBufferfv(GL_DEPTH , 0, clear_depth);
        
    
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This renders the objects
        
        // Set the trackball locatiom
        SetTrackballLocation(trackball.getRotationMatrix());
        
        // draw the objects
//        cs->draw();
        
        sphere1->draw();
        
        sphere2->draw();
        
        sphere3->draw();
        
        sphere4->draw();
        
        //// This renders the objects
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    
//    delete cs;


}

