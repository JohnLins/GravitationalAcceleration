#include "raylib.h"
//#include <unistd.h>
#include <stdio.h>


float path(float *acceleration, float *changeInX, float x, float *initialHeight){
    printf("%f", *acceleration);
    return (-1 * ((1 / *changeInX) * x^2)) + *initialHeight;
    //float a = 0.1;
    //a is vertial stretch and compression
    //return 0.2((*x)*(*x)) + *initialHeight;
}



int main(void)
{
    
    float initialHeight;
    printf("Enter the initial height(Meters): ");
    scanf("%f", &initialHeight);  
    
    float angle;
    //double speed = 0.00f;
    Vector3 floorSize;
    
    float acceleration;
    float *acceleration_ptr = &acceleration;
    printf("Enter the acceleration(Meters per second^2): ");
    scanf("%f", acceleration_ptr);
    
    *acceleration_ptr = acceleration / 1000.0;

    
    char verticalOrAngle;
   
    printf("Vertical(\"v\") or at angle(\"a\"): ");
    scanf(" %c", &verticalOrAngle);
    
    if(verticalOrAngle == 'v' || verticalOrAngle == 'V'){
        angle = 0.0;
        printf("Running...");
        floorSize = (Vector3){20.0f, 1.0f, 20.0f};
    } else if (verticalOrAngle == 'a' || verticalOrAngle == 'A'){
        
        float *angle_ptr = &angle;
        printf("Enter the angle(In degrees, must be positive, must be between ): ");
        scanf("%f", angle_ptr);

        if(angle > 180 || angle < -180) {
            printf("Angle can not be less than -180 deg or more than 180 deg");
            return 0;
        }
        
        *angle_ptr = angle / 100.0;
        
        printf("Running...");
        
        floorSize = (Vector3){200.0f, 1.0f, 20.0f};
    
    } else {
       printf("Invalid input");
       return 0;
    }
    
    
    float changeInX = 20.0;

    
  
    const int screenWidth = 1000;
    const int screenHeight = 1000;
  
    
    
    
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
        if (IsKeyDown('R')){
            agentPosition.y = initialHeight;
            agentPosition.x = 0.0f;
            agentPosition.z = 0.0f;
        }
        
    

        BeginDrawing();

        ClearBackground(GRAY);

        BeginMode3D(camera);
        
        
        
        if(agentPosition.y - agentSize.y/2 >= 1.0f){
            agentPosition.x += 1.0;
            agentPosition.y = path(&acceleration, &changeInX, agentPosition.x, initialHeight);
           
                
            
        }
        
        
        DrawCube((Vector3){0.0f, initialHeight/2, 0.0f}, 2.0f, initialHeight, 2.0f, BLACK);
        DrawCubeWires((Vector3){0.0f, initialHeight/2, 0.0f}, 2.0f, initialHeight, 2.0f, BLUE);
        
        
        DrawCubeV(agentPosition, agentSize, BLUE);
        DrawCubeWires(agentPosition, agentSize.x, agentSize.y, agentSize.z, BLACK);
        
        DrawCubeV((Vector3){0.0f, 0.0f, 0.0f}, floorSize, RED);
        DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, floorSize.x, floorSize.y, floorSize.z, BLACK);
       // DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, floorSize, RED);
        
        
        
        
        

        EndMode3D();

          

        EndDrawing();
    }
    

    
    CloseWindow();              


    return 0;
}