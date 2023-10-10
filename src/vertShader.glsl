#version 430
uniform float offset;
uniform float size;
uniform float rotation;

layout (location=0) in vec3 position;
uniform mat4 mv_matrix;
uniform mat4 proj_matrix;
uniform float tf; // time factor for animation and placement of cubes 

out vec4 varyingColor;

// declaration of matrix transformation utility functions 
// (GLSL requires functions to be declared prior to invocation) 

mat4 buildRotateX(float rad);
mat4 buildRotateY(float rad);
mat4 buildRotateZ(float rad);

mat4 buildTranslate(float x, float y, float z);

mat4 buildTranslate(float x, float y, float z) {
	mat4 trans = mat4(1.0,0.0,0.0,0.0,
					0.0,1.0,0.0,0.0,
					0.0,0.0,1.0,0.0,
					x,y,z,1.0);
	return trans;
};

mat4 buildRotateX(float rad) {
	mat4 rotateX = mat4(1.0,0.0,0.0,0.0,
						0.0,cos(rad),-sin(rad),0.0,
						0.0,sin(rad),cos(rad),0.0,
						0.0,0.0,0.0,1.0);
	return rotateX;
};
mat4 buildRotateY(float rad) {
	mat4 rotateY = mat4(cos(rad),0.0,sin(rad),0.0,
						0.0,1.0,0.0,0.0,
						-sin(rad),0.0,cos(rad),0.0,
						0.0,0.0,0.0,1.0);
	return rotateY;
};
mat4 buildRotateZ(float rad) {
	mat4 rotateZ = mat4(cos(rad),-sin(rad),0.0,0.0,
						sin(rad),cos(rad),0.0,0.0,
						0.0,0.0,1.0,0.0,
						0.0,0.0,0.0,1.0);
	return rotateZ;
};

void main(void)
{
float i = gl_InstanceID +tf;
float a = sin(2.0 *i) * 8.0;
float b = sin(3.0 *i) * 8.0;
float c = sin(4.0 *i) * 8.0;

// build the rotation and translation matrices to be applied ot the cube's model matrix.

mat4 localRotX = buildRotateX(i);
mat4 localRotY = buildRotateY(i);
mat4 localRotZ = buildRotateZ(i);
mat4 localTranslate = buildTranslate(a,b,c);

// build the model matrix and append to view matrix to create model -view matrix.

//mat4 newM_matrix = localTranslate * localRotX * localRotY * localRotZ;
//mat4 mv_matrix = mv_matrix * newM_matrix;

gl_Position = proj_matrix * mv_matrix * vec4(position, 1.0);
varyingColor = vec4(position,1.0) * 0.5 + vec4(0.5,0.5,0.5,0.5);
}