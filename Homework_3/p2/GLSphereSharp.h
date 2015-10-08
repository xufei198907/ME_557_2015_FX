//
//  GLSphereExt.hpp
//  HCI557_Spotlight
//
//   Adam Kohl, Fei Xu
//
//
#pragma once


// stl include
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// locals
#include "GLObject.h"
#include "GLSphere.h"
#include "Shaders.h"

#include "HCI557Datatypes.h"





class GLSphereSharp : public GLSphere
{
public:
    
    GLSphereSharp(float center_x, float center_y, float center_z, float radius, int rows = 10, int segments = 10 );
    ~GLSphereSharp();
    
    
protected:
    
    
    
    /*
     Inits the shader program for this object
     */
    virtual void initShader(void);
    
    
    // The spotlight object
    GLSpotLightSource           _light_source1;
    GLSpotLightSource           _light_source2;
    


};