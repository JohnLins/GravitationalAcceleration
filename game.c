#include "raylib.h"
#include <unistd.h>
int main(void)
{
  
    const int screenWidth = 1000;
    const int screenHeight = 1000;
  
    
    Vector3 floorSize = {20.0f, 0.0f, 20.0f};
    
    Vector3 agentPosition = {0.0f, 300.0f, 0.0f};
    Vector3 agentSize = {10.0f, 10.0f, 10.0f};
    
    double speed = 0.00f;
    double acceleration = 0.00981f;
  
    InitWindow(screenWidth, screenHeight, "gravity");

   
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 50.0f, -10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 20.0f, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };           
    camera.fovy = 45.0f;                               
    camera.type = CAMERA_PERSPECTIVE;                 
              

    SetCameraMode(camera, CAMERA_FREE); 
    

    SetTargetFPS(60);   
    
 
   
    while (!WindowShouldClose())        
    {
        
        UpdateCamera(&camera);     
        if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    

        BeginDrawing();

        ClearBackground(GRAY);

        BeginMode3D(camera);
        
        if(agentPosition.y - agentSize.y/2 >= 0.0f){
        agentPosition.y-=(speed += acceleration);
        }
        
        DrawCubeV(agentPosition, agentSize, BLUE);
        DrawCubeV((Vector3){0.0f, 0.0f, 0.0f}, floorSize, RED);
        
        

        EndMode3D();

          

        EndDrawing();
    }
    

    
    CloseWindow();              


    return 0;
}