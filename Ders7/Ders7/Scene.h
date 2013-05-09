
#ifndef Ders_7_Scene_h
#define Ders_7_Scene_h
#include <windows.h>
#include <vector>
#include "Camera.h"
#include "Geometry.h"
#include "ShadedGeometry.h"


class Scene{
public:
    void addNode( SceneNode *child){
        children.push_back(child);
    }
    void setCamera( Camera *camera){
        this->camera = camera;
    }
    void draw(){
        unsigned long len = children.size();
        for(  unsigned long i = 0; i < len ; i++)
        {
            drawNode(children[i]);
        }
    }
private:
    std::vector<SceneNode*> children;
    Camera *camera;
    void drawNode(SceneNode *node){
        node->draw(camera);
        unsigned long len = node->children.size();
        for(  unsigned long i = 0; i < len ; i++)
        {
            drawNode(node->children[i]);
        }    
    }
};


#endif
