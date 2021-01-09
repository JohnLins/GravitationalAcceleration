#include "raylib.h"
//#include <unistd.h>
#include <stdio.h>
int main(void)
{
    
    float initialHeight;
    printf("Enter the initial height(Meters): ");
    scanf("%f", &initialHeight);  
    
    double speed = 0.00f;
    float acceleration;
    float *acceleration_ptr = &acceleration;
    printf("Enter the acceleration(Meters per second^2): ");
    scanf("%f", acceleration_ptr);
    
    *acceleration_ptr = acceleration / 1000.0;



    
    float angle;
    float *angle_ptr = &angle;
    printf("Enter the angle(In degrees, must be positive, must be between ): ");
    scanf("%f", angle_ptr);

    if(angle > 180 || angle < -180) {
        printf("Angle can not be less than -180 deg or more than 180 deg");
        return 0;
    }
    
    *angle_ptr = angle / 100.0;
    
    

    
  
    const int screenWidth = 1000;
    const int screenHeight = 1000;
  
    
    Vector3 floorSize = {200.0f, 1.0f, 20.0f};
    
    Vector3 agentPosition = {0.0f, initialHeight, 0.0f};
    Vector3 agentSize = {10.0f, 10.0f, 10.0f};
    
    
  
    InitWindow(screenWidth, screenHeight, "(Angle) Gravitational Acceleration By John Lins");

   
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 230.0f, 50.0f, 230.0f };
    camera.target = (Vector3){ 0.0f, -1.0f, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };           
    camera.fovy = 45.0f;                               
    camera.type = CAMERA_PERSPECTIVE;                 
              

    SetCameraMode(camera, CAMERA_FREE); 
    

    SetTargetFPS(60);   
    
 
   
    while (!WindowShouldClose())        
    {
        
        UpdateCamera(&camera);     
        if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
        
        if (IsKeyDown('R')) agentPosition.y = 500.0f;
    

        BeginDrawing();

        ClearBackground(GRAY);

        BeginMode3D(camera);
        
        if(agentPosition.y - agentSize.y/2 >= 1.0f){
        agentPosition.y-=(speed += acceleration);

            agentPosition.x += angle;
        }
        
        
        DrawCube((Vector3){0.0f, initialHeight/2, 0.0f}, 2.0f, initialHeight, 2.0f, BLACK);
        
        
        DrawCubeV(agentPosition, agentSize, BLUE);
        DrawCubeV((Vector3){0.0f, 0.0f, 0.0f}, floorSize, RED);
        
        

        EndMode3D();

          

        EndDrawing();
    }
    

    
    CloseWindow();              


    return 0;
}