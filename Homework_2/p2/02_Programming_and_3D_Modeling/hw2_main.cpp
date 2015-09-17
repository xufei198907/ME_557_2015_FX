//
//  main.cpp
//  OpenGL4Test
//
//  Created by Rafael Radkowski on 5/28/15.
//  Copyright (c) 2015 -. All rights reserved.
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


// glfw includes
#include <GLFW/glfw3.h>


// include local files
#include "controls.h"
#include "HCI557Common.h"


using namespace std;

static const string vs_string =
"#version 410 core                                                 \n"
"                                                                   \n"
"uniform mat4 projectionMatrix;                                    \n"
"uniform mat4 viewMatrix;                                           \n"
"uniform mat4 modelMatrix;                                          \n"
"in vec3 in_Position;                                               \n"
"                                                                   \n"
"in vec3 in_Color;                                                  \n"
"out vec3 pass_Color;                                               \n"
"                                                                  \n"
"void main(void)                                                   \n"
"{                                                                 \n"
"    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);  \n"
"    pass_Color = in_Color;                                         \n"
"}                                                                 \n";

// Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
static const string fs_string  =
"#version 410 core                                                 \n"
"                                                                  \n"
"in vec3 pass_Color;                                                 \n"
"out vec4 color;                                                    \n"
"void main(void)                                                   \n"
"{                                                                 \n"
"    color = vec4(pass_Color, 1.0);                               \n"
"}                                                                 \n";




/// Camera control matrices
glm::mat4 projectionMatrix; // Store the projection matrix
glm::mat4 viewMatrix; // Store the view matrix
glm::mat4 modelMatrix; // Store the model matrix




// The handle to the window object
GLFWwindow*         window;


// Define some of the global variables we're using for this sample
GLuint program;







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Fill this functions with your model code.

// USE THESE vertex array objects to define your objects
unsigned int vaoID[2];

unsigned int vboID[2];

