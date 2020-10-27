#include "raylib.h"
#include <unistd.h>
int main(void)
{
  
    const int screenWidth = 1000;
    const int screenHeight = 1000;
  
    
    Vector3 floorSize = {20.0f, 0.0f, 20.0f};
    
    Vector3 agentPosition = {0.0f, 30.0f, 0.0f};
    Vector3 agentSize = {10.0f, 10.0f, 10.0f};
  
    InitWindow(screenWidth, screenHeight, "gravity");

   
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };           
    camera.fovy = 45.0f;                               
    camera.type = CAMERA_PERSPECTIVE;                 
              

    SetCameraMode(camera, CAMERA_FREE); 
    

    SetTargetFPS(60);   
    
    //for(int i = 0; i < 100000; i++){
            //sleep(1);
            
       // if(agentPosition.y == 0.0f){
          //  break;
      //  }
      //  }
   
    while (!WindowShouldClose())        
    {
        
        UpdateCamera(&camera);     
        if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    

        BeginDrawing();

        ClearBackground(WHITE);

        BeginMode3D(camera);
        
        if(agentPosition.y - agentSize.y/2 >= 0.0f){
        agentPosition.y-=0.05f;
        }
        
        DrawCubeV(agentPosition, agentSize, GREEN);
        DrawCubeV((Vector3){0.0f, 0.0f, 0.0f}, floorSize, RED);
        
        

        EndMode3D();

          

        EndDrawing();
    }
    

    
    CloseWindow();              


    return 0;
}