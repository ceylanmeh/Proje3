#version 120

// sabit degiskenler
uniform mat4 MVP;

// diziden alinacak degiskenler
attribute vec4 Position;
attribute vec3 Normal;

// fragment shader'a aktarilacak veriler
varying vec3 normal;
varying vec3 x;

// vertex shader main metodu
void main()
{	
    // gl_Position ekranda noktanin nerede olacagini belirtir.
    gl_Position = MVP * Position;
    normal = mat3(MVP)*Normal;
	x = Normal*mat3(gl_ModelViewMatrix);
	
}