/*!
 ADD YOUR CODE TO CREATE THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
void createTriangleStripModel(void)
{
    // use the vertex array object vaoID[0] for this model representation
    
    
    //TODO:
    float* vertices = new float[117];  // Vertices for our square
    float *colors = new float[117]; // Colors for our vertices
    
    vertices[0] = 0.0; vertices[1] = 0.0; vertices[2] = 0.0; //1
    colors[0] = 1.0; colors[1] = 1.0; colors[2] = 0.0;
    
    vertices[3] = -3.0; vertices[4] = 0.0; vertices[5] = 0.0; //2
    colors[3] = 1.0; colors[4] = 1.0; colors[5] = 0.0;
    
    vertices[6] = -1.0; vertices[7] = 0.0; vertices[8] = 1.0; //3
    colors[6] = 1.0; colors[7] = 1.0; colors[8] = 0.0;
    
    vertices[9] = -3.0; vertices[10] = 0.0; vertices[11] = 1.0; //4
    colors[9] = 1.0; colors[10] = 1.0; colors[11] = 0.0;
    
    // RIGHT SIDE
    vertices[12] = -3.0; vertices[13] = 1.0; vertices[14] = 1.0; // 5
    colors[12] = 0.0; colors[13] = 1.0; colors[14] = 0.0; //
    
    vertices[15] = -3.0; vertices[16] = 0.0; vertices[17] = 0.0; // 6
    colors[15] = 0.0; colors[16] = 1.0; colors[17] = 0.0; //
    
    // BACK
    vertices[18] = -3.0; vertices[19] = 1.0; vertices[20] = 0.0; // 7
    colors[18] = 0.0; colors[19] = 0.0; colors[20] = 1.0; //
    
    vertices[21] = 0.0; vertices[22] = 0.0; vertices[23] = 0.0; // 8
    colors[21] = 0.0; colors[22] = 01.0; colors[23] = 1.0; //
    
    // LEFT
    vertices[24] = -1.0; vertices[25] = 1.0; vertices[26] = 0.0; // 9
    colors[24] = 0.0; colors[25] = 1.0; colors[26] = 0.0; // Top left corner
    
    vertices[27] = 0.0; vertices[28] = 2.0; vertices[29] = 0.0; //10
    colors[27] = 0.0; colors[28] = 1.0; colors[29] = 0.0; // Bottom left corner
    
    // BOTTOM
    vertices[30] = -1.0; vertices[31] = 2.0; vertices[32] = 0.0; // 11
    colors[30] = 1.0; colors[31] = 1.0; colors[32] = 0.0; // Top left corner
    
    vertices[33] = 0.0; vertices[34] = 2.0; vertices[35] = 1.0; // 12
    colors[33] = 1.0; colors[34] = 1.0; colors[35] = 0.0; // Bottom left corner
    
    //TOP
    vertices[36] = -1.0; vertices[37] = 2.0; vertices[38] = 1.0; // 13
    colors[36] = 0.0; colors[37] = 1.0; colors[38] = 0.0; // Top left corner
    
    vertices[39] = 0.0; vertices[40] = 1.0; vertices[41] = 3.0; // 14
    colors[39] = 0.0; colors[40] = 1.0; colors[41] = 0.0; // Bottom left corner

    vertices[42] = -1.0; vertices[43] = 1.0; vertices[44] = 3.0; // 15
    colors[42] = 1.0; colors[43] = 1.0; colors[44] = 0.0; // Top left corner
    
    vertices[45] = 0.0; vertices[46] = 0.0; vertices[47] = 3.0; // 16
    colors[45] = 1.0; colors[46] = 1.0; colors[47] = 0.0;
    
    vertices[48] = -1.0; vertices[49] = 0.0; vertices[50] = 3.0; // 17
    colors[48] = 1.0; colors[49] = 1.0; colors[50] = 0.0;
    
    vertices[51] = 0.0; vertices[52] = 0.0; vertices[53] = 0.0; // 18
    colors[51] = 1.0; colors[52] = 1.0; colors[53] = 0.0;
    
    vertices[54] = 0.0; vertices[55] = 2.0; vertices[56] = 0.0; // 19
    colors[54] = 1.0; colors[55] = 1.0; colors[56] = 0.0;
    
    vertices[57] = 0.0; vertices[58] = 0.0; vertices[59] = 3.0; // 20
    colors[57] = 1.0; colors[58] = 1.0; colors[59] = 0.0;
    
    vertices[60] = 0.0; vertices[61] = 2.0; vertices[62] = 1.0; // 21
    colors[60] = 1.0; colors[61] = 1.0; colors[62] = 0.0;
    
    vertices[63] = 0.0; vertices[64] = 1.0; vertices[65] = 3.0; // 22
    colors[63] = 1.0; colors[64] = 1.0; colors[65] = 0.0;
    
    vertices[66] = -1.0; vertices[67] = 0.0; vertices[68] = 3.0; // 23
    colors[66] = 1.0; colors[67] = 1.0; colors[68] = 0.0;
    
    vertices[69] = 0.0; vertices[70] = 0.0; vertices[71] = 0.0; // 24
    colors[69] = 1.0; colors[70] = 1.0; colors[71] = 0.0;
    
    vertices[72] = -1.0; vertices[73] = 0.0; vertices[74] = 1.0; // 25
    colors[72] = 1.0; colors[73] = 1.0; colors[74] = 0.0;
    
    vertices[75] = -1.0; vertices[76] = 1.0; vertices[77] = 1.0; // 26
    colors[75] = 1.0; colors[76] = 1.0; colors[77] = 0.0;
    
    vertices[78] = -3.0; vertices[79] = 1.0; vertices[80] = 1.0; // 27
    colors[78] = 1.0; colors[79] = 1.0; colors[80] = 1.0;
    
    vertices[81] = -1.0; vertices[82] = 1.0; vertices[83] = 0.0; // 28
    colors[81] = 0.0; colors[82] = 0.0; colors[83] = 1.0;
    
    vertices[84] = -3.0; vertices[85] = 1.0; vertices[86] = 0.0; // 29
    colors[84] = 0.0; colors[85] = 0.0; colors[86] = 1.0;
    
    vertices[87] = -1.0; vertices[88] = 0.0; vertices[89] = 1.0; // 30
    colors[87] = 0.0; colors[88] = 0.0; colors[89] = 1.0;
    
    vertices[90] = -1.0; vertices[91] = 1.0; vertices[92] = 1.0; // 31
    colors[90] = 0.0; colors[91] = 0.0; colors[92] = 1.0;
    
    vertices[93] = -1.0; vertices[94] = 1.0; vertices[95] = 0.0; // 32
    colors[93] = 0.0; colors[94] = 0.0; colors[95] = 1.0;
    
    vertices[96] = -1.0; vertices[97] = 2.0; vertices[98] = 1.0; // 33
    colors[96] = 0.0; colors[97] = 0.0; colors[98] = 1.0;
    
    vertices[99] = -1.0; vertices[100] = 2.0; vertices[101] = 0.0; // 34
    colors[99] = 0.0; colors[100] = 0.0; colors[101] = 1.0;
    
    vertices[102] = 0.0; vertices[103] = 0.0; vertices[104] = 0.0; // 35
    colors[102] = 0.0; colors[103] = 0.0; colors[104] = 1.0;
    
    vertices[105] = -1.0; vertices[106] = 0.0; vertices[107] = 3.0; // 36
    colors[105] = 0.0; colors[106] = 0.0; colors[107] = 1.0;
    
    vertices[108] = -1.0; vertices[109] = 1.0; vertices[110] = 3.0; // 37
    colors[108] = 0.0; colors[109] = 0.0; colors[110] = 1.0;
    
    vertices[111] = -1.0; vertices[112] = 0.0; vertices[113] = 1.0; // 38
    colors[111] = 0.0; colors[112] = 0.0; colors[113] = 1.0;
    
    vertices[114] = -1.0; vertices[115] = 2.0; vertices[116] = 1.0; // 39
    colors[114] = 0.0; colors[115] = 0.0; colors[116] = 1.0;
    
    // for (int i = 0; i < 117; i++)
 //    {
 //        switch (i%3)
 //        {
 //            case 0:
 //                colors[i] = 0.0;
 //                break;
 //            case 1:
 //                colors[i] = 0.0;
 //                break;
 //            case 2:
 //                colors[i] = 0.8+0.2*i/176.0;
 //                break;
 //            default:
 //                break;
 //        }
 //    }

    glGenVertexArrays(2, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it
    
    
    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object
    
    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 117 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object
    
    
    //Color
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 117 * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array
    
    glBindVertexArray(0); // Disable our Vertex Buffer Object
    
    
    delete [] vertices; // Delete our vertices from memory
    
}

/*!
 ADD YOUR CODE TO CREATE A MODEL USING PRIMITIVES OF YOUR CHOISE TO THIS FUNCTION
 */
