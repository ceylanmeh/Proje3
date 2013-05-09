#version 120

// vertex shaderindan gelen veriler
varying vec3 normal;
varying vec3 x;

// fragment shader main metodu
void main(void)
{
    // gl_FragColor ekrana basilacak rengi secer
    vec3 z = vec3(0.0,0.0,-1.0);
	vec3 y = normalize(x);     
	float c = dot(y,z);
	vec3 PURPLE = vec3( 0.5, 0.0, 1.0 );
    vec3 RED = vec3( 1.0, 0.0, 0.0 );
	vec3 fresnel = mix(PURPLE,RED,cos(c));
	//vec3 fresnel = 0 + (1-0.1) * pow(1+cos(c), 0.1);

	gl_FragColor = vec4(normalize(fresnel),1.0);
	
}