void createMyModel(void)
{
    // use the vertex array object vaoID[1] for this model representation
    
    //TODO:
    // use the vertex array object vaoID[0] for this model representation
    
    //TODO:
    float* vertices = new float[243];  // Vertices for our square
    float *colors = new float[243]; // Colors for our vertices
    
    
    vertices[0] = 0.0; vertices[1] = 0.0; vertices[2] = 0.0; //1 bottom
    vertices[3] = -3.0; vertices[4] = 0.0; vertices[5] = 0.0;
    vertices[6] = -1.0; vertices[7] = 0.0; vertices[8] = 1.0;
    
    // colors[2] = 0.5; colors[5] = 0.5; colors[8] = 0.5;
    
    vertices[9] = -3.0; vertices[10] = 0.0; vertices[11] = 0.0; //2 bottom
    vertices[12] = -1.0; vertices[13] = 0.0; vertices[14] = 1.0;
    vertices[15] = -3.0; vertices[16] = 0.0; vertices[17] = 1.0;
    
    // colors[11] = 0.5; colors[14] = 0.5; colors[17] = 0.5;
    
    vertices[18] = -3.0; vertices[19] = 0.0; vertices[20] = 1.0; //3 left
    vertices[21] = -3.0; vertices[22] = 1.0; vertices[23] = 0.0;
    vertices[24] = -3.0; vertices[25] = 1.0; vertices[26] = 1.0;
    
    // colors[20] = 0.7; colors[23] = 0.7; colors[26] = 0.7;
    
    vertices[27] = -3.0; vertices[28] = 1.0; vertices[29] = 0.0; //4 left
    vertices[30] = -3.0; vertices[31] = 0.0; vertices[32] = 0.0;
    vertices[33] = -3.0; vertices[34] = 0.0; vertices[35] = 1.0;
    
    // colors[29] = 0.7; colors[32] = 0.7; colors[35] = 0.7;
    
    vertices[36] = 0.0; vertices[37] = 0.0; vertices[38] = 0.0; //5  back
    vertices[39] = -3.0; vertices[40] = 0.0; vertices[41] = 0.0;
    vertices[42] = -1.0; vertices[43] = 1.0; vertices[44] = 0.0;
    
    // colors[38] = 0.65; colors[41] = 0.65; colors[44] = 0.65;
    
    vertices[45] = -1.0; vertices[46] = 1.0; vertices[47] = 0.0; //6 back
    vertices[48] = -3.0; vertices[49] = 1.0; vertices[50] = 0.0;
    vertices[51] = -3.0; vertices[52] = 0.0; vertices[53] = 0.0;
    
    // colors[47] = 0.65; colors[50] = 0.65; colors[53] = 0.65;
    
    vertices[54] = 0.0; vertices[55] = 0.0; vertices[56] = 0.0; //7 back
    vertices[57] = -1.0; vertices[58] = 1.0; vertices[59] = 0.0;
    vertices[60] = 0.0; vertices[61] = 2.0; vertices[62] = 0.0;
    
    // colors[56] = 0.65; colors[59] = 0.65; colors[62] = 0.65;
    
    vertices[63] = -1.0; vertices[64] = 1.0; vertices[65] = 0.0; //8 back
    vertices[66] = -1.0; vertices[67] = 2.0; vertices[68] = 0.0;
    vertices[69] = -0.0; vertices[70] = 2.0; vertices[71] = 0.0;
    
    // colors[65] = 0.65; colors[68] = 0.65; colors[71] = 0.65;
    
    vertices[72] = 0.0; vertices[73] = 0.0; vertices[74] = 0.0;  //9 right
    vertices[75] = 0.0; vertices[76] = 0.0; vertices[77] = 3.0;
    vertices[78] = 0.0; vertices[79] = 2.0; vertices[80] = 0.0;
    
    vertices[81] = 0.0; vertices[82] = 2.0; vertices[83] = 0.0; //10 right
    vertices[84] = 0.0; vertices[85] = 1.0; vertices[86] = 3.0;
    vertices[87] = 0.0; vertices[88] = 0.0; vertices[89] = 3.0;
    
    vertices[90] = 0.0; vertices[91] = 2.0; vertices[92] = 0.0; //11 right
    vertices[93] = 0.0; vertices[94] = 2.0; vertices[95] = 1.0;
    vertices[96] = 0.0; vertices[97] = 1.0; vertices[98] = 3.0;
    
    vertices[99] = -3.0; vertices[100] = 1.0; vertices[101] = 0.0; //12 left top
    vertices[102] = -3.0; vertices[103] = 1.0; vertices[104] = 1.0;
    vertices[105] = -1.0; vertices[106] = 1.0; vertices[107] = 0.0;
    
    // colors[101] = 0.85; colors[104] = 0.85; colors[107] = 0.85;
    
    vertices[108] = -1.0; vertices[109] = 1.0; vertices[110] = 0.0; //13 left top
    vertices[111] = -3.0; vertices[112] = 1.0; vertices[113] = 1.0;
    vertices[114] = -1.0; vertices[115] = 1.0; vertices[116] = 1.0;
    
    // colors[110] = 0.85; colors[113] = 0.85; colors[116] = 0.85;

    vertices[117] = 0.0; vertices[118] = 0.0; vertices[119] = 0.0; //14 bottom
    vertices[120] = -1.0; vertices[121] = 0.0; vertices[122] = 1.0;
    vertices[123] = -1.0; vertices[124] = 0.0; vertices[125] = 3.0;
    
    // colors[119] = 0.5; colors[122] = 0.5; colors[125] = 0.5;
    
    vertices[126] = 0.0; vertices[127] = 0.0; vertices[128] = 0.0; //15 bottom
    vertices[129] = -0.0; vertices[130] = 0.0; vertices[131] = 3.0;
    vertices[132] = -1.0; vertices[133] = 0.0; vertices[134] = 3.0;
    
    // colors[128] = 0.5; colors[131] = 0.5; colors[134] = 0.5;
    
    vertices[135] = -3.0; vertices[136] = 0.0; vertices[137] = 1.0; //16 left front
    vertices[138] = -1.0; vertices[139] = 0.0; vertices[140] = 1.0;
    vertices[141] = -1.0; vertices[142] = 1.0; vertices[143] = 1.0;
    
    // colors[137] = 0.8; colors[140] = 0.8; colors[143] = 0.8;
    
    vertices[144] = -3.0; vertices[145] = 1.0; vertices[146] = 1.0; //17 left front
    vertices[147] = -3.0; vertices[148] = 0.0; vertices[149] = 1.0;
    vertices[150] = -1.0; vertices[151] = 1.0; vertices[152] = 1.0;
    
    // colors[146] = 0.8; colors[149] = 0.8; colors[152] = 0.8;
    
    vertices[153] = -1.0; vertices[154] = 2.0; vertices[155] = 0.0; //18 left 2
    vertices[156] = -1.0; vertices[157] = 2.0; vertices[158] = 1.0;
    vertices[159] = -1.0; vertices[160] = 1.0; vertices[161] = 0.0;
    
    // colors[155] = 0.7; colors[158] = 0.7; colors[161] = 0.7;
    
    vertices[162] = -1.0; vertices[163] = 1.0; vertices[164] = 0.0; //19 left 2
    vertices[165] = -1.0; vertices[166] = 2.0; vertices[167] = 1.0;
    vertices[168] = -1.0; vertices[169] = 1.0; vertices[170] = 3.0;
    
    // colors[164] = 0.7; colors[167] = 0.7; colors[170] = 0.7;
    
    vertices[171] = -1.0; vertices[172] = 1.0; vertices[173] = 1.0; //20 left 2
    vertices[174] = -1.0; vertices[175] = 0.0; vertices[176] = 1.0;
    vertices[177] = -1.0; vertices[178] = 0.0; vertices[179] = 3.0;
    
    // colors[173] = 0.7; colors[176] = 0.7; colors[179] = 0.7;
    
    vertices[180] = -1.0; vertices[181] = 0.0; vertices[182] = 3.0; //21 left 2
    vertices[183] = -1.0; vertices[184] = 1.0; vertices[185] = 3.0;
    vertices[186] = -1.0; vertices[187] = 1.0; vertices[188] = 1.0;
    
    // colors[182] = 0.7; colors[185] = 0.7; colors[188] = 0.7;
    
    vertices[189] = 0.0; vertices[190] = 2.0; vertices[191] = 0.0; //22 top
    vertices[192] = -1.0; vertices[193] = 2.0; vertices[194] = 0.0;
    vertices[195] = 0.0; vertices[196] = 2.0; vertices[197] = 1.0;
    
    // colors[191] = 0.85; colors[194] = 0.85; colors[197] = 0.85;
    
    vertices[198] = -1.0; vertices[199] = 2.0; vertices[200] = 0.0; //23 top
    vertices[201] = -1.0; vertices[202] = 2.0; vertices[203] = 1.0;
    vertices[204] = 0.0; vertices[205] = 2.0; vertices[206] = 1.0;
    
    // colors[200] = 0.85; colors[203] = 0.85; colors[206] = 0.85;
    
    vertices[207] = 0.0; vertices[208] = 2.0; vertices[209] = 1.0; //24 slope
    vertices[210] = -1.0; vertices[211] = 2.0; vertices[212] = 1.0;
    vertices[213] = 0.0; vertices[214] = 1.0; vertices[215] = 3.0;
    
    // colors[209] = 0.9; colors[212] = 0.9; colors[215] = 0.9;
    
    vertices[216] = -1.0; vertices[217] = 2.0; vertices[218] = 1.0; //25 slope
    vertices[219] = 0.0; vertices[220] = 1.0; vertices[221] = 3.0;
    vertices[222] = -1.0; vertices[223] = 1.0; vertices[224] = 3.0;
    
    // colors[218] = 0.9; colors[221] = 0.9; colors[224] = 0.9;
    
    vertices[225] = 0.0; vertices[226] = 1.0; vertices[227] = 3.0; //26 front
    vertices[228] = -1.0; vertices[229] = 1.0; vertices[230] = 3.0;
    vertices[231] = 0.0; vertices[232] = 0.0; vertices[233] = 3.0;
    
    // colors[227] = 0.95; colors[230] = 0.95; colors[233] = 0.95;
    
    vertices[234] = -1.0; vertices[235] = 1.0; vertices[236] = 3.0; //27 front
    vertices[237] = -1.0; vertices[238] = 0.0; vertices[239] = 3.0;
    vertices[240] = 0.0; vertices[241] = 0.0; vertices[242] = 3.0;
    
    // colors[236] = 0.95; colors[239] = 0.95; colors[242] = 0.95;

    for (int i = 0; i < 243; i++)
    {
        switch (i%3)
        {
            case 0:
                colors[i] = 0.0;
                break;
            case 1:
                colors[i] = 0.0;
                break;
            case 2:
                colors[i] = 1.0;
                break;
            default:
                break;
        }
    }
    
    
    glGenVertexArrays(2, &vaoID[1]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[1]); // Bind our Vertex Array Object so we can use it
    
    
    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object
    
    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 243 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object
    
    
    //Color
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 243 * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array
    
    glBindVertexArray(0); // Disable our Vertex Buffer Object
    
    
    delete [] vertices; // Delete our vertices from memory
}



/*!
 ADD YOUR CODE TO RENDER THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
void renderTriangleStripModel(void)
{
    glBindVertexArray(vaoID[0]);
    // Draw the triangles
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 39);
    // Unbind our Vertex Array Object
    glBindVertexArray(0);

    
}

/*!
 ADD YOUR CODE TO RENDER YOUR MODEL TO THIS FUNCTION
 */
void renderMyModel(void)
{
    glBindVertexArray(vaoID[1]);
    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 81);
    // Unbind our Vertex Array Object
    glBindVertexArray(0);
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!
 This function creates the two models
 */
void setupScene(void) {
    
    createTriangleStripModel();
    createMyModel();
    
}


/*!
 This function updates the virtual camera
 */
bool updateCamera()
{
    // Compute the MVP matrix from keyboard and mouse input
    computeMatricesFromInputs();
    viewMatrix =  getViewMatrix(); // get the current view matrix
    
    return true;
}





int main(int argc, const char * argv[])
{
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Init glfw, create a window, and init glew
    
    // Init the GLFW Window
    window = initWindow();
    
    
    // Init the glew api
    initGlew();
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// The Shader Program starts here
    
    // Vertex shader source code. This draws the vertices in our window. We have 3 vertices since we're drawing an triangle.
    // Each vertex is represented by a vector of size 4 (x, y, z, w) coordinates.
    static const string vertex_code = vs_string;
    static const char * vs_source = vertex_code.c_str();
    
    // Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
    static const string fragment_code = fs_string;
    static const char * fs_source = fragment_code.c_str();
    
    // This next section we'll generate the OpenGL program and attach the shaders to it so that we can render our triangle.
    program = glCreateProgram();
    
    // We create a shader with our fragment shader source code and compile it.
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);
    
    // We create a shader with our vertex shader source code and compile it.
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);
    
    // We'll attach our two compiled shaders to the OpenGL program.
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    
    glLinkProgram(program);
    
    // We'll specify that we want to use this program that we've attached the shaders to.
    glUseProgram(program);
    
    //// The Shader Program ends here
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    // It controls the virtual camera
    
    // Set up our green background color
    static const GLfloat clear_color[] = { 0.6f, 0.7f, 1.0f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    
    projectionMatrix = glm::perspective(1.1f, (float)800 / (float)600, 0.1f, 100.f);
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Create our model matrix which will halve the size of our model
    viewMatrix = glm::lookAt(glm::vec3(1.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    int projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix"); // Get the location of our projection matrix in the shader
    int viewMatrixLocation = glGetUniformLocation(program, "viewMatrix"); // Get the location of our view matrix in the shader
    int modelMatrixLocation = glGetUniformLocation(program, "modelMatrix"); // Get the location of our model matrix in the shader
    
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); // Send our projection matrix to the shader
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
    
    
    glBindAttribLocation(program, 0, "in_Position");
    glBindAttribLocation(program, 1, "in_Color");
    
    //// The Shader Program ends here
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    // this creates the scene
    setupScene();
    
    

    // Enable depth test
    // ignore this line, it allows us to keep the distance value after we proejct each object to a 2d canvas.
    glEnable(GL_DEPTH_TEST);
    
    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {
        
        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR , 0, clear_color);
        glClearBufferfv(GL_DEPTH , 0, clear_depth);
        
        
        // update the virtual camera
        // ignore this line since we did not introduced cameras.
        updateCamera();
        
        
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This generate the object
        // Enable the shader program
        glUseProgram(program);
        
        // this changes the camera location
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // send the view matrix to our shader
        
        // This moves the model to the right
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(3.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
        
        renderTriangleStripModel();
        
        // This moves the model to the left
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader
        
        renderMyModel();
        
        
        glUseProgram(0);
        //// This generate the object
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    // Program clean up when the window gets closed.
    glDeleteVertexArrays(2, vaoID);
    glDeleteProgram(program);
}

